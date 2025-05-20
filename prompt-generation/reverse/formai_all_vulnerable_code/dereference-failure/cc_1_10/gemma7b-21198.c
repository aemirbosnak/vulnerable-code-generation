//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int estimated_time;
  struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->estimated_time = time;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (currentTask->estimated_time - now >= 0) {
      printf("Starting task: %s\n", currentTask->name);
      sleep(currentTask->estimated_time);
      printf("Finished task: %s\n", currentTask->name);
    }
    currentTask = currentTask->next;
  }
}

int main() {
  Task* head = NULL;

  insertTask(&head, "Clean the kitchen", 3, 20);
  insertTask(&head, "Do laundry", 2, 40);
  insertTask(&head, "Buy groceries", 1, 30);

  scheduleTasks(head);

  return 0;
}