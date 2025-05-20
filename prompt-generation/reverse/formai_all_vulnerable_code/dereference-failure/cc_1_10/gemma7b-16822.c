//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process {
  int arrival_time;
  int burst_time;
  struct Process* next;
} Process;

Process* createProcess(int arrival_time, int burst_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->arrival_time = arrival_time;
  process->burst_time = burst_time;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, int arrival_time, int burst_time) {
  Process* process = createProcess(arrival_time, burst_time);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void roundRobin(Process* head) {
  int time_quantum = 5;
  Process* currentProcess = head;
  while (currentProcess) {
    printf("Process: %d, Time Remaining: %d\n", currentProcess->arrival_time, currentProcess->burst_time);
    currentProcess->burst_time -= time_quantum;
    if (currentProcess->burst_time <= 0) {
      printf("Process: %d completed\n", currentProcess->arrival_time);
      currentProcess = currentProcess->next;
    }
  }
}

int main() {
  Process* head = NULL;
  addProcess(head, 0, 10);
  addProcess(head, 2, 5);
  addProcess(head, 4, 15);
  addProcess(head, 6, 8);
  roundRobin(head);
  return 0;
}