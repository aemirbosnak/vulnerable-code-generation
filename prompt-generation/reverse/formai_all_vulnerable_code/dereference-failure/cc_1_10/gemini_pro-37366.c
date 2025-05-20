//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads to use
#define NUM_THREADS 4

// Define the number of simulations to run
#define NUM_SIMULATIONS 1000000

// Define the probability of an alien invasion
#define PROBABILITY_OF_INVASION 0.01

// Declare the mutex
pthread_mutex_t mutex;

// Declare the shared variable
int num_invasions;

// Define the thread function
void *thread_function(void *arg) {
  // Get the thread ID
  int thread_id = *(int *)arg;

  // Run the simulations
  for (int i = 0; i < NUM_SIMULATIONS; i++) {
    // Generate a random number
    double random_number = (double)rand() / RAND_MAX;

    // Check if the random number is less than the probability of invasion
    if (random_number < PROBABILITY_OF_INVASION) {
      // Increment the number of invasions
      pthread_mutex_lock(&mutex);
      num_invasions++;
      pthread_mutex_unlock(&mutex);
    }
  }

  // Return NULL
  return NULL;
}

// Define the main function
int main() {
  // Initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // Initialize the number of invasions
  num_invasions = 0;

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    int *thread_id = malloc(sizeof(int));
    *thread_id = i;
    pthread_create(&threads[i], NULL, thread_function, thread_id);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  // Print the number of invasions
  printf("The number of invasions is: %d\n", num_invasions);

  // Return 0
  return 0;
}