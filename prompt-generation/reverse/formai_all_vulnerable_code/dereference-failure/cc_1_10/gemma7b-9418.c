//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int burst_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = process_id;
  process->arrival_time = arrival_time;
  process->burst_time = burst_time;
  process->remaining_time = burst_time;
  process->next = NULL;
  return process;
}

void add_process(Process* head, int process_id, int arrival_time, int burst_time) {
  Process* process = create_process(process_id, arrival_time, burst_time);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void round_robin(Process* head) {
  int quantum = 2;
  Process* current_process = head;
  while (current_process) {
    if (current_process->remaining_time > 0) {
      current_process->remaining_time -= quantum;
      printf("Process %d is running for %d cycles\n", current_process->process_id, quantum);
    } else {
      printf("Process %d has completed\n", current_process->process_id);
      current_process = current_process->next;
    }
  }
}

int main() {
  Process* head = NULL;
  add_process(head, 1, 0, 5);
  add_process(head, 2, 2, 4);
  add_process(head, 3, 4, 3);
  add_process(head, 4, 6, 2);

  round_robin(head);

  return 0;
}