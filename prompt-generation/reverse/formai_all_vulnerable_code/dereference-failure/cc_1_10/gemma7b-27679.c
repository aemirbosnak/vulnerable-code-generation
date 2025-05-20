//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  int completion_time;
  struct Process* next;
} Process;

void create_process(Process** head) {
  *head = malloc(sizeof(Process));
  (*head)->process_id = 1;
  (*head)->arrival_time = rand() % MAX_QUEUE_SIZE;
  (*head)->service_time = rand() % MAX_QUEUE_SIZE;
  (*head)->completion_time = 0;
  (*head)->next = NULL;
}

void add_process(Process** head, Process* new_process) {
  new_process->next = NULL;
  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
    *head = new_process;
  }
}

void round_robin(Process** head) {
  time_t start_time = time(NULL);
  Process* current_process = *head;
  while (current_process) {
    time_t end_time = time(NULL);
    int waiting_time = end_time - start_time - current_process->arrival_time;
    current_process->completion_time = waiting_time + current_process->service_time;
    start_time = end_time;
    current_process = current_process->next;
  }
}

int main() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESS; i++) {
    create_process(&head);
  }
  round_robin(&head);
  for (Process* process = head; process; process = process->next) {
    printf("Process ID: %d, Arrival Time: %d, Service Time: %d, Completion Time: %d\n", process->process_id, process->arrival_time, process->service_time, process->completion_time);
  }
  return 0;
}