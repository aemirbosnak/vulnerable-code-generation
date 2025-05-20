//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
  char name[20];
  int priority;
  int start_time;
  int end_time;
  struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, int start_time, int end_time) {
  Task* new_task = malloc(sizeof(Task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->end_time = end_time;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void print_tasks(Task* head) {
  while (head) {
    printf("%s (%d) - Start: %d, End: %d\n", head->name, head->priority, head->start_time, head->end_time);
    head = head->next;
  }
}

int main() {
  Task* head = NULL;

  add_task(&head, "Wake up", 1, 7, 9);
  add_task(&head, "Breakfast", 2, 9, 10);
  add_task(&head, "School", 3, 10, 16);
  add_task(&head, "Lunch", 2, 16, 17);
  add_task(&head, "Afternoon classes", 3, 17, 18);
  add_task(&head, "Snack", 2, 18, 19);
  add_task(&head, "Homework", 1, 19, 20);

  print_tasks(head);

  return 0;
}