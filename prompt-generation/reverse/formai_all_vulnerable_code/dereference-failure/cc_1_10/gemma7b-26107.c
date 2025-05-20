//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char *name;
  int priority;
  struct Task *next;
} Task;

Task *scheduler_head = NULL;

void add_task(char *name, int priority)
{
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
  new_task->priority = priority;
  new_task->next = NULL;

  if (scheduler_head == NULL)
  {
    scheduler_head = new_task;
  }
  else
  {
    Task *current = scheduler_head;
    Task *previous = NULL;

    while (current)
    {
      if (new_task->priority < current->priority)
      {
        previous = current;
        current = current->next;
      }
    }

    if (previous)
    {
      previous->next = new_task;
    }
    else
    {
      scheduler_head = new_task;
    }
  }
}

void run_scheduler()
{
  while (scheduler_head)
  {
    Task *current = scheduler_head;
    int time_to_sleep = 1000 / current->priority;

    printf("Running task: %s\n", current->name);
    sleep(time_to_sleep);

    free(current);
    scheduler_head = scheduler_head->next;
  }
}

int main()
{
  add_task("Task 1", 1);
  add_task("Task 2", 3);
  add_task("Task 3", 2);

  run_scheduler();

  return 0;
}