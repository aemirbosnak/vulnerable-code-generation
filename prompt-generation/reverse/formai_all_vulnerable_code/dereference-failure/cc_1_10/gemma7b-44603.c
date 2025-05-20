//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

struct Task {
  char name[20];
  int duration;
  struct Task* next;
};

void addTask(struct Task** head, char* name, int duration) {
  struct Task* newTask = malloc(sizeof(struct Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(struct Task* head) {
  time_t now = time(NULL);
  struct Task* currentTask = head;

  while (currentTask) {
    if (currentTask->duration - now >= 0) {
      printf("Starting task: %s\n", currentTask->name);
      sleep(currentTask->duration);
      printf("Finished task: %s\n", currentTask->name);
    }
    currentTask = currentTask->next;
  }
}

int main() {
  struct Task* head = NULL;

  addTask(&head, "Task 1", 10);
  addTask(&head, "Task 2", 5);
  addTask(&head, "Task 3", 15);
  addTask(&head, "Task 4", 20);
  addTask(&head, "Task 5", 25);

  scheduleTasks(head);

  return 0;
}