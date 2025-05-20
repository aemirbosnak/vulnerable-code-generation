//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NR_PROC 5
#define MAX_TIME 10

struct proc {
  int id;
  int arrival_time;
  int burst_time;
  int remaining_time;
  struct proc* next;
};

void roundrobin(struct proc* ready_queue)
{
  struct proc* current_proc = ready_queue;
  while (current_proc)
  {
    printf("Proc %d is running\n", current_proc->id);
    current_proc->remaining_time--;
    if (current_proc->remaining_time == 0)
    {
      printf("Proc %d has finished\n", current_proc->id);
      struct proc* next_proc = current_proc->next;
      free(current_proc);
      current_proc = next_proc;
    }
  }
}

int main()
{
  struct proc* ready_queue = NULL;
  for (int i = 0; i < NR_PROC; i++)
  {
    struct proc* new_proc = (struct proc*)malloc(sizeof(struct proc));
    new_proc->id = i + 1;
    new_proc->arrival_time = rand() % MAX_TIME;
    new_proc->burst_time = rand() % MAX_TIME;
    new_proc->remaining_time = new_proc->burst_time;
    new_proc->next = ready_queue;
    ready_queue = new_proc;
  }

  roundrobin(ready_queue);

  return 0;
}