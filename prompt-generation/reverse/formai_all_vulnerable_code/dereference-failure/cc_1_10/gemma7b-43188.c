//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  int estimated_time;
  struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int estimated_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->estimated_time = estimated_time;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  int i = 0;

  for (Task* currentTask = head; currentTask; currentTask = currentTask->next) {
    if (currentTask->estimated_time - now >= 0) {
      printf("%s (%d) will run in %d minutes\n", currentTask->name, currentTask->priority, (currentTask->estimated_time - now) / 60);
      i++;
    }
  }

  printf("Total tasks to run: %d\n", i);
}

int main() {
  Task* head = NULL;

  insertTask(&head, "Task 1", 1, 30);
  insertTask(&head, "Task 2", 2, 60);
  insertTask(&head, "Task 3", 3, 90);
  insertTask(&head, "Task 4", 4, 120);

  scheduleTasks(head);

  return 0;
}