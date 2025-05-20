//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
  char name[20];
  int priority;
  struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority) {
  Task* newTask = malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* current = head;
    Task* previous = NULL;
    while (current) {
      if (newTask->priority < current->priority) {
        previous = current;
        current = current->next;
      } else {
        break;
      }
    }
    if (previous) {
      previous->next = newTask;
    } else {
      head = newTask;
    }
  }

  return head;
}

void printTasks(Task* head) {
  while (head) {
    printf("%s (%d) ", head->name, head->priority);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Task* head = NULL;
  head = insertTask(head, "Task 1", 1);
  head = insertTask(head, "Task 2", 3);
  head = insertTask(head, "Task 3", 2);
  head = insertTask(head, "Task 4", 4);

  printTasks(head);

  return 0;
}