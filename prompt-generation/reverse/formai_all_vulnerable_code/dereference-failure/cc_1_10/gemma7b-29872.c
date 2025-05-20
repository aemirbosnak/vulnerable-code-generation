//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 5

struct process {
  int id;
  int burst_time;
  int waiting_time;
  int turn_around_time;
  struct process* next;
};

void roundrobin(struct process* head) {
  struct process* current = head;
  struct process* next = NULL;
  int time = 0;

  while (current) {
    if (next) {
      next = current->next;
    } else {
      next = head;
    }

    time += current->burst_time;
    current->waiting_time = time - current->burst_time;
    current->turn_around_time = time;

    current = next;
  }
}

int main() {
  struct process* head = NULL;

  // Create some processes
  struct process* process1 = malloc(sizeof(struct process));
  process1->id = 1;
  process1->burst_time = 5;

  struct process* process2 = malloc(sizeof(struct process));
  process2->id = 2;
  process2->burst_time = 3;

  struct process* process3 = malloc(sizeof(struct process));
  process3->id = 3;
  process3->burst_time = 8;

  struct process* process4 = malloc(sizeof(struct process));
  process4->id = 4;
  process4->burst_time = 2;

  struct process* process5 = malloc(sizeof(struct process));
  process5->id = 5;
  process5->burst_time = 6;

  // Link processes together
  process1->next = process2;
  process2->next = process3;
  process3->next = process4;
  process4->next = process5;
  process5->next = head;

  // Round robin scheduling
  roundrobin(process1);

  // Print results
  printf("Process ID\tWaiting Time\tTurnaround Time\n");
  for (struct process* current = process1; current; current = current->next) {
    printf("%d\t\t%d\t\t%d\n", current->id, current->waiting_time, current->turn_around_time);
  }

  return 0;
}