//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
  char name[20];
  int cpu_time;
  int waiting_time;
  int turnaround_time;
  struct Process* next;
} Process;

Process* createProcess() {
  Process* process = (Process*)malloc(sizeof(Process));
  process->name[0] = '\0';
  process->cpu_time = 0;
  process->waiting_time = 0;
  process->turnaround_time = 0;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, char* name, int cpu_time) {
  Process* process = createProcess();
  strcpy(process->name, name);
  process->cpu_time = cpu_time;
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void roundRobin(Process* head) {
  Process* currentProcess = head;
  while (currentProcess) {
    currentProcess->waiting_time++;
    if (currentProcess->waiting_time == currentProcess->cpu_time) {
      currentProcess->waiting_time = 0;
      printf("%s is finished.\n", currentProcess->name);
      currentProcess = currentProcess->next;
    }
  }
}

int main() {
  Process* head = NULL;
  addProcess(head, "A", 5);
  addProcess(head, "B", 2);
  addProcess(head, "C", 4);
  addProcess(head, "D", 3);
  addProcess(head, "E", 6);

  roundRobin(head);

  return 0;
}