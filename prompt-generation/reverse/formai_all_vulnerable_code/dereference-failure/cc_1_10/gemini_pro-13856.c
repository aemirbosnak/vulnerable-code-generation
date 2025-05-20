//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a job
typedef struct Job {
  int id;           // Job ID
  int deadline;     // Deadline of the job
  int profit;       // Profit associated with the job
} Job;

// Function to compare jobs based on their deadlines
int compareJobs(const void *a, const void *b) {
  Job *job1 = (Job *)a;
  Job *job2 = (Job *)b;
  return job1->deadline - job2->deadline;
}

// Function to find the maximum profit sequence of jobs
int scheduleJobs(Job jobs[], int n) {
  // Sort jobs based on their deadlines
  qsort(jobs, n, sizeof(Job), compareJobs);

  // Initialize the profit and time tracker
  int profit = 0, time = 0;

  // Iterate through the jobs
  for (int i = 0; i < n; i++) {
    // Check if the job can be scheduled without exceeding its deadline
    if (time + jobs[i].id <= jobs[i].deadline) {
      // Schedule the job and update the profit and time
      profit += jobs[i].profit;
      time += jobs[i].id;
    }
  }

  // Return the maximum profit
  return profit;
}

// Generate random jobs
Job *generateJobs(int n) {
  Job *jobs = malloc(n * sizeof(Job));

  // Initialize the random number generator
  srand(time(NULL));

  // Generate random jobs
  for (int i = 0; i < n; i++) {
    jobs[i].id = rand() % 100 + 1;          // ID between 1 and 100
    jobs[i].deadline = rand() % 50 + 1;       // Deadline between 1 and 50
    jobs[i].profit = rand() % 100 + 1;       // Profit between 1 and 100
  }

  return jobs;
}

// Print the jobs
void printJobs(Job jobs[], int n) {
  printf("Jobs:\n");
  for (int i = 0; i < n; i++) {
    printf("Job %d: Deadline %d, Profit %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }
}

// Main function
int main() {
  // Initialize the number of jobs
  int n = 5;

  // Generate random jobs
  Job *jobs = generateJobs(n);

  // Print the jobs
  printJobs(jobs, n);

  // Find the maximum profit sequence of jobs
  int profit = scheduleJobs(jobs, n);

  // Print the maximum profit
  printf("Maximum Profit: %d\n", profit);

  // Free the memory allocated for jobs
  free(jobs);

  return 0;
}