#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i]->completed)
                cout << "[Completed] ";
            cout << tasks[i]->description << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks[index]->completed = true;
        cout << "Task " << index + 1 << " marked as completed." << endl;
    }

    ~ToDoList() {
        for (auto& task : tasks)
            delete task;
    }
};

int main() {
    ToDoList myList;
    myList.addTask("Finish Lab 3");
    myList.addTask("Read a book");
    myList.addTask("Go to the gym");

    cout << "Initial tasks:" << endl;
    myList.listTasks();

    myList.markTaskCompleted(0);
    myList.markTaskCompleted(2);

    cout << "After marking tasks completed:" << endl;
    myList.listTasks();

    return 0;
}
