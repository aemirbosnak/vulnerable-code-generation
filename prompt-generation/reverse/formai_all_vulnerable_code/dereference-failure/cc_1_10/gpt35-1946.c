//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a job
typedef struct Job {
    int id;
    int deadline;
    int profit;
} Job;

// Compare function for qsort
int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Greedy algorithm to maximize profit
int maximizeProfit(Job jobs[], int n) {
    int i, j, max_profit = 0;
    int* timeslot = (int*)calloc(n, sizeof(int));

    // Sort the jobs by profit
    qsort(jobs, n, sizeof(Job), compare);

    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (j < n && !timeslot[j]) {
                timeslot[j] = 1;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }

    free(timeslot);
    return max_profit;
}

int main() {
    int n, i, max_profit;
    Job* jobs;

    // Get the number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Allocate memory for the jobs
    jobs = (Job*)calloc(n, sizeof(Job));

    // Get the details for each job
    for (i = 0; i < n; i++) {
        printf("\nEnter details for job %d:", i + 1);
        printf("\nEnter deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Enter profit: ");
        scanf("%d", &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    // Calculate the maximum profit using Greedy algorithm
    max_profit = maximizeProfit(jobs, n);

    // Print the maximum profit and the sequence of jobs
    printf("\nMaximum profit is %d\n", max_profit);
    printf("\nSequence of jobs: ");
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline <= i + 1) {
            printf("%d ", jobs[i].id);
        }
    }

    free(jobs);
    return 0;
}