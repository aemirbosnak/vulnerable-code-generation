//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: protected
#include <stdlib.h>
#include <stdio.h>

// A custom memory manager that uses a linked list to track allocated memory
typedef struct memory_block {
    size_t size;
    struct memory_block *next;
} memory_block;

// The start of the free memory list
memory_block *free_list;

// Allocate memory from the memory manager
void *my_malloc(size_t size) {
    // If the free list is empty, allocate a new block of memory
    if (!free_list) {
        free_list = malloc(sizeof(memory_block) + size);
        if (!free_list) {
            return NULL;
        }
        free_list->size = size;
        free_list->next = NULL;
    }

    // Find the first block of memory that is large enough to hold the requested size
    memory_block *current = free_list;
    while (current && current->size < size) {
        current = current->next;
    }

    // If no block of memory is large enough, return NULL
    if (!current) {
        return NULL;
    }

    // If the block of memory is exactly the right size, remove it from the free list
    if (current->size == size) {
        free_list = current->next;
    } else {
        // Otherwise, split the block of memory into two blocks: one for the requested size and one for the remaining memory
        memory_block *new_block = (memory_block *) ((char *) current + size);
        new_block->size = current->size - size;
        new_block->next = current->next;
        current->size = size;
        current->next = new_block;
    }

    // Return the address of the allocated memory
    return (void *) current + sizeof(memory_block);
}

// Free memory back to the memory manager
void my_free(void *ptr) {
    // Get the address of the memory block
    memory_block *block = (memory_block *) ((char *) ptr - sizeof(memory_block));

    // Insert the block of memory back into the free list
    block->next = free_list;
    free_list = block;
}

// Example usage of the custom memory manager
int main() {
    // Allocate some memory
    int *array = (int *) my_malloc(sizeof(int) * 10);

    // Use the memory
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    // Free the memory
    my_free(array);

    return 0;
}