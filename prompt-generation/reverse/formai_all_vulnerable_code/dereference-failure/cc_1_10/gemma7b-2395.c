//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int estimated_time;
  struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, int estimated_time) {
  Task* new_task = (Task*)malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->estimated_time = estimated_time;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void print_tasks(Task* head) {
  while (head) {
    printf("%s (priority %d, estimated time %d)\n", head->name, head->priority, head->estimated_time);
    head = head->next;
  }
}

void schedule_tasks(Task* head) {
  time_t now = time(NULL);
  for (Task* task = head; task; task = task->next) {
    if (task->estimated_time - now >= 0) {
      printf("Starting task: %s\n", task->name);
      sleep(task->estimated_time);
    }
  }
}

int main() {
  Task* head = NULL;
  add_task(&head, "Task 1", 1, 5);
  add_task(&head, "Task 2", 3, 2);
  add_task(&head, "Task 3", 2, 4);
  add_task(&head, "Task 4", 4, 3);

  print_tasks(head);
  schedule_tasks(head);

  return 0;
}