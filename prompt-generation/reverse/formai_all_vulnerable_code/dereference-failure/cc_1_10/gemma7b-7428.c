//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PROCESSES 10
#define PROCESS_TIME 5

struct process {
  int pid;
  int remaining_time;
  struct process* next;
};

void insert_process(struct process** head, int pid, int remaining_time) {
  struct process* new_process = malloc(sizeof(struct process));
  new_process->pid = pid;
  new_process->remaining_time = remaining_time;
  new_process->next = NULL;

  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void schedule_process(struct process** head) {
  struct process* current_process = *head;
  struct process* next_process = NULL;

  while (current_process) {
    current_process->remaining_time--;

    if (current_process->remaining_time == 0) {
      printf("Process %d completed.\n", current_process->pid);

      if (next_process) {
        current_process = next_process;
      } else {
        current_process = NULL;
      }
    } else {
      next_process = current_process->next;
      current_process = NULL;
    }
  }
}

int main() {
  struct process* processes = NULL;

  for (int i = 0; i < MAX_PROCESSES; i++) {
    insert_process(&processes, i + 1, PROCESS_TIME);
  }

  schedule_process(&processes);

  return 0;
}