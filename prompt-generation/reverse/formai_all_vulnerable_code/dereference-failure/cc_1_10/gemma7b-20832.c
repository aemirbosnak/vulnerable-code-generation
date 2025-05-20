//Gemma-7B DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_MEMORY 1024

typedef struct MemBlock {
  struct MemBlock *next;
  void *ptr;
  int size;
} MemBlock;

MemBlock *head = NULL;

void *allocate(int size) {
  MemBlock *newBlock = malloc(sizeof(MemBlock) + size);
  newBlock->next = head;
  head = newBlock;
  newBlock->ptr = (void *)((char *)newBlock + sizeof(MemBlock));
  newBlock->size = size;
  return newBlock->ptr;
}

void free(void *ptr) {
  MemBlock *prev = NULL;
  MemBlock *curr = head;

  while (curr) {
    if (curr->ptr == ptr) {
      if (prev) {
        prev->next = curr->next;
      } else {
        head = curr->next;
      }
      free(curr);
      return;
    }
    prev = curr;
    curr = curr->next;
  }

  printf("Error: Pointer not found.\n");
  return;
}

int main() {
  allocate(10);
  allocate(20);
  allocate(30);
  allocate(40);

  free(allocate(50));
  free(allocate(60));

  return 0;
}