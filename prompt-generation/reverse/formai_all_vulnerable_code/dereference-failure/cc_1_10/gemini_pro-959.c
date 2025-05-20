//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Structure to represent a job
typedef struct Job {
    int id;             // Job ID
    int profit;         // Profit associated with the job
    int deadline;       // Deadline for the job
} Job;

// Comparison function for sorting jobs by profit in descending order
int compare(const void* a, const void* b) {
    const Job* p = (const Job*)a;
    const Job* q = (const Job*)b;
    return q->profit - p->profit;
}

// Function to find the maximum profit achievable by scheduling jobs
int findMaxProfit(Job* jobs, int n, int maxDeadline) {
    // Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Create an array to store the scheduled jobs
    int* schedule = (int*)malloc(sizeof(int) * maxDeadline);
    memset(schedule, 0, sizeof(int) * maxDeadline);

    // Initialize the total profit to 0
    int totalProfit = 0;

    // Iterate over jobs in descending order of profit
    for (int i = 0; i < n; i++) {
        // Find the latest available time slot for the job
        int latestAvailableSlot = jobs[i].deadline - 1;
        while (latestAvailableSlot >= 0 && schedule[latestAvailableSlot] != 0) {
            latestAvailableSlot--;
        }

        // If a time slot for the job is found
        if (latestAvailableSlot >= 0) {
            // Schedule the job
            schedule[latestAvailableSlot] = jobs[i].id;
            totalProfit += jobs[i].profit;
        }
    }

    // Free the allocated memory
    free(schedule);

    // Return the maximum profit
    return totalProfit;
}

int main() {
    // Input: an array of jobs, where each job has an integer id, profit, and deadline
    Job jobs[] = {
        {0, 20, 2},
        {1, 10, 1},
        {2, 30, 3},
        {3, 15, 2},
        {4, 18, 1},
    };

    // Number of jobs
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Maximum deadline
    int maxDeadline = 3;

    // Find the maximum profit achievable by scheduling jobs
    int maxProfit = findMaxProfit(jobs, n, maxDeadline);

    // Print the maximum profit
    printf("The maximum profit achievable is: %d\n", maxProfit);

    return 0;
}