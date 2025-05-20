//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int id;
  int burst_time;
  int waiting_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int burst_time) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->id = id;
  process->burst_time = burst_time;
  process->waiting_time = 0;
  process->remaining_time = burst_time;
  process->next = NULL;
  return process;
}

void scheduleProcess(Process* process) {
  process->waiting_time++;
  process->remaining_time--;
  if (process->remaining_time == 0) {
    printf("Process %d completed\n", process->id);
  }
}

int main() {
  Process* head = NULL;
  Process* tail = NULL;

  // Create a few processes
  for (int i = 0; i < MAX_PROCESS; i++) {
    Process* process = createProcess(i, rand() % MAX_SCHEDULE_SIZE);
    if (head == NULL) {
      head = process;
      tail = process;
    } else {
      tail->next = process;
      tail = process;
    }
  }

  // Simulate the scheduler
  time_t start_time = time(NULL);
  while (!tail->next) {
    scheduleProcess(head);
    time_t end_time = time(NULL);
    printf("Time spent: %ld seconds\n", end_time - start_time);
  }

  return 0;
}