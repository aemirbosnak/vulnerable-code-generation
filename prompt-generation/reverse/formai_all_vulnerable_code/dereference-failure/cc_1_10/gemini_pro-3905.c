//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Custom memory manager
typedef struct _MemBlock {
    size_t size;
    struct _MemBlock *next;
    struct _MemBlock *prev;
} MemBlock;

MemBlock *free_list = NULL;
MemBlock *used_list = NULL;

void *my_malloc(size_t size) {
    if (free_list == NULL) {
        // No free blocks available, allocate a new one
        MemBlock *new_block = malloc(sizeof(MemBlock) + size);
        new_block->size = size;
        new_block->next = NULL;
        new_block->prev = NULL;
        return new_block + 1;  // Return pointer to data after MemBlock header
    } else {
        // Find a suitable free block
        MemBlock *block = free_list;
        while (block != NULL) {
            if (block->size >= size) {
                break;
            }
            block = block->next;
        }
        if (block == NULL) {
            // No suitable free block found, allocate a new one
            MemBlock *new_block = malloc(sizeof(MemBlock) + size);
            new_block->size = size;
            new_block->next = NULL;
            new_block->prev = NULL;
            return new_block + 1;  // Return pointer to data after MemBlock header
        } else {
            // Split the free block if it's larger than needed
            if (block->size > size) {
                MemBlock *new_block = (MemBlock *)((char *)block + size + sizeof(MemBlock));
                new_block->size = block->size - size - sizeof(MemBlock);
                new_block->next = block->next;
                new_block->prev = block;
                block->next = new_block;
                block->size = size;
            }
            // Remove the block from the free list
            if (block->prev != NULL) {
                block->prev->next = block->next;
            } else {
                free_list = block->next;
            }
            if (block->next != NULL) {
                block->next->prev = block->prev;
            }
            // Add the block to the used list
            block->next = used_list;
            block->prev = NULL;
            if (used_list != NULL) {
                used_list->prev = block;
            }
            used_list = block;
            return block + 1;  // Return pointer to data after MemBlock header
        }
    }
}

void my_free(void *ptr) {
    // Get the MemBlock header
    MemBlock *block = (MemBlock *)ptr - 1;
    // Remove the block from the used list
    if (block->prev != NULL) {
        block->prev->next = block->next;
    } else {
        used_list = block->next;
    }
    if (block->next != NULL) {
        block->next->prev = block->prev;
    }
    // Add the block to the free list
    block->next = free_list;
    block->prev = NULL;
    if (free_list != NULL) {
        free_list->prev = block;
    }
    free_list = block;
}

int main() {
    // Allocate some memory using our custom memory manager
    int *array = (int *)my_malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    // Print the allocated memory
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory using our custom memory manager
    my_free(array);

    return 0;
}