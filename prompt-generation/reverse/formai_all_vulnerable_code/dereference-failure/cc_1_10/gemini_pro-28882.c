//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// A job has a start time, finish time, and profit.
struct Job {
    int start;
    int finish;
    int profit;
};

// A list of jobs.
struct JobList {
    struct Job *jobs;
    int size;
};

// Compare two jobs by their finish times.
int compareJobs(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    return job1->finish - job2->finish;
}

// Find the maximum profit that can be obtained by scheduling a subset of jobs.
int scheduleJobs(struct JobList *jobs) {
    // Sort the jobs by their finish times.
    qsort(jobs->jobs, jobs->size, sizeof(struct Job), compareJobs);

    // Create a table to store the maximum profit that can be obtained by scheduling the first i jobs.
    int dp[jobs->size];
    dp[0] = jobs->jobs[0].profit;

    // Iterate over the jobs.
    for (int i = 1; i < jobs->size; i++) {
        // Find the latest non-overlapping job that can be scheduled before job i.
        int latestNonOverlappingJob = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (jobs->jobs[j].finish <= jobs->jobs[i].start) {
                latestNonOverlappingJob = j;
                break;
            }
        }

        // Calculate the maximum profit that can be obtained by scheduling job i.
        if (latestNonOverlappingJob == -1) {
            dp[i] = jobs->jobs[i].profit;
        } else {
            dp[i] = dp[latestNonOverlappingJob] + jobs->jobs[i].profit;
        }
    }

    // Return the maximum profit.
    return dp[jobs->size - 1];
}

int main() {
    // Create a list of jobs.
    struct JobList jobs = {
        .jobs = malloc(sizeof(struct Job) * 5),
        .size = 5,
    };

    // Initialize the jobs.
    jobs.jobs[0] = (struct Job){.start = 1, .finish = 3, .profit = 5};
    jobs.jobs[1] = (struct Job){.start = 2, .finish = 5, .profit = 6};
    jobs.jobs[2] = (struct Job){.start = 4, .finish = 6, .profit = 5};
    jobs.jobs[3] = (struct Job){.start = 6, .finish = 9, .profit = 4};
    jobs.jobs[4] = (struct Job){.start = 8, .finish = 11, .profit = 3};

    // Find the maximum profit that can be obtained by scheduling a subset of jobs.
    int maxProfit = scheduleJobs(&jobs);

    // Print the maximum profit.
    printf("Maximum profit: %d\n", maxProfit);

    return 0;
}