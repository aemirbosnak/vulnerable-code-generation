//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: light-weight
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Define a custom memory management function
void *my_malloc(size_t size) {
  // Allocate memory with the standard malloc function
  void *ptr = malloc(size);

  // Check if the allocation was successful
  if (ptr == NULL) {
    // If the allocation fails, print an error message and exit the program
    fprintf(stderr, "Error: malloc failed!\n");
    exit(1);
  }

  // Return the allocated memory
  return ptr;
}

// Define a custom memory free function
void my_free(void *ptr) {
  // Free the memory using the standard free function
  free(ptr);
}

// Define a custom memory reallocation function
void *my_realloc(void *ptr, size_t new_size) {
  // Reallocate memory with the standard realloc function
  void *new_ptr = realloc(ptr, new_size);

  // Check if the reallocation was successful
  if (new_ptr == NULL) {
    // If the reallocation fails, print an error message and exit the program
    fprintf(stderr, "Error: realloc failed!\n");
    exit(1);
  }

  // Return the reallocated memory
  return new_ptr;
}

// Define a custom memory management structure
typedef struct {
  void *ptr;
  size_t size;
} my_memory_block;

// Create a custom memory pool
my_memory_block *my_pool;

// Initialize the custom memory pool
void my_pool_init(size_t size) {
  // Allocate memory for the pool
  my_pool = (my_memory_block *)my_malloc(sizeof(my_memory_block) * size);

  // Set the initial size of the pool
  my_pool->size = size;

  // Set the initial pointer of the pool to NULL
  my_pool->ptr = NULL;
}

// Allocate memory from the custom memory pool
void *my_pool_malloc(size_t size) {
  // Check if the pool is initialized
  if (my_pool == NULL) {
    // If the pool is not initialized, print an error message and exit the program
    fprintf(stderr, "Error: memory pool not initialized!\n");
    exit(1);
  }

  // Check if there is enough space in the pool
  if (my_pool->ptr + size > my_pool->size) {
    // If there is not enough space in the pool, print an error message and exit the program
    fprintf(stderr, "Error: not enough space in pool!\n");
    exit(1);
  }

  // Allocate memory from the pool
  void *ptr = my_pool->ptr;

  // Increment the pool pointer
  my_pool->ptr += size;

  // Return the allocated memory
  return ptr;
}

// Free memory from the custom memory pool
void my_pool_free(void *ptr) {
  // Check if the pool is initialized
  if (my_pool == NULL) {
    // If the pool is not initialized, print an error message and exit the program
    fprintf(stderr, "Error: memory pool not initialized!\n");
    exit(1);
  }

  // Check if the pointer is in the pool
  if (ptr < my_pool->ptr || ptr > my_pool->ptr + my_pool->size) {
    // If the pointer is not in the pool, print an error message and exit the program
    fprintf(stderr, "Error: pointer not in pool!\n");
    exit(1);
  }

  // Free memory from the pool
  my_pool->ptr = ptr;
}

// Destroy the custom memory pool
void my_pool_destroy() {
  // Free the memory for the pool
  my_free(my_pool);
}

// Example usage of the custom memory management functions
int main() {
  // Allocate memory using the custom malloc function
  int *ptr1 = (int *)my_malloc(sizeof(int));

  // Reallocate memory using the custom realloc function
  ptr1 = (int *)my_realloc(ptr1, 2 * sizeof(int));

  // Free memory using the custom free function
  my_free(ptr1);

  // Create a custom memory pool
  my_pool_init(1024);

  // Allocate memory from the custom memory pool
  char *ptr2 = (char *)my_pool_malloc(100);

  // Free memory from the custom memory pool
  my_pool_free(ptr2);

  // Destroy the custom memory pool
  my_pool_destroy();

  return 0;
}