//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Structure for a job
typedef struct Job {
    int id;         // Job ID
    int deadline;   // Deadline of the job
    int profit;     // Profit of the job
} Job;

// Comparison function for sorting jobs by profit
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit; // Sort in descending order of profit
}

// Function to find the maximum profit jobs within their deadlines
void jobScheduling(Job jobs[], int n) {
    // Sort jobs according to profit
    qsort(jobs, n, sizeof(Job), compare);

    // To keep track of free time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Array to keep track of free time slots
    int *slot = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1; // Initialize all slots as free

    int totalProfit = 0;
    int jobCount = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        for (int j = (jobs[i].deadline - 1); j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id; // Assign job id to slot
                totalProfit += jobs[i].profit; // Add profit
                jobCount++; // Increase job count
                break;
            }
        }
    }

    // Output the scheduled jobs
    printf("Total jobs scheduled: %d\n", jobCount);
    printf("Total profit earned: %d\n", totalProfit);
    printf("Jobs scheduled in slots:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("Slot %d -> Job %d\n", i + 1, slot[i]);
        }
    }

    // Free the allocated memory
    free(slot);
}

int main() {
    int n = 5; // Number of jobs
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30},
        {5, 4, 50}
    };

    jobScheduling(jobs, n);

    return 0;
}