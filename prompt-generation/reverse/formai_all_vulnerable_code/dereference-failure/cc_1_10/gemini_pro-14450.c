//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct task {
  int id;                 // Task ID
  int arrival_time;       // Task arrival time
  int execution_time;     // Task execution time
  int remaining_time;    // Remaining execution time
  int priority;           // Task priority
  struct task *next;      // Pointer to the next task
} task;

// Task queue
task *task_queue = NULL;

// Create a new task
task *create_task(int id, int arrival_time, int execution_time, int priority) {
  task *new_task = malloc(sizeof(task));
  if (new_task == NULL) {
    perror("Error allocating memory for new task");
    return NULL;
  }

  new_task->id = id;
  new_task->arrival_time = arrival_time;
  new_task->execution_time = execution_time;
  new_task->remaining_time = execution_time;
  new_task->priority = priority;
  new_task->next = NULL;

  return new_task;
}

// Insert a task into the task queue, sorted by arrival time
void insert_task(task *new_task) {
  task *current = task_queue;
  task *previous = NULL;

  while (current != NULL && new_task->arrival_time >= current->arrival_time) {
    previous = current;
    current = current->next;
  }

  if (previous == NULL) {
    new_task->next = task_queue;
    task_queue = new_task;
  } else {
    previous->next = new_task;
    new_task->next = current;
  }
}

// Schedule tasks using the Round Robin algorithm with a time quantum of 2
void schedule_tasks() {
  task *current = task_queue;
  int current_time = 0;

  while (current != NULL) {
    // Check if the task has arrived
    if (current->arrival_time > current_time) {
      current_time = current->arrival_time;
    }

    // Execute the task for a time quantum of 2
    while (current->remaining_time > 0 && current_time < current->arrival_time + 2) {
      current->remaining_time--;
      current_time++;
      printf("Task %d executing at time %d\n", current->id, current_time);
    }

    // If the task is still not completed, move it to the end of the queue
    if (current->remaining_time > 0) {
      task *temp = task_queue;
      task *prev = NULL;

      // Find the last task in the queue
      while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
      }

      // Move the current task to the end of the queue
      if (prev != NULL) {
        prev->next = current;
      } else {
        task_queue = current;
      }
      current->next = NULL;
    }

    // Move to the next task
    current = current->next;
  }
}

// Print the tasks in the task queue
void print_tasks() {
  task *current = task_queue;

  while (current != NULL) {
    printf("Task %d: arrival time %d, execution time %d, priority %d\n", current->id, current->arrival_time, current->execution_time, current->priority);
    current = current->next;
  }
}

// Main function
int main() {
  // Initialize the task queue
  task_queue = NULL;

  // Create 5 tasks
  task *task1 = create_task(1, 0, 5, 3);
  task *task2 = create_task(2, 2, 3, 1);
  task *task3 = create_task(3, 4, 4, 4);
  task *task4 = create_task(4, 6, 2, 2);
  task *task5 = create_task(5, 8, 1, 5);

  // Insert the tasks into the task queue
  insert_task(task1);
  insert_task(task2);
  insert_task(task3);
  insert_task(task4);
  insert_task(task5);

  // Print the tasks in the task queue
  printf("Tasks in the task queue:\n");
  print_tasks();

  // Schedule the tasks
  printf("\nScheduling tasks using Round Robin with time quantum 2:\n");
  schedule_tasks();

  return 0;
}