CODE:-
  #include <iostream>
#include <vector>
#include <algorithm>

struct Patient {
    int id;
    int triagePriority; // Lower number indicates higher priority
    std::string conditionSeverity;
    std::string arrivalTime;

    // Constructor
    Patient(int id, int priority, std::string severity, std::string time)
        : id(id), triagePriority(priority), conditionSeverity(severity), arrivalTime(time) {}
};

bool comparePatients(const Patient &a, const Patient &b) {
    if (a.triagePriority != b.triagePriority) {
        return a.triagePriority < b.triagePriority; // Higher priority first
    }
    return a.arrivalTime < b.arrivalTime; // Then by arrival time
}

int main() {
    std::vector<Patient> patients = {
        Patient(1, 2, "Critical", "10:00"),
        Patient(2, 1, "Severe", "09:50"),
        Patient(3, 3, "Moderate", "10:05")
    };

    std::sort(patients.begin(), patients.end(), comparePatients);

    for (const auto &p : patients) {
        std::cout << "Patient ID: " << p.id << ", Triage Priority: " << p.triagePriority << std::endl;
    }

    return 0;
}
/*
OUTPUT:-
  
Patient ID: 2, Triage Priority: 1
Patient ID: 1, Triage Priority: 2
Patient ID: 3, Triage Priority: 3
*/
