/*Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top priority), 
b) non-serious (medium priority), c) General Checkup (Least priority). 
Implement the priority queue to cater services to the patients. */

#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Patient {
public:
    string name;
    int priority;

    Patient(string n, int p) {
        name = n;
        priority = p;
    }
};

struct ComparePriority {
    bool operator()(Patient const& p1, Patient const& p2) {
        return p1.priority > p2.priority;
    }
};

void addPatient(priority_queue<Patient, vector<Patient>, ComparePriority>& pq) {
    string name;
    int priority;

    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter patient priority (1-Serious, 2-Non-serious, 3-General Checkup): ";
    cin >> priority;

    pq.push(Patient(name, priority));
}

void servePatient(priority_queue<Patient, vector<Patient>, ComparePriority>& pq) {
    if(pq.empty()) {
        cout << "No patients to serve." << endl;
        return;
    }

    Patient p = pq.top();
    pq.pop();

    cout << "Serving patient: " << p.name << endl;
}

void displayQueue(priority_queue<Patient, vector<Patient>, ComparePriority> pq) {
    if(pq.empty()) {
        cout << "No patients in the queue." << endl;
        return;
    }

    cout << "Patients in the queue:" << endl;
    while(!pq.empty()) {
        Patient p = pq.top();
        pq.pop();

        cout << p.name << " (Priority: " << p.priority << ")" << endl;
    }
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> pq;
    int choice;

    do {
        cout << "\n1. Add Patient\n2. Serve Patient\n3. Display Queue\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addPatient(pq);
                break;
            case 2:
                servePatient(pq);
                break;
            case 3:
                displayQueue(pq);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
