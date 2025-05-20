//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

struct process {
  int pid;
  char state;
  int waiting_time;
  int service_time;
  struct process* next;
};

void insert_process(struct process** head, int pid, int waiting_time, int service_time) {
  struct process* new_process = (struct process*)malloc(sizeof(struct process));
  new_process->pid = pid;
  new_process->state = 'W';
  new_process->waiting_time = waiting_time;
  new_process->service_time = service_time;
  new_process->next = NULL;

  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void simulate_scheduler(struct process* head) {
  while (head) {
    printf("Process %d in state %c, waiting time %d, service time %d\n", head->pid, head->state, head->waiting_time, head->service_time);

    if (head->state == 'W') {
      head->state = 'R';
      head->waiting_time--;
    }

    if (head->waiting_time == 0) {
      head->state = 'C';
      sleep(head->service_time);
      head->state = 'F';
    }

    head = head->next;
  }
}

int main() {
  struct process* head = NULL;

  insert_process(&head, 1, 5, 2);
  insert_process(&head, 2, 2, 3);
  insert_process(&head, 3, 3, 4);

  simulate_scheduler(head);

  return 0;
}