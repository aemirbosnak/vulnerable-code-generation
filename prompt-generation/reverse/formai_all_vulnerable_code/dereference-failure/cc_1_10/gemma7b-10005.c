//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 100

typedef struct Process {
  int id;
  int burstTime;
  int remainingTime;
  struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->id = id;
  process->burstTime = burstTime;
  process->remainingTime = burstTime;
  process->next = NULL;
  return process;
}

void addProcessToSchedule(Process* process, Process** schedule) {
  *schedule = process;
  (*schedule)->next = NULL;
}

void roundRobin(Process** schedule) {
  time_t t = time(NULL);
  int currentProcessIndex = 0;
  while (*schedule) {
    Process* currentProcess = (*schedule)->next;
    if (currentProcess) {
      sleep(1);
      (*schedule)->remainingTime--;
      if ((*schedule)->remainingTime == 0) {
        printf("Process %d completed.\n", (*schedule)->id);
        free(*schedule);
        *schedule = currentProcess;
      } else {
        *schedule = currentProcess;
      }
    } else {
      printf("All processes completed.\n");
      break;
    }
  }
  sleep(t);
}

int main() {
  Process** schedule = (Process**)malloc(MAX_SCHEDULE_SIZE * sizeof(Process));
  for (int i = 0; i < MAX_PROCESSES; i++) {
    addProcessToSchedule(createProcess(i + 1, rand() % 10), schedule);
  }

  roundRobin(schedule);

  return 0;
}