//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMORY 1024
#define MEMORY_POOL_SIZE 64

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

memory_block_t* memory_pool = NULL;
size_t memory_pool_capacity = 0;

void init_memory_pool(void) {
    memory_pool = calloc(MEMORY_POOL_SIZE, sizeof(memory_block_t));
    memory_pool_capacity = MEMORY_POOL_SIZE;
}

void* alloc_memory(size_t size) {
    if (memory_pool_capacity == 0) {
        return malloc(size);
    }

    for (memory_block_t* current = memory_pool; current != NULL; current = current->next) {
        if (current->size >= size) {
            void* data = current->data;
            current->size -= size;
            current->next = NULL;
            return data;
        }
    }

    memory_block_t* new_block = calloc(1, sizeof(memory_block_t));
    new_block->data = malloc(size);
    new_block->size = size;
    new_block->next = memory_pool;
    memory_pool = new_block;
    memory_pool_capacity += size;
    return new_block->data;
}

void free_memory(void* data, size_t size) {
    memory_block_t* block = (memory_block_t*) data;
    if (block == NULL) {
        return;
    }

    if (block->size > size) {
        block->size -= size;
        return;
    }

    block->next = NULL;
    memory_pool_capacity -= size;
    free(block->data);
    free(block);
}

int main(void) {
    srand(time(NULL));

    init_memory_pool();

    for (int i = 0; i < 10; i++) {
        size_t size = rand() % 100 + 1;
        void* data = alloc_memory(size);
        printf("Allocated %zu bytes at %p\n", size, data);

        for (int j = 0; j < size; j++) {
            *((char*) (data + j)) = 'A' + rand() % 26;
        }

        sleep(rand() % 10 + 1);

        free_memory(data, size);
    }

    return 0;
}