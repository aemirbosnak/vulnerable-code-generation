//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  newProcess->process_id = id;
  newProcess->arrival_time = arrivalTime;
  newProcess->service_time = serviceTime;
  newProcess->next = NULL;
  return newProcess;
}

void addProcess(Process* head, int id, int arrivalTime, int serviceTime) {
  Process* newProcess = createProcess(id, arrivalTime, serviceTime);
  if (head == NULL) {
    head = newProcess;
  } else {
    newProcess->next = head;
    head = newProcess;
  }
}

void printProcess(Process* head) {
  Process* currentProcess = head;
  while (currentProcess) {
    printf("Process ID: %d, Arrival Time: %d, Service Time: %d\n", currentProcess->process_id, currentProcess->arrival_time, currentProcess->service_time);
    currentProcess = currentProcess->next;
  }
}

void roundRobin(Process* head) {
  int quantum = 5;
  Process* currentProcess = head;
  while (currentProcess) {
    printf("Current Process: %d\n", currentProcess->process_id);
    sleep(quantum);
    currentProcess = currentProcess->next;
  }
}

int main() {
  Process* head = NULL;
  addProcess(head, 1, 0, 3);
  addProcess(head, 2, 2, 4);
  addProcess(head, 3, 4, 2);
  addProcess(head, 4, 6, 5);

  printProcess(head);

  roundRobin(head);

  return 0;
}