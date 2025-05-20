//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int seconds;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int seconds) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->seconds = seconds;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    head->next = newTask;
  }
}

void scheduleTasks() {
  time_t now = time(NULL);
  Task* currentTask = head;

  while (currentTask) {
    if (now >= currentTask->seconds) {
      printf("Task: %s, completed at: %s\n", currentTask->name, asctime(localtime(time(NULL))));
      currentTask = currentTask->next;
    } else {
      break;
    }
  }
}

int main() {
  addTask("Wake up", 7 * 60);
  addTask("Breakfast", 8 * 60);
  addTask("School", 10 * 60);
  addTask("Lunch", 12 * 60);
  addTask("Homework", 14 * 60);
  addTask("Dinner", 18 * 60);
  addTask("Watch TV", 20 * 60);

  scheduleTasks();

  return 0;
}