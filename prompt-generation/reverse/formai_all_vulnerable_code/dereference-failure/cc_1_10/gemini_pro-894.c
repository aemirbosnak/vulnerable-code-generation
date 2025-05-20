//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a job
typedef struct Job {
  int id;       // Job ID
  int arrival;  // Arrival time
  int burst;    // Burst time
} Job;

// A structure to represent a schedule
typedef struct Schedule {
  int num_jobs;  // Number of jobs
  Job *jobs;     // Array of jobs
} Schedule;

// A utility function to compare jobs by arrival time
int compare_jobs_by_arrival(const void *a, const void *b) {
  const Job *job1 = (const Job *)a;
  const Job *job2 = (const Job *)b;
  return job1->arrival - job2->arrival;
}

// A utility function to print a schedule
void print_schedule(const Schedule *schedule) {
  printf("Schedule:\n");
  for (int i = 0; i < schedule->num_jobs; i++) {
    printf("Job %d: arrival = %d, burst = %d\n",
           schedule->jobs[i].id, schedule->jobs[i].arrival, schedule->jobs[i].burst);
  }
}

// A greedy algorithm to find the minimum average waiting time
Schedule *min_avg_waiting_time(const Schedule *unsorted_schedule) {
  // Sort the jobs by arrival time
  qsort(unsorted_schedule->jobs, unsorted_schedule->num_jobs, sizeof(Job), compare_jobs_by_arrival);

  // Initialize the variables used to calculate the average waiting time
  int total_waiting_time = 0;
  int current_time = 0;

  // Create a copy of the unsorted schedule
  Schedule *sorted_schedule = (Schedule *)malloc(sizeof(Schedule));
  sorted_schedule->num_jobs = unsorted_schedule->num_jobs;
  sorted_schedule->jobs = (Job *)malloc(sizeof(Job) * sorted_schedule->num_jobs);

  // Iterate over the jobs in the sorted schedule
  for (int i = 0; i < sorted_schedule->num_jobs; i++) {
    // If the current time is less than the arrival time of the current job,
    // then wait until the arrival time of the current job
    if (current_time < sorted_schedule->jobs[i].arrival) {
      current_time = sorted_schedule->jobs[i].arrival;
    }

    // Update the total waiting time
    total_waiting_time += current_time - sorted_schedule->jobs[i].arrival;

    // Schedule the current job
    sorted_schedule->jobs[i].id = unsorted_schedule->jobs[i].id;
    sorted_schedule->jobs[i].arrival = current_time;
    sorted_schedule->jobs[i].burst = unsorted_schedule->jobs[i].burst;

    // Update the current time
    current_time += sorted_schedule->jobs[i].burst;
  }

  // Calculate the average waiting time
  float avg_waiting_time = (float)total_waiting_time / sorted_schedule->num_jobs;

  // Print the sorted schedule
  print_schedule(sorted_schedule);

  // Return the sorted schedule
  return sorted_schedule;
}

int main() {
  // Initialize the unsorted schedule
  Schedule unsorted_schedule = {
      5,
      (Job []){
          {1, 0, 3},
          {2, 1, 6},
          {3, 2, 5},
          {4, 4, 4},
          {5, 6, 2},
      },
  };

  // Find the minimum average waiting time
  Schedule *sorted_schedule = min_avg_waiting_time(&unsorted_schedule);

  // Print the average waiting time
  printf("Average waiting time: %f\n", (float)sorted_schedule->num_jobs / sorted_schedule->jobs[sorted_schedule->num_jobs - 1].arrival);

  // Free the memory allocated for the sorted schedule
  free(sorted_schedule->jobs);
  free(sorted_schedule);

  return 0;
}