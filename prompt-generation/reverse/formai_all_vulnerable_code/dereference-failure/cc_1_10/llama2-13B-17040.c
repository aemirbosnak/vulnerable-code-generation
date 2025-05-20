//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_POOL_SIZE 1024
#define MEMORY_POOL_COUNT 10

typedef struct memory_pool_t {
    void* mem;
    size_t size;
    struct memory_pool_t* next;
} memory_pool_t;

memory_pool_t* create_memory_pool(size_t size) {
    memory_pool_t* pool = (memory_pool_t*)calloc(1, sizeof(memory_pool_t));
    pool->mem = malloc(size);
    pool->size = size;
    pool->next = NULL;
    return pool;
}

void destroy_memory_pool(memory_pool_t* pool) {
    free(pool->mem);
    free(pool);
}

void* allocate_memory(size_t size) {
    memory_pool_t* pool = NULL;
    for (int i = 0; i < MEMORY_POOL_COUNT; i++) {
        if (pool == NULL || pool->size < size) {
            pool = create_memory_pool(size);
        }
        void* mem = pool->mem;
        pool = pool->next;
        return mem;
    }
    return NULL;
}

void deallocate_memory(void* mem, size_t size) {
    memory_pool_t* pool = NULL;
    for (int i = 0; i < MEMORY_POOL_COUNT; i++) {
        if (pool == NULL || pool->size < size) {
            pool = pool->next;
        }
        if (pool->mem == mem && pool->size == size) {
            destroy_memory_pool(pool);
            return;
        }
    }
    fprintf(stderr, "Memory not found\n");
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        size_t size = rand() % 1024;
        void* mem = allocate_memory(size);
        if (mem == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        deallocate_memory(mem, size);
    }
    return 0;
}