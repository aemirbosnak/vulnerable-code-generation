//Gemma-7B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>

#define MAX_MEMORY 1024

typedef struct MemoryBlock {
  struct MemoryBlock* next;
  int size;
  void* data;
} MemoryBlock;

MemoryBlock* head = NULL;

void* allocate(int size) {
  MemoryBlock* newBlock = malloc(sizeof(MemoryBlock) + size);
  newBlock->size = size;
  newBlock->data = (void*) ((char*) newBlock + sizeof(MemoryBlock));
  newBlock->next = head;
  head = newBlock;
  return newBlock->data;
}

void free(void* ptr) {
  MemoryBlock* current = head;
  MemoryBlock* previous = NULL;
  while (current) {
    if (ptr == current->data) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  return;
}

int main() {
  allocate(50);
  allocate(20);
  allocate(30);
  allocate(10);
  free(allocate(20));
  free(allocate(30));
  return 0;
}