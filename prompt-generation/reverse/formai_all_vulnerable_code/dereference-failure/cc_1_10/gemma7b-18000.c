//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10
#define PROCESS_SIZE 20

struct Process {
  int id;
  int arrivalTime;
  int serviceTime;
  int completionTime;
  struct Process* next;
};

void createProcess(struct Process** head) {
  *head = (struct Process*)malloc(sizeof(struct Process));
  (*head)->id = 0;
  (*head)->arrivalTime = rand() % MAX_PROCESSES;
  (*head)->serviceTime = rand() % PROCESS_SIZE;
  (*head)->completionTime = -1;
  (*head)->next = NULL;
}

void addProcess(struct Process** head, struct Process* newProcess) {
  newProcess->next = *head;
  *head = newProcess;
}

void schedule(struct Process* head) {
  struct Process* currentProcess = head;
  while (currentProcess) {
    if (currentProcess->arrivalTime <= time(NULL) && currentProcess->completionTime == -1) {
      currentProcess->completionTime = time(NULL) + currentProcess->serviceTime;
      printf("Process %d completed.\n", currentProcess->id);
      currentProcess = currentProcess->next;
    } else {
      currentProcess = currentProcess->next;
    }
  }
}

int main() {
  struct Process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    createProcess(&head);
  }

  schedule(head);

  return 0;
}