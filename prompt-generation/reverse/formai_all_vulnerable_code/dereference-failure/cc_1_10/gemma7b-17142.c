//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define PROCESS_SIZE 20

typedef struct Process {
  int pid;
  char name[PROCESS_SIZE];
  int cpu_time;
  int waiting_time;
  struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
  Process* current_process = head;
  while (current_process) {
    if (current_process->cpu_time > 0) {
      current_process->cpu_time--;
      printf("%d: Working on process %s\n", current_process->pid, current_process->name);
    } else {
      current_process->waiting_time++;
      current_process = current_process->next;
    }
  }
}

int main() {
  // Create a few processes
  for (int i = 0; i < MAX_PROCESSES; i++) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->pid = i + 1;
    sprintf(new_process->name, "Process %d", i + 1);
    new_process->cpu_time = rand() % 10;
    new_process->waiting_time = 0;
    new_process->next = head;
    head = new_process;
  }

  // Schedule the processes
  schedule();

  // Wait for a while
  sleep(10);

  // Schedule the processes again
  schedule();

  return 0;
}