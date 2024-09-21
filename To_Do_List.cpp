#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Task
{
    string description;
    bool completed;
};

void viewTasks(const vector<Task> &tasks)
{
    cout << "\nTo-Do List:" << endl;
    if (tasks.empty())
    {
        cout << "No tasks yet!" << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}
void addTask(vector<Task> &tasks)
{
    string taskDescription;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, taskDescription);
    tasks.push_back({taskDescription, false});
    cout << "Task added!" << endl;
}

void markTaskCompleted(vector<Task> &tasks)
{
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask(vector<Task> &tasks)
{
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size())
    {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!" << endl;
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}
int main()
{
    vector<Task> tasks;
    int choice;

    cout << "Welcome to the To-Do List!" << endl;

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewTasks(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            markTaskCompleted(tasks);
            break;
        case 4:
            removeTask(tasks);
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 5);
    return 0;
}
