//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  struct Process* next;
} Process;

void roundrobin_scheduling(Process* head) {
  int current_processor = 0;
  int time_quantum = 5;
  Process* current_process = head;

  while (current_process) {
    if (current_process->arrival_time <= time_quantum && current_processor == 0) {
      current_process->execution_time--;
      time_quantum = current_process->arrival_time;
      current_processor = 1;
    } else if (current_process->execution_time == 0) {
      current_processor = 0;
      current_process = current_process->next;
    } else {
      time_quantum--;
    }
  }
}

int main() {
  Process* head = NULL;
  Process* process_1 = malloc(sizeof(Process));
  process_1->process_id = 1;
  process_1->arrival_time = 0;
  process_1->execution_time = 8;
  process_1->next = NULL;

  Process* process_2 = malloc(sizeof(Process));
  process_2->process_id = 2;
  process_2->arrival_time = 2;
  process_2->execution_time = 4;
  process_2->next = NULL;

  Process* process_3 = malloc(sizeof(Process));
  process_3->process_id = 3;
  process_3->arrival_time = 4;
  process_3->execution_time = 6;
  process_3->next = NULL;

  Process* process_4 = malloc(sizeof(Process));
  process_4->process_id = 4;
  process_4->arrival_time = 6;
  process_4->execution_time = 2;
  process_4->next = NULL;

  head = process_1;
  head->next = process_2;
  head->next->next = process_3;
  head->next->next->next = process_4;

  roundrobin_scheduling(head);

  printf("Process completed:\n");
  process_1->execution_time = 0;
  process_2->execution_time = 0;
  process_3->execution_time = 0;
  process_4->execution_time = 0;

  for (process_1 = head; process_1; process_1 = process_1->next) {
    printf("Process ID: %d, Execution Time: %d\n", process_1->process_id, process_1->execution_time);
  }

  return 0;
}