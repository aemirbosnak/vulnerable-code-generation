//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the number of threads to create
#define NUM_THREADS 4

// Define the number of elements in the array
#define ARRAY_SIZE 10

// Create a mutex to protect the array
pthread_mutex_t mutex;

// Create a condition variable to signal when the array is full
pthread_cond_t cond_full;

// Create a condition variable to signal when the array is empty
pthread_cond_t cond_empty;

// Create an array to store the data
int array[ARRAY_SIZE];

// Create a variable to store the index of the next element to be added to the array
int next_in = 0;

// Create a variable to store the index of the next element to be removed from the array
int next_out = 0;

// Create a variable to store the number of elements in the array
int count = 0;

// Create a function to be executed by each thread
void *thread_function(void *arg) {
  int id = *(int *)arg;

  while (1) {
    // Acquire the mutex lock
    pthread_mutex_lock(&mutex);

    // Wait until the array is not full
    while (count == ARRAY_SIZE) {
      pthread_cond_wait(&cond_full, &mutex);
    }

    // Add an element to the array
    array[next_in] = id;
    next_in = (next_in + 1) % ARRAY_SIZE;
    count++;

    // Signal that the array is not empty
    pthread_cond_signal(&cond_empty);

    // Release the mutex lock
    pthread_mutex_unlock(&mutex);

    // Sleep for a random amount of time
    usleep(rand() % 1000000);
  }

  return NULL;
}

int main() {
  // Initialize the mutex and condition variables
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cond_full, NULL);
  pthread_cond_init(&cond_empty, NULL);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    int *id = malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], NULL, thread_function, id);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex and condition variables
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&cond_full);
  pthread_cond_destroy(&cond_empty);

  return 0;
}