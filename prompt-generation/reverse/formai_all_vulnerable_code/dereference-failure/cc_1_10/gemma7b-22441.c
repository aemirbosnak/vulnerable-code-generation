//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_PROCESS 10

typedef struct Process {
  int id;
  int arrivalTime;
  int processingTime;
  struct Process* next;
} Process;

void schedule(Process* head) {
  // Use round robin algorithm with preemption
  Process* currentProcess = head;
  int time = 0;
  while (currentProcess) {
    // Simulate time passage
    time++;
    if (time >= currentProcess->arrivalTime) {
      // Execute process for its duration
      time += currentProcess->processingTime;
      currentProcess->processingTime = 0;
    }

    // Rotate to the next process in the queue
    currentProcess = currentProcess->next;
  }
}

int main() {
  // Create a list of processes
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESS; i++) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = i;
    newProcess->arrivalTime = rand() % MAX_PROCESSORS;
    newProcess->processingTime = rand() % MAX_PROCESSORS;
    newProcess->next = head;
    head = newProcess;
  }

  // Schedule the processes
  schedule(head);

  // Print the completion times of each process
  for (Process* process = head; process; process = process->next) {
    printf("Process %d completed at time %d\n", process->id, time);
  }

  return 0;
}