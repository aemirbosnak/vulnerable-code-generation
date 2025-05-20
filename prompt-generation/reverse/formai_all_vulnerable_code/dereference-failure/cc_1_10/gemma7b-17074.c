//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_INSTRUCTIONS 10

typedef struct Process {
  int id;
  int instructions;
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int id, int instructions) {
  Process* newProcess = malloc(sizeof(Process));
  newProcess->id = id;
  newProcess->instructions = instructions;
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    head->next = newProcess;
  }
}

void schedule() {
  time_t start = time(NULL);
  Process* currentProcess = head;

  while (currentProcess) {
    int instructions = currentProcess->instructions;
    for (int i = 0; i < instructions; i++) {
      printf("Process %d is executing instruction %d\n", currentProcess->id, i);
    }

    time_t end = time(NULL);
    int timeTaken = end - start;
    printf("Process %d took %d seconds to complete\n", currentProcess->id, timeTaken);

    currentProcess = currentProcess->next;
  }

  printf("All processes have completed execution\n");
}

int main() {
  addProcess(1, MAX_INSTRUCTIONS);
  addProcess(2, MAX_INSTRUCTIONS - 1);
  addProcess(3, MAX_INSTRUCTIONS / 2);
  addProcess(4, MAX_INSTRUCTIONS / 4);

  schedule();

  return 0;
}