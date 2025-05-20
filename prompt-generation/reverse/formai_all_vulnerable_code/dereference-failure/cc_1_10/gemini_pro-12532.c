//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the number of threads
#define NUM_THREADS 10

// Define the thread data structure
typedef struct thread_data {
  int id;
  int *sum;
} thread_data;

// Define the thread function
void *thread_function(void *arg) {
  // Get the thread data
  thread_data *data = (thread_data *)arg;

  // Initialize the local sum
  int local_sum = 0;

  // Generate a random number
  srand(time(NULL) + data->id);
  int random_number = rand() % 100;

  // Add the random number to the local sum
  local_sum += random_number;

  // Print the local sum
  printf("Thread %d: %d\n", data->id, local_sum);

  // Add the local sum to the global sum
  *data->sum += local_sum;

  // Return the thread data
  return (void *)data;
}

// Main function
int main() {
  // Create the thread data
  thread_data data[NUM_THREADS];

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    data[i].id = i;
    data[i].sum = malloc(sizeof(int));
    *data[i].sum = 0;
    pthread_create(&threads[i], NULL, thread_function, &data[i]);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the global sum
  int global_sum = 0;
  for (int i = 0; i < NUM_THREADS; i++) {
    global_sum += *data[i].sum;
    free(data[i].sum);
  }
  printf("Global sum: %d\n", global_sum);

  return 0;
}