//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
  char name[20];
  int priority;
  int state;
  int cpu_burst;
  struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int priority, int cpu_burst) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->priority = priority;
  newProcess->state = 0;
  newProcess->cpu_burst = cpu_burst;
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    Process* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newProcess;
  }
}

void schedule() {
  Process* currentProcess = head;

  while (currentProcess) {
    // Calculate the waiting time for the process.
    int waitingTime = 0;
    for (Process* process = head; process != currentProcess; process++) {
      waitingTime++;
    }

    // Execute the process.
    printf("Process: %s, CPU burst: %d, Waiting time: %d\n", currentProcess->name, currentProcess->cpu_burst, waitingTime);

    // Update the process state.
    currentProcess->state = 1;

    // Move to the next process.
    currentProcess = currentProcess->next;
  }
}

int main() {
  insertProcess("Process A", 1, 10);
  insertProcess("Process B", 2, 5);
  insertProcess("Process C", 3, 15);
  insertProcess("Process D", 4, 20);
  insertProcess("Process E", 5, 12);

  schedule();

  return 0;
}