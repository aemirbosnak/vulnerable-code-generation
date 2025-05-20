//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef struct {
  time_t next_execution;
  int interval;
  void (*task)(void*);
  void *data;
} task_t;

typedef struct {
  int num_tasks;
  task_t *tasks;
} task_scheduler_t;

task_scheduler_t *task_scheduler_create() {
  return malloc(sizeof(task_scheduler_t));
}

void task_scheduler_destroy(task_scheduler_t *scheduler) {
  if (scheduler != NULL) {
    free(scheduler->tasks);
    free(scheduler);
  }
}

void task_scheduler_add_task(task_scheduler_t *scheduler, time_t first_execution, int interval, void (*task)(void*), void *data) {
  if (scheduler != NULL) {
    scheduler->num_tasks++;
    scheduler->tasks = realloc(scheduler->tasks, scheduler->num_tasks * sizeof(task_t));
    scheduler->tasks[scheduler->num_tasks - 1].next_execution = first_execution;
    scheduler->tasks[scheduler->num_tasks - 1].interval = interval;
    scheduler->tasks[scheduler->num_tasks - 1].task = task;
    scheduler->tasks[scheduler->num_tasks - 1].data = data;
  }
}

void task_scheduler_run(task_scheduler_t *scheduler) {
  if (scheduler != NULL) {
    time_t now = time(NULL);
    for (int i = 0; i < scheduler->num_tasks; i++) {
      if (scheduler->tasks[i].next_execution <= now) {
        scheduler->tasks[i].task(scheduler->tasks[i].data);
        scheduler->tasks[i].next_execution += scheduler->tasks[i].interval;
      }
    }
  }
}

void print_hello(void *data) {
  printf("Hello, world!\n");
}

int main() {
  task_scheduler_t *scheduler = task_scheduler_create();
  task_scheduler_add_task(scheduler, time(NULL) + 1, 5, print_hello, NULL);
  while (1) {
    task_scheduler_run(scheduler);
    sleep(1);
  }
  task_scheduler_destroy(scheduler);
  return 0;
}