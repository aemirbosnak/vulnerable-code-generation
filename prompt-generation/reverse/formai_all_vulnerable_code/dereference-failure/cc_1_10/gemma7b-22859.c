//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TASK_STATE_ACTIVE 1
#define TASK_STATE_INACTIVE 0

typedef struct Task {
  char name[20];
  int state;
  int delay;
  struct Task* next;
} Task;

Task* task_head = NULL;

void add_task(char* name, int delay) {
  Task* new_task = (Task*)malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->state = TASK_STATE_ACTIVE;
  new_task->delay = delay;
  new_task->next = NULL;

  if (task_head == NULL) {
    task_head = new_task;
  } else {
    task_head->next = new_task;
  }
}

void scheduler() {
  Task* current_task = task_head;

  while (current_task) {
    if (current_task->state == TASK_STATE_ACTIVE) {
      printf("Executing task: %s\n", current_task->name);
      sleep(current_task->delay);
      current_task->state = TASK_STATE_INACTIVE;
    }
    current_task = current_task->next;
  }
}

int main() {
  add_task("Task 1", 5);
  add_task("Task 2", 3);
  add_task("Task 3", 2);

  scheduler();

  return 0;
}