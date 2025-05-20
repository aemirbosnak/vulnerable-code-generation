//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMORY 1024
#define MEMORY_INCREMENT 64

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

memory_block_t* memory_pool = NULL;

void init_memory_pool(void) {
    memory_pool = (memory_block_t*) calloc(1, sizeof(memory_block_t));
    memory_pool->data = NULL;
    memory_pool->size = 0;
    memory_pool->next = NULL;
}

void* allocate_memory(size_t size) {
    if (size == 0) {
        return NULL;
    }

    if (memory_pool == NULL) {
        init_memory_pool();
    }

    memory_block_t* new_block = (memory_block_t*) calloc(1, sizeof(memory_block_t));
    new_block->size = size;
    new_block->data = calloc(1, size);
    new_block->next = memory_pool;
    memory_pool = new_block;

    return new_block->data;
}

void deallocate_memory(void* data, size_t size) {
    memory_block_t* block = (memory_block_t*) data;

    if (block == NULL) {
        return;
    }

    if (block->next == NULL) {
        memory_pool = block;
    }

    free(block->data);
    free(block);
}

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        size_t size = rand() % 1024;
        void* data = allocate_memory(size);

        if (data == NULL) {
            printf("Error: Could not allocate memory\n");
            return 1;
        }

        // Do something with the memory
        memset(data, 'A', size);

        deallocate_memory(data, size);
    }

    return 0;
}