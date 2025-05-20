//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  struct Process* next;
} Process;

Process* head = NULL;

void add_process(int id, int arrival_time, int burst_time) {
  Process* new_process = malloc(sizeof(Process));
  new_process->process_id = id;
  new_process->arrival_time = arrival_time;
  new_process->burst_time = burst_time;
  new_process->next = head;
  head = new_process;
}

void round_robin(int quantum) {
  Process* current_process = head;
  int time_quantum = quantum;
  while (current_process) {
    if (time_quantum > 0) {
      time_quantum--;
    } else {
      current_process->burst_time--;
      time_quantum = quantum;
    }
    current_process = current_process->next;
  }
}

int main() {
  add_process(1, 0, 5);
  add_process(2, 2, 3);
  add_process(3, 4, 2);
  add_process(4, 6, 4);

  round_robin(2);

  printf("Process completed:\n");
  Process* current_process = head;
  while (current_process) {
    printf("Process ID: %d, Completion Time: %d\n", current_process->process_id, current_process->burst_time);
    current_process = current_process->next;
  }

  return 0;
}