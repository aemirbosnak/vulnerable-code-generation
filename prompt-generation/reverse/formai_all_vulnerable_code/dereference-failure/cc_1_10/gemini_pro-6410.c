//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
typedef struct Job {
    int id;             // Job ID
    int profit;         // Profit associated with the job
    int deadline;       // Deadline of the job
} Job;

// Structure to store the jobs in the order in which they should be executed
typedef struct JobSequence {
    int num_jobs;       // Number of jobs in the sequence
    Job* jobs;           // Array of jobs in the sequence
} JobSequence;

// Function to compare two jobs based on their profit
int compare_jobs_by_profit(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;

    return job2->profit - job1->profit;
}

// Function to find the maximum profit from a set of jobs
JobSequence* find_maximum_profit(Job* jobs, int num_jobs) {
    // Sort the jobs in decreasing order of profit
    qsort(jobs, num_jobs, sizeof(Job), compare_jobs_by_profit);

    // Create a JobSequence object to store the jobs in the order in which they should be executed
    JobSequence* job_sequence = malloc(sizeof(JobSequence));
    job_sequence->num_jobs = 0;
    job_sequence->jobs = malloc(sizeof(Job) * num_jobs);

    // Initialize the time slot to 0
    int time_slot = 0;

    // Iterate over the jobs in decreasing order of profit
    for (int i = 0; i < num_jobs; i++) {
        // If the current job can be executed at the current time slot, add it to the job sequence
        if (jobs[i].deadline >= time_slot + 1) {
            job_sequence->jobs[job_sequence->num_jobs++] = jobs[i];
            time_slot++;
        }
    }

    // Return the job sequence
    return job_sequence;
}

// Function to print the job sequence
void print_job_sequence(JobSequence* job_sequence) {
    for (int i = 0; i < job_sequence->num_jobs; i++) {
        printf("Job %d: Profit = %d, Deadline = %d\n", job_sequence->jobs[i].id, job_sequence->jobs[i].profit, job_sequence->jobs[i].deadline);
    }
}

// Main function
int main() {
    // Create an array of jobs
    Job jobs[] = {
        {1, 20, 2},
        {2, 15, 2},
        {3, 10, 1},
        {4, 5, 3},
        {5, 1, 1},
    };

    // Find the maximum profit from the jobs
    JobSequence* job_sequence = find_maximum_profit(jobs, 5);

    // Print the job sequence
    print_job_sequence(job_sequence);

    // Free the allocated memory
    free(job_sequence->jobs);
    free(job_sequence);

    return 0;
}