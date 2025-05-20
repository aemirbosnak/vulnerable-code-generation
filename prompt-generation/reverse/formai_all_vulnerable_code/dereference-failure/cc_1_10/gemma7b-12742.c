//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define NUM_TASKS 5

struct task {
  char name[20];
  int priority;
  int start_time;
  int duration;
  struct task* next;
};

void add_task(struct task** head, char* name, int priority, int start_time, int duration) {
  struct task* new_task = malloc(sizeof(struct task));
  strcpy(new_task->name, name);
  new_task->priority = priority;
  new_task->start_time = start_time;
  new_task->duration = duration;
  new_task->next = NULL;

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void schedule_tasks(struct task* head) {
  time_t now = time(NULL);
  struct task* current = head;

  while (current) {
    if (now >= current->start_time) {
      printf("Task: %s, Start Time: %d, Duration: %d\n", current->name, current->start_time, current->duration);
      sleep(current->duration);
    }
    current = current->next;
  }
}

int main() {
  struct task* head = NULL;
  add_task(&head, "Task 1", 1, 10, 5);
  add_task(&head, "Task 2", 2, 15, 3);
  add_task(&head, "Task 3", 3, 20, 2);
  add_task(&head, "Task 4", 4, 25, 4);
  add_task(&head, "Task 5", 5, 30, 6);

  schedule_tasks(head);

  return 0;
}