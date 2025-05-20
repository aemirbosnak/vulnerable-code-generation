//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int id;
  int burstTime;
  int waitingTime;
  int turnaroundTime;
  struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
  Process* process = malloc(sizeof(Process));
  process->id = id;
  process->burstTime = burstTime;
  process->waitingTime = 0;
  process->turnaroundTime = 0;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, int id, int burstTime) {
  Process* process = createProcess(id, burstTime);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void roundRobin(Process* head) {
  time_t currentTime = time(NULL);
  Process* currentProcess = head;
  while (currentProcess) {
    // Calculate the time quantum
    int timeQuantum = 5;
    if (currentProcess->burstTime < timeQuantum) {
      timeQuantum = currentProcess->burstTime;
    }

    // Update the waiting time of the process
    currentProcess->waitingTime++;

    // Simulate the execution of the process
    printf("Process %d is running...\n", currentProcess->id);
    sleep(timeQuantum);

    // Update the turnaround time of the process
    currentProcess->turnaroundTime = currentTime - currentProcess->waitingTime;

    // Move to the next process
    currentProcess = currentProcess->next;
  }
}

int main() {
  Process* head = NULL;
  addProcess(head, 1, 8);
  addProcess(head, 2, 4);
  addProcess(head, 3, 12);
  addProcess(head, 4, 6);
  addProcess(head, 5, 10);

  roundRobin(head);

  return 0;
}