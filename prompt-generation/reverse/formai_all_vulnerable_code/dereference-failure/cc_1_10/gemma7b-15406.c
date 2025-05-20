//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct process {
  int id;
  int arrivalTime;
  int burstTime;
  struct process* next;
} process;

process* createProcess(int id, int arrivalTime, int burstTime) {
  process* newProcess = (process*)malloc(sizeof(process));
  newProcess->id = id;
  newProcess->arrivalTime = arrivalTime;
  newProcess->burstTime = burstTime;
  newProcess->next = NULL;
  return newProcess;
}

void addProcess(process* head, process* newProcess) {
  if (head == NULL) {
    head = newProcess;
  } else {
    head->next = newProcess;
    head = newProcess;
  }
}

void simulate(process* head) {
  time_t currentTime = time(NULL);
  while (head) {
    if (head->arrivalTime <= currentTime) {
      printf("Process %d arrived at time %ld\n", head->id, currentTime);
      currentTime += head->burstTime;
      printf("Process %d completed at time %ld\n", head->id, currentTime);
      free(head);
      head = NULL;
    } else {
      break;
    }
  }
}

int main() {
  process* head = NULL;
  addProcess(head, createProcess(1, 0, 5));
  addProcess(head, createProcess(2, 2, 4));
  addProcess(head, createProcess(3, 4, 6));
  addProcess(head, createProcess(4, 6, 3));
  addProcess(head, createProcess(5, 8, 2));

  simulate(head);

  return 0;
}