// Lovenson Beaucicot
// 1123557
// Nov 28, 2024

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Task
{
public:
    int profit;
    int deadline;

    Task(int p, int d) : profit(p), deadline(d) {}
    bool operator<(const Task &other) const
    {
        return profit < other.profit;
    }
};

class TaskScheduler
{
public:
    pair<int, vector<int>> scheduleMaxProfit(vector<Task> &tasks)
    {
        int maxDeadline = 0;
        for (auto &task : tasks)
        {
            maxDeadline = max(maxDeadline, task.deadline);
        }

        priority_queue<Task> pq;
        for (auto &task : tasks)
        {
            pq.push(task);
        }

        vector<bool> slots(maxDeadline + 1, false);
        vector<int> scheduledTasks;
        int totalProfit = 0;

        while (!pq.empty())
        {
            Task currTask = pq.top();
            pq.pop();

            for (int j = currTask.deadline; j > 0; --j)
            {
                if (!slots[j])
                {
                    slots[j] = true;
                    scheduledTasks.push_back(currTask.profit);
                    totalProfit += currTask.profit;
                    break;
                }
            }
        }

        return {totalProfit, scheduledTasks};
    }
};

int main()
{
    int N;
    cin >> N;

    vector<Task> tasks;

    for (int i = 0; i < N; ++i)
    {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.emplace_back(profit, deadline);
    }

    TaskScheduler scheduler;
    auto [maxProfit, scheduledTasks] = scheduler.scheduleMaxProfit(tasks);

    cout << "Maximum Profit: " << maxProfit << endl;

    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < scheduledTasks.size(); ++i)
    {
        cout << scheduledTasks[i];
        if (i < scheduledTasks.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}