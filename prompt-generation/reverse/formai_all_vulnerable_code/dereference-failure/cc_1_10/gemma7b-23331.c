//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
  char name[20];
  int priority;
  struct task* next;
} task;

void insertTask(task** head, char* name, int priority) {
  task* newTask = (task*)malloc(sizeof(task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(task* head) {
  time_t now = time(NULL);
  time_t nextTaskTime = now + 1;
  task* currentTask = head;

  while (currentTask) {
    if (currentTask->priority == 1 && now >= nextTaskTime) {
      printf("Starting task: %s\n", currentTask->name);
      nextTaskTime = now + currentTask->priority;
    } else if (currentTask->priority == 2 && now >= nextTaskTime) {
      printf("Starting task: %s\n", currentTask->name);
      nextTaskTime = now + currentTask->priority;
    } else if (currentTask->priority == 3 && now >= nextTaskTime) {
      printf("Starting task: %s\n", currentTask->name);
      nextTaskTime = now + currentTask->priority;
    }
    currentTask = currentTask->next;
  }
}

int main() {
  task* head = NULL;

  insertTask(&head, "Laundry", 1);
  insertTask(&head, "Shopping", 2);
  insertTask(&head, "Cooking", 3);
  insertTask(&head, "Work", 1);

  scheduleTasks(head);

  return 0;
}