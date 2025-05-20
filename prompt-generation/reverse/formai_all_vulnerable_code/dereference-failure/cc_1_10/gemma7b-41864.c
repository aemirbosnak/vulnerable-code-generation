//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 10
#define SCHEDULER_QUEUE_SIZE 20

typedef struct Process {
  int process_id;
  int cpu_burst_time;
  int waiting_time;
  int turn_around_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int burstTime) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  newProcess->process_id = id;
  newProcess->cpu_burst_time = burstTime;
  newProcess->waiting_time = 0;
  newProcess->turn_around_time = 0;
  newProcess->next = NULL;
  return newProcess;
}

void addProcessToQueue(Process* newProcess, Process** head) {
  if (*head == NULL) {
    *head = newProcess;
  } else {
    (*head)->next = newProcess;
    *head = newProcess;
  }
}

void roundRobin(Process** head) {
  int timeQuantum = 5;
  Process* currentProcess = *head;
  while (currentProcess) {
    if (currentProcess->cpu_burst_time > 0) {
      currentProcess->cpu_burst_time--;
    } else {
      currentProcess->waiting_time++;
      currentProcess = currentProcess->next;
    }
    sleep(timeQuantum);
  }
}

int main() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    addProcessToQueue(createProcess(i, rand() % 10), &head);
  }

  roundRobin(&head);

  for (Process* process = head; process; process = process->next) {
    printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", process->process_id, process->waiting_time, process->turn_around_time);
  }

  return 0;
}