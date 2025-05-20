//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_TIME 10

struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  int waiting_time;
  int turnaround_time;
  struct Process* next;
};

void create_process(struct Process** head) {
  *head = (struct Process*)malloc(sizeof(struct Process));
  (*head)->process_id = 0;
  (*head)->arrival_time = rand() % MAX_TIME;
  (*head)->execution_time = rand() % MAX_TIME;
  (*head)->waiting_time = 0;
  (*head)->turnaround_time = 0;
  (*head)->next = NULL;
}

void add_process(struct Process** head, int process_id) {
  struct Process* new_process = (struct Process*)malloc(sizeof(struct Process));
  new_process->process_id = process_id;
  new_process->arrival_time = rand() % MAX_TIME;
  new_process->execution_time = rand() % MAX_TIME;
  new_process->waiting_time = 0;
  new_process->turnaround_time = 0;
  new_process->next = NULL;

  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void simulate_cpu(struct Process** head) {
  struct Process* current_process = *head;
  int time = 0;

  while (current_process) {
    if (current_process->arrival_time <= time) {
      current_process->waiting_time++;
      current_process = current_process->next;
    } else {
      time++;
    }
  }

  time = 0;
  current_process = *head;

  while (current_process) {
    current_process->turnaround_time = time + current_process->execution_time;
    time++;
    current_process = current_process->next;
  }
}

int main() {
  struct Process* head = NULL;
  int i;

  for (i = 0; i < MAX_PROCESS; i++) {
    add_process(&head, i);
  }

  simulate_cpu(&head);

  return 0;
}