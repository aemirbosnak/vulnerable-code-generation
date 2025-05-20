//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10

struct Process {
  int id;
  int burstTime;
  struct Process* next;
};

void simulateRoundRobin(struct Process* head) {
  time_t currentTime = time(NULL);
  struct Process* currentProcess = head;

  while (currentProcess) {
    int timeLeft = currentProcess->burstTime - (time(NULL) - currentTime);

    if (timeLeft > 0) {
      printf("Process %d is running...", currentProcess->id);
      sleep(timeLeft);
    } else {
      printf("Process %d has completed...", currentProcess->id);
      currentProcess = currentProcess->next;
    }

    currentTime = time(NULL);
  }
}

int main() {
  struct Process* head = NULL;
  for (int i = 0; i < MAX_PROCESSES; i++) {
    head = malloc(sizeof(struct Process));
    head->id = i + 1;
    head->burstTime = rand() % 10 + 1;
    head->next = NULL;

    if (head != NULL) {
      if (head->next == NULL) {
        head = head;
      } else {
        head->next = head;
      }
    }
  }

  simulateRoundRobin(head);

  return 0;
}