//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
  int process_id;
  int arrival_time;
  int burst_time;
  struct Process* next;
} Process;

void schedule_process(Process* head) {
  Process* current = head;
  while (current) {
    // Calculate remaining time
    int remaining_time = current->burst_time - 1;
    // If remaining time is less than or equal to quantum, execute process
    if (remaining_time <= 2) {
      printf("Process %d completed.\n", current->process_id);
      current->burst_time = 0;
    } else {
      // Update remaining time
      current->burst_time = remaining_time;
    }
    current = current->next;
  }
}

int main() {
  Process* head = NULL;

  // Create a few processes
  Process* process1 = malloc(sizeof(Process));
  process1->process_id = 1;
  process1->arrival_time = 0;
  process1->burst_time = 5;

  Process* process2 = malloc(sizeof(Process));
  process2->process_id = 2;
  process2->arrival_time = 2;
  process2->burst_time = 3;

  Process* process3 = malloc(sizeof(Process));
  process3->process_id = 3;
  process3->arrival_time = 4;
  process3->burst_time = 4;

  // Link the processes together
  process1->next = process2;
  process2->next = process3;

  // Schedule the processes
  schedule_process(head);

  return 0;
}