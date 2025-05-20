//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

struct Task {
  char name[20];
  int duration;
  time_t scheduled_time;
  struct Task* next;
};

struct Task* head = NULL;

void addTask(char* name, int duration) {
  struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
  strcpy(newTask->name, name);
  newTask->duration = duration;
  newTask->scheduled_time = time(NULL) + duration;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    struct Task* currentTask = head;
    while (currentTask->next) {
      currentTask = currentTask->next;
    }
    currentTask->next = newTask;
  }
}

void scheduleTasks() {
  struct Task* currentTask = head;
  while (currentTask) {
    if (time(NULL) >= currentTask->scheduled_time) {
      printf("Starting task: %s\n", currentTask->name);
      sleep(currentTask->duration);
      printf("Task completed: %s\n", currentTask->name);
    }
    currentTask = currentTask->next;
  }
}

int main() {
  addTask("Task 1", 10);
  addTask("Task 2", 5);
  addTask("Task 3", 15);
  addTask("Task 4", 20);
  addTask("Task 5", 25);

  scheduleTasks();

  return 0;
}