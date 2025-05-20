//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSORS 4

typedef struct Process {
  int id;
  int burstTime;
  int waitingTime;
  int turnaroundTime;
  struct Process* next;
} Process;

Process* head = NULL;

void addToQueue(int burstTime) {
  Process* newNode = malloc(sizeof(Process));
  newNode->id = head ? head->id + 1 : 0;
  newNode->burstTime = burstTime;
  newNode->waitingTime = 0;
  newNode->turnaroundTime = 0;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
    head = newNode;
  }
}

void roundRobin() {
  Process* currentProcess = head;
  time_t currentTime = time(NULL);
  time_t nextTime = currentTime + currentProcess->burstTime;

  while (currentTime < nextTime) {
    printf("Processor %d is working on Process %d\n", currentProcess->id, currentProcess->id);
    sleep(1);
    currentTime = time(NULL);
  }

  currentProcess->waitingTime = currentTime - nextTime;
  currentProcess->turnaroundTime = currentTime - currentProcess->burstTime;

  currentProcess = currentProcess->next;

  if (currentProcess) {
    roundRobin();
  } else {
    printf("All processes have been completed\n");
  }
}

int main() {
  addToQueue(5);
  addToQueue(3);
  addToQueue(8);
  addToQueue(4);

  roundRobin();

  return 0;
}