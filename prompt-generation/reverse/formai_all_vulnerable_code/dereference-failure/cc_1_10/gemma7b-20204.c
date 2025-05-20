//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = id;
  process->arrival_time = arrivalTime;
  process->burst_time = burstTime;
  process->remaining_time = burstTime;
  process->next = NULL;
  return process;
}

void roundRobin(Process* processes) {
  int current_time = 0;
  Process* current_process = processes;

  while (processes) {
    if (current_process->arrival_time <= current_time) {
      current_process->remaining_time--;
      if (current_process->remaining_time == 0) {
        printf("Process %d completed.\n", current_process->process_id);
        free(current_process);
        current_process = processes;
      } else {
        current_time++;
      }
    } else {
      current_time++;
    }
  }
}

int main() {
  Process* processes = NULL;

  // Create some processes
  processes = createProcess(1, 0, 5);
  processes = createProcess(2, 2, 4);
  processes = createProcess(3, 4, 3);
  processes = createProcess(4, 6, 2);
  processes = createProcess(5, 8, 1);

  // Round Robin scheduling
  roundRobin(processes);

  return 0;
}