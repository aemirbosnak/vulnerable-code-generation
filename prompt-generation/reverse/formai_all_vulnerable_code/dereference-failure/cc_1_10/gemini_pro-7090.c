//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_BLOCKS 100

// Define a memory block
struct memory_block {
  void* data;
  size_t size;
  int allocated;
};

// Create a global memory pool
static struct memory_block memory_pool[NUM_BLOCKS];

// Create a mutex to protect the memory pool
pthread_mutex_t memory_pool_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to allocate a memory block
void* allocate_memory(size_t size) {
  // Lock the memory pool
  pthread_mutex_lock(&memory_pool_mutex);

  // Find a free memory block
  for (int i = 0; i < NUM_BLOCKS; i++) {
    if (!memory_pool[i].allocated) {
      // Allocate the memory block
      memory_pool[i].data = malloc(size);
      memory_pool[i].size = size;
      memory_pool[i].allocated = 1;

      // Unlock the memory pool
      pthread_mutex_unlock(&memory_pool_mutex);

      // Return the memory block
      return memory_pool[i].data;
    }
  }

  // No free memory blocks found
  pthread_mutex_unlock(&memory_pool_mutex);
  return NULL;
}

// Function to free a memory block
void free_memory(void* data) {
  // Lock the memory pool
  pthread_mutex_lock(&memory_pool_mutex);

  // Find the memory block
  for (int i = 0; i < NUM_BLOCKS; i++) {
    if (memory_pool[i].data == data) {
      // Free the memory block
      free(memory_pool[i].data);
      memory_pool[i].allocated = 0;

      // Unlock the memory pool
      pthread_mutex_unlock(&memory_pool_mutex);

      // Return
      return;
    }
  }

  // Memory block not found
  pthread_mutex_unlock(&memory_pool_mutex);
}

// Thread function
void* thread_function(void* arg) {
  // Allocate memory
  void* data = allocate_memory(1024);

  // Use the memory
  // ...

  // Free the memory
  free_memory(data);

  return NULL;
}

// Main function
int main() {
  // Create threads
  pthread_t threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_function, NULL);
  }

  // Join threads
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}