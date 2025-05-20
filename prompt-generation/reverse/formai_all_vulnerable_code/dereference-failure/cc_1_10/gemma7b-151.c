//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* head = NULL;

void add_task(char* name, time_t start, time_t end) {
  Task* new_task = malloc(sizeof(Task));

  strcpy(new_task->name, name);
  new_task->start_time = start;
  new_task->end_time = end;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    head->next = new_task;
  }
}

void schedule_manager() {
  time_t now = time(NULL);

  Task* current_task = head;

  while (current_task) {
    if (now >= current_task->start_time && now < current_task->end_time) {
      printf("Currently executing task: %s\n", current_task->name);
    } else if (now > current_task->end_time) {
      printf("Task %s completed.\n", current_task->name);
      free(current_task);
      current_task = NULL;
    } else {
      current_task = current_task->next;
    }
  }

  if (current_task == NULL) {
    printf("No tasks scheduled.\n");
  }
}

int main() {
  add_task("Wake up", 7 * 60 * 60, 9 * 60 * 60);
  add_task("Breakfast", 9 * 60 * 60, 10 * 60 * 60);
  add_task("Work", 10 * 60 * 60, 18 * 60 * 60);
  add_task("Dinner", 18 * 60 * 60, 20 * 60 * 60);

  schedule_manager();

  return 0;
}