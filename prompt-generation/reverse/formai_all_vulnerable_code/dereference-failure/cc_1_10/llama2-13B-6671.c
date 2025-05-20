//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BRAVE_MEMORY_MANAGEMENT

typedef struct {
    char *name;
    size_t size;
} brave_memory_block;

static brave_memory_block *brave_memory_pool = NULL;
static size_t brave_memory_pool_size = 0;

void brave_memory_init(void) {
    brave_memory_pool = calloc(1, sizeof(brave_memory_block));
    brave_memory_pool_size = 1;
}

void *brave_memory_alloc(size_t size) {
    assert(size > 0);

    if (brave_memory_pool_size == 0) {
        brave_memory_init();
    }

    if (size > brave_memory_pool_size) {
        size_t new_size = brave_memory_pool_size * 2;
        brave_memory_block *new_pool = realloc(brave_memory_pool, new_size * sizeof(brave_memory_block));
        if (new_pool == NULL) {
            perror("Reallocation failed");
            exit(EXIT_FAILURE);
        }
        brave_memory_pool = new_pool;
        brave_memory_pool_size = new_size;
    }

    brave_memory_block *block = brave_memory_pool + brave_memory_pool_size - size;
    memset(block, 0, size);
    return block;
}

void brave_memory_free(void *ptr) {
    assert(ptr != NULL);

    brave_memory_block *block = ptr;
    brave_memory_pool_size -= block->size;

    if (brave_memory_pool_size == 0) {
        free(brave_memory_pool);
        brave_memory_pool = NULL;
    }
}

int main(void) {
    brave_memory_init();

    void *ptr1 = brave_memory_alloc(10);
    void *ptr2 = brave_memory_alloc(20);
    void *ptr3 = brave_memory_alloc(30);

    brave_memory_free(ptr1);
    brave_memory_free(ptr2);
    brave_memory_free(ptr3);

    return 0;
}