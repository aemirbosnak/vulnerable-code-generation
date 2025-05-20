//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int pid;
  char name[20];
  int cpu_burst;
  int waiting_time;
  int turnaround_time;
  struct Process* next;
} Process;

Process* head = NULL;

void add_process(int pid, char* name, int cpu_burst) {
  Process* new_process = (Process*)malloc(sizeof(Process));
  new_process->pid = pid;
  strcpy(new_process->name, name);
  new_process->cpu_burst = cpu_burst;
  new_process->waiting_time = 0;
  new_process->turnaround_time = 0;
  new_process->next = NULL;

  if (head == NULL) {
    head = new_process;
  } else {
    Process* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_process;
  }
}

void simulate_cpu() {
  Process* current_process = head;

  while (current_process) {
    current_process->waiting_time++;
    current_process->cpu_burst--;

    if (current_process->cpu_burst == 0) {
      current_process->turnaround_time = current_process->waiting_time + current_process->cpu_burst;
      printf("Process %d (%s) completed.\n", current_process->pid, current_process->name);
      free(current_process);
      current_process = head;
    } else {
      current_process = current_process->next;
    }
  }
}

int main() {
  add_process(1, "A", 5);
  add_process(2, "B", 3);
  add_process(3, "C", 2);
  add_process(4, "D", 4);
  add_process(5, "E", 3);

  simulate_cpu();

  return 0;
}