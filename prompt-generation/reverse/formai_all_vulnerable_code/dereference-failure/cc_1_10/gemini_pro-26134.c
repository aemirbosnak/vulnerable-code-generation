//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define NUM_TASKS 10

// Define the task structure
typedef struct {
  int id;
  int duration;
} Task;

// Create a shared task queue
Task **task_queue;
int task_queue_size = 0;
int task_queue_front = 0;
int task_queue_rear = 0;

// Create a mutex to protect the task queue
pthread_mutex_t task_queue_mutex;

// Create a condition variable to signal when the task queue is not empty
pthread_cond_t task_queue_cond;

// Create a thread pool
pthread_t threads[NUM_THREADS];

// Create a function to add a task to the task queue
void add_task(Task *task) {
  // Lock the task queue mutex
  pthread_mutex_lock(&task_queue_mutex);

  // Add the task to the task queue
  task_queue[task_queue_rear] = task;
  task_queue_rear = (task_queue_rear + 1) % NUM_TASKS;
  task_queue_size++;

  // Signal that the task queue is not empty
  pthread_cond_signal(&task_queue_cond);

  // Unlock the task queue mutex
  pthread_mutex_unlock(&task_queue_mutex);
}

// Create a function to get a task from the task queue
Task *get_task() {
  // Lock the task queue mutex
  pthread_mutex_lock(&task_queue_mutex);

  // Wait until the task queue is not empty
  while (task_queue_size == 0) {
    pthread_cond_wait(&task_queue_cond, &task_queue_mutex);
  }

  // Get the task from the task queue
  Task *task = task_queue[task_queue_front];
  task_queue_front = (task_queue_front + 1) % NUM_TASKS;
  task_queue_size--;

  // Unlock the task queue mutex
  pthread_mutex_unlock(&task_queue_mutex);

  return task;
}

// Create a function to perform a task
void *perform_task(void *args) {
  while (1) {
    // Get a task from the task queue
    Task *task = get_task();

    // Perform the task
    sleep(task->duration);

    // Free the task
    free(task);
  }

  return NULL;
}

// Create a function to generate a random task
Task *generate_task() {
  // Create a new task
  Task *task = malloc(sizeof(Task));

  // Set the task's id
  task->id = rand() % 100;

  // Set the task's duration
  task->duration = rand() % 10;

  return task;
}

// Create a function to initialize the thread pool
void init_thread_pool() {
  // Create the task queue
  task_queue = malloc(sizeof(Task *) * NUM_TASKS);

  // Initialize the task queue mutex
  pthread_mutex_init(&task_queue_mutex, NULL);

  // Initialize the task queue condition variable
  pthread_cond_init(&task_queue_cond, NULL);

  // Create the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, perform_task, NULL);
  }
}

// Create a function to destroy the thread pool
void destroy_thread_pool() {
  // Destroy the task queue mutex
  pthread_mutex_destroy(&task_queue_mutex);

  // Destroy the task queue condition variable
  pthread_cond_destroy(&task_queue_cond);

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Free the task queue
  free(task_queue);
}

// Create a function to test the thread pool
void test_thread_pool() {
  // Initialize the thread pool
  init_thread_pool();

  // Generate a random task
  Task *task = generate_task();

  // Add the task to the task queue
  add_task(task);

  // Wait for the task to complete
  sleep(task->duration + 1);

  // Destroy the thread pool
  destroy_thread_pool();
}

// Create the main function
int main() {
  // Test the thread pool
  test_thread_pool();

  return 0;
}