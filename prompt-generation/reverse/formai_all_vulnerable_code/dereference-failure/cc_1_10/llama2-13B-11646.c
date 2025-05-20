//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_POOL_SIZE 1024

typedef struct {
    char *name;
    size_t size;
} memory_block_t;

static memory_block_t *memory_pool;
static size_t memory_pool_capacity;

void init_memory_pool(void) {
    memory_pool = (memory_block_t *)calloc(MEMORY_POOL_SIZE, sizeof(memory_block_t));
    memory_pool_capacity = MEMORY_POOL_SIZE;
}

void *allocate_memory(size_t size) {
    for (size_t i = 0; i < memory_pool_capacity; i++) {
        if (memory_pool[i].size == 0) {
            memory_pool[i].size = size;
            memory_pool[i].name = (char *)malloc(size);
            return memory_pool[i].name;
        }
    }
    return NULL;
}

void deallocate_memory(void *memory) {
    for (size_t i = 0; i < memory_pool_capacity; i++) {
        if (memory_pool[i].name == memory) {
            free(memory_pool[i].name);
            memory_pool[i].name = NULL;
            memory_pool[i].size = 0;
            return;
        }
    }
}

void print_memory_pool(void) {
    for (size_t i = 0; i < memory_pool_capacity; i++) {
        if (memory_pool[i].name != NULL) {
            printf("Memory block %zu: %s (%zu bytes)\n", i, memory_pool[i].name, memory_pool[i].size);
        }
    }
}

int main(void) {
    init_memory_pool();

    void *ptr1 = allocate_memory(100);
    void *ptr2 = allocate_memory(200);
    void *ptr3 = allocate_memory(300);

    // Use the memory blocks
    char *str1 = "Hello, world!";
    char *str2 = "This is a longer string";
    char *str3 = "And another one";

    strcpy(ptr1, str1);
    strcpy(ptr2, str2);
    strcpy(ptr3, str3);

    // Deallocate the memory blocks
    deallocate_memory(ptr1);
    deallocate_memory(ptr2);
    deallocate_memory(ptr3);

    // Print the memory pool
    print_memory_pool();

    return 0;
}