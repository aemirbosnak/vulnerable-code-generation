//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
  int process_id;
  int arrival_time;
  int service_time;
  struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
  Process* process = (Process*)malloc(sizeof(Process));
  process->process_id = id;
  process->arrival_time = arrivalTime;
  process->service_time = serviceTime;
  process->next = NULL;
  return process;
}

void addProcess(Process* head, int id, int arrivalTime, int serviceTime) {
  Process* process = createProcess(id, arrivalTime, serviceTime);
  if (head == NULL) {
    head = process;
  } else {
    process->next = head;
    head = process;
  }
}

void simulate() {
  Process* head = NULL;
  addProcess(head, 1, 0, 5);
  addProcess(head, 2, 2, 4);
  addProcess(head, 3, 4, 3);
  addProcess(head, 4, 6, 2);
  addProcess(head, 5, 8, 1);

  // Round Robin Scheduling Algorithm
  int current_time = 0;
  Process* current_process = head;

  while (current_process) {
    if (current_time >= current_process->arrival_time) {
      printf("Process %d is being serviced...\n", current_process->process_id);
      current_time += current_process->service_time;
      printf("Process %d is completed.\n", current_process->process_id);
      current_process = current_process->next;
    } else {
      current_time++;
    }
  }

  printf("All processes are completed.\n");
}

int main() {
  simulate();
  return 0;
}