//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024

struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
};

struct memory_pool {
    struct memory_block* block;
    size_t current_size;
};

void init_memory_pool(struct memory_pool* pool) {
    pool->block = malloc(MAX_MEMORY);
    pool->current_size = 0;
}

void* alloc_memory(struct memory_pool* pool, size_t size) {
    if (pool->current_size + size > MAX_MEMORY) {
        printf("Out of memory! :O\n");
        return NULL;
    }

    void* data = pool->block + pool->current_size;
    pool->current_size += size;
    return data;
}

void free_memory(struct memory_pool* pool, void* data) {
    if (data == NULL) {
        printf("Trying to free null pointer! :O\n");
        return;
    }

    size_t index = (size_t)data - (size_t)pool->block;
    pool->current_size -= pool->block[index].size;
    memmove(pool->block + index, pool->block + index + 1, (pool->current_size - index - 1) * sizeof(struct memory_block));
}

int main() {
    struct memory_pool pool;
    init_memory_pool(&pool);

    void* p1 = alloc_memory(&pool, 10);
    void* p2 = alloc_memory(&pool, 20);
    void* p3 = alloc_memory(&pool, 30);

    printf("Memory usage: %zu\n", pool.current_size);

    free_memory(&pool, p1);
    free_memory(&pool, p2);
    free_memory(&pool, p3);

    printf("Memory usage: %zu\n", pool.current_size);

    return 0;
}