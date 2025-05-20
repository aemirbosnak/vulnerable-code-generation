//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// A custom memory allocator that uses a linked list to keep track of allocated blocks.
typedef struct mem_block {
    size_t size;
    struct mem_block *next;
} mem_block;

// The head of the linked list of allocated blocks.
static mem_block *free_list = NULL;

// Allocates a block of memory of the specified size.
void *my_malloc(size_t size) {
    // If the free list is empty, allocate a new block of memory.
    if (free_list == NULL) {
        free_list = malloc(sizeof(mem_block) + size);
        free_list->size = size;
        free_list->next = NULL;
    }

    // Find the first block of memory that is large enough to hold the requested size.
    mem_block *block = free_list;
    while (block != NULL && block->size < size) {
        block = block->next;
    }

    // If no block was found, return NULL.
    if (block == NULL) {
        return NULL;
    }

    // If the block is larger than the requested size, split it into two blocks.
    if (block->size > size) {
        mem_block *new_block = (mem_block *)((void *)block + size);
        new_block->size = block->size - size;
        new_block->next = block->next;
        block->size = size;
        block->next = new_block;
    }

    // Remove the block from the free list.
    if (block == free_list) {
        free_list = block->next;
    } else {
        mem_block *prev = free_list;
        while (prev->next != block) {
            prev = prev->next;
        }
        prev->next = block->next;
    }

    // Return the pointer to the allocated block.
    return (void *)block + sizeof(mem_block);
}

// Frees a block of memory that was previously allocated with my_malloc().
void my_free(void *ptr) {
    // Get the pointer to the mem_block structure for the block.
    mem_block *block = (mem_block *)((void *)ptr - sizeof(mem_block));

    // Add the block to the free list.
    block->next = free_list;
    free_list = block;
}

int main() {
    // Allocate a block of memory of size 100 bytes.
    void *ptr = my_malloc(100);

    // Use the allocated memory.
    // ...

    // Free the allocated memory.
    my_free(ptr);

    return 0;
}