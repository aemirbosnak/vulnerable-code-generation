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

Task* createTask(char* name, int priority, time_t start_time, time_t end_time) {
  Task* task = (Task*)malloc(sizeof(Task));
  strcpy(task->name, name);
  task->priority = priority;
  task->start_time = start_time;
  task->end_time = end_time;
  task->next = NULL;
  return task;
}

void addTask(Task* head, char* name, int priority, time_t start_time, time_t end_time) {
  Task* task = createTask(name, priority, start_time, end_time);
  if (head == NULL) {
    head = task;
  } else {
    task->next = head;
    head = task;
  }
}

void printTasks(Task* head) {
  while (head) {
    printf("Name: %s, Priority: %d, Start Time: %ld, End Time: %ld\n", head->name, head->priority, head->start_time, head->end_time);
    head = head->next;
  }
}

int main() {
  Task* head = NULL;
  addTask(head, "Task 1", 1, 10, 20);
  addTask(head, "Task 2", 2, 20, 30);
  addTask(head, "Task 3", 3, 30, 40);

  printTasks(head);

  return 0;
}