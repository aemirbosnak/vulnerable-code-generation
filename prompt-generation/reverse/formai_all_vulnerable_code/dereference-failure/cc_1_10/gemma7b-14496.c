//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct process {
  int pid;
  int time_remaining;
  struct process* next;
} process;

process* head = NULL;

void add_process(int pid, int time_remaining) {
  process* new_process = malloc(sizeof(process));
  new_process->pid = pid;
  new_process->time_remaining = time_remaining;
  new_process->next = NULL;

  if (head == NULL) {
    head = new_process;
  } else {
    head->next = new_process;
  }
}

void schedule() {
  process* current_process = head;

  while (current_process) {
    if (current_process->time_remaining > 0) {
      current_process->time_remaining--;
      printf("Process %d is running\n", current_process->pid);
      sleep(1);
    } else {
      printf("Process %d has finished\n", current_process->pid);
      free(current_process);
      current_process = head;
    }
  }
}

int main() {
  add_process(1, 5);
  add_process(2, 3);
  add_process(3, 2);
  add_process(4, 4);
  add_process(5, 6);

  schedule();

  return 0;
}