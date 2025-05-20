//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_DELAY_MIN 1
#define TASK_DELAY_MAX 5

typedef struct Task {
  char *name;
  int delay;
  struct Task *next;
} Task;

void scheduler_add(Task **head, char *name, int delay) {
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
  new_task->delay = delay;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void scheduler_run(Task *head) {
  time_t now = time(NULL);
  Task *current = head;

  while (current) {
    if (current->delay <= now) {
      printf("%s is running...\n", current->name);
      sleep(current->delay);
    }

    current = current->next;
  }
}

int main() {
  Task *scheduler = NULL;

  scheduler_add(&scheduler, "Task A", 3);
  scheduler_add(&scheduler, "Task B", 2);
  scheduler_add(&scheduler, "Task C", 4);

  scheduler_run(scheduler);

  return 0;
}