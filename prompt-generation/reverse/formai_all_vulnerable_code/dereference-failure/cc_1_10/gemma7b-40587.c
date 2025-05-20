//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

struct process {
  int id;
  int arrivalTime;
  int serviceTime;
  int completionTime;
  struct process* next;
};

void schedule(struct process** head) {
  // Round robin scheduling algorithm
  struct process* currentProcess = *head;
  struct process* nextProcess = NULL;
  int i = 0;

  while (currentProcess) {
    // Calculate the completion time for the current process
    currentProcess->completionTime = currentProcess->arrivalTime + currentProcess->serviceTime;

    // Insert the completed process into the completed list
    struct process* completedProcess = malloc(sizeof(struct process));
    completedProcess->id = currentProcess->id;
    completedProcess->arrivalTime = currentProcess->arrivalTime;
    completedProcess->serviceTime = currentProcess->serviceTime;
    completedProcess->completionTime = currentProcess->completionTime;
    completedProcess->next = NULL;

    // If the next process is not NULL, update the next process pointer
    if (nextProcess) {
      nextProcess->next = completedProcess;
    } else {
      *head = completedProcess;
    }

    // Move to the next process in the queue
    nextProcess = currentProcess->next;
    currentProcess->next = NULL;
    currentProcess = nextProcess;

    // Increment the round robin counter
    i++;

    // If the round robin counter reaches the maximum number of processes, reset the counter
    if (i == MAX_PROCESSES) {
      i = 0;
    }
  }
}

int main() {
  // Create a linked list of processes
  struct process* head = NULL;

  // Add some processes to the list
  struct process* process1 = malloc(sizeof(struct process));
  process1->id = 1;
  process1->arrivalTime = 0;
  process1->serviceTime = 5;
  process1->next = NULL;
  head = process1;

  struct process* process2 = malloc(sizeof(struct process));
  process2->id = 2;
  process2->arrivalTime = 2;
  process2->serviceTime = 3;
  process2->next = NULL;
  process1->next = process2;

  struct process* process3 = malloc(sizeof(struct process));
  process3->id = 3;
  process3->arrivalTime = 4;
  process3->serviceTime = 2;
  process3->next = NULL;
  process2->next = process3;

  // Schedule the processes
  schedule(&head);

  // Print the completion times of the processes
  struct process* currentProcess = head;
  while (currentProcess) {
    printf("Process %d completed at time %d\n", currentProcess->id, currentProcess->completionTime);
    currentProcess = currentProcess->next;
  }

  return 0;
}