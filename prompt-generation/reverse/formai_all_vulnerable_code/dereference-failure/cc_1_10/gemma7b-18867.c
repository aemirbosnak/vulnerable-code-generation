//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
  char name[20];
  int duration;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int duration) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newTask;
  }
}

void scheduleTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    time_t taskStart = now + currentTask->duration;
    if (taskStart >= now) {
      printf("Task: %s, Start time: %ld\n", currentTask->name, taskStart);
      currentTask = currentTask->next;
    } else {
      currentTask = currentTask->next;
    }
  }
}

int main() {
  addTask("Wake up", 60);
  addTask("Breakfast", 30);
  addTask("School", 120);
  addTask("Lunch", 60);
  addTask("Study", 90);
  addTask("Dinner", 60);

  scheduleTasks();

  return 0;
}