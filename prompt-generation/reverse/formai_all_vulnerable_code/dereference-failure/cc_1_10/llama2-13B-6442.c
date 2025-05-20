//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MEMORY_POOL_SIZE (1024 * 1024 * 10)

struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
};

struct memory_pool {
    struct memory_block* blocks;
    size_t capacity;
    size_t used;
};

static void* allocate_memory(struct memory_pool* pool, size_t size) {
    for (struct memory_block* block = pool->blocks; block; block = block->next) {
        if (block->size >= size) {
            void* data = block->data;
            block->size -= size;
            return data;
        }
    }
    if (pool->capacity - pool->used >= size) {
        void* data = malloc(size);
        if (!data) {
            perror("malloc");
            return NULL;
        }
        pool->used += size;
        return data;
    }
    return NULL;
}

static void deallocate_memory(struct memory_pool* pool, void* data) {
    for (struct memory_block* block = pool->blocks; block; block = block->next) {
        if (block->data == data) {
            block->size += data - block->data;
            return;
        }
    }
    free(data);
}

int main() {
    srand(time(NULL));
    struct memory_pool* pool = malloc(sizeof(struct memory_pool));
    if (!pool) {
        perror("malloc");
        return 1;
    }
    pool->blocks = malloc(MEMORY_POOL_SIZE);
    if (!pool->blocks) {
        perror("malloc");
        free(pool);
        return 1;
    }
    pool->capacity = MEMORY_POOL_SIZE;
    pool->used = 0;

    for (size_t i = 0; i < 1000; i++) {
        void* data = allocate_memory(pool, rand() % 100 + 1);
        if (!data) {
            break;
        }
        printf("Allocated %zu bytes at %p\n", data - pool->blocks->data, data);
        deallocate_memory(pool, data);
    }

    free(pool->blocks);
    free(pool);
    return 0;
}