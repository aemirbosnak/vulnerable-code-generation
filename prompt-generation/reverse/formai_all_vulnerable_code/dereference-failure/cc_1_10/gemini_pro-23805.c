//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Define the task structure
typedef struct task {
  int id;
  double arrival_time;
  double service_time;
  double remaining_time;
  struct task *next;
} task_t;

// Define the task queue
typedef struct task_queue {
  task_t *head;
  task_t *tail;
  int size;
} task_queue_t;

// Create a new task
task_t *create_task(int id, double arrival_time, double service_time) {
  task_t *task = malloc(sizeof(task_t));
  task->id = id;
  task->arrival_time = arrival_time;
  task->service_time = service_time;
  task->remaining_time = service_time;
  task->next = NULL;
  return task;
}

// Enqueue a task into the queue
void enqueue_task(task_queue_t *queue, task_t *task) {
  if (queue->head == NULL) {
    queue->head = task;
    queue->tail = task;
  } else {
    queue->tail->next = task;
    queue->tail = task;
  }
  queue->size++;
}

// Dequeue a task from the queue
task_t *dequeue_task(task_queue_t *queue) {
  if (queue->head == NULL) {
    return NULL;
  } else {
    task_t *task = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
      queue->tail = NULL;
    }
    queue->size--;
    return task;
  }
}

// Print the tasks in the queue
void print_tasks(task_queue_t *queue) {
  task_t *task = queue->head;
  while (task != NULL) {
    printf("Task ID: %d, Arrival Time: %.2f, Service Time: %.2f, Remaining Time: %.2f\n", task->id, task->arrival_time, task->service_time, task->remaining_time);
    task = task->next;
  }
}

// Simulate the task scheduler
void simulate_scheduler(task_queue_t *queue, double quantum) {
  double time = 0.0;
  while (queue->size > 0) {
    task_t *task = dequeue_task(queue);
    if (task->remaining_time > quantum) {
      task->remaining_time -= quantum;
      enqueue_task(queue, task);
    } else {
      time += task->remaining_time;
      printf("Task ID: %d, Completion Time: %.2f\n", task->id, time);
      free(task);
    }
    time += quantum;
  }
}

// Generate a random task
task_t *generate_random_task() {
  int id = rand() % 100;
  double arrival_time = rand() % 100;
  double service_time = rand() % 100;
  return create_task(id, arrival_time, service_time);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Create a task queue
  task_queue_t queue;
  queue.head = NULL;
  queue.tail = NULL;
  queue.size = 0;

  // Generate 100 random tasks
  for (int i = 0; i < 100; i++) {
    task_t *task = generate_random_task();
    enqueue_task(&queue, task);
  }

  // Print the tasks in the queue
  printf("Initial Task Queue:\n");
  print_tasks(&queue);

  // Simulate the task scheduler with a quantum of 10
  printf("\nTask Completion Times with Quantum of 10:\n");
  simulate_scheduler(&queue, 10.0);

  return 0;
}