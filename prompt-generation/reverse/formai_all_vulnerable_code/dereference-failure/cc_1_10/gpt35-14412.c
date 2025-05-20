//FormAI DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a task struct
typedef struct {
  char task_name[50];
  int priority;
  bool completed;
  time_t timestamp;
} task;

// Function to print the task details
void print_task(task* t) {
  printf("Task Name: %s\n", t->task_name);
  printf("Priority: %d\n", t->priority);
  printf("Completed: %s\n", t->completed ? "Yes" : "No");
  printf("Timestamp: %s\n", ctime(&t->timestamp));
}

// Function to compare timestamps of two tasks
int compare_timestamps(const void* t1, const void* t2) {
  return (*(task*)t1).timestamp - (*(task*)t2).timestamp;
}

int main() {
  int num_tasks;
  printf("Welcome to the Task Scheduler Program!\n");
  printf("How many tasks do you want to schedule? ");
  scanf("%d", &num_tasks);

  // Allocate space for the tasks
  task* tasks = malloc(num_tasks * sizeof(task));

  // Get the task details from the user
  for (int i = 0; i < num_tasks; i++) {
    printf("\nEnter details for Task %d:\n", i+1);
    printf("Task Name: ");
    scanf("%s", tasks[i].task_name);
    printf("Priority (1-10): ");
    scanf("%d", &tasks[i].priority);
    tasks[i].completed = false;
    tasks[i].timestamp = time(NULL);
  }

  // Sort the tasks based on their timestamps
  qsort(tasks, num_tasks, sizeof(task), compare_timestamps);

  // Print the sorted list of tasks
  printf("\n\n--- Your Task List ---\n");

  for (int i = 0; i < num_tasks; i++) {
    printf("\nTask %d:\n", i+1);
    print_task(&tasks[i]);
  }

  // Free the memory allocated for the tasks
  free(tasks);

  printf("\nThank you for using the Task Scheduler Program!\n");
  return 0;
}