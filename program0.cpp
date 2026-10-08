#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getChoice(const string& question, const vector<string>& options) {
    int choice;
    while (true) {
        cout << question << endl;
        for (size_t i = 0; i < options.size(); i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
        cout << "Enter your choice (1-" << options.size() << "): ";

        if (cin >> choice) {
            if (choice >= 1 && choice <= static_cast<int>(options.size())) {
                return choice;
            } else {
                cout << "\nError: Choice out of range. Please try again.\n" << endl;
            }
        } else {
            cout << "\nError: Invalid input type. Please enter a number.\n" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

int main() {
    int totalPoints = 0;

    cout << "=== Housing Selection Points Calculator ===" << endl << endl;

   
    int classYear = getChoice(
        "What is your class year?",
        {"Freshman", "Sophomore", "Junior", "Senior"}
    );
    if (classYear == 1) totalPoints += 10;
    else if (classYear == 2) totalPoints += 7;
    else if (classYear == 3) totalPoints += 4;
    else if (classYear == 4) totalPoints += 2;
    cout << "Added " << (classYear == 1 ? 10 : classYear == 2 ? 7 : classYear == 3 ? 4 : 2) << " points" << endl << endl;

    
    int age;
    cout << "What is your age? ";
    cin >> age;
    int agePoints = max(0, (age - 18) / 2);
    totalPoints += agePoints;
    cout << "Added " << agePoints << " points (calculated: max(0, (age-18)/2))" << endl << endl;

    
    int offCampus = getChoice(
        "Are you in a full-time, off-campus program (e.g., student teaching)?",
        {"Yes", "No"}
    );
    if (offCampus == 1) totalPoints += 1;
    cout << "Added " << (offCampus == 1 ? 1 : 0) << " points" << endl << endl;

    
    if (classYear == 4) {
        int graduation = getChoice(
            "Are you graduating this year?",
            {"Yes", "No"}
        );
        if (graduation == 1) totalPoints += 3;
        cout << "Added " << (graduation == 1 ? 3 : 0) << " points (Senior conditional)" << endl << endl;
    }

    
    int discipline = getChoice(
        "Do you have academic or disciplinary flags?",
        {"Academic Probation", "Academic Suspension", "Disciplinary Probation", "None"}
    );
    if (discipline == 1) totalPoints -= 1;
    else if (discipline == 2) totalPoints -= 2;
    else if (discipline == 3) totalPoints -= 3;
    cout << "Adjusted " << (discipline == 1 ? -1 : discipline == 2 ? -2 : discipline == 3 ? -3 : 0) << " points" << endl << endl;

    cout << "============================" << endl;
    cout << "You have " << totalPoints << " housing points." << endl;
    cout << "============================" << endl;

    return 0;
}