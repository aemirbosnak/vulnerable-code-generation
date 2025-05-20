//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int priority, time_t start_time, time_t end_time) {
  Task* new_task = (Task*)malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->end_time = end_time;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    Task* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_task;
  }
}

void print_tasks() {
  Task* current = head;
  while (current) {
    printf("%s (priority: %d), start: %s, end: %s\n", current->name, current->priority, current->start_time, current->end_time);
    current = current->next;
  }
}

int main() {
  add_task("Task 1", 1, time(NULL), time(NULL) + 60);
  add_task("Task 2", 2, time(NULL) + 30, time(NULL) + 60);
  add_task("Task 3", 3, time(NULL) + 60, time(NULL) + 90);

  print_tasks();

  return 0;
}