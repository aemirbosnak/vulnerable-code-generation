//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int duration;
  struct Task* next;
} Task;

void insertTask(Task** head, char* name, int duration) {
  Task* newTask = malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  time_t nextTaskTime = now + head->duration;

  while (head) {
    if (now >= nextTaskTime) {
      printf("Task: %s completed.\n", head->name);
      nextTaskTime = now + head->duration;
    } else {
      printf("Next task: %s in %d seconds.\n", head->name, (int)(nextTaskTime - now));
    }
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  insertTask(&head, "Wake up", 60);
  insertTask(&head, "Breakfast", 30);
  insertTask(&head, "Work", 120);
  insertTask(&head, "Lunch", 60);
  insertTask(&head, "Sleep", 180);

  scheduleTasks(head);

  return 0;
}