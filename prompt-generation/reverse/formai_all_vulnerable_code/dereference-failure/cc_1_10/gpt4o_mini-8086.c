//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;         // Job ID
    int deadline;   // Job deadline
    int profit;     // Job profit
};

// A comparison function to sort jobs according to profit
int compare(const void *a, const void *b) {
    struct Job *jobA = (struct Job *)a;
    struct Job *jobB = (struct Job *)b;
    return jobB->profit - jobA->profit; // Descending order
}

// Function to perform the job scheduling using the Greedy algorithm
void scheduleJobs(struct Job jobs[], int n) {
    // Sort jobs in descending order by profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Find the maximum deadline among the jobs to size the slots array
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create and initialize the result/job slots
    int *result = (int *)malloc(maxDeadline * sizeof(int));
    int *slotFilled = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = -1; // -1 indicates no job scheduled
        slotFilled[i] = 0; // Not filled
    }

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = (jobs[i].deadline < maxDeadline ? jobs[i].deadline : maxDeadline) - 1; j >= 0; j--) {
            if (slotFilled[j] == 0) {
                result[j] = jobs[i].id; // Schedule the job
                slotFilled[j] = 1; // Mark this slot as filled
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            printf("Time Slot %d -> Job ID %d\n", i + 1, result[i]);
        }
    }

    // Free allocated memory
    free(result);
    free(slotFilled);
}

// Main function to run the program
int main() {
    // Example jobs to be scheduled
    struct Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    scheduleJobs(jobs, n);

    return 0;
}