//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  int scheduled_time;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int scheduled_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->scheduled_time = scheduled_time;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task** head, char* name, int priority, int scheduled_time) {
  Task* newTask = createTask(name, priority, scheduled_time);
  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t current_time = time(NULL);
  while (head) {
    if (head->scheduled_time <= current_time) {
      printf("Task: %s, Priority: %d, Scheduled Time: %d\n", head->name, head->priority, head->scheduled_time);
      head = head->next;
    } else {
      break;
    }
  }
}

int main() {
  Task* head = NULL;
  addTask(&head, "Task 1", 1, 10);
  addTask(&head, "Task 2", 2, 12);
  addTask(&head, "Task 3", 3, 14);
  addTask(&head, "Task 4", 4, 16);

  scheduleTasks(head);

  return 0;
}