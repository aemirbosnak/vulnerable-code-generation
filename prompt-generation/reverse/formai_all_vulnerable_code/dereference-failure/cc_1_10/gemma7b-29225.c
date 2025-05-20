//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_DURATION 5

typedef struct Task {
  char name[20];
  int duration;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int duration) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* currentTask = head;
    while (currentTask->next != NULL) {
      currentTask = currentTask->next;
    }
    currentTask->next = newTask;
  }
}

void executeTasks() {
  Task* currentTask = head;
  while (currentTask) {
    printf("Executing task: %s\n", currentTask->name);
    sleep(currentTask->duration);
    currentTask = currentTask->next;
  }
}

int main() {
  addTask("Task 1", TASK_DURATION);
  addTask("Task 2", TASK_DURATION);
  addTask("Task 3", TASK_DURATION);

  executeTasks();

  return 0;
}