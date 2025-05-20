//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Define the task structure
typedef struct task {
  int priority;
  char *command;
} task;

// Define the task queue
task *tasks;
int task_count = 0;

// Add a task to the queue
void add_task(int priority, char *command) {
  // Allocate memory for the new task
  task *new_task = malloc(sizeof(task));

  // Initialize the new task
  new_task->priority = priority;
  new_task->command = command;

  // Add the new task to the queue
  tasks[task_count] = *new_task;
  task_count++;
}

// Get the next task from the queue
task *get_next_task() {
  // Find the task with the highest priority
  int max_priority = -1;
  int max_priority_index = -1;
  for (int i = 0; i < task_count; i++) {
    if (tasks[i].priority > max_priority) {
      max_priority = tasks[i].priority;
      max_priority_index = i;
    }
  }

  // If there is no task with a higher priority, return NULL
  if (max_priority_index == -1) {
    return NULL;
  }

  // Return the task with the highest priority
  return &tasks[max_priority_index];
}

// Remove a task from the queue
void remove_task(int index) {
  // Move the tasks after the removed task one position forward
  for (int i = index + 1; i < task_count; i++) {
    tasks[i - 1] = tasks[i];
  }

  // Decrement the task count
  task_count--;
}

// Run the tasks in the queue
void run_tasks() {
  // While there are still tasks in the queue, get the next task and run it
  while (task_count > 0) {
    task *next_task = get_next_task();

    // If there is no next task, break out of the loop
    if (next_task == NULL) {
      break;
    }

    // Run the task
    system(next_task->command);

    // Remove the task from the queue
    remove_task(next_task - tasks);
  }
}

// Main function
int main() {
  // Add some tasks to the queue
  add_task(1, "echo \"Task 1\"");
  add_task(2, "echo \"Task 2\"");
  add_task(3, "echo \"Task 3\"");

  // Run the tasks
  run_tasks();

  return 0;
}