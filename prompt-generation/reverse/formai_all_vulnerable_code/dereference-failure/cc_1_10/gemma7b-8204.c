//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_QUEUE_SIZE 10

typedef struct Process {
  int id;
  char name[20];
  int arrival_time;
  int service_time;
  int completion_time;
  int waiting_time;
  struct Process* next;
} Process;

void roundRobin(Process* head) {
  Process* current = head;
  while (current) {
    printf("Process %d: ", current->id);
    printf("Arrival time: %d, Service time: %d, Completion time: %d, Waiting time: %d\n",
       current->arrival_time, current->service_time, current->completion_time, current->waiting_time);
    current = current->next;
  }
}

int main() {
  Process* head = NULL;
  Process* tail = NULL;

  // Create a few processes
  Process* process1 = malloc(sizeof(Process));
  process1->id = 1;
  strcpy(process1->name, "Process A");
  process1->arrival_time = 0;
  process1->service_time = 5;

  Process* process2 = malloc(sizeof(Process));
  process2->id = 2;
  strcpy(process2->name, "Process B");
  process2->arrival_time = 2;
  process2->service_time = 3;

  Process* process3 = malloc(sizeof(Process));
  process3->id = 3;
  strcpy(process3->name, "Process C");
  process3->arrival_time = 4;
  process3->service_time = 2;

  // Add the processes to the queue
  if (head == NULL) {
    head = process1;
    tail = process1;
  } else {
    tail->next = process1;
    tail = process1;
  }
  tail->next = process2;
  tail = process2;
  tail->next = process3;
  tail = process3;

  // Round robin scheduling
  roundRobin(head);

  return 0;
}