//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority) {
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
  time_t nextTaskTime = now + 60;
  Task* currentTask = head;

  while (currentTask) {
    time_t taskTime = now + currentTask->priority;
    if (taskTime > nextTaskTime) {
      nextTaskTime = taskTime;
      printf("Executing task: %s\n", currentTask->name);
      currentTask = currentTask->next;
    } else {
      currentTask = currentTask->next;
    }
  }
}

int main() {
  Task* head = NULL;
  addTask(&head, "Wake up", 0);
  addTask(&head, "Breakfast", 1);
  addTask(&head, "Code", 2);
  addTask(&head, "Lunch", 3);
  addTask(&head, "Sleep", 4);

  scheduleTasks(head);

  return 0;
}