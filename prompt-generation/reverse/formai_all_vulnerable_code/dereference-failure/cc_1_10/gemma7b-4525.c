//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char name[20];
  int priority;
  int estimated_time;
  struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int estimated_time) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->estimated_time = estimated_time;
  newTask->next = NULL;

  if (*head == NULL) {
    *head = newTask;
  } else {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task** head) {
  time_t now = time(NULL);
  struct tm* nowTm = localtime(&now);

  Task* currentTask = *head;
  while (currentTask) {
    struct tm* taskTm = localtime(&currentTask->estimated_time);
    int hoursDiff = taskTm->tm_hour - nowTm->tm_hour;
    int minutesDiff = taskTm->tm_min - nowTm->tm_min;

    if (hoursDiff >= 0 && minutesDiff >= 0) {
      printf("Task: %s, Estimated Time: %d:%d, Remaining Time: %d:%d\n", currentTask->name, taskTm->tm_hour, taskTm->tm_min, hoursDiff, minutesDiff);
    }
    currentTask = currentTask->next;
  }
}

int main() {
  Task* head = NULL;
  insertTask(&head, "Task 1", 1, 10);
  insertTask(&head, "Task 2", 2, 20);
  insertTask(&head, "Task 3", 3, 30);

  scheduleTasks(&head);

  return 0;
}