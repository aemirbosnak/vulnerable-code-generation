//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MEMORY_POOL_SIZE 1000
#define MEMORY_POOL_ALLOCATIONS 100

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

typedef struct memory_pool {
    memory_block_t* blocks;
    size_t capacity;
    size_t size;
} memory_pool_t;

void init_memory_pool(memory_pool_t* pool) {
    pool->blocks = malloc(MEMORY_POOL_SIZE);
    pool->capacity = MEMORY_POOL_SIZE;
    pool->size = 0;
}

void* alloc_memory(memory_pool_t* pool, size_t size) {
    if (pool->size + size > pool->capacity) {
        size_t new_capacity = pool->capacity * 2;
        memory_block_t* new_blocks = realloc(pool->blocks, new_capacity);
        if (new_blocks == NULL) {
            return NULL;
        }
        pool->blocks = new_blocks;
        pool->capacity = new_capacity;
    }

    void* data = NULL;
    size_t remaining = pool->size;
    while (remaining < size) {
        size_t block_size = remaining > pool->capacity ? pool->capacity : remaining;
        memory_block_t* block = pool->blocks + pool->size;
        pool->size += block_size;
        data = block->data;
        block->data = NULL;
        block->size = 0;
        remaining -= block_size;
    }

    return data;
}

void free_memory(memory_pool_t* pool, void* data) {
    if (data == NULL) {
        return;
    }

    memory_block_t* block = (memory_block_t*) data;
    size_t index = pool->size - block->size;
    pool->size -= block->size;

    if (index < MEMORY_POOL_ALLOCATIONS) {
        pool->blocks[index].data = block->data;
        pool->blocks[index].size = block->size;
    } else {
        memory_block_t* new_block = malloc(sizeof(memory_block_t));
        new_block->data = block->data;
        new_block->size = block->size;
        new_block->next = pool->blocks + index;
        pool->blocks[index].data = new_block;
        pool->blocks[index].size = 0;
    }

    block->data = NULL;
    block->size = 0;
}

int main() {
    memory_pool_t pool;
    init_memory_pool(&pool);

    void* data1 = alloc_memory(&pool, 100);
    void* data2 = alloc_memory(&pool, 200);
    void* data3 = alloc_memory(&pool, 300);

    free_memory(&pool, data1);
    free_memory(&pool, data2);
    free_memory(&pool, data3);

    return 0;
}