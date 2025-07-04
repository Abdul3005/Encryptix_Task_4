#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed = false;
};

void addTask(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void viewTasks(vector<Task>& tasks);
int  getIndex(vector<Task>& tasks);

int getIndex(vector<Task>& tasks) {
    viewTasks(tasks);

    int i;
    cout << "Enter task number: ";
    cin >> i;
    cin.ignore();                   

    if (i >= 1 && i <= tasks.size())   
        return i - 1;                 
    return -1;
}

void addTask(vector<Task>& tasks) {
    cin.ignore();                  
    Task t;
    cout << "Enter task description: ";
    getline(cin, t.description);
    tasks.push_back(t);
    cout << "Task added successfully" << endl;
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "There is no task to remove yet" << endl;
        return;
    }
    int i = getIndex(tasks);
    if (i != -1) {
        tasks.erase(tasks.begin() + i);
        cout << "Task removed successfully" << endl;
    }
    else {
        cout << "Invalid task number!" << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark." << endl;
        return;
    }
    int i = getIndex(tasks);
    if (i != -1) {
        tasks[i].completed = true;
        cout << "Task marked as completed" << endl;
    }
    else {
        cout << "Invalid task number!" << endl;
    }
}

void viewTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available" << endl;
        return;
    }
    cout << endl << "----- Your Tasks -----" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << "[" << i + 1 << "] " << tasks[i].description
            << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

int main() {
    vector<Task> tasks;
    char choice;

    do {
        cout << endl;
        cout << "===== Task Manager =====" << endl;
        cout << "[1] Add a task" << endl;
        cout << "[2] Remove a task" << endl;
        cout << "[3] Mark a task as completed" << endl;
        cout << "[4] View all tasks" << endl;
        cout << "[5] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1': 
            addTask(tasks);
            break;
        case '2':
            removeTask(tasks);     
            break;
        case '3':
            markTaskCompleted(tasks); 
            break;
        case '4':
            viewTasks(tasks);   
            break;
        case '5': 
            cout << "Exited successfully" << endl; 
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != '5');

    return 0;
}
