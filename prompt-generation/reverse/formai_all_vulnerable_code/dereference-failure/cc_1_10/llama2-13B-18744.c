//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_POOL_SIZE 1024
#define BLOCK_SIZE 16

typedef struct {
    void* data;
    size_t size;
    struct node* next;
} block_t;

typedef struct {
    block_t* head;
    block_t* tail;
    size_t used_size;
} memory_pool_t;

void init_memory_pool(memory_pool_t* pool) {
    pool->head = NULL;
    pool->tail = NULL;
    pool->used_size = 0;
}

void* alloc_memory(memory_pool_t* pool, size_t size) {
    block_t* new_block = NULL;
    size_t block_size = MEMORY_POOL_SIZE - pool->used_size;
    if (block_size < size) {
        new_block = (block_t*) malloc(sizeof(block_t));
        new_block->data = malloc(size);
        new_block->size = size;
        new_block->next = NULL;
        if (pool->tail == NULL) {
            pool->head = new_block;
        } else {
            pool->tail->next = new_block;
        }
        pool->tail = new_block;
        pool->used_size += size;
    }
    return new_block->data;
}

void free_memory(memory_pool_t* pool, void* data) {
    block_t* block = NULL;
    for (block = pool->head; block != NULL; block = block->next) {
        if (block->data == data) {
            break;
        }
    }
    if (block != NULL) {
        block->size -= (data - block->data);
        pool->used_size -= block->size;
        if (block == pool->tail) {
            pool->tail = block->next;
        }
        free(block->data);
        free(block);
    }
}

int main() {
    memory_pool_t pool;
    init_memory_pool(&pool);

    void* p1 = alloc_memory(&pool, 4);
    void* p2 = alloc_memory(&pool, 8);
    void* p3 = alloc_memory(&pool, 12);

    printf("Memory Pool Size: %zu\n", pool.used_size);

    free_memory(&pool, p1);
    free_memory(&pool, p2);
    free_memory(&pool, p3);

    printf("Memory Pool Size: %zu\n", pool.used_size);

    return 0;
}