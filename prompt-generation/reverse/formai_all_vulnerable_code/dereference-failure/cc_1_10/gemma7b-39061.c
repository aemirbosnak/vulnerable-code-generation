//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

struct Process {
  int id;
  int burstTime;
  int waitingTime;
  int turnaroundTime;
  struct Process* next;
};

void schedule(struct Process* head) {
  struct Process* current = head;
  struct Process* next = NULL;
  int time = 0;

  while (current) {
    // Calculate the waiting time for the current process
    current->waitingTime = time - current->burstTime;

    // Update the turnaround time for the current process
    current->turnaroundTime = time + current->burstTime;

    // If the next process is not NULL, calculate the waiting time for the next process
    if (next) {
      next->waitingTime = time - next->burstTime;
    }

    // Increment the time
    time++;

    // If the current process is completed, move to the next process
    if (current->waitingTime == 0) {
      next = current->next;
      free(current);
      current = next;
    } else {
      current = current->next;
    }
  }

  // Print the results
  printf("Process ID\tWaiting Time\tTurnaround Time\n");
  for (current = head; current; current = current->next) {
    printf("%d\t\t%d\t\t%d\n", current->id, current->waitingTime, current->turnaroundTime);
  }
}

int main() {
  struct Process* head = NULL;

  // Create a list of processes
  for (int i = 0; i < MAX_PROCESS; i++) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->id = i + 1;
    newProcess->burstTime = rand() % 5 + 1;
    newProcess->waitingTime = 0;
    newProcess->turnaroundTime = 0;
    newProcess->next = head;
    head = newProcess;
  }

  // Schedule the processes
  schedule(head);

  return 0;
}