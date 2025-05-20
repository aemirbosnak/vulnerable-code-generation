//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_DELAY 1000

typedef struct Task {
  char name[20];
  int delay;
  struct Task* next;
} Task;

Task* createTask(char* name, int delay) {
  Task* task = (Task*)malloc(sizeof(Task));
  strcpy(task->name, name);
  task->delay = delay;
  task->next = NULL;
  return task;
}

void addTask(Task* head, char* name, int delay) {
  Task* newTask = createTask(name, delay);
  if (head == NULL) {
    head = newTask;
  } else {
    newTask->next = head;
    head = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  for (Task* task = head; task; task = task->next) {
    if (task->delay - now >= 0) {
      printf("Task: %s, Time Left: %d seconds\n", task->name, task->delay - now);
    }
  }
}

int main() {
  Task* head = NULL;
  addTask(head, "Task 1", TASK_DELAY);
  addTask(head, "Task 2", TASK_DELAY + 2000);
  addTask(head, "Task 3", TASK_DELAY + 4000);

  scheduleTasks(head);

  return 0;
}