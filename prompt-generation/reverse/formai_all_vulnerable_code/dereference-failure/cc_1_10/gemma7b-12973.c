//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char *name;
  int priority;
  struct Task *next;
} Task;

Task *head = NULL;

void addTask(char *name, int priority) {
  Task *newTask = malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task *currTask = head;
    while (currTask->next) {
      currTask = currTask->next;
    }
    currTask->next = newTask;
  }
}

void scheduleTasks() {
  time_t now = time(NULL);
  Task *currTask = head;

  while (currTask) {
    int taskTime = now + currTask->priority;
    if (taskTime <= now) {
      printf("%s has completed!\n", currTask->name);
      free(currTask);
      currTask = head;
    } else {
      currTask = currTask->next;
    }
  }
}

int main() {
  addTask("Wake up", 0);
  addTask("Eat breakfast", 1);
  addTask("Go to school", 2);
  addTask("Study", 3);
  addTask("Have fun", 4);

  scheduleTasks();

  return 0;
}