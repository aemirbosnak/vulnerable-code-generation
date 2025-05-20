//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct task {
  int id;
  int arrival_time;
  int execution_time;
  int remaining_time;
  int priority;
  struct task *next;
} task;

// Queue structure
typedef struct queue {
  task *head;
  task *tail;
  int size;
} queue;

// Function to create a new task
task *create_task(int id, int arrival_time, int execution_time, int priority) {
  task *new_task = (task *)malloc(sizeof(task));
  new_task->id = id;
  new_task->arrival_time = arrival_time;
  new_task->execution_time = execution_time;
  new_task->remaining_time = execution_time;
  new_task->priority = priority;
  new_task->next = NULL;
  return new_task;
}

// Function to enqueue a task into the queue
void enqueue(queue *q, task *new_task) {
  // If the queue is empty, set the head and tail to the new task
  if (q->size == 0) {
    q->head = new_task;
    q->tail = new_task;
  }
  // Otherwise, add the new task to the end of the queue
  else {
    q->tail->next = new_task;
    q->tail = new_task;
  }
  // Increment the size of the queue
  q->size++;
}

// Function to dequeue a task from the queue
task *dequeue(queue *q) {
  // If the queue is empty, return NULL
  if (q->size == 0) {
    return NULL;
  }
  // Otherwise, get the task at the head of the queue
  task *task = q->head;
  // Move the head of the queue to the next task
  q->head = q->head->next;
  // If the head of the queue is now NULL, set the tail to NULL as well
  if (q->head == NULL) {
    q->tail = NULL;
  }
  // Decrement the size of the queue
  q->size--;
  // Return the task that was dequeued
  return task;
}

// Function to print the queue
void print_queue(queue *q) {
  // If the queue is empty, print an empty message
  if (q->size == 0) {
    printf("Queue is empty\n");
  }
  // Otherwise, iterate over the queue and print each task
  else {
    task *current_task = q->head;
    while (current_task != NULL) {
      printf("Task ID: %d, Arrival Time: %d, Execution Time: %d, Remaining Time: %d, Priority: %d\n",
             current_task->id, current_task->arrival_time, current_task->execution_time, current_task->remaining_time, current_task->priority);
      current_task = current_task->next;
    }
  }
}

// Function to simulate the task scheduler
void task_scheduler(queue *q) {
  // Get the current time
  int current_time = 0;

  // While the queue is not empty
  while (q->size > 0) {
    // Get the task at the head of the queue
    task *current_task = dequeue(q);

    // If the current time is greater than or equal to the arrival time of the task
    if (current_time >= current_task->arrival_time) {
      // Execute the task
      current_task->remaining_time--;

      // If the task has finished executing, print a message
      if (current_task->remaining_time == 0) {
        printf("Task ID: %d finished executing at time %d\n", current_task->id, current_time);
      }
    }
    // Otherwise, put the task back into the queue
    else {
      enqueue(q, current_task);
    }

    // Increment the current time
    current_time++;
  }
}

int main() {
  // Create a new task queue
  queue *q = (queue *)malloc(sizeof(queue));
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;

  // Add some tasks to the queue
  enqueue(q, create_task(1, 0, 5, 1));
  enqueue(q, create_task(2, 2, 3, 2));
  enqueue(q, create_task(3, 5, 4, 3));
  enqueue(q, create_task(4, 7, 2, 4));

  // Print the queue
  printf("Initial Queue:\n");
  print_queue(q);

  // Simulate the task scheduler
  task_scheduler(q);

  // Print the queue after the simulation
  printf("Final Queue:\n");
  print_queue(q);

  return 0;
}