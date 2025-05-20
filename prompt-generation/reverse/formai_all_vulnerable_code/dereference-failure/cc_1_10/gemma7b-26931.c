//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4

typedef struct Process {
  int id;
  int burst_time;
  struct Process* next;
} Process;

void roundrobin(Process* head) {
  Process* current = head;
  while (current) {
    printf("Process %d is running...\n", current->id);
    current->burst_time--;
    if (current->burst_time == 0) {
      current = current->next;
    }
  }
}

int main() {
  Process* head = NULL;
  Process* process1 = malloc(sizeof(Process));
  process1->id = 1;
  process1->burst_time = 5;
  process1->next = NULL;
  head = process1;

  Process* process2 = malloc(sizeof(Process));
  process2->id = 2;
  process2->burst_time = 3;
  process2->next = NULL;
  head->next = process2;

  Process* process3 = malloc(sizeof(Process));
  process3->id = 3;
  process3->burst_time = 4;
  process3->next = NULL;
  process2->next = process3;

  Process* process4 = malloc(sizeof(Process));
  process4->id = 4;
  process4->burst_time = 2;
  process3->next = process4;

  roundrobin(head);

  return 0;
}