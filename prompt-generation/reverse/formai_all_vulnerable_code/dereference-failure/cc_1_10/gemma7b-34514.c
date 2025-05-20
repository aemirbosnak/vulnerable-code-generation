//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_TASKS 10

typedef struct task {
  char name[20];
  int priority;
  int state;
  struct task* next;
} task_t;

task_t* head = NULL;

void add_task(char* name, int priority) {
  task_t* new_task = malloc(sizeof(task_t));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->state = 0;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    task_t* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = new_task;
  }
}

void scheduler() {
  task_t* current = head;
  while (current) {
    if (current->state == 0) {
      printf("Executing task: %s\n", current->name);
      current->state = 1;
      sleep(current->priority);
      current->state = 0;
    }
    current = current->next;
  }
}

int main() {
  add_task("Task 1", 5);
  add_task("Task 2", 3);
  add_task("Task 3", 2);
  add_task("Task 4", 4);

  scheduler();

  return 0;
}