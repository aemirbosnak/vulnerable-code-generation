//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int id;
  int arrival_time;
  int service_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* create_process(int id, int arrival_time, int service_time) {
  Process* process = malloc(sizeof(Process));
  process->id = id;
  process->arrival_time = arrival_time;
  process->service_time = service_time;
  process->remaining_time = service_time;
  process->next = NULL;
  return process;
}

void add_process(Process** head, int id, int arrival_time, int service_time) {
  Process* process = create_process(id, arrival_time, service_time);
  if (*head == NULL) {
    *head = process;
  } else {
    (*head)->next = process;
  }
}

void simulate_scheduler(Process** head) {
  time_t now = time(NULL);
  Process* current_process = NULL;

  while (*head) {
    Process* process = *head;

    if (current_process == NULL) {
      if (process->arrival_time <= now) {
        current_process = process;
      }
    } else {
      if (process->arrival_time <= now && process->remaining_time > 0) {
        current_process = process;
      }
    }

    if (current_process) {
      current_process->remaining_time--;
      printf("Process %d is running...\n", current_process->id);
    }

    if (current_process->remaining_time == 0) {
      printf("Process %d is complete.\n", current_process->id);
      free(current_process);
      current_process = NULL;
    }

    head = &((*head)->next);
  }
}

int main() {
  Process** head = NULL;

  add_process(&head, 1, 0, 5);
  add_process(&head, 2, 2, 4);
  add_process(&head, 3, 3, 3);
  add_process(&head, 4, 4, 2);

  simulate_scheduler(&head);

  return 0;
}