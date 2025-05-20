//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int pid;
  char name[20];
  int cpu_time;
  int waiting_time;
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(char* name, int cpuTime) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  newProcess->pid = getpid();
  strcpy(newProcess->name, name);
  newProcess->cpu_time = cpuTime;
  newProcess->waiting_time = 0;
  newProcess->next = head;
  head = newProcess;
}

void scheduleProcess() {
  if (head) {
    Process* currentProcess = head;
    while (currentProcess->next) {
      currentProcess = currentProcess->next;
    }
    currentProcess->waiting_time++;
    printf("Process %s waiting for CPU...\n", currentProcess->name);
    sleep(currentProcess->cpu_time);
    currentProcess->waiting_time--;
    printf("Process %s finished!\n", currentProcess->name);
  }
}

int main() {
  addProcess("Process A", 5);
  addProcess("Process B", 3);
  addProcess("Process C", 2);

  for (int i = 0; i < MAX_PROCESSES; i++) {
    scheduleProcess();
  }

  return 0;
}