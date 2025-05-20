//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define BLOCK_SIZE 1024

typedef struct {
  void *pointer;
  int size;
} block;

block memory[MAX_BLOCKS];
int blocks_allocated = 0;

void *dalloc(int size);
void dfree(void *ptr);
void print_blocks();

int main() {
  void *a, *b, *c;
  a = dalloc(512);
  b = dalloc(256);
  c = dalloc(128);
  print_blocks();
  dfree(b);
  print_blocks();
  dalloc(256);
  print_blocks();
  return 0;
}

void *dalloc(int size) {
  if (blocks_allocated == MAX_BLOCKS) {
    printf("Maximum number of blocks allocated. Cannot allocate more.\n");
    return NULL;
  }

  void *pointer = malloc(size);
  if (pointer == NULL) {
    printf("Memory allocation failed. Cannot allocate block of size %d\n", size);
    return NULL;
  }

  memory[blocks_allocated].pointer = pointer;
  memory[blocks_allocated].size = size;
  blocks_allocated++;

  printf("Allocated %d bytes at %p\n", size, pointer);
  return pointer;
}

void dfree(void *ptr) {
  int i;
  for (i=0; i<blocks_allocated; i++) {
    if (memory[i].pointer == ptr) {
      free(memory[i].pointer);
      memory[i].pointer = NULL;
      memory[i].size = 0;
      printf("Freed block at %p\n", ptr);
      return;
    }
  }
  printf("Block not found. Unable to free.\n");
}

void print_blocks() {
  printf("Total Blocks: %d\n", blocks_allocated);
  int i;
  for (i=0; i<blocks_allocated; i++) {
    printf("Block %d: Size: %d, Address: %p\n", i+1, memory[i].size, memory[i].pointer);
  }
  printf("---------------------------\n");
}