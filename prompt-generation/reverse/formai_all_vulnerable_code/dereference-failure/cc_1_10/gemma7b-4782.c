//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int duration;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int duration) {
  Task* newTask = malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    head->next = newTask;
  }
}

void scheduleTasks() {
  Task* currentTask = head;
  time_t now = time(NULL);
  while (currentTask) {
    time_t taskTime = now + currentTask->duration;
    if (taskTime <= now) {
      printf("Task: %s completed.\n", currentTask->name);
      free(currentTask);
      currentTask = head;
    } else {
      currentTask = currentTask->next;
    }
  }
}

int main() {
  addTask("Wake up", 60);
  addTask("Breakfast", 30);
  addTask("Work", 120);
  addTask("Lunch", 30);
  addTask("Nap", 30);
  addTask("Dinner", 60);
  addTask("Watch TV", 30);

  scheduleTasks();

  return 0;
}