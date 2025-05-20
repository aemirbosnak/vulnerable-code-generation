//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_TIME 10

struct Process {
  int id;
  int arrival_time;
  int execution_time;
  int remaining_time;
  struct Process* next;
};

void schedule_process(struct Process* head) {
  struct Process* current_process = head;
  while (current_process) {
    if (current_process->remaining_time > 0) {
      sleep(current_process->arrival_time);
      current_process->remaining_time--;
    }
    current_process = current_process->next;
  }
}

int main() {
  struct Process* processes = NULL;

  // Create a list of processes
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes = malloc(sizeof(struct Process));
    processes->id = i + 1;
    processes->arrival_time = rand() % MAX_SCHEDULE_TIME;
    processes->execution_time = rand() % MAX_SCHEDULE_TIME;
    processes->remaining_time = processes->execution_time;
    processes->next = NULL;

    if (processes != NULL) {
      processes = processes->next;
    } else {
      processes = processes;
    }
  }

  // Schedule the processes
  schedule_process(processes);

  // Print the completion order
  struct Process* completed_processes = processes;
  while (completed_processes) {
    printf("Process %d completed.\n", completed_processes->id);
    completed_processes = completed_processes->next;
  }

  return 0;
}