//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MEMORY_POOL_SIZE 0x10000
#define BUFFER_SIZE 1024

typedef struct memory_block {
    void* data;
    size_t size;
    struct memory_block* next;
} memory_block_t;

memory_block_t* memory_pool = NULL;

void init_memory_pool(void) {
    memory_pool = calloc(1, sizeof(memory_block_t));
    memory_pool->data = malloc(MEMORY_POOL_SIZE);
    memory_pool->size = MEMORY_POOL_SIZE;
    memory_pool->next = NULL;
}

void* alloc_memory(size_t size) {
    if (size > MEMORY_POOL_SIZE) {
        return NULL;
    }

    memory_block_t* block = memory_pool;
    while (block != NULL && block->size < size) {
        block = block->next;
    }

    if (block == NULL) {
        block = calloc(1, sizeof(memory_block_t));
        block->data = malloc(size);
        block->size = size;
        if (block->data == NULL) {
            return NULL;
        }
        if (memory_pool == NULL) {
            memory_pool = block;
        } else {
            memory_pool->next = block;
        }
    }

    return block->data;
}

void free_memory(void* data) {
    memory_block_t* block = (memory_block_t*)data;
    if (block == NULL) {
        return;
    }

    if (block == memory_pool) {
        memory_pool = block->next;
    }

    free(block->data);
    free(block);
}

int main(void) {
    init_memory_pool();

    void* buffer = alloc_memory(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    char* string = (char*)buffer;
    strcpy(string, "Hello, world!");

    free_memory(buffer);

    return 0;
}