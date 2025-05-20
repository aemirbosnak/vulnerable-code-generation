//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
  int pid;
  char name[20];
  int burst_time;
  int waiting_time;
  int remaining_time;
  struct Process* next;
} Process;

void initialize_process(Process* process) {
  process->pid = rand() % MAX_PROCESS + 1;
  process->name[0] = 'A' + process->pid - 1;
  process->burst_time = rand() % 5 + 1;
  process->waiting_time = 0;
  process->remaining_time = process->burst_time;
  process->next = NULL;
}

void round_robin(Process* head) {
  time_t start_time = time(NULL);
  Process* current_process = head;
  while (current_process) {
    current_process->waiting_time++;
    if (current_process->remaining_time > 0) {
      current_process->remaining_time--;
      printf("Process %c is running...\n", current_process->name[0]);
    } else {
      current_process->remaining_time = current_process->burst_time;
      printf("Process %c completed.\n", current_process->name[0]);
    }
    current_process = current_process->next;
  }
  time_t end_time = time(NULL);
  printf("Total time: %ld seconds\n", end_time - start_time);
}

int main() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESS; i++) {
    Process* process = (Process*)malloc(sizeof(Process));
    initialize_process(process);
    if (head == NULL) {
      head = process;
    } else {
      process->next = head;
      head = process;
    }
  }
  round_robin(head);
  return 0;
}