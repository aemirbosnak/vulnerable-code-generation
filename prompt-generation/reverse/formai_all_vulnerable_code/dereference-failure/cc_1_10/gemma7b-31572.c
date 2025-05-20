//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 5
#define MAX_PROCESS_TIME 10

typedef struct Process {
  int process_num;
  int arrival_time;
  int execution_time;
  struct Process* next;
} Process;

Process* createProcess(int process_num, int arrival_time, int execution_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_num = process_num;
  process->arrival_time = arrival_time;
  process->execution_time = execution_time;
  process->next = NULL;
  return process;
}

void addProcess(Process** head, int process_num, int arrival_time, int execution_time) {
  Process* process = createProcess(process_num, arrival_time, execution_time);
  if (*head == NULL) {
    *head = process;
  } else {
    (*head)->next = process;
    *head = process;
  }
}

void simulate(Process* head) {
  time_t start_time = time(NULL);
  Process* current_process = head;
  while (current_process) {
    time_t end_time = time(NULL) - start_time;
    if (end_time >= current_process->arrival_time) {
      printf("Process %d is started at time %ld.\n", current_process->process_num, end_time);
      current_process->arrival_time = 0;
      sleep(current_process->execution_time);
      printf("Process %d is completed at time %ld.\n", current_process->process_num, time(NULL) - start_time);
    }
    current_process = current_process->next;
  }
}

int main() {
  Process* head = NULL;
  addProcess(&head, 1, 0, 5);
  addProcess(&head, 2, 2, 3);
  addProcess(&head, 3, 4, 4);
  addProcess(&head, 4, 6, 2);
  addProcess(&head, 5, 8, 6);

  simulate(head);

  return 0;
}