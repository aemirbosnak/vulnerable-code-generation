//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Our very own memory manager!
typedef struct mem_block {
    size_t size;
    int free;
    struct mem_block *next;
} mem_block;

// Initialize the memory manager with a block of memory
void mem_init(mem_block *start, size_t size) {
    start->size = size;
    start->free = 1;
    start->next = NULL;
}

// Allocate a block of memory
void *mem_alloc(mem_block *start, size_t size) {
    mem_block *current = start;

    // Find a free block of memory that is large enough
    while (current != NULL && (current->free == 0 || current->size < size)) {
        current = current->next;
    }

    // If no free block was found, return NULL
    if (current == NULL) {
        return NULL;
    }

    // Mark the block as allocated
    current->free = 0;

    // If the block is larger than the requested size, split it
    if (current->size > size) {
        mem_block *new_block = (mem_block *)((char *)current + size);
        new_block->size = current->size - size;
        new_block->free = 1;
        new_block->next = current->next;
        current->next = new_block;
    }

    // Return the address of the allocated block
    return (void *)current;
}

// Free a block of memory
void mem_free(mem_block *start, void *ptr) {
    mem_block *current = start;

    // Find the block to free
    while (current != NULL && current + 1 != ptr) {
        current = current->next;
    }

    // If the block was not found, return
    if (current == NULL) {
        return;
    }

    // Mark the block as free
    current->free = 1;

    // Coalesce with the next block if it is also free
    if (current->next != NULL && current->next->free == 1) {
        current->size += current->next->size;
        current->next = current->next->next;
    }
}

// Print the memory map
void mem_print(mem_block *start) {
    mem_block *current = start;

    printf("Memory Map:\n");
    while (current != NULL) {
        printf("  Address: %p, Size: %lu, Free: %d\n", current, current->size, current->free);
        current = current->next;
    }
}

int main() {
    // Initialize the memory manager with a block of memory
    mem_block *start = (mem_block *)malloc(1024);
    mem_init(start, 1024);

    // Allocate some blocks of memory
    void *ptr1 = mem_alloc(start, 100);
    void *ptr2 = mem_alloc(start, 200);
    void *ptr3 = mem_alloc(start, 300);

    // Print the memory map
    mem_print(start);

    // Free some blocks of memory
    mem_free(start, ptr2);
    mem_free(start, ptr3);

    // Print the memory map
    mem_print(start);

    return 0;
}