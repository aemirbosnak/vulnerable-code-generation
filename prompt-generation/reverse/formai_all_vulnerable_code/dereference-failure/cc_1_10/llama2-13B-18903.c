//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_INITIAL_SIZE 1024
#define MEM_INCREMENT_SIZE 512

struct mem_block {
    void* data;
    size_t size;
    struct mem_block* next;
};

struct mem_pool {
    struct mem_block* head;
    struct mem_block* tail;
};

void* mem_alloc(struct mem_pool* pool, size_t size) {
    struct mem_block* block = pool->head;

    if (block == NULL) {
        size_t new_size = MEM_INITIAL_SIZE;

        while (new_size < size) {
            new_size += MEM_INCREMENT_SIZE;
        }

        pool->head = (struct mem_block*) malloc(new_size);
        if (pool->head == NULL) {
            printf("Failed to allocate memory\n");
            return NULL;
        }

        pool->head->size = new_size;
        pool->head->data = (void*) (pool->head + 1);
        pool->head->next = pool->tail;
        pool->tail = pool->head;
    }

    size_t remaining = size;
    void* ret = NULL;

    while (remaining > 0) {
        size_t this_size = remaining > pool->head->size ? pool->head->size : remaining;

        ret = pool->head->data + pool->head->size - this_size;
        pool->head->size -= this_size;
        remaining -= this_size;

        if (pool->head->size == 0) {
            pool->head = pool->head->next;
        }
    }

    return ret;
}

void mem_free(struct mem_pool* pool, void* data) {
    struct mem_block* block = (struct mem_block*) (data - 1);

    if (block->next != NULL) {
        pool->tail = block->next;
    } else {
        pool->tail = pool->head;
    }

    pool->head = block;
    block->next = NULL;
}

int main() {
    struct mem_pool pool;

    pool.head = NULL;
    pool.tail = NULL;

    void* p1 = mem_alloc(&pool, 100);
    void* p2 = mem_alloc(&pool, 200);
    void* p3 = mem_alloc(&pool, 300);

    mem_free(&pool, p1);
    mem_free(&pool, p2);
    mem_free(&pool, p3);

    return 0;
}