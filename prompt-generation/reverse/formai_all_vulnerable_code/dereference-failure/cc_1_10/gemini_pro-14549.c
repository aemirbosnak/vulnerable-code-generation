//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the number of baggage handlers and the size of the baggage queue
#define NUM_HANDLERS 4
#define QUEUE_SIZE 100

// Define the baggage queue and semaphores
sem_t queue_mutex;
sem_t queue_empty;
sem_t queue_full;
struct baggage_queue {
  int head;
  int tail;
  int count;
  int *items;
};
struct baggage_queue baggage_queue;

// Define the baggage handler threads
pthread_t handler_threads[NUM_HANDLERS];

// Initialize the baggage queue and semaphores
void init_baggage_queue() {
  baggage_queue.head = 0;
  baggage_queue.tail = 0;
  baggage_queue.count = 0;
  baggage_queue.items = malloc(QUEUE_SIZE * sizeof(int));
  sem_init(&queue_mutex, 0, 1);
  sem_init(&queue_empty, 0, 0);
  sem_init(&queue_full, 0, QUEUE_SIZE);
}

// Enqueue a baggage item into the queue
void enqueue(int item) {
  sem_wait(&queue_full);
  sem_wait(&queue_mutex);
  baggage_queue.items[baggage_queue.tail] = item;
  baggage_queue.tail = (baggage_queue.tail + 1) % QUEUE_SIZE;
  baggage_queue.count++;
  sem_post(&queue_mutex);
  sem_post(&queue_empty);
}

// Dequeue a baggage item from the queue
int dequeue() {
  sem_wait(&queue_empty);
  sem_wait(&queue_mutex);
  int item = baggage_queue.items[baggage_queue.head];
  baggage_queue.head = (baggage_queue.head + 1) % QUEUE_SIZE;
  baggage_queue.count--;
  sem_post(&queue_mutex);
  sem_post(&queue_full);
  return item;
}

// The baggage handler thread function
void *baggage_handler(void *args) {
  while (1) {
    // Wait for a baggage item to become available
    sem_wait(&queue_empty);

    // Dequeue the baggage item
    int item = dequeue();

    // Handle the baggage item
    printf("Handling baggage item %d\n", item);

    // Signal that the baggage item has been handled
    sem_post(&queue_full);
  }
}

// Main function
int main() {
  // Initialize the baggage queue and semaphores
  init_baggage_queue();

  // Create the baggage handler threads
  for (int i = 0; i < NUM_HANDLERS; i++) {
    pthread_create(&handler_threads[i], NULL, baggage_handler, NULL);
  }

  // Enqueue some baggage items into the queue
  for (int i = 0; i < 100; i++) {
    enqueue(i);
  }

  // Join the baggage handler threads
  for (int i = 0; i < NUM_HANDLERS; i++) {
    pthread_join(handler_threads[i], NULL);
  }

  return 0;
}