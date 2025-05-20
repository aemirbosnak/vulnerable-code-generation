//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct task {
  char name[20];
  int time_slot;
  struct task* next;
} task;

task* head = NULL;

void add_task(char* name, int time_slot) {
  task* new_task = (task*)malloc(sizeof(task));
  strcpy(new_task->name, name);
  new_task->time_slot = time_slot;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    head->next = new_task;
  }
}

void schedule() {
  time_t now = time(NULL);
  task* current = head;

  while (current) {
    if (current->time_slot == now) {
      printf("Task: %s started!\n", current->name);
      current->time_slot++;
    }
    current = current->next;
  }
}

int main() {
  add_task("Math Homework", 10);
  add_task("Physics Quiz", 12);
  add_task("English Reading", 14);
  add_task("Computer Programming", 16);
  add_task("Dinner", 18);

  schedule();

  return 0;
}