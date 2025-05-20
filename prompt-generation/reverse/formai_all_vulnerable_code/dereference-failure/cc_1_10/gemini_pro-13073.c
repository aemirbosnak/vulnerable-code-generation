//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a job
typedef struct job {
    int arrival_time;
    int processing_time;
    int deadline;
    int profit;
} job;

// Function to compare jobs by their arrival times
int compare_jobs_by_arrival_time(const void* a, const void* b) {
    const job* job1 = (const job*)a;
    const job* job2 = (const job*)b;
    return job1->arrival_time - job2->arrival_time;
}

// Function to compare jobs by their profit per unit of time
int compare_jobs_by_profit_per_unit_of_time(const void* a, const void* b) {
    const job* job1 = (const job*)a;
    const job* job2 = (const job*)b;
    return (float)job1->profit / job1->processing_time - (float)job2->profit / job2->processing_time;
}

// Function to print a job
void print_job(const job* job) {
    printf("Job: arrival_time=%d, processing_time=%d, deadline=%d, profit=%d\n",
           job->arrival_time, job->processing_time, job->deadline, job->profit);
}

// Function to print a list of jobs
void print_jobs(const job* jobs, int num_jobs) {
    for (int i = 0; i < num_jobs; i++) {
        print_job(&jobs[i]);
    }
}

// Function to read a list of jobs from a file
int read_jobs(job** jobs, int max_num_jobs, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }

    int num_jobs = 0;
    while (fscanf(file, "%d %d %d %d\n", &(*jobs)[num_jobs].arrival_time, &(*jobs)[num_jobs].processing_time, &(*jobs)[num_jobs].deadline, &(*jobs)[num_jobs].profit) == 4) {
        num_jobs++;
        if (num_jobs >= max_num_jobs) {
            printf("Error: number of jobs exceeds maximum of %d\n", max_num_jobs);
            return -1;
        }
    }
    
    fclose(file);
    return num_jobs;
}

// Function to schedule jobs using the greedy algorithm
int schedule_jobs(const job* jobs, int num_jobs) {
    int total_profit = 0;
    int current_time = 0;
    
    // Sort the jobs by their arrival times
    qsort(jobs, num_jobs, sizeof(job), compare_jobs_by_arrival_time);
    
    // Iterate over the jobs
    for (int i = 0; i < num_jobs; i++) {
        // If the current time is less than the arrival time of the job, wait until the arrival time
        if (current_time < jobs[i].arrival_time) {
            current_time = jobs[i].arrival_time;
        }
        
        // If the current time plus the processing time of the job is less than or equal to the deadline of the job, schedule the job
        if (current_time + jobs[i].processing_time <= jobs[i].deadline) {
            current_time += jobs[i].processing_time;
            total_profit += jobs[i].profit;
        }
    }
    
    return total_profit;
}

// Main function
int main() {
    // Create an array of jobs
    job* jobs = malloc(sizeof(job) * 100);
    
    // Read the jobs from a file
    int num_jobs = read_jobs(&jobs, 100, "jobs.txt");
    if (num_jobs == -1) {
        return EXIT_FAILURE;
    }
    
    // Print the jobs
    printf("Jobs:\n");
    print_jobs(jobs, num_jobs);
    
    // Sort the jobs by their profit per unit of time
    qsort(jobs, num_jobs, sizeof(job), compare_jobs_by_profit_per_unit_of_time);
    
    // Schedule the jobs
    int total_profit = schedule_jobs(jobs, num_jobs);
    
    // Print the total profit
    printf("Total profit: %d\n", total_profit);
    
    // Free the array of jobs
    free(jobs);
    
    return EXIT_SUCCESS;
}