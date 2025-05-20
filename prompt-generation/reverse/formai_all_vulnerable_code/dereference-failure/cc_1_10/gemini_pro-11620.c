//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A linked list node to store a task
typedef struct Task {
  char *name;
  void (*function)(void *);
  void *args;
  struct Task *next;
} Task;

// A queue to store tasks
typedef struct Queue {
  Task *head;
  Task *tail;
} Queue;

// Create a new task
Task *task_new(char *name, void (*function)(void *), void *args) {
  Task *task = malloc(sizeof(Task));
  task->name = strdup(name);
  task->function = function;
  task->args = args;
  task->next = NULL;
  return task;
}

// Enqueue a task
void queue_enqueue(Queue *queue, Task *task) {
  if (queue->tail == NULL) {
    queue->head = task;
  } else {
    queue->tail->next = task;
  }
  queue->tail = task;
}

// Dequeue a task
Task *queue_dequeue(Queue *queue) {
  if (queue->head == NULL) {
    return NULL;
  }
  Task *task = queue->head;
  queue->head = task->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  return task;
}

// Print a task
void task_print(Task *task) {
  printf("%s\n", task->name);
}

// Print a queue
void queue_print(Queue *queue) {
  Task *task = queue->head;
  while (task != NULL) {
    task_print(task);
    task = task->next;
  }
}

// A function to be executed as a task
void task_function(void *args) {
  printf("Task %s executed\n", args);
}

// A function to schedule tasks
void task_scheduler(Queue *queue) {
  while (queue->head != NULL) {
    Task *task = queue_dequeue(queue);
    task->function(task->args);
    free(task->name);
    free(task);
  }
}

int main() {
  // Create a queue of tasks
  Queue queue;
  queue.head = NULL;
  queue.tail = NULL;

  // Enqueue some tasks
  queue_enqueue(&queue, task_new("Task 1", task_function, "Task 1"));
  queue_enqueue(&queue, task_new("Task 2", task_function, "Task 2"));
  queue_enqueue(&queue, task_new("Task 3", task_function, "Task 3"));

  // Print the queue
  printf("Queue:\n");
  queue_print(&queue);

  // Schedule the tasks
  printf("\nScheduling tasks:\n");
  task_scheduler(&queue);

  return 0;
}