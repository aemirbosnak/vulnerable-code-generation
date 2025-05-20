//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 10

// Define the maximum number of threads that can be used
#define MAX_THREADS 4

// Define the structure of an item
typedef struct item {
  char *name;
  int quantity;
} item_t;

// Define the structure of the warehouse
typedef struct warehouse {
  item_t *items;
  int num_items;
  sem_t mutex;
  sem_t empty;
  sem_t full;
} warehouse_t;

// Initialize the warehouse
void warehouse_init(warehouse_t *warehouse) {
  warehouse->items = malloc(sizeof(item_t) * MAX_ITEMS);
  warehouse->num_items = 0;
  sem_init(&warehouse->mutex, 0, 1);
  sem_init(&warehouse->empty, 0, MAX_ITEMS);
  sem_init(&warehouse->full, 0, 0);
}

// Destroy the warehouse
void warehouse_destroy(warehouse_t *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->items[i].name);
  }
  free(warehouse->items);
  sem_destroy(&warehouse->mutex);
  sem_destroy(&warehouse->empty);
  sem_destroy(&warehouse->full);
}

// Produce an item
void produce(warehouse_t *warehouse, item_t *item) {
  // Wait for the warehouse to have space for another item
  sem_wait(&warehouse->empty);

  // Lock the warehouse
  sem_wait(&warehouse->mutex);

  // Add the item to the warehouse
  warehouse->items[warehouse->num_items] = *item;
  warehouse->num_items++;

  // Unlock the warehouse
  sem_post(&warehouse->mutex);

  // Signal that the warehouse is no longer empty
  sem_post(&warehouse->full);
}

// Consume an item
void consume(warehouse_t *warehouse, item_t *item) {
  // Wait for the warehouse to have an item
  sem_wait(&warehouse->full);

  // Lock the warehouse
  sem_wait(&warehouse->mutex);

  // Remove the item from the warehouse
  *item = warehouse->items[warehouse->num_items - 1];
  warehouse->num_items--;

  // Unlock the warehouse
  sem_post(&warehouse->mutex);

  // Signal that the warehouse is no longer full
  sem_post(&warehouse->empty);
}

// Thread function
void *thread_function(void *arg) {
  warehouse_t *warehouse = (warehouse_t *) arg;
  item_t item;

  while (1) {
    // Produce an item
    item.name = malloc(10);
    sprintf(item.name, "Item %d", rand() % 100);
    item.quantity = rand() % 10;
    produce(warehouse, &item);

    // Sleep for a random amount of time
    sleep(rand() % 5);

    // Consume an item
    consume(warehouse, &item);

    // Sleep for a random amount of time
    sleep(rand() % 5);
  }

  return NULL;
}

// Main function
int main(int argc, char **argv) {
  warehouse_t warehouse;
  pthread_t threads[MAX_THREADS];

  // Initialize the warehouse
  warehouse_init(&warehouse);

  // Create the threads
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, &warehouse);
  }

  // Join the threads
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the warehouse
  warehouse_destroy(&warehouse);

  return 0;
}