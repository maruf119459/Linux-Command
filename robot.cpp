// Pin Definitions
const int ENA = 10;    // Motor A speed control (PWM)
const int IN1 = 9;     // Motor A direction control
const int IN2 = 8;     // Motor A direction control
const int IN3 = 7;     // Motor B direction control
const int IN4 = 6;     // Motor B direction control
const int ENB = 5;     // Motor B speed control (PWM)
const int buzzer = 2;  //buzzer to arduino pin 9

// Flame sensor pins
const int FLAME1 = A0;
const int FLAME2 = A1;
const int FLAME3 = A2;

// Water pump pin
const int WATER_PUMP = A5;  // Pin for controlling the water pump

// Time to move for calculated distances
const int forwardTime = 736;    // Time in ms for 14 cm forward
const int backwardTime = 2105;  // Time in ms for 40 cm backward
int pumpSpeed = 0;
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(FLAME1, INPUT);
  pinMode(FLAME2, INPUT);
  pinMode(FLAME3, INPUT);
  pinMode(buzzer, OUTPUT);  // Set buzzer - pin 9 as an output

  pinMode(WATER_PUMP, OUTPUT);

  Serial.begin(9600);
  stopMotors();  // Ensure motors are stopped at startup
}

// Function to move forward
void moveForward(int speedA, int speedB, int duration) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speedA);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speedB);

  delay(duration);
  stopMotors();
}

// Function to move backward
void moveBackward(int speedA, int speedB, int duration) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speedA);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speedB);

  delay(duration);
  stopMotors();
  stopPump();
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void stopPump() {
  pumpSpeed = 0;                       // Set pump speed to 200 (approx. 80% intensity)
  analogWrite(WATER_PUMP, pumpSpeed);  // Ensure water pump is off at startup
  Serial.println("Water pump stop...");
}
void runPump() {
  pumpSpeed = 200;  // Set pump speed to 200 (approx. 80% intensity)
  analogWrite(WATER_PUMP, pumpSpeed);
  Serial.println("Water pump starting...");
}

void runBuzzer() {
  Serial.println("Start Buzzer sound");
  tone(buzzer, 1000);  // Send 1KHz sound signal...
}

void stopBuzzer() {
  Serial.println("No Buzzer sound");
  noTone(buzzer);  // Stop sound...
}

void loop() {
  // Check flame sensors
  int flame1 = digitalRead(FLAME1);
  int flame2 = digitalRead(FLAME2);
  int flame3 = digitalRead(FLAME3);

  int flame4 = analogRead(FLAME1);
  int flame5 = analogRead(FLAME2);
  int flame6 = analogRead(FLAME3);

  if (flame1 == LOW || flame2 == LOW || flame3 == LOW) {
    Serial.println("Flame detected! Moving forward 14 cm.");
    runBuzzer();
    moveForward(200, 200, forwardTime);  // Move forward 14 cm

    // Serial.println("Water pump starting...");
    runPump();  // Start water pump

    // Wait until fire is extinguished
    while (digitalRead(FLAME1) == LOW || digitalRead(FLAME2) == LOW || digitalRead(FLAME3) == LOW) {
      delay(100);  // Check flame sensors every 100 ms
    }

    // Serial.println("Fire extinguished. Stopping water pump.");
    digitalWrite(WATER_PUMP, LOW);  // Stop water pump

    delay(500);  // Small pause before moving backward

    Serial.println("Moving backward 40 cm.");
    moveBackward(200, 200, backwardTime);  // Move backward 40 cm

    stopMotors();  // Stop after completing the backward motion
  }
  stopBuzzer();
}
