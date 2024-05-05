#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

// Function to compare jobs based on their profits
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit schedule using Greedy algorithm
vector<int> maxProfitSchedule(const vector<Job>& jobs) {
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> schedule(maxDeadline, -1);
    int totalProfit = 0;

    for (const Job& job : jobs) {
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (schedule[i] == -1) {
                schedule[i] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    return schedule;
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 50},
        {3, 2, 200},
        {4, 1, 70},
        {5, 3, 80}
    };

    // Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> schedule = maxProfitSchedule(jobs);

    // Print the schedule
    cout << "Maximum Profit Schedule:\n";
    for (int jobId : schedule) {
        if (jobId != -1) {
            cout << "Job " << jobId << endl;
        }
    }

    return 0;
}
