//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  int completion_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int service_time) {
  Process* new_process = (Process*)malloc(sizeof(Process));
  new_process->process_id = process_id;
  new_process->arrival_time = arrival_time;
  new_process->service_time = service_time;
  new_process->completion_time = 0;
  new_process->next = NULL;
  return new_process;
}

void schedule_processes(Process* head) {
  int quantum = 0;
  Process* current_process = head;
  while (current_process) {
    if (quantum < current_process->service_time) {
      quantum++;
    } else {
      current_process->completion_time = quantum;
      current_process = current_process->next;
      quantum = 0;
    }
  }
  current_process->completion_time = quantum;
}

int main() {
  Process* processes = NULL;
  processes = create_process(1, 0, 5);
  processes = create_process(2, 2, 3);
  processes = create_process(3, 4, 6);
  processes = create_process(4, 6, 4);
  processes = create_process(5, 8, 2);

  schedule_processes(processes);

  for (processes = processes; processes; processes = processes->next) {
    printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Completion Time: %d\n", processes->process_id, processes->arrival_time, processes->service_time, processes->completion_time);
  }

  return 0;
}