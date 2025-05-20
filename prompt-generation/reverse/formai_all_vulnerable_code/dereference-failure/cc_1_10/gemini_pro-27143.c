//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>

// Allocate a block of memory with a size of n bytes
void* my_malloc(size_t n) {
  void* p = malloc(n);
  if (p == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(1);
  }
  return p;
}

// Free a block of memory that was previously allocated with my_malloc
void my_free(void* p) {
  free(p);
}

// Reallocate a block of memory that was previously allocated with my_malloc
void* my_realloc(void* p, size_t n) {
  void* q = realloc(p, n);
  if (q == NULL) {
    fprintf(stderr, "Error: realloc failed\n");
    exit(1);
  }
  return q;
}

// A simple memory manager that uses my_malloc, my_free, and my_realloc
void* my_memory_manager(size_t n) {
  static void* p = NULL;
  static size_t size = 0;

  if (n == 0) {
    // Free the memory block
    my_free(p);
    p = NULL;
    size = 0;
    return NULL;
  } else if (n <= size) {
    // The requested size is smaller than or equal to the current size, so just return a pointer to the existing memory block
    return p;
  } else {
    // The requested size is larger than the current size, so reallocate the memory block
    p = my_realloc(p, n);
    size = n;
    return p;
  }
}

// A simple example of how to use the my_memory_manager
int main() {
  int* p = (int*)my_memory_manager(sizeof(int));
  *p = 42;
  printf("%d\n", *p);

  // Reallocate the memory block to a larger size
  p = (int*)my_memory_manager(sizeof(int) * 2);
  p[1] = 24;
  printf("%d %d\n", p[0], p[1]);

  // Free the memory block
  my_memory_manager(0);

  return 0;
}