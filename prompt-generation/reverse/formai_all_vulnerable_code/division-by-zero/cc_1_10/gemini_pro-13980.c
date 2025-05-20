//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The number of threads to use
#define NUM_THREADS 4

// The maximum number to check for primality
#define MAX_NUMBER 1000000

// The array of numbers to check for primality
int numbers[MAX_NUMBER];

// The array of prime numbers
int primes[MAX_NUMBER];

// The number of prime numbers found
int num_primes = 0;

// The mutex to protect the shared data
pthread_mutex_t mutex;

// The thread function
void *thread_function(void *arg) {
  // Get the thread's ID
  int thread_id = *(int *)arg;

  // Check for primality the numbers assigned to this thread
  for (int i = thread_id; i < MAX_NUMBER; i += NUM_THREADS) {
    // Check if the number is divisible by any of the prime numbers found so far
    int is_prime = 1;
    for (int j = 0; j < num_primes; j++) {
      if (numbers[i] % primes[j] == 0) {
        is_prime = 0;
        break;
      }
    }

    // If the number is prime, add it to the array of prime numbers
    if (is_prime) {
      pthread_mutex_lock(&mutex);
      primes[num_primes++] = numbers[i];
      pthread_mutex_unlock(&mutex);
    }
  }

  return NULL;
}

int main() {
  // Initialize the mutex
  pthread_mutex_init(&mutex, NULL);

  // Create the threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, (void *)&i);
  }

  // Join the threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&mutex);

  // Print the prime numbers
  for (int i = 0; i < num_primes; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");

  return 0;
}