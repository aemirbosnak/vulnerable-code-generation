//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct process {
  int process_id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct process* next;
} process;

process* create_process(int process_id, int arrival_time, int burst_time) {
  process* new_process = (process*)malloc(sizeof(process));
  new_process->process_id = process_id;
  new_process->arrival_time = arrival_time;
  new_process->burst_time = burst_time;
  new_process->remaining_time = burst_time;
  new_process->next = NULL;

  return new_process;
}

void round_robin(process* head) {
  process* current_process = head;
  while (current_process) {
    current_process->remaining_time--;
    if (current_process->remaining_time == 0) {
      printf("Process %d completed.\n", current_process->process_id);
      free(current_process);
      current_process = head;
    } else {
      current_process = current_process->next;
    }
  }
}

int main() {
  process* processes = NULL;

  // Create some processes
  processes = create_process(1, 0, 5);
  processes = create_process(2, 1, 4);
  processes = create_process(3, 2, 3);
  processes = create_process(4, 3, 2);
  processes = create_process(5, 4, 1);

  // Round robin scheduling
  round_robin(processes);

  return 0;
}