//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct process {
  int id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct process* next;
} process;

process* createProcess(int id, int arrival_time, int burst_time) {
  process* newProcess = (process*)malloc(sizeof(process));
  newProcess->id = id;
  newProcess->arrival_time = arrival_time;
  newProcess->burst_time = burst_time;
  newProcess->remaining_time = burst_time;
  newProcess->next = NULL;
  return newProcess;
}

void addProcess(process** head, int id, int arrival_time, int burst_time) {
  process* newProcess = createProcess(id, arrival_time, burst_time);
  if (*head == NULL) {
    *head = newProcess;
  } else {
    (*head)->next = newProcess;
  }
}

void roundRobin(process** head) {
  time_t currentTime = time(NULL);
  process* currentProcess = NULL;
  process* nextProcess = NULL;

  while (*head) {
    if (currentProcess == NULL) {
      currentProcess = *head;
    } else if (currentProcess->remaining_time == 0) {
      currentProcess->remaining_time = currentProcess->burst_time;
      nextProcess = currentProcess->next;
      currentProcess = NULL;
    } else if (currentTime - currentProcess->arrival_time >= currentProcess->remaining_time) {
      currentProcess->remaining_time--;
    }

    if (nextProcess) {
      nextProcess->arrival_time = currentTime;
    }
  }
}

int main() {
  process* head = NULL;
  addProcess(&head, 1, 0, 5);
  addProcess(&head, 2, 2, 4);
  addProcess(&head, 3, 4, 3);
  addProcess(&head, 4, 6, 2);

  roundRobin(&head);

  for (process* process = head; process; process = process->next) {
    printf("Process ID: %d, Remaining Time: %d\n", process->id, process->remaining_time);
  }

  return 0;
}