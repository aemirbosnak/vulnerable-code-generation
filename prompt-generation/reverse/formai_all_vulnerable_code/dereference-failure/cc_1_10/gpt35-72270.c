//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include<stdio.h>

struct process {
  int process_id;
  int burst_time;
  int arrival_time;
  int waiting_time;
  int turnaround_time;
};

int main() {
  int n, i, total_waiting_time = 0, total_turnaround_time = 0;
  float avg_waiting_time, avg_turnaround_time;

  // Get input from user for number of processes
  printf("Enter number of processes: ");
  scanf("%d", &n);

  // Allocate memory for the processes
  struct process *p = malloc(n * sizeof(struct process));

  // Get input from user for process burst time and arrival time
  for(i=0; i<n; i++) {
    printf("Enter arrival time for process %d: ", i+1);
    scanf("%d", &p[i].arrival_time);

    printf("Enter burst time for process %d: ", i+1);
    scanf("%d", &p[i].burst_time);

    p[i].process_id = i + 1;
  }

  // Implement FCFS scheduling algorithm
  int current_time = 0;
  for(i=0; i<n; i++) {
    if(current_time < p[i].arrival_time)
      current_time = p[i].arrival_time;

    p[i].waiting_time = current_time - p[i].arrival_time;
    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;

    total_waiting_time += p[i].waiting_time;
    total_turnaround_time += p[i].turnaround_time;

    current_time += p[i].burst_time;
  }

  // Calculate average waiting time and average turnaround time
  avg_waiting_time = (float)total_waiting_time / n;
  avg_turnaround_time = (float)total_turnaround_time / n;

  // Print process details
  printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0; i<n; i++)
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);

  // Print average waiting time and average turnaround time
  printf("Average Waiting Time: %.2f\n", avg_waiting_time);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

  // Deallocate memory
  free(p);

  return 0;
}