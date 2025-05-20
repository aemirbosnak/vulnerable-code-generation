//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  int start_time;
  int end_time;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int start_time, int end_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->start_time = start_time;
  newTask->end_time = end_time;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task** head, char* name, int priority, int start_time, int end_time) {
  Task* newTask = createTask(name, priority, start_time, end_time);
  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  while (head) {
    if (head->start_time <= now && now < head->end_time) {
      printf("%s is running\n", head->name);
    }
    head = head->next;
  }
}

int main() {
  Task* head = NULL;
  addTask(&head, "Task 1", 1, 10, 20);
  addTask(&head, "Task 2", 2, 15, 30);
  addTask(&head, "Task 3", 3, 20, 40);

  scheduleTasks(head);

  return 0;
}