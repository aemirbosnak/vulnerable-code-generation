//Gemma-7B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALLOC 1024

typedef struct MemoryBlock {
  struct MemoryBlock* next;
  void* data;
  size_t size;
  size_t used;
} MemoryBlock;

MemoryBlock* head = NULL;

void* alloc(size_t size) {
  if (head == NULL) {
    head = malloc(sizeof(MemoryBlock));
    head->next = NULL;
    head->data = malloc(MAX_ALLOC);
    head->size = MAX_ALLOC;
    head->used = 0;
  }

  size_t alloc_size = size + 1;
  MemoryBlock* new_block = malloc(sizeof(MemoryBlock));
  new_block->next = head;
  new_block->data = malloc(alloc_size);
  new_block->size = alloc_size;
  new_block->used = 0;
  head = new_block;

  return new_block->data;
}

void free(void* ptr) {
  MemoryBlock* current = head;
  MemoryBlock* previous = NULL;

  while (current) {
    if (current->data == ptr) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }

      free(current->data);
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  return;
}

int main() {
  void* ptr = alloc(10);
  strcpy(ptr, "Hello, world!");
  printf("%s\n", ptr);

  free(ptr);
  ptr = alloc(20);
  strcpy(ptr, "Goodbye, cruel world!");
  printf("%s\n", ptr);

  free(ptr);

  return 0;
}