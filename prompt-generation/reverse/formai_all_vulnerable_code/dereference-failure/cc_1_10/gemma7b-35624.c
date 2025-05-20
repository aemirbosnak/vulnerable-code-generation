//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority) {
  Task* newTask = malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    Task* currentTask = *head;
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
      *head = newTask;
    }
  }
}

void printTasks(Task* head) {
  while (head) {
    printf("%s (priority %d)\n", head->name, head->priority);
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  insertTask(&head, "Task 1", 1);
  insertTask(&head, "Task 2", 3);
  insertTask(&head, "Task 3", 2);

  printTasks(head);

  return 0;
}