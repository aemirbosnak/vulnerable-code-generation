//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Number of threads
#define NUM_THREADS 4

// Size of the array
#define ARRAY_SIZE 1000000

// Array to be searched
int *array;

// Target value
int target;

// Index of the target value in the array
int result = -1;

// Semaphore to protect the result variable
sem_t result_lock;

// Thread function
void *search(void *arg) {
  // Get the thread ID
  int tid = *(int *)arg;

  // Calculate the range of elements to be searched by this thread
  int start = tid * ARRAY_SIZE / NUM_THREADS;
  int end = (tid + 1) * ARRAY_SIZE / NUM_THREADS;

  // Search the range for the target value
  for (int i = start; i < end; i++) {
    if (array[i] == target) {
      // Acquire the semaphore to protect the result variable
      sem_wait(&result_lock);

      // Update the result variable
      result = i;

      // Release the semaphore
      sem_post(&result_lock);

      // Break out of the loop
      break;
    }
  }

  // Return NULL to indicate that the target value was not found by this thread
  return NULL;
}

int main() {
  // Initialize the semaphore
  sem_init(&result_lock, 0, 1);

  // Allocate memory for the array
  array = malloc(ARRAY_SIZE * sizeof(int));

  // Initialize the array with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 1000000;
  }

  // Get the target value from the user
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    int *tid = malloc(sizeof(int));
    *tid = i;
    pthread_create(&threads[i], NULL, search, tid);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Check if the target value was found
  if (result != -1) {
    printf("Target value found at index %d\n", result);
  } else {
    printf("Target value not found\n");
  }

  // Free the memory allocated for the array
  free(array);

  // Destroy the semaphore
  sem_destroy(&result_lock);

  return 0;
}