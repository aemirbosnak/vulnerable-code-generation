//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a job
typedef struct Job {
    char *name;
    int duration;
    int deadline;
    int profit;
} Job;

// Comparison function for sorting jobs by deadline
int compare_jobs_by_deadline(const void *a, const void *b) {
    const Job *job1 = (const Job *)a;
    const Job *job2 = (const Job *)b;

    return job1->deadline - job2->deadline;
}

// Comparison function for sorting jobs by profit
int compare_jobs_by_profit(const void *a, const void *b) {
    const Job *job1 = (const Job *)a;
    const Job *job2 = (const Job *)b;

    return job2->profit - job1->profit;
}

// Function to print a job
void print_job(const Job *job) {
    printf("Job: %s, Duration: %d, Deadline: %d, Profit: %d\n", job->name, job->duration, job->deadline, job->profit);
}

// Function to find the maximum profit by scheduling jobs
int max_profit_scheduling(Job *jobs, int num_jobs) {
    // Sort jobs by deadline
    qsort(jobs, num_jobs, sizeof(Job), compare_jobs_by_deadline);

    // Initialize the profit to 0
    int profit = 0;

    // Initialize the time to 0
    int time = 0;

    // Iterate over jobs
    for (int i = 0; i < num_jobs; i++) {
        // If the current time plus the duration of the job is less than or equal to the deadline of the job
        if (time + jobs[i].duration <= jobs[i].deadline) {
            // Add the profit of the job to the total profit
            profit += jobs[i].profit;

            // Update the time to the current time plus the duration of the job
            time += jobs[i].duration;
        }
    }

    // Return the maximum profit
    return profit;
}

// Function to generate random jobs
Job *generate_random_jobs(int num_jobs) {
    // Allocate memory for the jobs
    Job *jobs = malloc(sizeof(Job) * num_jobs);

    // Generate random values for the jobs
    for (int i = 0; i < num_jobs; i++) {
        jobs[i].name = malloc(sizeof(char) * 10);
        sprintf(jobs[i].name, "Job %d", i + 1);
        jobs[i].duration = rand() % 10 + 1;
        jobs[i].deadline = rand() % 100 + 1;
        jobs[i].profit = rand() % 100 + 1;
    }

    // Return the jobs
    return jobs;
}

// Function to print the jobs
void print_jobs(Job *jobs, int num_jobs) {
    for (int i = 0; i < num_jobs; i++) {
        print_job(&jobs[i]);
    }
}

// Main function
int main() {
    // Generate random jobs
    int num_jobs = 10;
    Job *jobs = generate_random_jobs(num_jobs);

    // Print the jobs
    printf("Jobs:\n");
    print_jobs(jobs, num_jobs);

    // Sort jobs by profit
    qsort(jobs, num_jobs, sizeof(Job), compare_jobs_by_profit);

    // Find the maximum profit by scheduling jobs
    int profit = max_profit_scheduling(jobs, num_jobs);

    // Print the maximum profit
    printf("Maximum profit: %d\n", profit);

    // Free the memory allocated for the jobs
    for (int i = 0; i < num_jobs; i++) {
        free(jobs[i].name);
    }
    free(jobs);

    return 0;
}