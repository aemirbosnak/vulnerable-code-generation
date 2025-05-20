//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

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

void scheduleProcesses(Process* head) {
  int time = 0;
  int processes_completed = 0;
  Process* current_process = head;

  while (processes_completed < MAX_PROCESSES) {
    for (Process* process = current_process; process; process = process->next) {
      if (process->arrival_time <= time && process->remaining_time > 0) {
        process->remaining_time--;
        time++;
        if (process->remaining_time == 0) {
          processes_completed++;
          printf("Process %d completed.\n", process->process_id);
        }
      }
    }

    time++;
  }

  printf("All processes completed.\n");
}

int main() {
  Process* head = createProcess(1, 0, 5);
  head = createProcess(2, 2, 4);
  head = createProcess(3, 3, 3);
  head = createProcess(4, 4, 2);
  head = createProcess(5, 5, 1);

  scheduleProcesses(head);

  return 0;
}