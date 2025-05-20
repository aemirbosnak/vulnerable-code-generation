//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 5

typedef struct Task {
  char name[20];
  int priority;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task* head, char* name, int priority) {
  Task* newTask = createTask(name, priority);
  if (head == NULL) {
    head = newTask;
  } else {
    Task* currentTask = head;
    Task* previousTask = NULL;
    while (currentTask) {
      if (newTask->priority < currentTask->priority) {
        previousTask = currentTask;
        currentTask = currentTask->next;
      } else {
        break;
      }
    }
    if (previousTask) {
      previousTask->next = newTask;
    } else {
      head = newTask;
    }
  }
}

void printTasks(Task* head) {
  while (head) {
    printf("%s (priority: %d)\n", head->name, head->priority);
    head = head->next;
  }
}

int main() {
  Task* scheduler = NULL;
  addTask(scheduler, "Task 1", 1);
  addTask(scheduler, "Task 2", 3);
  addTask(scheduler, "Task 3", 2);
  addTask(scheduler, "Task 4", 4);
  addTask(scheduler, "Task 5", 5);

  printTasks(scheduler);

  return 0;
}