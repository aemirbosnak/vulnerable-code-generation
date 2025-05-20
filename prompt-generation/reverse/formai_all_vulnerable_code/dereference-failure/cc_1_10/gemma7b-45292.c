//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
  int id;
  int burstTime;
  int waitingTime;
  struct Process* next;
} Process;

Process* insertProcess(Process* head, int id, int burstTime) {
  Process* newNode = (Process*)malloc(sizeof(Process));
  newNode->id = id;
  newNode->burstTime = burstTime;
  newNode->waitingTime = 0;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void simulate(Process* head) {
  int time = 0;
  Process* currentProcess = head;

  while (currentProcess) {
    time++;
    currentProcess->waitingTime++;

    if (currentProcess->burstTime == 0) {
      currentProcess->waitingTime = 0;
      printf("Process %d completed.\n", currentProcess->id);
      currentProcess = currentProcess->next;
    } else {
      currentProcess->burstTime--;
    }

    printf("Time: %d\n", time);
  }

  printf("All processes completed.\n");
}

int main() {
  Process* head = insertProcess(NULL, 1, 5);
  insertProcess(head, 2, 4);
  insertProcess(head, 3, 2);
  insertProcess(head, 4, 3);

  simulate(head);

  return 0;
}