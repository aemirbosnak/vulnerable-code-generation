//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  void (*function)(void);
  struct Task* next;
} Task;

Task* head = NULL;

void schedule_task(char* name, int priority, void (*function)(void)) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->function = function;
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

void execute_scheduler() {
  Task* current = head;
  while (current) {
    printf("Executing task: %s\n", current->name);
    current->function();
    current = current->next;
  }
}

void example_function() {
  printf("Hello, world!\n");
}

int main() {
  schedule_task("Task 1", 1, example_function);
  schedule_task("Task 2", 2, example_function);
  schedule_task("Task 3", 3, example_function);

  execute_scheduler();

  return 0;
}