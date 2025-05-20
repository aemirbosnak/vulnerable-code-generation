//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20
#define MAX_TASK_DESC_LEN 50

/* Task structure */
typedef struct task {
  char name[MAX_TASK_NAME_LEN];
  char description[MAX_TASK_DESC_LEN];
  int priority;
  int time_remaining;
  int is_running;
} task;

/* Task scheduler structure */
typedef struct scheduler {
  task tasks[MAX_TASKS];
  int num_tasks;
} scheduler;

/* Function to create a new task */
task *create_task(char *name, char *description, int priority, int time_remaining) {
  task *new_task = malloc(sizeof(task));
  if (new_task == NULL) {
    return NULL;
  }
  strcpy(new_task->name, name);
  strcpy(new_task->description, description);
  new_task->priority = priority;
  new_task->time_remaining = time_remaining;
  new_task->is_running = 0;
  return new_task;
}

/* Function to add a task to the scheduler */
int add_task(scheduler *s, task *task) {
  if (s->num_tasks >= MAX_TASKS) {
    return -1;
  }
  s->tasks[s->num_tasks++] = *task;
  return 0;
}

/* Function to remove a task from the scheduler */
int remove_task(scheduler *s, char *name) {
  int i;
  for (i = 0; i < s->num_tasks; i++) {
    if (strcmp(s->tasks[i].name, name) == 0) {
      s->tasks[i] = s->tasks[s->num_tasks - 1];
      s->num_tasks--;
      return 0;
    }
  }
  return -1;
}

/* Function to run a task */
int run_task(scheduler *s, char *name) {
  int i;
  for (i = 0; i < s->num_tasks; i++) {
    if (strcmp(s->tasks[i].name, name) == 0) {
      if (s->tasks[i].time_remaining > 0) {
        s->tasks[i].time_remaining--;
        printf("Running task: %s\n", s->tasks[i].name);
        return 0;
      } else {
        printf("Task: %s has finished running\n", s->tasks[i].name);
        remove_task(s, s->tasks[i].name);
        return 0;
      }
    }
  }
  return -1;
}

/* Function to print the tasks in the scheduler */
void print_tasks(scheduler *s) {
  int i;
  printf("Tasks in the scheduler:\n");
  for (i = 0; i < s->num_tasks; i++) {
    printf("  %s (%d) - %s\n", s->tasks[i].name, s->tasks[i].priority, s->tasks[i].description);
  }
}

/* Main function */
int main() {
  scheduler s;
  s.num_tasks = 0;

  /* Add some tasks to the scheduler */
  task *task1 = create_task("Task 1", "This is task 1", 1, 10);
  add_task(&s, task1);
  task *task2 = create_task("Task 2", "This is task 2", 2, 5);
  add_task(&s, task2);
  task *task3 = create_task("Task 3", "This is task 3", 3, 2);
  add_task(&s, task3);

  /* Print the tasks in the scheduler */
  print_tasks(&s);

  /* Run some tasks */
  run_task(&s, "Task 1");
  run_task(&s, "Task 2");

  /* Print the tasks in the scheduler again */
  print_tasks(&s);

  /* Remove a task from the scheduler */
  remove_task(&s, "Task 2");

  /* Print the tasks in the scheduler one last time */
  print_tasks(&s);

  return 0;
}