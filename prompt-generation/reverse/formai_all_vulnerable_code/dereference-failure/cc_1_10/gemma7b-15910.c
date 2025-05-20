//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Decentralized Task Scheduler

struct Task {
  char name[50];
  int priority;
  struct Task* next;
};

struct Task* insertTask(struct Task* head, char* name, int priority) {
  struct Task* newTask = malloc(sizeof(struct Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    struct Task* currentTask = head;
    while (currentTask->next) {
      currentTask = currentTask->next;
    }
    currentTask->next = newTask;
  }

  return head;
}

void executeTasks(struct Task* head) {
  struct Task* currentTask = head;
  while (currentTask) {
    printf("Executing task: %s\n", currentTask->name);
    sleep(currentTask->priority);
    currentTask = currentTask->next;
  }
}

int main() {
  struct Task* head = NULL;

  insertTask(head, "Task 1", 3);
  insertTask(head, "Task 2", 2);
  insertTask(head, "Task 3", 1);

  executeTasks(head);

  return 0;
}