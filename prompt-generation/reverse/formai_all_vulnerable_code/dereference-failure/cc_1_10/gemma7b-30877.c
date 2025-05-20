//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUEUE_SIZE 5

typedef struct process {
  int process_id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct process* next;
} process;

process* create_process(int id, int arrival_time, int burst_time) {
  process* new_process = (process*)malloc(sizeof(process));
  new_process->process_id = id;
  new_process->arrival_time = arrival_time;
  new_process->burst_time = burst_time;
  new_process->remaining_time = burst_time;
  new_process->next = NULL;

  return new_process;
}

void add_process(process** head, int id, int arrival_time, int burst_time) {
  process* new_process = create_process(id, arrival_time, burst_time);

  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void round_robin(process** head) {
  time_t current_time = time(NULL);
  process* current_process = *head;
  process* next_process = NULL;

  while (current_process) {
    if (current_process->arrival_time <= current_time && current_process->remaining_time > 0) {
      current_process->remaining_time--;
      next_process = current_process->next;
    } else {
      current_process = next_process;
      next_process = NULL;
    }
  }

  *head = current_process;
}

int main() {
  process* processes = NULL;
  add_process(&processes, 1, 0, 5);
  add_process(&processes, 2, 2, 4);
  add_process(&processes, 3, 4, 3);
  add_process(&processes, 4, 6, 2);

  round_robin(&processes);

  printf("Processes after round robin:");
  for (process* process = processes; process; process = process->next) {
    printf(" Process ID: %d, Remaining Time: %d\n", process->process_id, process->remaining_time);
  }

  return 0;
}