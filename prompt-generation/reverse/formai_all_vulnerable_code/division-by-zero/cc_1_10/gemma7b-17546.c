//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

struct Process {
  int id;
  int burst_time;
  int waiting_time;
  int turnaround_time;
  int status;
};

void schedule() {
  int i, j, quantum = 0, completed = 0;
  struct Process processes[MAX_PROCESSES];

  // Initialize processes
  for (i = 0; i < MAX_PROCESSES; i++) {
    processes[i].id = i + 1;
    processes[i].burst_time = rand() % 10;
    processes[i].waiting_time = 0;
    processes[i].turnaround_time = 0;
    processes[i].status = 0;
  }

  // Simulate CPU scheduling
  while (!completed) {
    for (i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i].status == 0 && quantum % processes[i].burst_time == 0) {
        processes[i].status = 1;
        processes[i].waiting_time++;
        quantum = processes[i].burst_time;
      }
    }

    // Check if all processes are completed
    completed = 1;
    for (i = 0; i < MAX_PROCESSES; i++) {
      if (processes[i].status == 0) {
        completed = 0;
      }
    }

    // Increment quantum
    quantum++;
  }

  // Calculate turnaround time and print results
  for (i = 0; i < MAX_PROCESSES; i++) {
    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    printf("Process %d: Burst Time %d, Waiting Time %d, Turnaround Time %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
  }
}

int main() {
  schedule();
  return 0;
}