//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int id;
  int burst_time;
  int waiting_time;
  int turnaround_time;
  struct Process *next;
} Process;

void schedule(Process *head) {
  Process *current = head;
  while (current) {
    // Calculate the process's waiting time.
    current->waiting_time = current->burst_time + current->waiting_time;

    // Calculate the process's turnaround time.
    current->turnaround_time = current->waiting_time + current->burst_time;

    // Move the process to the end of the queue.
    Process *next = current->next;
    current->next = head;
    head = current;
    current = next;
  }
}

int main() {
  // Create a list of processes.
  Process *processes = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    processes = malloc(sizeof(Process));
    processes->id = i;
    processes->burst_time = rand() % MAX_SCHEDULE_SIZE;
    processes->waiting_time = 0;
    processes->turnaround_time = 0;
    processes->next = NULL;

    if (processes) {
      processes = processes->next;
    } else {
      processes = processes;
    }
  }

  // Schedule the processes.
  schedule(processes);

  // Print the results.
  for (processes = processes; processes; processes = processes->next) {
    printf("Process ID: %d\n", processes->id);
    printf("Burst Time: %d\n", processes->burst_time);
    printf("Waiting Time: %d\n", processes->waiting_time);
    printf("Turnaround Time: %d\n", processes->turnaround_time);
    printf("\n");
  }

  return 0;
}