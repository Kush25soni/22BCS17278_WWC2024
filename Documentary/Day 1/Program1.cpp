#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, uid, home, dob, bio;                          //Declaration of all variable
    int section;
    float cgpa;

    // Taking input of all type of data.
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your UID: ";
    cin >> uid;

    cout << "Enter your section: ";
    cin >> section;

    cout << "Enter your hometown: ";
    cin >> home;

    cout << "Enter your date of birth (e.g., 19/12/2000): ";
    cin >> dob;

    cout << "Enter your CGPA: ";
    cin >> cgpa;

    cin.ignore();                                         // To handle leftover newline from previous inputs
    cout << "Enter your academic bio: ";
    getline(cin, bio);                                    // For multi-word input


    //Write all the Detail.
    cout << "\n My All Detail:" << endl;
    cout << "Name: " << name << endl;
    cout << "UID: " << uid << endl;
    cout << "Section: " << section << endl;
    cout << "Hometown: " << hometown << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Academic Bio: " << bio << endl;

    return 0;
}
