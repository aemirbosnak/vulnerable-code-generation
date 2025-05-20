//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task_t {
  char name[20];
  int priority;
  int start_time;
  int end_time;
  struct task_t* next;
} task_t;

void add_task(task_t** head) {
  task_t* new_task = malloc(sizeof(task_t));
  new_task->next = NULL;

  printf("Enter task name: ");
  scanf("%s", new_task->name);

  printf("Enter task priority (1-10): ");
  scanf("%d", &new_task->priority);

  printf("Enter task start time (HH:MM): ");
  scanf("%d:%d", &new_task->start_time);

  printf("Enter task end time (HH:MM): ");
  scanf("%d:%d", &new_task->end_time);

  if (*head == NULL) {
    *head = new_task;
  } else {
    (*head)->next = new_task;
  }
}

void print_tasks(task_t* head) {
  while (head) {
    printf("Task name: %s\n", head->name);
    printf("Priority: %d\n", head->priority);
    printf("Start time: %d:%d\n", head->start_time);
    printf("End time: %d:%d\n", head->end_time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  task_t* head = NULL;

  while (1) {
    printf("Enter 1 to add a task, 2 to print tasks, or 3 to exit: ");
    int choice = getchar();

    switch (choice) {
      case 1:
        add_task(&head);
        break;
      case 2:
        print_tasks(head);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}