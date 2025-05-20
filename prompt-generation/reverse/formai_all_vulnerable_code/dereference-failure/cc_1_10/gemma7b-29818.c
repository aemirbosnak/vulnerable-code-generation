//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSORS 4
#define MAX_INSTRUCTIONS 10

typedef struct process {
  int id;
  int instructions;
  struct process* next;
} process;

process* head = NULL;

void schedule() {
  process* current = head;
  while (current) {
    printf("Process %d is running...\n", current->id);
    current->instructions--;
    if (current->instructions == 0) {
      process* next = current->next;
      free(current);
      current = next;
    }
  }
}

int main() {
  // Create a few processes
  process* p1 = malloc(sizeof(process));
  p1->id = 1;
  p1->instructions = MAX_INSTRUCTIONS;
  head = p1;

  process* p2 = malloc(sizeof(process));
  p2->id = 2;
  p2->instructions = MAX_INSTRUCTIONS / 2;
  p1->next = p2;

  process* p3 = malloc(sizeof(process));
  p3->id = 3;
  p3->instructions = MAX_INSTRUCTIONS / 3;
  p2->next = p3;

  process* p4 = malloc(sizeof(process));
  p4->id = 4;
  p4->instructions = MAX_INSTRUCTIONS / 4;
  p3->next = p4;

  // Schedule the processes
  schedule();

  return 0;
}