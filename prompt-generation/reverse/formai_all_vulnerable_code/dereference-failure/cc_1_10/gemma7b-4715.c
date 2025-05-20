//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_TIME_MAX 60

typedef struct task_t {
  char name[20];
  int time;
  struct task_t* next;
} task_t;

task_t* head = NULL;

void schedule_task(char* name, int time) {
  task_t* new_task = (task_t*)malloc(sizeof(task_t));
  strcpy(new_task->name, name);
  new_task->time = time;
  new_task->next = NULL;

  if (head == NULL) {
    head = new_task;
  } else {
    head->next = new_task;
  }
}

void execute_scheduler() {
  time_t now = time(NULL);
  task_t* current = head;

  while (current) {
    if (now >= current->time) {
      printf("Task: %s completed!\n", current->name);
      free(current);
      current = head;
    } else {
      current = current->next;
    }
  }
}

int main() {
  schedule_task("Wake up", 7);
  schedule_task("Breakfast", 10);
  schedule_task("Work", 16);
  schedule_task("Dinner", 19);
  schedule_task("Sleep", 22);

  execute_scheduler();

  return 0;
}