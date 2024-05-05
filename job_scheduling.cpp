#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);
    int maxDeadline = 0;
    for (Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    vector<bool> slot(maxDeadline + 1, false);
    vector<int> result(maxDeadline + 1, -1);
    for (const Job& job : jobs) {
        for (int j = job.deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = job.id;
                break;
            }
        }
    }
    cout << "Job sequence is: ";
    for (int i = 1; i <= maxDeadline;