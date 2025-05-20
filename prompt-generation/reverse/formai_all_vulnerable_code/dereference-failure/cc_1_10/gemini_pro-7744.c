//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// The number of threads to create
#define NUM_THREADS 4

// The maximum number of primes to find
#define MAX_PRIMES 1000000

// The shared array of primes
int primes[MAX_PRIMES];

// The number of primes found so far
int num_primes = 0;

// The mutex lock for the shared array
pthread_mutex_t primes_lock;

// The condition variable for the shared array
pthread_cond_t primes_cond;

// The thread function
void *find_primes(void *arg) {
  // Get the thread ID
  int tid = *(int *)arg;

  // Iterate over the odd numbers starting from tid
  for (int i = tid * 2 + 1; i < MAX_PRIMES; i += NUM_THREADS) {
    // Check if the number is prime
    int is_prime = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }

    // If the number is prime, add it to the shared array
    if (is_prime) {
      pthread_mutex_lock(&primes_lock);
      primes[num_primes++] = i;
      pthread_mutex_unlock(&primes_lock);

      // Signal the condition variable to wake up the main thread
      pthread_cond_signal(&primes_cond);
    }
  }

  // Return NULL to indicate that the thread has finished
  return NULL;
}

int main() {
  // Initialize the mutex lock and condition variable
  pthread_mutex_init(&primes_lock, NULL);
  pthread_cond_init(&primes_cond, NULL);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, find_primes, &i);
  }

  // Wait for the threads to finish
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the primes
  for (int i = 0; i < num_primes; i++) {
    printf("%d\n", primes[i]);
  }

  // Destroy the mutex lock and condition variable
  pthread_mutex_destroy(&primes_lock);
  pthread_cond_destroy(&primes_cond);

  return 0;
}