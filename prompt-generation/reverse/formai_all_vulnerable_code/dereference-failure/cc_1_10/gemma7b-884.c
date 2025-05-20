//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

struct process {
  int id;
  int arrivalTime;
  int serviceTime;
  int completionTime;
  struct process* next;
};

void simulate() {
  struct process* head = NULL;
  struct process* tail = NULL;

  // Create a number of processes
  for (int i = 0; i < MAX_PROCESSES; i++) {
    struct process* newProcess = malloc(sizeof(struct process));
    newProcess->id = i + 1;
    newProcess->arrivalTime = rand() % MAX_TIME;
    newProcess->serviceTime = rand() % MAX_TIME;

    if (head == NULL) {
      head = newProcess;
      tail = newProcess;
    } else {
      tail->next = newProcess;
      tail = newProcess;
    }
  }

  // Simulate the CPU scheduling algorithm
  struct process* currentProcess = head;
  time_t startTime = time(NULL);
  while (!currentProcess->completionTime) {
    // Calculate the completion time for the current process
    currentProcess->completionTime = startTime + currentProcess->arrivalTime + currentProcess->serviceTime;

    // Move the current process to the completed processes list
    struct process* nextProcess = currentProcess->next;
    free(currentProcess);
    currentProcess = nextProcess;

    // Update the start time for the next process
    startTime = time(NULL);
  }

  // Print the completion times for each process
  printf("Process ID\tCompletion Time\n");
  for (struct process* process = head; process; process++) {
    printf("%d\t\t%d\n", process->id, process->completionTime);
  }
}

int main() {
  simulate();

  return 0;
}