//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8

typedef struct process {
  int id;
  int burst_time;
  struct process* next;
} process;

process* create_process(int id, int burst_time) {
  process* new_process = malloc(sizeof(process));
  new_process->id = id;
  new_process->burst_time = burst_time;
  new_process->next = NULL;
  return new_process;
}

void add_process(process* head, int id, int burst_time) {
  process* new_process = create_process(id, burst_time);
  if (head == NULL) {
    head = new_process;
  } else {
    new_process->next = head;
    head = new_process;
  }
}

void round_robin(process* head) {
  int quantum = 5;
  process* current_process = head;
  while (current_process) {
    printf("Process %d is running...\n", current_process->id);
    sleep(quantum);
    current_process = current_process->next;
  }
}

int main() {
  process* head = NULL;
  add_process(head, 1, 10);
  add_process(head, 2, 5);
  add_process(head, 3, 15);
  add_process(head, 4, 8);

  round_robin(head);

  return 0;
}