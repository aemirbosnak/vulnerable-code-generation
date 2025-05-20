//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int time_slot;
  struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, int priority, int time_slot) {
  Task* new_task = malloc(sizeof(Task));
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

void print_tasks() {
  Task* current = head;
  printf("Tasks:\n");
  while (current) {
    printf("  %-20s (Priority: %d, Time Slot: %d)\n", current->name, current->priority, current->time_slot);
    current = current->next;
  }
}

void execute_tasks() {
  Task* current = head;
  time_t now = time(NULL);
  while (current) {
    if (current->time_slot == now) {
      printf("Executing: %s\n", current->name);
      current->time_slot = now + 1;
    }
    current = current->next;
  }
}

int main() {
  add_task("Clean water", 3, 10);
  add_task("Forage for food", 2, 12);
  add_task("Build shelter", 1, 14);

  print_tasks();
  execute_tasks();

  return 0;
}