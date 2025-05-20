//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;         // Job ID
    int deadline;   // Job deadline
    int profit;     // Job profit
};

// A comparison function used for sorting jobs according to profit
int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to perform the Job Sequencing using Greedy Algorithm
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs according to descending order of profit
    qsort(jobs, n, sizeof(jobs[0]), compare);

    // Array for storing result (sequence of jobs)
    int result[n];
    // Array to keep track of free time slots
    int slot[n];

    // Initially, all slots are free
    for (int i = 0; i < n; i++) {
        slot[i] = -1;
    }

    // Iterate through all the sorted jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (note that we go backwards)
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline : n) - 1; j >= 0; j--) {
            // If the slot is free, assign the job to this slot
            if (slot[j] == -1) {
                slot[j] = i; // Store index of job
                break;
            }
        }
    }

    // Print the sequence of jobs
    printf("Job sequence for maximum profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i] != -1) {
            printf("Job ID: %d, Profit: %d\n", jobs[slot[i]].id, jobs[slot[i]].profit);
        }
    }
}

// Driver program
int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job *jobs = (struct Job *)malloc(n * sizeof(struct Job));

    // Input job details
    printf("Enter job details (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    // Perform job sequencing
    jobSequencing(jobs, n);

    // Free allocated memory
    free(jobs);

    return 0;
}