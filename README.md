```mermaid
caseDiagram
    [*] --> ElectionManager: Initialize System
    ElectionManager --> Admin: Manage Admin Credentials
    Admin -->| authenticate(username: String, password: String) | ElectionManager
    ElectionManager --> Student: Register Students
    Student -->| hasVoted | ElectionManager
    ElectionManager --> Candidate: Register Candidates
    Candidate -->| getVotes() | ElectionManager
    ElectionManager -->| startElection(Scanner scanner) | Student
    ElectionManager -->| startElection(Scanner scanner) | Candidate
    ElectionManager -->| viewResults() | Admin
    ElectionManager -->| addCandidate(Scanner scanner) | Admin
    ElectionManager -->| studentPanel(Scanner scanner) | Student
    ElectionManager -->| adminPanel(Scanner scanner) | Admin
    [*] -->| loadElectionData() | ElectionManager
    ElectionManager -->| saveElectionData() | ElectionManager
