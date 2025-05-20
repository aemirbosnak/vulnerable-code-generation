//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CHECKIN_COUNTERS 5
#define NUM_BAGGAGE_HANDLERS 10

// Baggage struct
typedef struct {
  int id;
  char *destination;
  int weight;
} Baggage;

// Semaphore to protect the baggage queue
sem_t baggage_queue_sem;

// Queue of baggage
Baggage *baggage_queue[NUM_BAGS];
int baggage_queue_head = 0;
int baggage_queue_tail = 0;

// Semaphore to protect the baggage handlers
sem_t baggage_handlers_sem;

// Baggage handlers
pthread_t baggage_handlers[NUM_BAGGAGE_HANDLERS];

// Checkin counter threads
pthread_t checkin_counters[NUM_CHECKIN_COUNTERS];

// Function to add baggage to the queue
void add_baggage(Baggage *baggage) {
  // Wait for the semaphore
  sem_wait(&baggage_queue_sem);

  // Add the baggage to the queue
  baggage_queue[baggage_queue_tail] = baggage;
  baggage_queue_tail = (baggage_queue_tail + 1) % NUM_BAGS;

  // Signal the semaphore
  sem_post(&baggage_queue_sem);
}

// Function to get baggage from the queue
Baggage *get_baggage() {
  // Wait for the semaphore
  sem_wait(&baggage_queue_sem);

  // Get the baggage from the queue
  Baggage *baggage = baggage_queue[baggage_queue_head];
  baggage_queue_head = (baggage_queue_head + 1) % NUM_BAGS;

  // Signal the semaphore
  sem_post(&baggage_queue_sem);

  // Return the baggage
  return baggage;
}

// Function for the baggage handlers
void *baggage_handler(void *args) {
  while (1) {
    // Wait for the semaphore
    sem_wait(&baggage_handlers_sem);

    // Get baggage from the queue
    Baggage *baggage = get_baggage();

    // Handle the baggage
    printf("Baggage handler %d handling baggage %d to %s\n", (int)pthread_self(), baggage->id, baggage->destination);

    // Signal the semaphore
    sem_post(&baggage_handlers_sem);
  }
}

// Function for the checkin counters
void *checkin_counter(void *args) {
  while (1) {
    // Create a new baggage
    Baggage *baggage = malloc(sizeof(Baggage));
    baggage->id = rand() % 100;
    baggage->destination = "Destination";
    baggage->weight = rand() % 50;

    // Add the baggage to the queue
    add_baggage(baggage);
  }
}

int main() {
  // Initialize the semaphores
  sem_init(&baggage_queue_sem, 0, 1);
  sem_init(&baggage_handlers_sem, 0, NUM_BAGGAGE_HANDLERS);

  // Create the baggage handlers
  for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
    pthread_create(&baggage_handlers[i], NULL, baggage_handler, NULL);
  }

  // Create the checkin counters
  for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
    pthread_create(&checkin_counters[i], NULL, checkin_counter, NULL);
  }

  // Join the threads
  for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
    pthread_join(baggage_handlers[i], NULL);
  }

  for (int i = 0; i < NUM_CHECKIN_COUNTERS; i++) {
    pthread_join(checkin_counters[i], NULL);
  }

  // Destroy the semaphores
  sem_destroy(&baggage_queue_sem);
  sem_destroy(&baggage_handlers_sem);

  return 0;
}