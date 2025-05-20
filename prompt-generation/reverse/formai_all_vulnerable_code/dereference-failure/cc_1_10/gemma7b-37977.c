//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int execution_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = process_id;
  process->arrival_time = arrival_time;
  process->execution_time = execution_time;
  process->next = NULL;
  return process;
}

void add_process(Process* head, int process_id, int arrival_time, int execution_time) {
  Process* process = create_process(process_id, arrival_time, execution_time);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void simulate_cpu(Process* head) {
  int current_time = 0;
  Process* current_process = NULL;
  while (head) {
    if (current_time >= head->arrival_time && current_process == NULL) {
      current_process = head;
    }
    if (current_process && current_process->execution_time > 0) {
      current_process->execution_time--;
      printf("Process %d is running... (Time: %d)\n", current_process->process_id, current_time);
      sleep(1);
    }
    current_time++;
  }
}

int main() {
  Process* head = NULL;
  add_process(head, 1, 0, 5);
  add_process(head, 2, 2, 4);
  add_process(head, 3, 4, 3);
  add_process(head, 4, 6, 2);
  add_process(head, 5, 8, 1);

  simulate_cpu(head);

  return 0;
}