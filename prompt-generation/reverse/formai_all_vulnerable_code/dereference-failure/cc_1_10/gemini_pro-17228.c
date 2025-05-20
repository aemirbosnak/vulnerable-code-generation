//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a job
typedef struct Job {
    int id;           // Job ID
    int deadline;     // Deadline of the job
    int profit;       // Profit associated with the job
} Job;

// Function to compare two jobs based on their profit
int compareProfit(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;

    return job2->profit - job1->profit;
}

// Function to schedule jobs using Greedy Algorithm
void scheduleJobs(Job jobs[], int n) {
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(Job), compareProfit);

    // Initialize a time slot array to store job IDs
    int timeSlots[n];
    for (int i = 0; i < n; i++) {
        timeSlots[i] = -1;
    }

    // Iterate over all jobs in sorted order
    int profit = 0;
    for (int i = 0; i < n; i++) {
        // Find the first available time slot
        int slot = jobs[i].deadline - 1;
        while (slot >= 0 && timeSlots[slot] != -1) {
            slot--;
        }

        // If an available time slot is found
        if (slot >= 0) {
            timeSlots[slot] = jobs[i].id;
            profit += jobs[i].profit;
        }
    }

    // Print the scheduled jobs
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < n; i++) {
        if (timeSlots[i] != -1) {
            printf("Job ID: %d, Deadline: %d, Profit: %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
        }
    }

    // Print the total profit
    printf("Total Profit: %d\n", profit);
}

// Generate random jobs
Job *generateJobs(int n) {
    Job *jobs = (Job *)malloc(sizeof(Job) * n);

    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].deadline = rand() % n + 1;
        jobs[i].profit = rand() % 100 + 1;
    }

    return jobs;
}

// Main function
int main() {
    // Generate 10 random jobs
    int n = 10;
    Job *jobs = generateJobs(n);

    // Schedule jobs using Greedy Algorithm
    scheduleJobs(jobs, n);

    // Free the allocated memory
    free(jobs);

    return 0;
}