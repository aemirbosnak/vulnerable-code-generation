//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_SIZE 1024
#define MEMORY_GAP 32

typedef struct memory_block {
    char *data;
    size_t size;
    struct memory_block *next;
} memory_block_t;

memory_block_t *memory_pool = NULL;

void init_memory_pool(void) {
    memory_pool = malloc(MEMORY_SIZE);
    memset(memory_pool, 0, MEMORY_SIZE);
}

void add_memory_block(char *data, size_t size) {
    memory_block_t *new_block = malloc(sizeof(memory_block_t));
    new_block->data = data;
    new_block->size = size;
    new_block->next = NULL;

    if (memory_pool == NULL) {
        memory_pool = new_block;
    } else {
        memory_pool->next = new_block;
    }

    memory_pool = new_block;
}

char *get_memory_block(size_t size) {
    memory_block_t *block = memory_pool;

    while (block != NULL && block->size < size) {
        block = block->next;
    }

    if (block == NULL || block->size > size) {
        return NULL;
    }

    char *data = block->data;
    block->size -= size;
    block->data += size;

    return data;
}

void free_memory_block(char *data) {
    memory_block_t *block = memory_pool;

    while (block != NULL && block->data != data) {
        block = block->next;
    }

    if (block == NULL) {
        return;
    }

    block->size += data - block->data;
    block->data = data;
}

int main(void) {
    srand(time(NULL));

    init_memory_pool();

    for (size_t i = 0; i < 10; i++) {
        char *data = get_memory_block(rand() % MEMORY_SIZE);

        if (data == NULL) {
            continue;
        }

        printf("Found memory block at %p with size %zu\n", data, strlen(data));

        free_memory_block(data);
    }

    return 0;
}