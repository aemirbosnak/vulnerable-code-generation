//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS_NUM 5

typedef struct Process {
  int pid;
  char name[20];
  int cpu_time;
  int waiting_time;
  struct Process* next;
} Process;

Process* head = NULL;

void insertProcess(char* name, int cpuTime) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  newProcess->pid = getpid();
  strcpy(newProcess->name, name);
  newProcess->cpu_time = cpuTime;
  newProcess->waiting_time = 0;
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
    printf("Process: %s, CPU time: %d\n", currentProcess->name, currentProcess->cpu_time);
    sleep(currentProcess->cpu_time);
    currentProcess->waiting_time++;
    currentProcess = currentProcess->next;
  }

  printf("All processes finished!\n");
}

int main() {
  insertProcess("Process A", 5);
  insertProcess("Process B", 3);
  insertProcess("Process C", 2);
  insertProcess("Process D", 4);
  insertProcess("Process E", 3);

  schedule();

  return 0;
}