//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_Quantum 3

typedef struct Process {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* createProcess(int pid, int arrival_time, int burst_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->pid = pid;
  process->arrival_time = arrival_time;
  process->burst_time = burst_time;
  process->remaining_time = burst_time;
  process->next = NULL;
  return process;
}

void roundRobin(Process* processes) {
  int quantum = MAX_Quantum;
  time_t start_time = time(NULL);
  Process* currentProcess = processes;
  while (currentProcess) {
    time_t end_time = time(NULL);
    if (end_time - start_time >= quantum) {
      currentProcess->remaining_time--;
      start_time = time(NULL);
    }
    currentProcess = currentProcess->next;
  }
}

int main() {
  Process* processes = NULL;
  processes = createProcess(1, 0, 5);
  processes = createProcess(2, 2, 4);
  processes = createProcess(3, 4, 3);
  processes = createProcess(4, 6, 2);
  processes = createProcess(5, 8, 1);

  roundRobin(processes);

  for (Process* process = processes; process; process = process->next) {
    printf("Process %d completed with remaining time %d\n", process->pid, process->remaining_time);
  }

  return 0;
}