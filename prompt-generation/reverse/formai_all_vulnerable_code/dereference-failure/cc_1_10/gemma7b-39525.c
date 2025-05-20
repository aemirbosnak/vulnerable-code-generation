//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int process_id;
  char name[20];
  int burst_time;
  int remaining_time;
  struct Process* next;
} Process;

Process* head = NULL;

void addProcess(int process_id, char* name, int burst_time) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  newProcess->process_id = process_id;
  strcpy(newProcess->name, name);
  newProcess->burst_time = burst_time;
  newProcess->remaining_time = burst_time;
  newProcess->next = NULL;

  if (head == NULL) {
    head = newProcess;
  } else {
    Process* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newProcess;
  }
}

void schedule() {
  Process* currentProcess = head;

  if (currentProcess == NULL) {
    return;
  }

  printf("Process ID: %d, Name: %s, Remaining Time: %d\n",
    currentProcess->process_id, currentProcess->name, currentProcess->remaining_time);

  currentProcess->remaining_time--;

  if (currentProcess->remaining_time == 0) {
    printf("Process ID: %d, Name: %s, Completed\n",
      currentProcess->process_id, currentProcess->name);
    free(currentProcess);
    currentProcess = NULL;
  } else {
    schedule();
  }
}

int main() {
  addProcess(1, "Process A", 5);
  addProcess(2, "Process B", 3);
  addProcess(3, "Process C", 2);
  addProcess(4, "Process D", 4);
  addProcess(5, "Process E", 3);

  schedule();

  return 0;
}