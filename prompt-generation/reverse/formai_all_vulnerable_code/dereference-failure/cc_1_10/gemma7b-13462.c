//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULE 10

typedef struct task_t {
  char *name;
  int prio;
  int time_slice;
  struct task_t *next;
} task_t;

void insert_task(task_t **head, char *name, int prio, int time_slice)
{
  task_t *new_task = malloc(sizeof(task_t));
  new_task->name = strdup(name);
  new_task->prio = prio;
  new_task->time_slice = time_slice;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void schedule(task_t **head)
{
  task_t *current = *head;
  while (current) {
    sleep(current->time_slice);
    printf("%s is running\n", current->name);
    current = current->next;
  }
}

int main()
{
  task_t *head = NULL;
  insert_task(&head, "task1", 1, 5);
  insert_task(&head, "task2", 2, 3);
  insert_task(&head, "task3", 3, 2);
  insert_task(&head, "task4", 4, 4);

  schedule(&head);

  return 0;
}