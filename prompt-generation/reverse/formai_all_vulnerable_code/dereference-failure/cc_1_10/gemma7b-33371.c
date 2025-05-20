//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int time_slot;
  struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int priority, int time_slot) {
  Task* new_task = (Task*)malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->time_slot = time_slot;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    Task* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_task;
  }
}

void schedule_tasks() {
  time_t now = time(NULL);
  Task* current = head;
  while (current) {
    if (current->time_slot == now) {
      printf("Task: %s, Priority: %d\n", current->name, current->priority);
      sleep(current->time_slot - now);
    }
    current = current->next;
  }
}

int main() {
  add_task("Wake up", 1, 8);
  add_task("Breakfast", 2, 9);
  add_task("Study", 3, 10);
  add_task("Lunch", 2, 12);
  add_task("Work", 1, 13);
  add_task("Dinner", 2, 18);
  add_task("Watch TV", 3, 19);

  schedule_tasks();

  return 0;
}