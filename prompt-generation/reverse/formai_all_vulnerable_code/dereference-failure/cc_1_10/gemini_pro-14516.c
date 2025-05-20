//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

// A decentralized memory manager
typedef struct mem_block {
    size_t size;
    void *data;
    struct mem_block *next;
} mem_block;

// The head of the free list
mem_block *free_list = NULL;

// Allocate memory
void *malloc(size_t size) {
    // Check if there is a free block of sufficient size
    mem_block *block = free_list;
    while (block != NULL) {
        if (block->size >= size) {
            break;
        }
        block = block->next;
    }

    // If no free block is found, allocate a new one
    if (block == NULL) {
        block = (mem_block *)sbrk(size + sizeof(mem_block));
        if (block == (void *)-1) {
            return NULL;
        }
        block->size = size;
        block->data = (void *)((char *)block + sizeof(mem_block));
        block->next = NULL;
    }

    // Remove the block from the free list
    if (block != free_list) {
        mem_block *prev = free_list;
        while (prev->next != block) {
            prev = prev->next;
        }
        prev->next = block->next;
    } else {
        free_list = block->next;
    }

    // Return the data pointer
    return block->data;
}

// Free memory
void free(void *ptr) {
    // Find the block that contains the pointer
    mem_block *block = (mem_block *)((char *)ptr - sizeof(mem_block));

    // Add the block to the free list
    block->next = free_list;
    free_list = block;
}

// A simple example of how to use the memory manager
int main(void) {
    int *x = (int *)malloc(sizeof(int));
    *x = 42;
    printf("x = %d\n", *x);
    free(x);
    return 0;
}