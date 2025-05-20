//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int service_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = process_id;
  process->arrival_time = arrival_time;
  process->service_time = service_time;
  process->next = NULL;
  return process;
}

void add_process(Process* head, int process_id, int arrival_time, int service_time) {
  Process* process = create_process(process_id, arrival_time, service_time);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void print_processes(Process* head) {
  Process* current = head;
  while (current) {
    printf("Process ID: %d, Arrival Time: %d, Service Time: %d\n", current->process_id, current->arrival_time, current->service_time);
    current = current->next;
  }
}

void round_robin(Process* head) {
  Process* current = head;
  int time_quantum = 5;
  int completed_processes = 0;
  while (!completed_processes) {
    for (int i = 0; i < time_quantum && current; i++) {
      printf("Process ID: %d, Time Remaining: %d\n", current->process_id, current->service_time);
      current->service_time--;
      if (current->service_time == 0) {
        completed_processes++;
        printf("Process ID: %d Completed\n", current->process_id);
      }
      current = current->next;
    }
    sleep(1);
  }
}

int main() {
  Process* head = NULL;
  add_process(head, 1, 0, 3);
  add_process(head, 2, 2, 4);
  add_process(head, 3, 1, 2);
  add_process(head, 4, 3, 5);

  print_processes(head);

  round_robin(head);

  return 0;
}