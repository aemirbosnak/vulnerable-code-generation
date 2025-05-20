//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
  int id;
  char name[20];
  int burst_time;
  int waiting_time;
  struct Process* next;
} Process;

void schedule_process(Process* head) {
  time_t start_time = time(NULL);
  Process* current = head;
  while (current) {
    current->waiting_time++;
    printf("Process %d is waiting for %d seconds...\n", current->id, current->waiting_time);
    sleep(current->burst_time);
    current->waiting_time--;
    printf("Process %d finished execution.\n", current->id);
    current = current->next;
  }
  time_t end_time = time(NULL);
  printf("Total time elapsed: %d seconds\n", end_time - start_time);
}

int main() {
  Process* head = NULL;
  Process* tail = NULL;

  // Create a few processes
  Process* process1 = malloc(sizeof(Process));
  process1->id = 1;
  strcpy(process1->name, "Process A");
  process1->burst_time = 5;

  Process* process2 = malloc(sizeof(Process));
  process2->id = 2;
  strcpy(process2->name, "Process B");
  process2->burst_time = 3;

  Process* process3 = malloc(sizeof(Process));
  process3->id = 3;
  strcpy(process3->name, "Process C");
  process3->burst_time = 2;

  Process* process4 = malloc(sizeof(Process));
  process4->id = 4;
  strcpy(process4->name, "Process D");
  process4->burst_time = 4;

  // Add processes to the queue
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
  tail->next = process4;
  tail = process4;

  schedule_process(head);

  return 0;
}