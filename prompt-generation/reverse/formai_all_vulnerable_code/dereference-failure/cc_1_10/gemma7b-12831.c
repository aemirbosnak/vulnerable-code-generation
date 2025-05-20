//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
  int process_id;
  char name[20];
  int cpu_burst_time;
  int waiting_time;
  int turnaround_time;
  struct Process* next;
} Process;

void create_process(Process** head) {
  *head = (Process*)malloc(sizeof(Process));
  (*head)->process_id = 1;
  strcpy((*head)->name, "Process 1");
  (*head)->cpu_burst_time = rand() % 10;
  (*head)->waiting_time = 0;
  (*head)->turnaround_time = 0;
  (*head)->next = NULL;
}

void add_process(Process** head, Process* new_process) {
  new_process->next = *head;
  *head = new_process;
}

void round_robin(Process** head) {
  time_t start_time = time(NULL);
  Process* current_process = *head;
  while (current_process) {
    int time_spent = time(NULL) - start_time;
    if (time_spent >= current_process->cpu_burst_time) {
      current_process->waiting_time++;
      current_process = current_process->next;
      start_time = time(NULL);
    }
  }
}

int main() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESS; i++) {
    create_process(&head);
  }

  round_robin(&head);

  for (Process* process = head; process; process = process->next) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", process->process_id, process->waiting_time, process->turnaround_time);
  }

  return 0;
}