//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int execution_time;
  int completion_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int executionTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = id;
  process->arrival_time = arrivalTime;
  process->execution_time = executionTime;
  process->completion_time = 0;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, int id, int arrivalTime, int executionTime) {
  Process* process = createProcess(id, arrivalTime, executionTime);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void simulate(Process* head) {
  int currentTime = 0;
  while (!head->completion_time) {
    int i = 0;
    Process* currentProcess = head;
    for (; i < MAX_PROCESSES && currentProcess; i++) {
      if (currentProcess->arrival_time <= currentTime && currentProcess->execution_time > 0) {
        currentProcess->execution_time--;
        currentTime++;
        if (currentProcess->execution_time == 0) {
          currentProcess->completion_time = currentTime;
        }
      }
      currentProcess = currentProcess->next;
    }
  }
}

int main() {
  Process* head = NULL;
  addProcess(head, 1, 0, 5);
  addProcess(head, 2, 2, 3);
  addProcess(head, 3, 4, 6);
  addProcess(head, 4, 6, 2);

  simulate(head);

  return 0;
}