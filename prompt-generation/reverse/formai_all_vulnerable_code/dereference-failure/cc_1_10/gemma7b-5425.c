//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Process {
  int pid;
  int arrivalTime;
  int serviceTime;
  int completionTime;
  struct Process* next;
};

struct RoundRobin {
  struct Process* head;
  struct Process* tail;
  int currentProcess;
  int quantum;
  struct RoundRobin* next;
};

void insertProcess(struct Process** head, int arrivalTime, int serviceTime) {
  struct Process* newNode = (struct Process*)malloc(sizeof(struct Process));
  newNode->pid = arrivalTime;
  newNode->arrivalTime = arrivalTime;
  newNode->serviceTime = serviceTime;
  newNode->completionTime = 0;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void roundRobin(struct RoundRobin* rr) {
  rr->currentProcess = (rr->currentProcess + 1) % MAX;
  struct Process* process = rr->head;
  process = process->next;
  process->completionTime = rr->quantum;
  printf("Process %d completed at time %d\n", process->pid, process->completionTime);
}

int main() {
  struct RoundRobin* rr = (struct RoundRobin*)malloc(sizeof(struct RoundRobin));
  rr->head = NULL;
  rr->tail = NULL;
  rr->currentProcess = 0;
  rr->quantum = 3;

  insertProcess(&rr->head, 0, 5);
  insertProcess(&rr->head, 2, 4);
  insertProcess(&rr->head, 4, 3);
  insertProcess(&rr->head, 6, 2);

  roundRobin(rr);

  return 0;
}