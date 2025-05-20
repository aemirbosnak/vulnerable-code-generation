//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct TaskScheduler {
 int task_id;
 int priority;
 struct TaskScheduler* next;
} TaskScheduler;

void addTask(TaskScheduler** head_ref, int new_priority) {
 TaskScheduler* new_task = (TaskScheduler*)malloc(sizeof(TaskScheduler));
 new_task->task_id = rand() % 101;
 new_task->priority = new_priority;
 new_task->next = NULL;

 TaskScheduler* last_task = *head_ref;
 if (*head_ref == NULL) {
  *head_ref = new_task;
  return;
 }

 if ((*head_ref)->priority > new_priority) {
  new_task->next = *head_ref;
  *head_ref = new_task;
  return;
 }

 while (last_task->next != NULL && last_task->next->priority <= new_priority) {
  last_task = last_task->next;
 }

 new_task->next = last_task->next;
 last_task->next = new_task;
}

void removeTask(TaskScheduler** head_ref) {
 if (*head_ref == NULL) {
  printf("There are no tasks in the scheduler.\n");
  return;
 }

 TaskScheduler* temp = *head_ref;
 *head_ref = (*head_ref)->next;

 printf("Task %d with priority %d has been removed from the scheduler.\n", temp->task_id, temp->priority);
 free(temp);
}

void displayTasks(TaskScheduler* head) {
 if (head == NULL) {
  printf("The scheduler is empty.\n");
  return;
 }

 printf("Tasks in the scheduler:\n");
 while (head != NULL) {
  printf("- Task %d with priority %d\n", head->task_id, head->priority);
  head = head->next;
 }
}

int main() {
 TaskScheduler* scheduler_head = NULL;
 int option, priority;
 do {
  printf("\nTask Scheduler Operations:\n");
  printf("1. Add a new task.\n");
  printf("2. Remove the task with the highest priority.\n");
  printf("3. Display all tasks in the scheduler.\n");
  printf("4. Exit.\n");
  printf("Enter your choice (1-4): ");
  scanf("%d", &option);

 switch (option) {
  case 1:
   printf("Enter the priority of the new task (1-10): ");
   scanf("%d", &priority);
   if (priority < 1 || priority > 10) {
    printf("Invalid priority. Task not added.\n");
    break;
   }
   addTask(&scheduler_head, priority);
   printf("New task added to the scheduler.\n");
   break;

  case 2: 
   removeTask(&scheduler_head);
   break;

  case 3:
   displayTasks(scheduler_head);
   break;

  case 4:
   printf("Exiting...\n");
   exit(0);

  default:
   printf("Invalid choice. Please choose again (1-4).\n");
  }
 } while (option != 4);

 return 0;
}