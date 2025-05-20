//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A structure to represent a job
typedef struct Job {
    int id;             // Job ID
    int deadline;       // Deadline of the job
    int profit;         // Profit associated with the job
} Job;

// Function to compare jobs based on their profit
int compare_jobs(const void *a, const void *b) {
    const Job *job1 = (const Job *)a;
    const Job *job2 = (const Job *)b;
    return job2->profit - job1->profit;
}

// Function to schedule jobs using greedy algorithm
void schedule_jobs(Job *jobs, int n, int m) {
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(Job), compare_jobs);

    // A boolean array to mark jobs as scheduled
    int scheduled[n];
    for (int i = 0; i < n; i++) {
        scheduled[i] = 0;
    }

    // A priority queue to store jobs that can be scheduled at a given time
    typedef struct JobQueue {
        int *arr;       // Array to store jobs
        int size;       // Current size of the queue
        int capacity;   // Maximum capacity of the queue
    } JobQueue;

    JobQueue job_queue;
    job_queue.size = 0;
    job_queue.capacity = n;
    job_queue.arr = (int *)malloc(sizeof(int) * job_queue.capacity);

    // Schedule jobs greedily
    int time = 0;
    int max_profit = 0;
    while (time < m && job_queue.size > 0) {
        // Pop the job with the highest profit from the queue
        int job_id = job_queue.arr[0];
        Job job = jobs[job_id];
        scheduled[job_id] = 1;
        job_queue.size--;

        // Add the profit of the job to the total profit
        max_profit += job.profit;

        // Update the time
        time++;

        // Add all jobs that can be scheduled at the current time to the queue
        for (int i = 0; i < n; i++) {
            if (scheduled[i] == 0 && jobs[i].deadline >= time) {
                job_queue.arr[job_queue.size++] = i;
            }
        }
    }

    // Print the scheduled jobs and the maximum profit
    printf("Scheduled jobs: ");
    for (int i = 0; i < n; i++) {
        if (scheduled[i]) {
            printf("%d ", jobs[i].id);
        }
    }
    printf("\nMaximum profit: %d\n", max_profit);
}

// A sample test case
int main() {
    Job jobs[] = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int m = 3;
    schedule_jobs(jobs, n, m);
    return 0;
}