//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4

typedef struct Process {
  int id;
  char name[20];
  int cpu_burst;
  int waiting_time;
  int turnaround_time;
  struct Process* next;
} Process;

Process* head = NULL;

void schedule() {
  time_t start_time = time(NULL);
  Process* current_process = head;

  while (current_process) {
    current_process->waiting_time--;
    if (current_process->waiting_time == 0) {
      current_process->turnaround_time = time(NULL) - start_time;
      printf("Process %d (%s) completed.\n", current_process->id, current_process->name);
      free(current_process);
      current_process = head;
    } else {
      current_process = current_process->next;
    }
  }

  printf("All processes completed.\n");
}

void addProcess(int id, char* name, int cpu_burst) {
  Process* new_process = (Process*)malloc(sizeof(Process));
  new_process->id = id;
  strcpy(new_process->name, name);
  new_process->cpu_burst = cpu_burst;
  new_process->waiting_time = MAX_PROCESSORS;
  new_process->turnaround_time = 0;
  new_process->next = NULL;

  if (head == NULL) {
    head = new_process;
  } else {
    Process* last_process = head;
    while (last_process->next) {
      last_process = last_process->next;
    }
    last_process->next = new_process;
  }
}

int main() {
  addProcess(1, "Process A", 5);
  addProcess(2, "Process B", 3);
  addProcess(3, "Process C", 8);
  addProcess(4, "Process D", 2);

  schedule();

  return 0;
}