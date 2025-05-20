//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char *name;
  int priority;
  struct Task *next;
} Task;

Task *insertTask(Task *head, char *name, int priority) {
  Task *newTask = malloc(sizeof(Task));
  newTask->name = strdup(name);
  newTask->priority = priority;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task *prev = head;
    while (prev->next) {
      prev = prev->next;
    }
    prev->next = newTask;
  }

  return head;
}

void printSchedule(Task *head) {
  printf("Schedule:\n");
  for (Task *task = head; task; task = task->next) {
    printf("%s (priority %d)\n", task->name, task->priority);
  }
}

int main() {
  Task *head = NULL;

  insertTask(head, "Buy groceries", 3);
  insertTask(head, "Write report", 2);
  insertTask(head, "Clean apartment", 4);
  insertTask(head, "Do laundry", 1);

  printSchedule(head);

  sleep(5);

  printf("Updated schedule:\n");

  insertTask(head, "Water plants", 5);
  insertTask(head, "Make dinner", 2);

  printSchedule(head);

  return 0;
}