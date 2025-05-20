//Gemma-7B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
  char name[20];
  int pid;
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->pid = getpid();
  newProcess->next = head;
  head = newProcess;
}

void killProcess(char* name) {
  Process* currentProcess = head;
  Process* previousProcess = NULL;

  while (currentProcess) {
    if (strcmp(currentProcess->name, name) == 0) {
      break;
    }

    previousProcess = currentProcess;
    currentProcess = currentProcess->next;
  }

  if (previousProcess) {
    previousProcess->next = currentProcess->next;
  } else {
    head = currentProcess->next;
  }

  free(currentProcess);
}

int main() {
  addProcess("Process A");
  addProcess("Process B");
  addProcess("Process C");

  killProcess("Process B");

  Process* currentProcess = head;

  while (currentProcess) {
    printf("%s (PID: %d)\n", currentProcess->name, currentProcess->pid);
    currentProcess = currentProcess->next;
  }

  return 0;
}