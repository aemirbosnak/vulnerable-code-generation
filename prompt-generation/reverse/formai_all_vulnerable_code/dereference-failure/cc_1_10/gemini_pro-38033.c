//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Defining the maximum number of philosophers
#define MAX_PHILOSOPHERS 5
// Defining the number of chopsticks
#define NUM_CHOPSTICKS 5

// Initialize the chopsticks
bool chopsticks[NUM_CHOPSTICKS];

// Initialize the philosophers
bool philosophers[MAX_PHILOSOPHERS];

// Initialize the semaphores
sem_t forks[NUM_CHOPSTICKS];
sem_t mutex;

// Philosopher routine
void *philosopher(void *arg) {
  int philosopher_id = *(int *)arg;
  while (true) {
    // Think
    printf("Philosopher %d is thinking\n", philosopher_id);
    sleep(1);

    // Get the chopsticks
    sem_wait(&forks[philosopher_id]);
    sem_wait(&forks[(philosopher_id + 1) % NUM_CHOPSTICKS]);

    // Eat
    printf("Philosopher %d is eating\n", philosopher_id);
    sleep(1);

    // Put down the chopsticks
    sem_post(&forks[philosopher_id]);
    sem_post(&forks[(philosopher_id + 1) % NUM_CHOPSTICKS]);
  }
  return NULL;
}

int main() {
  // Initialize the semaphores
  for (int i = 0; i < NUM_CHOPSTICKS; i++) {
    sem_init(&forks[i], 0, 1);
  }
  sem_init(&mutex, 0, 1);

  // Create the philosopher threads
  pthread_t philosopher_threads[MAX_PHILOSOPHERS];
  for (int i = 0; i < MAX_PHILOSOPHERS; i++) {
    int *philosopher_id = malloc(sizeof(int));
    *philosopher_id = i;
    pthread_create(&philosopher_threads[i], NULL, philosopher, philosopher_id);
  }

  // Join the philosopher threads
  for (int i = 0; i < MAX_PHILOSOPHERS; i++) {
    pthread_join(philosopher_threads[i], NULL);
  }

  // Destroy the semaphores
  for (int i = 0; i < NUM_CHOPSTICKS; i++) {
    sem_destroy(&forks[i]);
  }
  sem_destroy(&mutex);

  return 0;
}