//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSORS 8

typedef struct Process {
  int id;
  int arrivalTime;
  int serviceTime;
  struct Process* next;
} Process;

void schedule(Process* head) {
  time_t currentTime = time(NULL);
  Process* currentProcess = head;

  while (currentProcess) {
    if (currentTime >= currentProcess->arrivalTime) {
      printf("Process %d is running...\n", currentProcess->id);
      currentTime += currentProcess->serviceTime;
      currentProcess = currentProcess->next;
    } else {
      printf("Waiting for process %d...\n", currentProcess->id);
      currentProcess = currentProcess->next;
    }
  }
}

int main() {
  Process* head = NULL;

  // Create some processes
  Process* process1 = malloc(sizeof(Process));
  process1->id = 1;
  process1->arrivalTime = 0;
  process1->serviceTime = 5;

  Process* process2 = malloc(sizeof(Process));
  process2->id = 2;
  process2->arrivalTime = 2;
  process2->serviceTime = 3;

  Process* process3 = malloc(sizeof(Process));
  process3->id = 3;
  process3->arrivalTime = 4;
  process3->serviceTime = 4;

  // Link the processes together
  process1->next = process2;
  process2->next = process3;

  // Schedule the processes
  schedule(head);

  return 0;
}