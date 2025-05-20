//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

struct process {
  int pid;
  int cpu_burst;
  int waiting_time;
  int turn_around_time;
  struct process* next;
};

void round_robin(struct process* head) {
  struct process* current = head;
  while (current) {
    current->waiting_time++;
    current = current->next;
  }

  current = head;
  while (current) {
    current->turn_around_time = current->waiting_time + current->cpu_burst;
    current = current->next;
  }
}

int main() {
  struct process* head = NULL;

  for (int i = 0; i < MAX_PROCESS; i++) {
    head = malloc(sizeof(struct process));
    head->pid = i;
    head->cpu_burst = rand() % 10;
    head->waiting_time = 0;
    head->turn_around_time = 0;
    head->next = NULL;

    if (head != NULL) {
      if (head->next == NULL) {
        head = head;
      } else {
        head->next = head;
      }
    }
  }

  round_robin(head);

  for (struct process* current = head; current; current = current->next) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", current->pid, current->waiting_time, current->turn_around_time);
  }

  return 0;
}