//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_POOL_SIZE 1024

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

static memory_block_t* memory_pool = NULL;

void* alloc_memory(size_t size) {
    memory_block_t* new_block = (memory_block_t*) malloc(sizeof(memory_block_t));
    new_block->data = malloc(size);
    new_block->size = size;
    new_block->next = NULL;

    if (memory_pool == NULL) {
        memory_pool = new_block;
    } else {
        memory_pool->next = new_block;
    }

    return new_block->data;
}

void free_memory(void* data) {
    memory_block_t* block = (memory_block_t*) data;
    if (block == NULL) {
        return;
    }

    if (block == memory_pool) {
        memory_pool = block->next;
    }

    free(block->data);
    free(block);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        size_t size = rand() % 1024;
        void* data = alloc_memory(size);
        printf("Allocated %zu bytes at %p\n", size, data);

        // Do some random stuff with the allocated memory
        for (size_t j = 0; j < size; j++) {
            ((char*) data)[j] = 'A' + (rand() % 26);
        }

        // Free the memory after we're done with it
        free_memory(data);
    }

    return 0;
}