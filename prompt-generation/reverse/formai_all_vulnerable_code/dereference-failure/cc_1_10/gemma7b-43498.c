//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
  char *name;
  int priority;
  int start_time;
  int end_time;
  struct Task *next;
} Task;

void add_task(Task **head, char *name, int priority, int start_time, int end_time) {
  Task *new_task = malloc(sizeof(Task));
  new_task->name = strdup(name);
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

void print_schedule(Task *head) {
  Task *current_task = head;
  while (current_task) {
    printf("Name: %s, Priority: %d, Start Time: %d, End Time: %d\n", current_task->name, current_task->priority, current_task->start_time, current_task->end_time);
    current_task = current_task->next;
  }
}

int main() {
  Task *head = NULL;

  // Add some tasks
  add_task(&head, "Sleep", 1, 9, 12);
  add_task(&head, "Eat", 2, 10, 11);
  add_task(&head, "Work", 3, 12, 14);

  // Print the schedule
  print_schedule(head);

  return 0;
}