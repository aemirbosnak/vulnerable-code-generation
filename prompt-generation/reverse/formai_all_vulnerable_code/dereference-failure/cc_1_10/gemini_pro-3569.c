//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Our playful task scheduler
typedef struct Task {
  char *name;
  int priority;
  int time_to_run;
  struct Task *next;
} Task;

// Create a new task with the given name, priority, and time to run
Task *create_task(char *name, int priority, int time_to_run) {
  Task *task = malloc(sizeof(Task));
  task->name = name;
  task->priority = priority;
  task->time_to_run = time_to_run;
  task->next = NULL;
  return task;
}

// Add a new task to the end of the linked list
void add_task(Task **head, Task *new_task) {
  Task *current = *head;
  if (!current) {
    *head = new_task;
    return;
  }

  while (current->next) {
    current = current->next;
  }
  current->next = new_task;
}

// Print the list of tasks
void print_tasks(Task *head) {
  while (head) {
    printf("Task: %s, Priority: %d, Time to Run: %d\n", head->name, head->priority, head->time_to_run);
    head = head->next;
  }
}

// Simulate running the tasks
void run_tasks(Task **head) {
  time_t start_time = time(NULL);
  Task *current = *head;

  printf("Running tasks...\n");
  while (current) {
    // Sleep for the time needed to run the task
    sleep(current->time_to_run);

    // Print a message when the task is complete
    time_t end_time = time(NULL);
    printf("Task %s completed in %ld seconds\n", current->name, end_time - start_time);

    // Move on to the next task
    current = current->next;
  }
}

// Free the memory allocated for the tasks
void free_tasks(Task **head) {
  Task *current = *head;
  while (current) {
    Task *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
  *head = NULL;
}

int main() {
  // Create a linked list of tasks
  Task *head = NULL;
  add_task(&head, create_task("Bake cookies", 5, 30));
  add_task(&head, create_task("Go for a walk", 2, 15));
  add_task(&head, create_task("Read a book", 4, 60));
  add_task(&head, create_task("Play with the dog", 3, 30));

  // Print the list of tasks
  printf("Tasks to be scheduled:\n");
  print_tasks(head);

  // Simulate running the tasks
  run_tasks(&head);

  // Free the memory allocated for the tasks
  free_tasks(&head);

  return 0;
}