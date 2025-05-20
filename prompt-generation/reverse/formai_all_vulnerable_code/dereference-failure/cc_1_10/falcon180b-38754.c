//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_BLOCKS 100
#define MAX_BLOCK_SIZE 100

typedef struct {
    void* address;
    size_t size;
    int is_free;
} MemoryBlock;

MemoryBlock memory_blocks[MAX_MEMORY_BLOCKS];
int num_memory_blocks = 0;

void* malloc_paranoid(size_t size) {
    if (size == 0) {
        printf("Error: Attempted to allocate 0 bytes of memory.\n");
        exit(1);
    }

    if (num_memory_blocks >= MAX_MEMORY_BLOCKS) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    for (int i = 0; i < num_memory_blocks; i++) {
        if (memory_blocks[i].is_free && memory_blocks[i].size >= size) {
            memory_blocks[i].is_free = 0;
            return memory_blocks[i].address;
        }
    }

    int new_block_size = size + sizeof(MemoryBlock);
    MemoryBlock* new_block = (MemoryBlock*) malloc(new_block_size);
    if (new_block == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    new_block->is_free = 0;
    new_block->size = size;
    new_block->address = (void*) ((char*) new_block + sizeof(MemoryBlock));

    memory_blocks[num_memory_blocks++] = *new_block;

    return new_block->address;
}

void free_paranoid(void* address) {
    for (int i = 0; i < num_memory_blocks; i++) {
        if (memory_blocks[i].address == address) {
            memory_blocks[i].is_free = 1;
            break;
        }
    }
}

int main() {
    void* ptr1 = malloc_paranoid(50);
    void* ptr2 = malloc_paranoid(100);
    void* ptr3 = malloc_paranoid(200);

    // Do some work with the allocated memory...

    free_paranoid(ptr1);
    free_paranoid(ptr2);
    free_paranoid(ptr3);

    return 0;
}