//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t size;
  void *data;
} Block;

typedef struct {
  size_t size;
  Block *blocks;
} Pool;

Pool *create_pool(size_t size) {
  Pool *pool = malloc(sizeof(Pool));
  pool->size = size;
  pool->blocks = malloc(sizeof(Block) * size);
  return pool;
}

void destroy_pool(Pool *pool) {
  free(pool->blocks);
  free(pool);
}

Block *allocate_block(Pool *pool, size_t size) {
  if (size <= 0) {
    return NULL;
  }

  for (size_t i = 0; i < pool->size; i++) {
    if (pool->blocks[i].size == 0) {
      pool->blocks[i].size = size;
      pool->blocks[i].data = malloc(size);
      return &pool->blocks[i];
    }
  }

  return NULL;
}

void free_block(Block *block) {
  if (block != NULL) {
    block->size = 0;
    free(block->data);
  }
}

int main() {
  Pool *pool = create_pool(10);

  Block *block1 = allocate_block(pool, 100);
  Block *block2 = allocate_block(pool, 200);
  Block *block3 = allocate_block(pool, 300);

  printf("Block 1: %p, Size: %zu\n", block1->data, block1->size);
  printf("Block 2: %p, Size: %zu\n", block2->data, block2->size);
  printf("Block 3: %p, Size: %zu\n", block3->data, block3->size);

  free_block(block1);
  free_block(block2);
  free_block(block3);

  destroy_pool(pool);

  return 0;
}