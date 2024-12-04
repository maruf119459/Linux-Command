// Motor driver pins
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;
const int ENB = 5;

// Ultrasonic sensor pins
const int trigPin = 12;
const int echoPin = 11;

// Buzzer and LED pins
const int buzzerPin = 3;
const int ledPin = 0;

// Sensor pins
const int flameSensor = A0;
const int smokeSensor = A5;
const int pumpPin = A4;

// Constants
const int fireDistance = 4; // Stopping distance from fire in cm
const int retreatDistance = 20; // Distance to move backward after extinguishing fire
const int nonFireAlertDistance = 10; // Object alert distance for non-fire objects in cm

// Function prototypes
long measureDistance();
void moveForward();
void moveBackward(int distance);
void stopMotors();
void extinguishFire();
void alertSmoke();
void soundBuzzer();

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  pinMode(flameSensor, INPUT);
  pinMode(smokeSensor, INPUT);
  pinMode(pumpPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (analogRead(smokeSensor) > 300) {  // Adjust threshold based on smoke sensor testing
    alertSmoke();
  }
  
  if (analogRead(flameSensor) < 500) {  // Adjust threshold for flame detection
    while (true) {
      long distance = measureDistance();
      
      if (distance <= nonFireAlertDistance && analogRead(flameSensor) >= 500) {
        soundBuzzer();
      } 
      else if (distance > fireDistance) {
        moveForward();
      } 
      else {
        stopMotors();
        extinguishFire();
        moveBackward(retreatDistance);
        break;
      }
    }
  } else {
    stopMotors();
  }
}

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  
  return distance;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void moveBackward(int distance) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  
  delay(distance * 100);  // Adjust based on calibration for distance
  stopMotors();
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void extinguishFire() {
  digitalWrite(pumpPin, HIGH);
  delay(5000);  // Run the pump for a fixed time; adjust as needed
  digitalWrite(pumpPin, LOW);
}

void alertSmoke() {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

void soundBuzzer() {
  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(buzzerPin, LOW);
  delay(500);
}
