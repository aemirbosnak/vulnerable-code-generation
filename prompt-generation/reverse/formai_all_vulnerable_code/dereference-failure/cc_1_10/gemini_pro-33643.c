//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

// Custom memory allocator
void *my_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }
  return ptr;
}

// Custom memory deallocator
void my_free(void *ptr) {
  if (ptr) {
    free(ptr);
  }
}

// Custom memory tracker
typedef struct memory_block {
  size_t size;
  void *ptr;
  struct memory_block *next;
} memory_block;

memory_block *memory_blocks = NULL;

void add_memory_block(size_t size, void *ptr) {
  memory_block *new_block = my_malloc(sizeof(memory_block));
  new_block->size = size;
  new_block->ptr = ptr;
  new_block->next = memory_blocks;
  memory_blocks = new_block;
}

void remove_memory_block(void *ptr) {
  memory_block *prev = NULL;
  memory_block *current = memory_blocks;
  while (current) {
    if (current->ptr == ptr) {
      if (prev) {
        prev->next = current->next;
      } else {
        memory_blocks = current->next;
      }
      my_free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

// Custom memory allocator wrapper
void *xmalloc(size_t size) {
  void *ptr = my_malloc(size);
  add_memory_block(size, ptr);
  return ptr;
}

// Custom memory deallocator wrapper
void xfree(void *ptr) {
  remove_memory_block(ptr);
  my_free(ptr);
}

// Memory leak detector
void print_memory_leaks() {
  printf("Memory leaks:\n");
  memory_block *current = memory_blocks;
  while (current) {
    printf("  * %p: %ld bytes\n", current->ptr, current->size);
    current = current->next;
  }
}

// Memory usage tracker
size_t total_memory_allocated = 0;

void update_memory_usage(size_t size, int increment) {
  if (increment) {
    total_memory_allocated += size;
  } else {
    total_memory_allocated -= size;
  }
}

// Custom memory allocator that tracks usage
void *ymalloc(size_t size) {
  void *ptr = xmalloc(size);
  update_memory_usage(size, 1);
  return ptr;
}

// Custom memory deallocator that tracks usage
void yfree(void *ptr) {
  xfree(ptr);
  update_memory_usage(0, 1);
}

// Main program
int main() {
  // Allocate some memory
  int *arr = ymalloc(100 * sizeof(int));
  char *str = ymalloc(256);

  // Use the memory
  // ...

  // Free the memory
  yfree(arr);
  yfree(str);

  // Print memory leaks and usage
  print_memory_leaks();
  printf("Total memory allocated: %ld bytes\n", total_memory_allocated);

  return 0;
}