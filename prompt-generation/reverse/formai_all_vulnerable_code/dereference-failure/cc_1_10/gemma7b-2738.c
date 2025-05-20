//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 8
#define MAX_INSTRUCTIONS 1000

typedef struct process {
  int id;
  int instructions;
  int state;
  struct process* next;
} process;

process* createProcess(int id, int instructions) {
  process* p = malloc(sizeof(process));
  p->id = id;
  p->instructions = instructions;
  p->state = 0;
  p->next = NULL;
  return p;
}

void schedule(process* head) {
  time_t t = time(NULL);
  process* current = head;
  while (current) {
    int time_spent = (int)time(NULL) - t;
    if (time_spent >= current->instructions) {
      current->state = 1;
      current = current->next;
    } else {
      current->state = 2;
    }
    t = time(NULL);
  }
}

int main() {
  process* head = createProcess(0, MAX_INSTRUCTIONS);
  head = createProcess(1, MAX_INSTRUCTIONS - 10);
  head = createProcess(2, MAX_INSTRUCTIONS - 20);
  head = createProcess(3, MAX_INSTRUCTIONS - 30);

  schedule(head);

  for (process* p = head; p; p = p->next) {
    printf("Process %d completed with state %d\n", p->id, p->state);
  }

  return 0;
}