//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: automated
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory manager structure
typedef struct {
    void *start; // Pointer to the start of the memory block
    void *end;   // Pointer to the end of the memory block
    void *free;  // Pointer to the next free byte in the memory block
} MemoryManager;

// Initialize the memory manager with a given memory block
void memory_manager_init(MemoryManager *mm, void *block, size_t size) {
    mm->start = block;
    mm->end = block + size;
    mm->free = block;
}

// Allocate a memory block of the given size
void *memory_manager_alloc(MemoryManager *mm, size_t size) {
    if (mm->free + size > mm->end) {
        return NULL; // Out of memory
    }

    void *ptr = mm->free;
    mm->free += size;

    return ptr;
}

// Free a previously allocated memory block
void memory_manager_free(MemoryManager *mm, void *ptr) {
    if (ptr < mm->start || ptr >= mm->free) {
        return; // Invalid pointer
    }

    mm->free = ptr;
}

// Example usage
int main() {
    // Allocate 1MB of memory
    void *memory = malloc(1024 * 1024);

    // Initialize the memory manager
    MemoryManager mm;
    memory_manager_init(&mm, memory, 1024 * 1024);

    // Allocate and free some memory blocks
    int *ptr1 = memory_manager_alloc(&mm, sizeof(int));
    int *ptr2 = memory_manager_alloc(&mm, sizeof(int));
    int *ptr3 = memory_manager_alloc(&mm, sizeof(int));

    *ptr1 = 10;
    *ptr2 = 20;
    *ptr3 = 30;

    printf("ptr1: %d\n", *ptr1);
    printf("ptr2: %d\n", *ptr2);
    printf("ptr3: %d\n", *ptr3);

    memory_manager_free(&mm, ptr2);

    // Reallocate ptr2
    ptr2 = memory_manager_alloc(&mm, sizeof(int));
    *ptr2 = 40;

    printf("ptr2: %d\n", *ptr2);

    // Free all allocated memory
    memory_manager_free(&mm, ptr1);
    memory_manager_free(&mm, ptr2);
    memory_manager_free(&mm, ptr3);

    // Free the memory block
    free(memory);

    return 0;
}