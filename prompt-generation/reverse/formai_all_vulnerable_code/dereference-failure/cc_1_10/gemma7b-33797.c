//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
  int process_id;
  char name[20];
  int burst_time;
  int waiting_time;
  int turnaround_time;
  struct process* next;
} process;

process* create_process(int process_id, char* name, int burst_time) {
  process* new_process = (process*)malloc(sizeof(process));
  new_process->process_id = process_id;
  strcpy(new_process->name, name);
  new_process->burst_time = burst_time;
  new_process->waiting_time = 0;
  new_process->turnaround_time = 0;
  new_process->next = NULL;
  return new_process;
}

void round_robin(process* ready_queue, process* waiting_queue) {
  if (ready_queue->next == NULL) {
    return;
  }

  time_t start_time = time(NULL);
  process* current_process = ready_queue->next;

  while (time(NULL) - start_time < current_process->burst_time) {
    printf("Process %d is running...\n", current_process->process_id);
    sleep(1);
  }

  current_process->waiting_time++;
  current_process->turnaround_time = time(NULL) - current_process->waiting_time;

  ready_queue->next = current_process->next;
  waiting_queue->next = current_process;
  free(current_process);
}

int main() {
  process* processes = create_process(1, "A", 5);
  processes = create_process(2, "B", 3);
  processes = create_process(3, "C", 4);
  processes = create_process(4, "D", 6);
  processes = create_process(5, "E", 2);

  process* ready_queue = create_process(0, "Ready Queue", 0);
  process* waiting_queue = create_process(0, "Waiting Queue", 0);

  round_robin(ready_queue, waiting_queue);

  for (process* process = processes; process; process = process->next) {
    printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", process->process_id, process->waiting_time, process->turnaround_time);
  }

  return 0;
}