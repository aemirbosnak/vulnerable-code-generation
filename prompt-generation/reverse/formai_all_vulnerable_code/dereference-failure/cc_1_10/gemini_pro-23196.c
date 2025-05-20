//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define the task structure.
typedef struct {
  int id;
  void (*task_func)(void*);
  void* arg;
} task_t;

// Define the task queue.
typedef struct {
  task_t* tasks;
  int head;
  int tail;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} task_queue_t;

// Initialize the task queue.
void task_queue_init(task_queue_t* queue) {
  queue->tasks = malloc(sizeof(task_t) * 100);
  queue->head = 0;
  queue->tail = 0;
  pthread_mutex_init(&queue->mutex, NULL);
  pthread_cond_init(&queue->cond, NULL);
}

// Destroy the task queue.
void task_queue_destroy(task_queue_t* queue) {
  free(queue->tasks);
  pthread_mutex_destroy(&queue->mutex);
  pthread_cond_destroy(&queue->cond);
}

// Enqueue a task.
void task_queue_enqueue(task_queue_t* queue, task_t task) {
  pthread_mutex_lock(&queue->mutex);
  queue->tasks[queue->tail] = task;
  queue->tail = (queue->tail + 1) % 100;
  pthread_cond_signal(&queue->cond);
  pthread_mutex_unlock(&queue->mutex);
}

// Dequeue a task.
task_t task_queue_dequeue(task_queue_t* queue) {
  pthread_mutex_lock(&queue->mutex);
  while (queue->head == queue->tail) {
    pthread_cond_wait(&queue->cond, &queue->mutex);
  }
  task_t task = queue->tasks[queue->head];
  queue->head = (queue->head + 1) % 100;
  pthread_mutex_unlock(&queue->mutex);
  return task;
}

// Task function.
void task_func(void* arg) {
  printf("Task %d running.\n", *(int*)arg);
  sleep(1);
  printf("Task %d finished.\n", *(int*)arg);
}

// Main function.
int main() {
  // Create the task queue.
  task_queue_t queue;
  task_queue_init(&queue);

  // Create the tasks.
  for (int i = 0; i < 100; i++) {
    task_t task;
    task.id = i;
    task.task_func = task_func;
    task.arg = &i;
    task_queue_enqueue(&queue, task);
  }

  // Create the threads.
  pthread_t threads[10];
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, (void*(*)(void*))task_queue_dequeue, &queue);
  }

  // Join the threads.
  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the task queue.
  task_queue_destroy(&queue);

  return 0;
}