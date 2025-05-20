//Gemma-7B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ALLOC 1024

typedef struct MemBlock {
  struct MemBlock* next;
  void* data;
  int size;
  char* name;
} MemBlock;

MemBlock* head = NULL;

void* alloc(int size, char* name) {
  MemBlock* newBlock = malloc(sizeof(MemBlock) + size);
  newBlock->next = head;
  head = newBlock;
  newBlock->size = size;
  newBlock->name = name;
  newBlock->data = (void*) ((char*) newBlock + sizeof(MemBlock));
  return newBlock->data;
}

void free(void* ptr) {
  MemBlock* prev = NULL;
  MemBlock* current = head;
  while (current) {
    if (current->data == ptr) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
  return;
}

int main() {
  alloc(10, "John Doe");
  alloc(20, "Jane Doe");
  alloc(30, "Peter Pan");
  free(alloc(40, "Mr. T"));
  free(alloc(50, "Mary Poppins"));
  return 0;
}