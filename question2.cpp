// Lovenson Beaucicot
// 1123557
// Nov 28, 2024

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Task
{
public:
    string name;
    int priority;

    Task(string n, int p) : name(n), priority(p) {}
    bool operator<(const Task &other) const
    {
        return priority < other.priority;
    }
};

class TaskPriorityQueue
{
private:
    priority_queue<Task> pq;
    vector<Task> remainingTasks;

public:
    void addTask(string name, int priority)
    {
        pq.push(Task(name, priority));
    }

    string getHighestPriorityTask()
    {
        if (pq.empty())
            return "No tasks";

        Task topTask = pq.top();
        pq.pop();
        return topTask.name;
    }

    void displayRemainingTasks()
    {
        // Create a copy of the current priority queue to preserve it
        priority_queue<Task> tempPq = pq;

        vector<Task> remainingTasksList;
        while (!tempPq.empty())
        {
            remainingTasksList.push_back(tempPq.top());
            tempPq.pop();
        }

        cout << "Remaining tasks: [";
        for (size_t i = 0; i < remainingTasksList.size(); ++i)
        {
            cout << "('" << remainingTasksList[i].name << "', "
                 << remainingTasksList[i].priority << ")";
            if (i < remainingTasksList.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    int N;
    cin >> N;

    TaskPriorityQueue taskQueue;

    for (int i = 0; i < N; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD")
        {
            string taskName;
            int priority;
            cin >> taskName >> priority;
            taskQueue.addTask(taskName, priority);
        }
        else if (operation == "GET")
        {
            cout << taskQueue.getHighestPriorityTask() << endl;
        }
    }

    taskQueue.displayRemainingTasks();

    return 0;
}