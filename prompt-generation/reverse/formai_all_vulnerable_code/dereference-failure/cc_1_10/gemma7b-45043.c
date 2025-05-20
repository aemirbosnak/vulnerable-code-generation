//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  int waiting_time;
  int turnaround_time;
} Process;

void initialize_processes(Process **processes) {
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes[i] = malloc(sizeof(Process));
    processes[i]->process_id = i + 1;
    processes[i]->arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[i]->execution_time = rand() % MAX_QUEUE_SIZE;
    processes[i]->waiting_time = 0;
    processes[i]->turnaround_time = 0;
  }
}

void schedule_processes(Process **processes) {
  // Round robin scheduling algorithm
  int current_time = 0;
  int next_process_id = 0;

  while (current_time < MAX_PROCESSES) {
    processes[next_process_id]->waiting_time++;
    current_time++;

    if (processes[next_process_id]->waiting_time == processes[next_process_id]->execution_time) {
      processes[next_process_id]->turnaround_time = current_time;
      next_process_id = (next_process_id + 1) % MAX_PROCESSES;
    }
  }
}

int main() {
  Process **processes = (Process **)malloc(MAX_PROCESSES * sizeof(Process));
  initialize_processes(processes);
  schedule_processes(processes);

  for (int i = 0; i < MAX_PROCESSES; i++) {
    printf("Process ID: %d, Arrival Time: %d, Execution Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i]->process_id, processes[i]->arrival_time, processes[i]->execution_time, processes[i]->waiting_time, processes[i]->turnaround_time);
  }

  return 0;
}