//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
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

void insert_task(Task** head, Task* new_task) {
  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
    *head = new_task;
  }
}

void print_tasks(Task* head) {
  while (head) {
    printf("%s (priority: %d), start: %ld, end: %ld\n", head->name, head->priority, head->start_time, head->end_time);
    head = head->next;
  }
}

int main() {
  Task* tasks = NULL;
  time_t now = time(NULL);

  insert_task(&tasks, (Task*)malloc(sizeof(Task)));
  strcpy(tasks->name, "Task 1");
  tasks->priority = 1;
  tasks->start_time = now + 60;
  tasks->end_time = now + 90;

  insert_task(&tasks, (Task*)malloc(sizeof(Task)));
  strcpy(tasks->name, "Task 2");
  tasks->priority = 3;
  tasks->start_time = now + 30;
  tasks->end_time = now + 60;

  insert_task(&tasks, (Task*)malloc(sizeof(Task)));
  strcpy(tasks->name, "Task 3");
  tasks->priority = 2;
  tasks->start_time = now + 15;
  tasks->end_time = now + 45;

  print_tasks(tasks);

  return 0;
}