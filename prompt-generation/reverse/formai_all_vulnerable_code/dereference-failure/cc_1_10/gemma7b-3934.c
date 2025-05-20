//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int pid;
  char name[20];
  int burst_time;
  int remaining_time;
  struct Process* next;
} Process;

void initialize_processes(Process** head) {
  *head = NULL;
  for (int i = 0; i < MAX_PROCESS; i++) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->pid = i + 1;
    sprintf(new_process->name, "Process %d", new_process->pid);
    new_process->burst_time = rand() % 10 + 1;
    new_process->remaining_time = new_process->burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
      *head = new_process;
    } else {
      (*head)->next = new_process;
      *head = new_process;
    }
  }
}

void round_robin(Process** head) {
  int time_quantum = 5;
  Process* current_process = head;

  while (!current_process->next || current_process->remaining_time > 0) {
    printf("Current process: %s, remaining time: %d\n", current_process->name, current_process->remaining_time);
    current_process->remaining_time -= time_quantum;

    if (current_process->remaining_time == 0) {
      printf("Process %s completed.\n", current_process->name);
    }

    current_process = current_process->next;
  }
}

int main() {
  Process* head = NULL;
  initialize_processes(&head);
  round_robin(&head);

  return 0;
}