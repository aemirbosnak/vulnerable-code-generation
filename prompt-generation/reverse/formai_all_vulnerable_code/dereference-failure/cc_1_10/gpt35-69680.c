//FormAI DATASET v1.0 Category: Task Scheduler ; Style: enthusiastic
/* 
  Welcome to my Task Scheduler program! 
  With this program, you can schedule and execute tasks at specific intervals.
  Let's get started!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct task {
  int id;
  int interval; // in seconds
  time_t lastRunTime; // in Unix time
} Task;

Task* createTask(int id, int interval) {
  Task* task = (Task*) malloc(sizeof(Task));
  task->id = id;
  task->interval = interval;
  task->lastRunTime = time(NULL);
  return task;
}

void executeTask(Task* task) {
  printf("Executing Task %d...\n", task->id);
  // do some task-specific work here
  task->lastRunTime = time(NULL);
}

bool isTimeToExecute(Task* task) {
  time_t currentTime = time(NULL);
  int timeDiff = (int) difftime(currentTime, task->lastRunTime);
  return timeDiff >= task->interval;
}

int main() {
  printf("Welcome to Task Scheduler program!\n\n");

  Task* task1 = createTask(1, 5); // Task ID 1, Runs every 5 seconds
  Task* task2 = createTask(2, 10); // Task ID 2, Runs every 10 seconds

  while (true) {
    if (isTimeToExecute(task1)) {
      executeTask(task1);
    }
    if (isTimeToExecute(task2)) {
      executeTask(task2);
    }
  }

  return 0;
}