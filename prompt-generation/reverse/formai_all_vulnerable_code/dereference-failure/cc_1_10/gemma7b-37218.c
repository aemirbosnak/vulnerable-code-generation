//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_SLICE 10

typedef struct Process {
  char name[20];
  int arrivalTime;
  int executionTime;
  int remainingTime;
  struct Process* next;
} Process;

Process* createProcess(char* name, int arrivalTime, int executionTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  strcpy(process->name, name);
  process->arrivalTime = arrivalTime;
  process->executionTime = executionTime;
  process->remainingTime = executionTime;
  process->next = NULL;
  return process;
}

void simulateRoundRobin(Process* head) {
  time_t currentTime = time(NULL);
  Process* currentProcess = head;
  while (currentProcess) {
    if (currentTime >= currentProcess->arrivalTime) {
      currentProcess->remainingTime--;
      if (currentProcess->remainingTime == 0) {
        printf("%s completed.\n", currentProcess->name);
      }
    }
    currentProcess = currentProcess->next;
  }
}

int main() {
  Process* head = NULL;
  head = createProcess("A", 0, 5);
  head = createProcess("B", 2, 3);
  head = createProcess("C", 4, 4);
  head = createProcess("D", 6, 2);
  head = createProcess("E", 8, 3);

  simulateRoundRobin(head);

  return 0;
}