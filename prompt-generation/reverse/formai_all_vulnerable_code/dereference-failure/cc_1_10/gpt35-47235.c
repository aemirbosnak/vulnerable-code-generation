//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// function to sort the jobs by their profits in descending order
int cmpfunc(const void* a, const void* b) {
    return ((*(int*)b) - (*(int*)a));
}

// function to find the maximum subset of jobs with maximum profit
void findMaxSubset(int n, int *profits, int *deadlines) {
    int maxDeadline = 0;
    int i;

    // find the maximum deadline
    for (i = 0; i < n; i++) {
        if (deadlines[i] > maxDeadline) {
            maxDeadline = deadlines[i];
        }
    }

    // array to store the time slots occupied by the jobs
    int *timeslots = (int*)calloc(maxDeadline, sizeof(int));
    int *jobIds = (int*)malloc(maxDeadline * sizeof(int));

    // sort the jobs by their profit in descending order
    qsort(profits, n, sizeof(int), cmpfunc);

    int jobCount = 0, profit = 0;

    // for each job, find the latest possible time slot to occupy
    for (i = 0; i < n; i++) {
        int j;
        for (j = (deadlines[i] - 1); j >= 0; j--) {
            if (timeslots[j] == 0) {
                timeslots[j] = 1;
                jobIds[j] = i;
                jobCount++;
                profit += profits[i];
                break;
            }
        }
    }

    // print the jobs with their start and end times
    printf("\nJobs with their start and end times:\n");
    for (i = 0; i < maxDeadline; i++) {
        if (timeslots[i]) {
            printf("Job %d: Start Time=%d End Time=%d\n", jobIds[i] + 1, i+1, i+2);
        }
    }

    // print the maximum profit
    printf("\nMaximum Profit: %d\n", profit);
}

int main() {
    int n = 5;
    int profits[] = { 35, 30, 25, 20, 15 };
    int deadlines[] = { 3, 4, 4, 2, 3 };

    findMaxSubset(n, profits, deadlines);

    return 0;
}