//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

struct Process {
  int id;
  int arrivalTime;
  int serviceTime;
  int completionTime;
  struct Process* next;
};

struct Queue {
  struct Process* head;
  struct Process* tail;
  int size;
  struct Queue* next;
};

void enqueue(struct Queue* queue, struct Process* process) {
  if (queue->tail) {
    queue->tail->next = process;
    queue->tail = process;
  } else {
    queue->head = process;
    queue->tail = process;
  }
  queue->size++;
}

struct Process* dequeue(struct Queue* queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  struct Process* process = queue->head;
  queue->head = process->next;
  queue->size--;
  return process;
}

void simulate(struct Process* processes) {
  struct Queue* readyQueue = malloc(sizeof(struct Queue));
  readyQueue->head = NULL;
  readyQueue->tail = NULL;
  readyQueue->size = 0;

  struct Queue* completedQueue = malloc(sizeof(struct Queue));
  completedQueue->head = NULL;
  completedQueue->tail = NULL;
  completedQueue->size = 0;

  int time = 0;

  while (!completedQueue->head) {
    for (struct Process* process = processes; process; process = process->next) {
      if (process->arrivalTime == time) {
        enqueue(readyQueue, process);
      }
    }

    if (!readyQueue->head) {
      time++;
    } else {
      struct Process* process = dequeue(readyQueue);
      process->completionTime = time;
      enqueue(completedQueue, process);
      time += process->serviceTime;
    }
  }

  printf("Completion Time for Each Process:\n");
  for (struct Process* process = processes; process; process = process->next) {
    printf("Process ID: %d, Completion Time: %d\n", process->id, process->completionTime);
  }
}

int main() {
  struct Process* processes = malloc(sizeof(struct Process));
  processes->id = 1;
  processes->arrivalTime = 0;
  processes->serviceTime = 5;

  processes->next = malloc(sizeof(struct Process));
  processes->next->id = 2;
  processes->next->arrivalTime = 2;
  processes->next->serviceTime = 3;

  processes->next->next = malloc(sizeof(struct Process));
  processes->next->next->id = 3;
  processes->next->next->arrivalTime = 4;
  processes->next->next->serviceTime = 4;

  simulate(processes);

  return 0;
}