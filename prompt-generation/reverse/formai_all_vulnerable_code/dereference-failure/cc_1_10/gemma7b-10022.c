//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  char name[20];
  int cpu_burst_time;
  int waiting_time;
  int turn_around_time;
  struct Process* next;
} Process;

void insert_process(Process** head, int process_id, char* name, int cpu_burst_time) {
  Process* new_process = (Process*)malloc(sizeof(Process));
  new_process->process_id = process_id;
  strcpy(new_process->name, name);
  new_process->cpu_burst_time = cpu_burst_time;
  new_process->waiting_time = 0;
  new_process->turn_around_time = 0;
  new_process->next = NULL;

  if (*head == NULL) {
    *head = new_process;
  } else {
    (*head)->next = new_process;
  }
}

void round_robin(Process** head) {
  Process* current_process = *head;
  while (current_process) {
    current_process->waiting_time++;
    current_process = current_process->next;
  }

  current_process = *head;
  while (current_process) {
    current_process->turn_around_time = current_process->waiting_time + current_process->cpu_burst_time;
    current_process = current_process->next;
  }
}

int main() {
  Process* head = NULL;
  insert_process(&head, 1, "Process A", 5);
  insert_process(&head, 2, "Process B", 8);
  insert_process(&head, 3, "Process C", 3);
  insert_process(&head, 4, "Process D", 6);
  insert_process(&head, 5, "Process E", 2);

  round_robin(&head);

  printf("Process ID\tName\tCPU Burst Time\tWaiting Time\tTurnaround Time\n");
  for (Process* current_process = head; current_process; current_process = current_process->next) {
    printf("%d\t%s\t%d\t%d\t%d\n", current_process->process_id, current_process->name, current_process->cpu_burst_time, current_process->waiting_time, current_process->turn_around_time);
  }

  return 0;
}