//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Custom data structure for managing memory
typedef struct MemoryBlock {
    void *ptr;
    size_t size;
    struct MemoryBlock *next;
} MemoryBlock;

// Linked list of memory blocks
MemoryBlock *free_list = NULL;

// Allocate memory from the free list
void *my_malloc(size_t size) {
    // Check if there's a suitable block in the free list
    MemoryBlock *prev = NULL;
    MemoryBlock *curr = free_list;
    while (curr && curr->size < size) {
        prev = curr;
        curr = curr->next;
    }

    // If a suitable block is found, remove it from the free list
    if (curr && curr->size == size) {
        if (prev) {
            prev->next = curr->next;
        } else {
            free_list = curr->next;
        }
        return curr->ptr;
    }

    // Allocate a new block of memory
    void *ptr = malloc(size);
    if (!ptr) {
        return NULL;
    }

    // Add the new block to the free list
    MemoryBlock *new_block = malloc(sizeof(MemoryBlock));
    if (!new_block) {
        free(ptr);
        return NULL;
    }
    new_block->ptr = ptr;
    new_block->size = size;
    new_block->next = NULL;
    if (prev) {
        prev->next = new_block;
    } else {
        free_list = new_block;
    }

    return ptr;
}

// Free memory back to the free list
void my_free(void *ptr) {
    // Find the block in the free list
    MemoryBlock *prev = NULL;
    MemoryBlock *curr = free_list;
    while (curr && curr->ptr != ptr) {
        prev = curr;
        curr = curr->next;
    }

    // If the block is found, add it to the free list
    if (curr) {
        if (prev) {
            prev->next = curr->next;
        } else {
            free_list = curr->next;
        }
        free(curr);
    } else {
        // The block was not in the free list, so add it as a new block
        MemoryBlock *new_block = malloc(sizeof(MemoryBlock));
        if (!new_block) {
            return;
        }
        new_block->ptr = ptr;
        new_block->size = 0;
        new_block->next = NULL;
        if (prev) {
            prev->next = new_block;
        } else {
            free_list = new_block;
        }
    }
}

int main() {
    // Allocate some memory using our custom malloc function
    int *ptr1 = my_malloc(sizeof(int));
    *ptr1 = 42;

    // Allocate some more memory using our custom malloc function
    double *ptr2 = my_malloc(sizeof(double));
    *ptr2 = 3.14;

    // Free the memory using our custom free function
    my_free(ptr1);
    my_free(ptr2);

    return 0;
}