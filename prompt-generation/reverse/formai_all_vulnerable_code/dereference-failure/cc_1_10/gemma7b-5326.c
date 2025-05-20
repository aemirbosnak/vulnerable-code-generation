//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int pid;
  char name[20];
  int burstTime;
  int remainingTime;
  struct Process* next;
} Process;

Process* createProcess(char* name, int burstTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->pid = getpid();
  strcpy(process->name, name);
  process->burstTime = burstTime;
  process->remainingTime = burstTime;
  process->next = NULL;
  return process;
}

void roundRobin(Process* processes) {
  int i = 0;
  while (processes) {
    processes->remainingTime--;
    if (processes->remainingTime == 0) {
      printf("Process %s completed.\n", processes->name);
      free(processes);
      processes = processes->next;
    } else {
      processes = processes->next;
    }
  }
}

int main() {
  Process* processes = NULL;

  // Create a few processes
  processes = createProcess("Process A", 10);
  processes = createProcess("Process B", 5);
  processes = createProcess("Process C", 15);
  processes = createProcess("Process D", 8);
  processes = createProcess("Process E", 20);

  // Round robin scheduling
  roundRobin(processes);

  return 0;
}