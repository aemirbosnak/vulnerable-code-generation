//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct task* next;
} task;

task* create_task(char* name, int priority, time_t start_time, time_t end_time) {
  task* new_task = (task*)malloc(sizeof(task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->end_time = end_time;
  new_task->next = NULL;
  return new_task;
}

void add_task(task** head, char* name, int priority, time_t start_time, time_t end_time) {
  task* new_task = create_task(name, priority, start_time, end_time);
  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void print_tasks(task* head) {
  while (head) {
    printf("%s (Priority: %d) - Start: %s, End: %s\n", head->name, head->priority,
        strftime(NULL, 0, "%H:%M:%S", localtime(&head->start_time)),
        strftime(NULL, 0, "%H:%M:%S", localtime(&head->end_time)));
    head = head->next;
  }
}

int main() {
  task* tasks = NULL;
  add_task(&tasks, "Task 1", 1, time(NULL) + 3600, time(NULL) + 3600 + 3600);
  add_task(&tasks, "Task 2", 2, time(NULL) + 1800, time(NULL) + 1800 + 1800);
  add_task(&tasks, "Task 3", 3, time(NULL) + 600, time(NULL) + 600 + 600);

  print_tasks(tasks);

  return 0;
}