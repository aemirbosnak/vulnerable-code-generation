//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Custom memory allocator
typedef struct MemoryBlock {
    size_t size;
    void *data;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *free_list = NULL;

void *brave_malloc(size_t size) {
    if (free_list != NULL) {
        // Check if there is a free block of the requested size
        MemoryBlock *block = free_list;
        while (block != NULL) {
            if (block->size >= size) {
                // Remove the block from the free list
                if (block == free_list) {
                    free_list = block->next;
                } else {
                    MemoryBlock *prev = free_list;
                    while (prev->next != block) {
                        prev = prev->next;
                    }
                    prev->next = block->next;
                }

                // Adjust the block size and return the data pointer
                block->size = size;
                return block->data;
            }
            block = block->next;
        }
    }

    // Allocate a new block from the system
    MemoryBlock *block = malloc(sizeof(MemoryBlock) + size);
    if (block == NULL) {
        return NULL;
    }
    block->size = size;
    block->data = (void *)(block + 1);
    return block->data;
}

void brave_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    // Get the memory block from the data pointer
    MemoryBlock *block = (MemoryBlock *)ptr - 1;

    // Add the block to the free list
    block->next = free_list;
    free_list = block;
}

// Custom memory usage tracker
typedef struct MemoryUsage {
    size_t total_allocated;
    size_t total_freed;
    size_t current_usage;
} MemoryUsage;

MemoryUsage memory_usage = {0, 0, 0};

void brave_memory_usage(MemoryUsage *usage) {
    usage->total_allocated = memory_usage.total_allocated;
    usage->total_freed = memory_usage.total_freed;
    usage->current_usage = memory_usage.current_usage;
}

// Brave the memory management wilderness!
int main() {
    // Allocate some memory
    int *arr = (int *)brave_malloc(100 * sizeof(int));
    char *str = (char *)brave_malloc(100);

    // Do something with the allocated memory
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    strcpy(str, "Brave the memory management wilderness!");

    // Print the allocated memory usage
    MemoryUsage usage;
    brave_memory_usage(&usage);
    printf("Total allocated: %zu bytes\n", usage.total_allocated);
    printf("Total freed: %zu bytes\n", usage.total_freed);
    printf("Current usage: %zu bytes\n", usage.current_usage);

    // Free the allocated memory
    brave_free(arr);
    brave_free(str);

    // Print the freed memory usage
    brave_memory_usage(&usage);
    printf("Total allocated: %zu bytes\n", usage.total_allocated);
    printf("Total freed: %zu bytes\n", usage.total_freed);
    printf("Current usage: %zu bytes\n", usage.current_usage);

    return 0;
}