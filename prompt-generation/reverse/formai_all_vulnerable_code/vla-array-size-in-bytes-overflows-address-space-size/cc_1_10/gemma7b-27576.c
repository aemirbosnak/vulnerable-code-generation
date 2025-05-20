//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of processes
#define MAX_PROCESSES 5

// Define the scheduling algorithm
void roundRobin(int processes, int *queue, int *quantum) {
  int i, j, currentProcess = 0, timeQuantum = *quantum;
  srand(time(NULL));

  // Simulate the processes
  for (i = 0; i < processes; i++) {
    queue[i] = rand() % 10 + 1;
  }

  // Allocate the time quantum
  for (j = 0; j < processes; j++) {
    if (queue[j] > timeQuantum) {
      queue[j] = timeQuantum;
    }
  }

  // Round robin schedule
  while (currentProcess < processes) {
    timeQuantum = queue[currentProcess];
    printf("Process %d is running for %d cycles\n", currentProcess, timeQuantum);
    currentProcess++;
    timeQuantum--;
  }

  // Print the completion of all processes
  printf("All processes have completed\n");
}

int main() {
  int processes, quantum;

  // Get the number of processes
  printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
  scanf("%d", &processes);

  // Get the time quantum
  printf("Enter the time quantum: ");
  scanf("%d", &quantum);

  // Create the process queue
  int queue[processes];

  // Round robin scheduling
  roundRobin(processes, queue, &quantum);

  return 0;
}