//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_TIME 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* create_process(int process_id, int arrival_time, int service_time) {
  Process* new_process = (Process*)malloc(sizeof(Process));
  new_process->process_id = process_id;
  new_process->arrival_time = arrival_time;
  new_process->service_time = service_time;
  new_process->remaining_time = service_time;
  new_process->next = NULL;
  return new_process;
}

void add_process(Process** head, int process_id, int arrival_time, int service_time) {
  Process* new_process = create_process(process_id, arrival_time, service_time);
  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void simulate_scheduler(Process* head) {
  time_t current_time = time(NULL);
  Process* current_process = head;
  while (current_process) {
    if (current_process->arrival_time <= current_time && current_process->remaining_time > 0) {
      printf("Process %d is running...\n", current_process->process_id);
      current_process->remaining_time--;
      current_time++;
    } else {
      current_process = current_process->next;
    }
  }
}

int main() {
  Process* head = NULL;
  add_process(&head, 1, 0, 5);
  add_process(&head, 2, 2, 3);
  add_process(&head, 3, 4, 2);
  add_process(&head, 4, 6, 4);
  add_process(&head, 5, 8, 3);

  simulate_scheduler(head);

  return 0;
}