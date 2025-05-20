//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sched.h>

// Define the task structure
typedef struct task {
  int id;            // Task ID
  int priority;      // Task priority
  void (*func)(void); // Task function
} task;

// Define the task queue
#define MAX_TASKS 10
task task_queue[MAX_TASKS];
int task_queue_size = 0;

// Define the scheduler function
void scheduler() {
  while (1) {
    // Find the task with the highest priority
    int highest_priority = -1;
    int highest_priority_index = -1;
    for (int i = 0; i < task_queue_size; i++) {
      if (task_queue[i].priority > highest_priority) {
        highest_priority = task_queue[i].priority;
        highest_priority_index = i;
      }
    }

    // Run the task with the highest priority
    if (highest_priority_index != -1) {
      task_queue[highest_priority_index].func();

      // Remove the task from the queue
      for (int i = highest_priority_index; i < task_queue_size - 1; i++) {
        task_queue[i] = task_queue[i + 1];
      }
      task_queue_size--;
    }
  }
}

// Define the task functions
void task1() {
  printf("Task 1 running\n");
}

void task2() {
  printf("Task 2 running\n");
}

void task3() {
  printf("Task 3 running\n");
}

// Main function
int main() {
  // Create the tasks
  task task1 = {1, 10, &task1};
  task task2 = {2, 5, &task2};
  task task3 = {3, 15, &task3};

  // Add the tasks to the queue
  task_queue[task_queue_size++] = task1;
  task_queue[task_queue_size++] = task2;
  task_queue[task_queue_size++] = task3;

  // Create the scheduler thread
  pthread_t scheduler_thread;
  pthread_create(&scheduler_thread, NULL, (void *)scheduler, NULL);

  // Wait for the scheduler thread to finish
  pthread_join(scheduler_thread, NULL);

  return 0;
}