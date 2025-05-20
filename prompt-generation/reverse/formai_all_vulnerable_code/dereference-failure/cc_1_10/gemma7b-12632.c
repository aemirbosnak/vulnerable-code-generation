//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_INSTRUCTIONS 10

typedef struct Process {
  int id;
  int instructions;
  int state;
  struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
  Process* current = head;
  while (current) {
    switch (current->state) {
      case 0:
        current->state = 1;
        printf("Process %d is executing...\n", current->id);
        sleep(current->instructions);
        current->state = 2;
        break;
      case 1:
        printf("Process %d is waiting...\n", current->id);
        break;
      case 2:
        current->next = head;
        printf("Process %d has completed...\n", current->id);
        free(current);
        break;
    }
    current = current->next;
  }
}

void main() {
  for (int i = 0; i < MAX_PROCESSES; i++) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = i + 1;
    newProcess->instructions = rand() % MAX_INSTRUCTIONS + 1;
    newProcess->state = 0;
    newProcess->next = head;
    head = newProcess;
  }

  schedule();

  return;
}