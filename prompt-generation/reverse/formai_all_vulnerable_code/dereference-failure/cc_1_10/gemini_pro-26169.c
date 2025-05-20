//GEMINI-pro DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads to create
#define NUM_THREADS 5

// Define the data structure that will be passed to each thread
typedef struct thread_data {
  int thread_id;
  int num;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
  // Get the thread data
  thread_data_t *data = (thread_data_t *)arg;

  // Calculate the square of the number
  int result = data->num * data->num;

  // Print the result
  printf("Thread %d: %d squared is %d\n", data->thread_id, data->num, result);

  // Free the thread data
  free(data);

  // Return NULL to indicate that the thread has completed successfully
  return NULL;
}

int main() {
  // Create the thread data
  thread_data_t thread_data[NUM_THREADS];

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    thread_data[i].thread_id = i;
    thread_data[i].num = i + 1;
    pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
  }

  // Wait for the threads to complete
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}