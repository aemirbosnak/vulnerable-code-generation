//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 1024
#define BLOCK_SIZE 32

struct memory_block {
    char *data;
    int size;
    struct memory_block *next;
};

struct memory_pool {
    struct memory_block *blocks;
    int block_count;
};

void init_memory_pool(struct memory_pool *pool) {
    pool->blocks = (struct memory_block *)malloc(MEMORY_SIZE);
    pool->block_count = 0;
}

void free_memory_block(struct memory_pool *pool, struct memory_block *block) {
    if (block == NULL) {
        printf("Oops! Attempt to free a NULL block!\n");
        return;
    }

    if (pool->block_count == 0) {
        printf("Attempt to free the last block! :(");
        return;
    }

    block->next = pool->blocks;
    pool->blocks = block;
    pool->block_count--;
}

void* malloc_memory(struct memory_pool *pool, int size) {
    if (size > MEMORY_SIZE) {
        printf("Oops! Requested memory size exceeds the pool size! :O\n");
        return NULL;
    }

    if (pool->block_count == 0) {
        printf("No more blocks available! :(");
        return NULL;
    }

    struct memory_block *block = pool->blocks;
    pool->blocks = block->next;
    block->next = NULL;
    pool->block_count--;

    char *data = block->data;
    block->data = NULL;
    return data;
}

void free_memory(struct memory_pool *pool, void *memory) {
    if (memory == NULL) {
        printf("Oops! Attempt to free a NULL memory block!\n");
        return;
    }

    char *data = memory;
    struct memory_block *block = (struct memory_block *)data;

    if (block == NULL) {
        printf("Oops! Attempt to free a non-block memory! :O\n");
        return;
    }

    free_memory_block(pool, block);
}

int main() {
    struct memory_pool pool;
    init_memory_pool(&pool);

    void *ptr1 = malloc_memory(&pool, 10);
    void *ptr2 = malloc_memory(&pool, 20);
    void *ptr3 = malloc_memory(&pool, 30);

    printf("Memory pool size: %d\n", pool.block_count);

    free_memory(&pool, ptr1);
    free_memory(&pool, ptr2);
    free_memory(&pool, ptr3);

    printf("Memory pool size: %d\n", pool.block_count);

    return 0;
}