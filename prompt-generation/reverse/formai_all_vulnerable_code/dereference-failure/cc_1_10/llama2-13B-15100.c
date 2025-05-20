//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MEM_POOL_SIZE (1024 * 1024)
#define MEM_ALIGNMENT (64)

struct mem_pool {
    void* mem;
    size_t size;
    size_t capacity;
};

static inline void* alloc_mem(size_t size) {
    size_t aligned_size = (size + MEM_ALIGNMENT - 1) & ~(MEM_ALIGNMENT - 1);
    void* mem = malloc(aligned_size);
    if (!mem) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    return mem;
}

static inline void free_mem(void* mem) {
    free(mem);
}

struct mem_pool* create_mem_pool(size_t size) {
    struct mem_pool* pool = calloc(1, sizeof(struct mem_pool));
    pool->mem = alloc_mem(size);
    pool->size = size;
    pool->capacity = size;
    return pool;
}

void* alloc_mem_pool(struct mem_pool* pool, size_t size) {
    if (pool->size - pool->capacity < size) {
        size_t new_capacity = pool->capacity * 2;
        void* new_mem = alloc_mem(new_capacity);
        memcpy(new_mem, pool->mem, pool->size);
        free_mem(pool->mem);
        pool->mem = new_mem;
        pool->capacity = new_capacity;
    }
    return pool->mem + pool->size - pool->capacity;
}

void free_mem_pool(struct mem_pool* pool) {
    free_mem(pool->mem);
    pool->mem = NULL;
    pool->size = 0;
    pool->capacity = 0;
}

int main() {
    struct mem_pool* pool = create_mem_pool(MEM_POOL_SIZE);
    void* mem = alloc_mem_pool(pool, 100);
    void* mem2 = alloc_mem_pool(pool, 200);
    void* mem3 = alloc_mem_pool(pool, 300);
    free_mem_pool(pool);
    return 0;
}