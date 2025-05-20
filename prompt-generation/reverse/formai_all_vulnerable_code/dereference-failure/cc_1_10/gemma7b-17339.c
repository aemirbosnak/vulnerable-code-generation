//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULE 10

typedef struct Task {
  char name[20];
  int priority;
  int executionTime;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int executionTime) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->executionTime = executionTime;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task** head, char* name, int priority, int executionTime) {
  Task* newTask = createTask(name, priority, executionTime);
  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  int i = 0;
  printf("Tasks scheduled:\n");
  for (head = head; head; head = head->next) {
    printf("%d. %s (Priority: %d, Execution Time: %d seconds)\n", i++, head->name, head->priority, head->executionTime);
  }
}

int main() {
  Task* head = NULL;

  addTask(&head, "Task 1", 1, 5);
  addTask(&head, "Task 2", 2, 3);
  addTask(&head, "Task 3", 1, 2);
  addTask(&head, "Task 4", 2, 4);

  scheduleTasks(head);

  return 0;
}