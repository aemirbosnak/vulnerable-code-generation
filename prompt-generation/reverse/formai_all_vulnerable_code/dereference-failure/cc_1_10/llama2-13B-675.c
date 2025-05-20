//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a "Happy Memory"
struct HappyMemory {
  void* data;  // The memory we're managing
  size_t size; // The size of the memory block
  struct HappyMemory* next; // The next memory block in the list
};

// Define a function to create a new Happy Memory block
struct HappyMemory* create_happy_memory(size_t size) {
  struct HappyMemory* new_mem = (struct HappyMemory*) malloc(size);
  new_mem->data = malloc(size);
  new_mem->size = size;
  new_mem->next = NULL;
  return new_mem;
}

// Define a function to free a Happy Memory block
void free_happy_memory(struct HappyMemory* mem) {
  if (mem == NULL) {
    printf("Whoops! Can't free NULL memory :(");
    return;
  }
  free(mem->data);
  free(mem);
}

// Define a function to allocate and free a Happy Memory block
struct HappyMemory* allocate_happy_memory(size_t size) {
  struct HappyMemory* mem = create_happy_memory(size);
  mem->data = malloc(size);
  return mem;
}

int main() {
  // Create a Happy Memory block of 100 bytes
  struct HappyMemory* mem1 = allocate_happy_memory(100);

  // Create another Happy Memory block of 200 bytes
  struct HappyMemory* mem2 = allocate_happy_memory(200);

  // Link the two Happy Memory blocks together
  mem1->next = mem2;

  // Print out the Happy Memory block list
  printf("Happy Memory List:\n");
  struct HappyMemory* current = mem1;
  while (current != NULL) {
    printf("[%zu] %p\n", current->size, current->data);
    current = current->next;
  }

  // Free the Happy Memory blocks
  free_happy_memory(mem1);
  free_happy_memory(mem2);

  return 0;
}