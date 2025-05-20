//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  time_t scheduled_time;
  struct Task* next;
} Task;

Task* head = NULL;

void schedule_task(char* name, int priority, time_t scheduled_time) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->scheduled_time = scheduled_time;
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

void print_schedule() {
  Task* current = head;
  while (current) {
    printf("Name: %s, Priority: %d, Scheduled Time: %ld\n", current->name, current->priority, current->scheduled_time);
    current = current->next;
  }
}

int main() {
  schedule_task("Task 1", 1, time(NULL) + 30);
  schedule_task("Task 2", 3, time(NULL) + 60);
  schedule_task("Task 3", 2, time(NULL) + 90);

  print_schedule();

  return 0;
}