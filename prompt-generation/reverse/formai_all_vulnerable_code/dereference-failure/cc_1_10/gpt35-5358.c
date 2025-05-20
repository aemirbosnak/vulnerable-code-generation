//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct process {
  int id;
  int burst_time;
  int arrival_time;
  int waiting_time;
  int turnaround_time;
};

int compare_arrival_time(const void *a, const void *b) {
  struct process *process_A = (struct process *)a;
  struct process *process_B = (struct process *)b;
  return process_A->arrival_time - process_B->arrival_time;
}

int compare_burst_time(const void *a, const void *b) {
  struct process *process_A = (struct process *)a;
  struct process *process_B = (struct process *)b;
  return process_A->burst_time - process_B->burst_time;
}

void fcfs(struct process *processes, int n) {
  int total_waiting_time = 0;
  int total_turnaround_time = 0;

  for (int i = 0; i < n; ++i) {
    int waiting_time = i == 0 ? 0 : total_turnaround_time - processes[i].arrival_time;
    total_waiting_time += waiting_time;
    total_turnaround_time += waiting_time + processes[i].burst_time;
    processes[i].waiting_time = waiting_time;
    processes[i].turnaround_time = waiting_time + processes[i].burst_time;
  }

  printf("FCFS\n");
  printf("ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; ++i) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
  }

  printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
  printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void sjf(struct process *processes, int n) {
  int total_waiting_time = 0;
  int total_turnaround_time = 0;
  int current_time = 0;

  qsort(processes, n, sizeof(struct process), compare_arrival_time);

  int *finished = (int *)calloc(n, sizeof(int));

  while (1) {
    int done = 1;
    int selected_process = -1;
    int min_burst_time = 2147483647; // max int

    for (int i = 0; i < n; ++i) {
      if (finished[i] == 0 && processes[i].arrival_time <= current_time && processes[i].burst_time < min_burst_time) {
        done = 0;
        selected_process = i;
        min_burst_time = processes[i].burst_time;
      }
    }
    
    if (done) break;
    
    int waiting_time = current_time - processes[selected_process].arrival_time;
    total_waiting_time += waiting_time;
    total_turnaround_time += waiting_time + processes[selected_process].burst_time;
    processes[selected_process].waiting_time = waiting_time;
    processes[selected_process].turnaround_time = waiting_time + processes[selected_process].burst_time;

    current_time += processes[selected_process].burst_time;
    finished[selected_process] = 1;
  }

  printf("SJF\n");
  printf("ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; ++i) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, processes[i].waiting_time, processes[i].turnaround_time);
  }

  printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
  printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

  free(finished);
}

int main() {
  struct process processes[] = {
    {1, 6, 0},
    {2, 8, 1},
    {3, 7, 2},
    {4, 3, 3},
    {5, 4, 4}
  };
  int n = sizeof(processes) / sizeof(struct process);

  fcfs(processes, n);
  sjf(processes, n);

  return 0;
}