//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  time_t nextTaskTime = now + 60; // Assuming tasks run every 60 seconds

  while (head) {
    if (now >= nextTaskTime && head->priority == 1) {
      printf("%s has started!\n", head->name);
      nextTaskTime = now + 60;
    } else if (now >= nextTaskTime) {
      nextTaskTime = now + 60;
    }
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  insertTask(&head, "Task 1", 1);
  insertTask(&head, "Task 2", 2);
  insertTask(&head, "Task 3", 1);
  insertTask(&head, "Task 4", 2);

  scheduleTasks(head);

  return 0;
}