//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_DELAY_MAX 60

typedef struct Task {
  char name[20];
  int delay;
  struct Task* next;
} Task;

Task* head = NULL;

void scheduleTask(char* name, int delay) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->delay = delay;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newTask;
  }
}

void executeTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (now >= currentTask->delay) {
      printf("Executing task: %s\n", currentTask->name);
      currentTask->delay = time(NULL) + TASK_DELAY_MAX;
    }
    currentTask = currentTask->next;
  }
}

int main() {
  scheduleTask("Wake up", 6 * 60);
  scheduleTask("Breakfast", 8 * 60);
  scheduleTask("Work", 10 * 60);
  scheduleTask("Lunch", 12 * 60);
  scheduleTask("Meeting", 14 * 60);
  scheduleTask("Dinner", 16 * 60);

  executeTasks();

  return 0;
}