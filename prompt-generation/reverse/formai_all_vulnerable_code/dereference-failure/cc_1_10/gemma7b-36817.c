//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_SIZE 10

struct Process {
  int id;
  int arrival_time;
  int execution_time;
  struct Process* next;
};

struct Schedule {
  struct Process* head;
  struct Process* tail;
  int size;
  struct Schedule* next;
};

void add_process(struct Schedule* schedule, int arrival_time, int execution_time) {
  struct Process* new_process = (struct Process*)malloc(sizeof(struct Process));
  new_process->id = schedule->size + 1;
  new_process->arrival_time = arrival_time;
  new_process->execution_time = execution_time;
  new_process->next = NULL;

  if (schedule->head == NULL) {
    schedule->head = new_process;
    schedule->tail = new_process;
  } else {
    schedule->tail->next = new_process;
    schedule->tail = new_process;
  }

  schedule->size++;
}

void simulate_cpu(struct Schedule* schedule) {
  struct Process* current_process = schedule->head;
  while (current_process) {
    printf("Process %d is running...\n", current_process->id);
    sleep(current_process->execution_time);
    current_process = current_process->next;
  }
}

int main() {
  struct Schedule* schedule = (struct Schedule*)malloc(sizeof(struct Schedule));
  schedule->head = NULL;
  schedule->tail = NULL;
  schedule->size = 0;
  schedule->next = NULL;

  add_process(schedule, 0, 5);
  add_process(schedule, 2, 3);
  add_process(schedule, 4, 2);

  simulate_cpu(schedule);

  return 0;
}