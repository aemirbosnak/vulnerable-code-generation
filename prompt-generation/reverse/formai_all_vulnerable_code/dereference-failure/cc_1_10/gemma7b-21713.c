//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROC_NUM 256

typedef struct Process {
  char name[256];
  int pid;
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name) {
  Process* newProcess = malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->pid = getpid();
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    head->next = newProcess;
    head = newProcess;
  }
}

void killProcess(char* name) {
  Process* currentProcess = head;

  while (currentProcess) {
    if (strcmp(currentProcess->name, name) == 0) {
      kill(currentProcess->pid, SIGKILL);
      free(currentProcess);
      currentProcess = NULL;
    } else {
      currentProcess = currentProcess->next;
    }
  }
}

void showProcesses() {
  Process* currentProcess = head;

  while (currentProcess) {
    printf("%s (PID: %d)\n", currentProcess->name, currentProcess->pid);
    currentProcess = currentProcess->next;
  }
}

int main() {
  addProcess("Process A");
  addProcess("Process B");
  addProcess("Process C");

  showProcesses();

  killProcess("Process B");

  showProcesses();

  return 0;
}