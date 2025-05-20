//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSORS 8

typedef struct Process {
  int pid;
  char name[20];
  int cpu_burst_time;
  struct Process* next;
} Process;

Process* head = NULL;

void add_process(int pid, char* name, int cpu_burst_time) {
  Process* new_process = malloc(sizeof(Process));
  new_process->pid = pid;
  strcpy(new_process->name, name);
  new_process->cpu_burst_time = cpu_burst_time;
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

void round_robin(int quantum) {
  Process* current_process = head;
  int time_quantum = quantum;

  while (current_process) {
    time_quantum--;

    if (time_quantum == 0) {
      current_process = current_process->next;
      time_quantum = quantum;
    }

    printf("Process %d is running\n", current_process->pid);
  }
}

int main() {
  add_process(1, "Process A", 5);
  add_process(2, "Process B", 3);
  add_process(3, "Process C", 7);

  round_robin(2);

  return 0;
}