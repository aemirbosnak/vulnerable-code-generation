//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSORS 4
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int id;
  int arrivalTime;
  int serviceTime;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->id = id;
  process->arrivalTime = arrivalTime;
  process->serviceTime = serviceTime;
  process->next = NULL;
  return process;
}

void scheduleProcesses(Process* head) {
  // Create a round robin schedule
  int i = 0;
  Process* currentProcess = head;
  while (currentProcess) {
    // Simulate preemption
    if (i % MAX_SCHEDULE_SIZE == 0) {
      printf("Preemption: Process %d is preempted.\n", currentProcess->id);
    }
    // Execute process
    printf("Process %d is running.\n", currentProcess->id);
    currentProcess->arrivalTime += currentProcess->serviceTime;
    currentProcess = currentProcess->next;
    i++;
  }

  // Print the schedule
  printf("Schedule complete.\n");
}

int main() {
  // Create a list of processes
  Process* head = createProcess(1, 0, 5);
  head = createProcess(2, 2, 3);
  head = createProcess(3, 4, 2);
  head = createProcess(4, 6, 4);

  // Schedule the processes
  scheduleProcesses(head);

  return 0;
}