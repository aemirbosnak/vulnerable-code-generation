//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int start_time;
  int finish_time;
} Process;

typedef struct {
  Process *processes;
  int num_processes;
} Queue;

void add_process(Queue *queue, Process *process) {
  if (queue->processes == NULL) {
    queue->processes = malloc(sizeof(Process));
  } else {
    queue->processes = realloc(queue->processes, (queue->num_processes + 1) * sizeof(Process));
  }
  queue->processes[queue->num_processes++] = *process;
}

void sort_processes(Queue *queue) {
  for (int i = 0; i < queue->num_processes - 1; i++) {
    for (int j = 0; j < queue->num_processes - i - 1; j++) {
      if (queue->processes[j].arrival_time > queue->processes[j + 1].arrival_time) {
        Process temp = queue->processes[j];
        queue->processes[j] = queue->processes[j + 1];
        queue->processes[j + 1] = temp;
      }
    }
  }
}

void print_queue(Queue *queue) {
  for (int i = 0; i < queue->num_processes; i++) {
    printf("Process %d: arrival time = %d, burst time = %d, remaining time = %d, start time = %d, finish time = %d\n",
      queue->processes[i].pid, queue->processes[i].arrival_time, queue->processes[i].burst_time,
      queue->processes[i].remaining_time, queue->processes[i].start_time, queue->processes[i].finish_time);
  }
}

int main() {
  Queue queue;
  queue.processes = NULL;
  queue.num_processes = 0;

  Process p1 = {1, 0, 5, 5, 0, 0};
  Process p2 = {2, 2, 3, 3, 0, 0};
  Process p3 = {3, 4, 4, 4, 0, 0};
  Process p4 = {4, 6, 2, 2, 0, 0};

  add_process(&queue, &p1);
  add_process(&queue, &p2);
  add_process(&queue, &p3);
  add_process(&queue, &p4);

  sort_processes(&queue);

  int current_time = 0;
  int finished_processes = 0;

  while (finished_processes < queue.num_processes) {
    for (int i = 0; i < queue.num_processes; i++) {
      if (queue.processes[i].arrival_time <= current_time && queue.processes[i].remaining_time > 0) {
        if (queue.processes[i].start_time == 0) {
          queue.processes[i].start_time = current_time;
        }
        queue.processes[i].remaining_time--;
        current_time++;
        if (queue.processes[i].remaining_time == 0) {
          queue.processes[i].finish_time = current_time;
          finished_processes++;
        }
      }
    }
  }

  print_queue(&queue);

  return 0;
}