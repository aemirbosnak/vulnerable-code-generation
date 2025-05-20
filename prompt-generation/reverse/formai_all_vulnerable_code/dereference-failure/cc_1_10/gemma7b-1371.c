//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int time_slice;
  struct Task* next;
} Task;

Task* task_create(char* name, int priority, int time_slice) {
  Task* new_task = (Task*)malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->time_slice = time_slice;
  new_task->next = NULL;
  return new_task;
}

void task_add(Task* head, Task* new_task) {
  if (head == NULL) {
    head = new_task;
  } else {
    new_task->next = head;
    head = new_task;
  }
}

void task_scheduler(Task* head) {
  time_t now = time(NULL);
  Task* current_task = head;

  while (current_task) {
    if (now >= current_task->time_slice) {
      printf("Executing task: %s\n", current_task->name);
      sleep(current_task->time_slice);
      current_task->time_slice = time(NULL) + current_task->time_slice;
    }
    current_task = current_task->next;
  }
}

int main() {
  Task* head = NULL;
  task_add(head, task_create("Task 1", 1, 5));
  task_add(head, task_create("Task 2", 2, 3));
  task_add(head, task_create("Task 3", 3, 2));

  task_scheduler(head);

  return 0;
}