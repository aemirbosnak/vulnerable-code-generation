//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  int waiting_time;
  int turnaround_time;
} Process;

void roundRobin(Process **processes, int num_processes) {
  int current_time = 0;
  int i = 0;

  while (current_time < processes[0]->arrival_time) {
    current_time++;
  }

  while (i < num_processes) {
    processes[i]->waiting_time = current_time - processes[i]->arrival_time;
    current_time += processes[i]->burst_time;
    i++;
  }

  for (i = 0; i < num_processes; i++) {
    processes[i]->turnaround_time = processes[i]->waiting_time + processes[i]->burst_time;
  }
}

int main() {
  Process processes[MAX_PROCESS];
  int num_processes = 0;

  // Create processes
  processes[num_processes].process_id = 1;
  processes[num_processes].arrival_time = 0;
  processes[num_processes].burst_time = 5;
  num_processes++;

  processes[num_processes].process_id = 2;
  processes[num_processes].arrival_time = 2;
  processes[num_processes].burst_time = 3;
  num_processes++;

  processes[num_processes].process_id = 3;
  processes[num_processes].arrival_time = 3;
  processes[num_processes].burst_time = 4;
  num_processes++;

  roundRobin(processes, num_processes);

  // Print results
  for (int i = 0; i < num_processes; i++) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
  }

  return 0;
}