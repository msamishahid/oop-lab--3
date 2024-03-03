#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    string name;
    vector<int> grades;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin >> newStudent.name;

    char choice;
    do {
        int grade;
        cout << "Enter grade for " << newStudent.name << ": ";
        cin >> grade;
        newStudent.grades.push_back(grade);
        cout << "Do you want to add another grade? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    students.push_back(newStudent);
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grades: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<Student> students;

    char option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Display all students\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case '1':
            addStudent(students);
            break;
        case '2':
            displayStudents(students);
            break;
        case '3':
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (option != '3');

    return 0;
}
