//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct Task {
  char name[20];
  int priority;
  int estimated_time;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int estimated_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->estimated_time = estimated_time;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task** head, char* name, int priority, int estimated_time) {
  Task* newTask = createTask(name, priority, estimated_time);
  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head) {
  time_t now = time(NULL);
  int i = 0;
  for (Task* task = head; task; task = task->next) {
    int estimated_time = task->estimated_time;
    if (now >= estimated_time) {
      printf("Task: %s, completed at: %s\n", task->name, ctime(NULL));
    } else {
      printf("Task: %s, estimated completion time: %s\n", task->name, estimated_time);
    }
  }
}

int main() {
  Task* head = NULL;
  addTask(&head, "Write a C Task Scheduler", 1, 60);
  addTask(&head, "Design a scientific calculator", 3, 90);
  addTask(&head, "Develop a neural network", 2, 80);
  addTask(&head, "Create a mobile game", 4, 70);
  addTask(&head, "Build a robot", 5, 100);

  scheduleTasks(head);

  return 0;
}