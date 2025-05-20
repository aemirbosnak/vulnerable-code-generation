//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SCHEDULER_MAX 10
#define TASK_MAX 5

typedef struct Task {
  char name[20];
  int priority;
  int time_slot;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int time_slot) {
  Task* task = malloc(sizeof(Task));
  strcpy(task->name, name);
  task->priority = priority;
  task->time_slot = time_slot;
  task->next = NULL;
  return task;
}

void addTask(Task* head, Task* newTask) {
  if (head == NULL) {
    head = newTask;
  } else {
    newTask->next = head;
    head = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  time_t next_slot = now + 60;
  while (head) {
    if (head->time_slot == next_slot) {
      printf("Executing task: %s\n", head->name);
      sleep(head->time_slot - now);
      now = time(NULL);
      next_slot = now + 60;
    }
    head = head->next;
  }
}

int main() {
  Task* head = NULL;
  addTask(head, createTask("Task 1", 1, 10));
  addTask(head, createTask("Task 2", 2, 20));
  addTask(head, createTask("Task 3", 1, 30));
  addTask(head, createTask("Task 4", 2, 40));
  addTask(head, createTask("Task 5", 1, 50));

  scheduleTasks(head);

  return 0;
}