//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define TASK_DELAY_MIN 1
#define TASK_DELAY_MAX 5

typedef struct Task {
  char name[20];
  int delay;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int delay) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->delay = delay;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    head->next = newTask;
  }
}

void scheduleTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (now >= currentTask->delay) {
      printf("Executing task: %s\n", currentTask->name);
      currentTask->delay += TASK_DELAY_MIN;
    } else {
      break;
    }
  }

  scheduleTasks();
}

int main() {
  addTask("Task 1", 3);
  addTask("Task 2", 4);
  addTask("Task 3", 2);
  addTask("Task 4", 5);

  scheduleTasks();

  return 0;
}