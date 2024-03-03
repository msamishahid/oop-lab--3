#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}
};

class StudentManager {
private:
    vector<Student*> records;
public:
    void addStudent(int id, string name, float grade) {
        // Check if student ID already exists
        for (Student* student : records) {
            if (student->id == id) {
                cout << "Student with ID " << id << " already exists." << endl;
                return;
            }
        }
        // Add new student
        Student* newStudent = new Student(id, name, grade);
        records.push_back(newStudent);
    }

    void updateGrade(int id, float newGrade) {
        for (Student* student : records) {
            if (student->id == id) {
                student->grade = newGrade;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }

    void displayRecords() {
        if (records.empty()) {
            cout << "No records found." << endl;
            return;
        }
        for (Student* student : records) {
            cout << "ID: " << student->id << ", Name: " << student->name << ", Grade: " << student->grade << endl;
        }
    }

    ~StudentManager() {
        // Free allocated memory
        for (Student* student : records) {
            delete student;
        }
        records.clear();
    }
};

int main() {
    StudentManager sm;
    sm.addStudent(1, "John Doe", 92.5);
    sm.addStudent(2, "Jane Doe", 88.0);
    sm.displayRecords();
    sm.updateGrade(1, 97.0);
    cout << "After grade update:" << endl;a
    sm.displayRecords();

    return 0;
}
