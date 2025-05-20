//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Global variables
int num_bags = 0;
int num_threads = 0;
int num_belts = 0;
int *belts;
int *bags;
pthread_mutex_t lock;
pthread_cond_t cond;

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to simulate a baggage handler
void *baggage_handler(void *arg) {
  int id = *(int *)arg;
  while (1) {
    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Wait for a bag to be available
    while (num_bags == 0) {
      pthread_cond_wait(&cond, &lock);
    }

    // Get a bag
    int bag = bags[--num_bags];
    printf("Baggage handler %d picked up bag %d\n", id, bag);

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Simulate moving the bag to a belt
    int belt = rand_range(0, num_belts - 1);
    belts[belt]++;
    printf("Baggage handler %d moved bag %d to belt %d\n", id, bag, belt);
  }
  return NULL;
}

// Function to simulate a baggage belt
void *baggage_belt(void *arg) {
  int id = *(int *)arg;
  while (1) {
    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Wait for a bag to be available on the belt
    while (belts[id] == 0) {
      pthread_cond_wait(&cond, &lock);
    }

    // Get a bag
    int bag = belts[id]--;
    printf("Baggage belt %d picked up bag %d\n", id, bag);

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Simulate moving the bag to the claim area
    printf("Baggage belt %d moved bag %d to the claim area\n", id, bag);
  }
  return NULL;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of bags, threads, and belts
  printf("Enter the number of bags: ");
  scanf("%d", &num_bags);
  printf("Enter the number of baggage handlers: ");
  scanf("%d", &num_threads);
  printf("Enter the number of baggage belts: ");
  scanf("%d", &num_belts);

  // Allocate memory for the bags and belts
  bags = (int *)malloc(num_bags * sizeof(int));
  belts = (int *)malloc(num_belts * sizeof(int));

  // Initialize the bags and belts
  for (int i = 0; i < num_bags; i++) {
    bags[i] = i + 1;
  }
  for (int i = 0; i < num_belts; i++) {
    belts[i] = 0;
  }

  // Initialize the lock and condition variable
  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&cond, NULL);

  // Create the baggage handler threads
  pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
  for (int i = 0; i < num_threads; i++) {
    int *id = (int *)malloc(sizeof(int));
    *id = i;
    pthread_create(&threads[i], NULL, baggage_handler, id);
  }

  // Create the baggage belt threads
  pthread_t *belts_threads = (pthread_t *)malloc(num_belts * sizeof(pthread_t));
  for (int i = 0; i < num_belts; i++) {
    int *id = (int *)malloc(sizeof(int));
    *id = i;
    pthread_create(&belts_threads[i], NULL, baggage_belt, id);
  }

  // Join the threads
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
  for (int i = 0; i < num_belts; i++) {
    pthread_join(belts_threads[i], NULL);
  }

  // Destroy the lock and condition variable
  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond);

  // Free the memory
  free(bags);
  free(belts);
  free(threads);
  free(belts_threads);

  return 0;
}