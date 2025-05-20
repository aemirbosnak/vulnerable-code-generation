//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct Process {
  int arrivalTime;
  int processingTime;
  struct Process* next;
} Process;

Process* createProcess(int arrivalTime, int processingTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->arrivalTime = arrivalTime;
  process->processingTime = processingTime;
  process->next = NULL;
  return process;
}

void simulate() {
  Process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    Process* process = createProcess(i, rand() % MAX_TIME);
    if (head == NULL) {
      head = process;
    } else {
      process->next = head;
      head = process;
    }
  }

  int time = 0;
  while (head) {
    if (time >= head->arrivalTime) {
      time += head->processingTime;
      printf("Process %d completed at time %d\n", head->arrivalTime, time);
      free(head);
      head = head->next;
    } else {
      time++;
    }
  }

  printf("All processes completed.\n");
}

int main() {
  simulate();
  return 0;
}