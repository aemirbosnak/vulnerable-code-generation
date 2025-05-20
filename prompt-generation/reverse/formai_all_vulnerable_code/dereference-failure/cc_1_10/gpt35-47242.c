//FormAI DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024 * 1024 // block size of 1MB
#define NUM_BLOCKS 10           // number of blocks available
#define MEM_SIZE BLOCK_SIZE * NUM_BLOCKS // total memory size

typedef struct block {
  void *addr;
  int size;
  struct block *next;
} block;

block *head = NULL;

void *allocateMemory(int size) {
  if (size > BLOCK_SIZE) {
    printf("Error: requested memory size is greater than block size\n");
    return NULL;
  }

  block *curr = head;

  while (curr) {
    if (curr->size >= size) {
      curr->size -= size;
      void *allocatedMem = curr->addr;
      curr->addr += size;

      return allocatedMem;
    }
    curr = curr->next;
  }

  printf("Error: out of memory\n");
  return NULL;
}

int deallocateMemory(void *addr, int size) {
  if (addr == NULL) {
    printf("Error: invalid address\n");
    return -1;
  }

  block *curr = head;

  while (curr) {
    if (curr->addr == addr + size) {
      curr->addr = addr;
      curr->size += size;
      return 0;
    } else if (curr->next && curr->next->addr == addr) {
      curr->next->addr = addr;
      curr->next->size += size;
      return 0;
    }

    curr = curr->next;
  }

  printf("Error: invalid address\n");
  return -1;
}

int main() {
  void *memStart = malloc(MEM_SIZE);

  if (!memStart) {
    printf("Error: could not allocate memory\n");
    return -1;
  }

  for (int i = 0; i < NUM_BLOCKS; i++) {
    block *newBlock = malloc(sizeof(block));

    if (!newBlock) {
      printf("Error: could not allocate memory for block\n");
      return -1;
    }

    newBlock->addr = memStart + i * BLOCK_SIZE;
    newBlock->size = BLOCK_SIZE;
    newBlock->next = head;
    head = newBlock;
  }

  // allocate some memory
  void *allocatedMem1 = allocateMemory(128);
  void *allocatedMem2 = allocateMemory(256);

  // deallocate the first memory block
  deallocateMemory(allocatedMem1, 128);

  // allocate memory again, it should be from the first block
  void *allocatedMem3 = allocateMemory(64);

  free(memStart);
  memStart = NULL;

  return 0;
}