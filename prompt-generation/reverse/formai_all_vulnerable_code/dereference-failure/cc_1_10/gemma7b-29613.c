//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_TASKS 5

struct task_t {
  char name[20];
  int priority;
  int time_slot;
  struct task_t* next;
};

struct task_t* head = NULL;

void add_task(char* name, int priority, int time_slot) {
  struct task_t* new_task = malloc(sizeof(struct task_t));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->time_slot = time_slot;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    struct task_t* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_task;
  }
}

void schedule() {
  time_t now = time(NULL);
  struct task_t* current = head;

  while (current) {
    if (current->time_slot == now) {
      printf("%s is running...\n", current->name);
      sleep(1);
    }
    current = current->next;
  }
}

int main() {
  add_task("Task 1", 1, 10);
  add_task("Task 2", 2, 12);
  add_task("Task 3", 3, 14);
  add_task("Task 4", 2, 16);
  add_task("Task 5", 1, 18);

  schedule();

  return 0;
}