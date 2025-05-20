//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 10
#define BLOCK_SIZE 100
#define HEADER_SIZE 8

typedef struct {
    size_t prev_size;
    int free;
} BlockHeader;

BlockHeader headers[MAX_BLOCKS];
void* mem_pool = (void*)0;
size_t current_pool_size = 0;

void init_memory_manager() {
    mem_pool = malloc(MAX_BLOCKS * BLOCK_SIZE);
    if (!mem_pool) {
        fprintf(stderr, "Error: Could not allocate memory for memory manager\n");
        exit(EXIT_FAILURE);
    }

    current_pool_size = MAX_BLOCKS * BLOCK_SIZE;

    for (size_t i = 0; i < MAX_BLOCKS; ++i) {
        headers[i].free = 1;
    }
}

void* allocate(size_t size) {
    for (size_t i = 0; i < MAX_BLOCKS; ++i) {
        if (headers[i].free && (size + HEADER_SIZE <= BLOCK_SIZE)) {
            headers[i].free = 0;
            headers[i].prev_size = size;
            void* block_ptr = (void*)((char*)mem_pool + (i * BLOCK_SIZE));
            return block_ptr;
        }
    }

    void* new_block = malloc(size + HEADER_SIZE);
    if (!new_block) {
        fprintf(stderr, "Error: Could not allocate memory from system\n");
        exit(EXIT_FAILURE);
    }

    headers[(MAX_BLOCKS - 1)].free = 0;
    headers[(MAX_BLOCKS - 1)].prev_size = size;

    current_pool_size += size + HEADER_SIZE;

    return new_block;
}

void deallocate(void* ptr) {
    size_t index = ((size_t)((char*)ptr - (char*)mem_pool)) / BLOCK_SIZE;

    headers[index].free = 1;

    current_pool_size -= (BLOCK_SIZE + headers[index].prev_size);
}

int main() {
    init_memory_manager();

    int* a = (int*)allocate(sizeof(int) * 10);
    int* b = (int*)allocate(sizeof(int) * 5);

    for (int i = 0; i < 15; ++i) {
        a[i] = i;
        b[i] = i + 5;
    }

    // Do some calculations

    deallocate(a);
    deallocate(b);

    init_memory_manager(); // Reset for next run

    return 0;
}