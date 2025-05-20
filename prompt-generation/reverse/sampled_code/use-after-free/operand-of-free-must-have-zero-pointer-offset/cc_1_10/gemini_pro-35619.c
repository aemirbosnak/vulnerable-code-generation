//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory manager struct
typedef struct {
    void *start;
    size_t size;
    void *end;
} MemoryManager;

// Initialize the memory manager
void memory_manager_init(MemoryManager *mm, void *start, size_t size) {
    mm->start = start;
    mm->size = size;
    mm->end = (char *)start + size;
}

// Allocate memory from the memory manager
void *memory_manager_alloc(MemoryManager *mm, size_t size) {
    // Check if the requested size is available
    if (mm->start + size > mm->end) {
        return NULL;
    }

    // Allocate the memory
    void *ptr = mm->start;
    mm->start = (char *)mm->start + size;

    return ptr;
}

// Free memory back to the memory manager
void memory_manager_free(MemoryManager *mm, void *ptr) {
    // Check if the pointer is within the memory manager's range
    if (ptr < mm->start || ptr >= mm->end) {
        return;
    }

    // Free the memory
    mm->start = ptr;
}

// Example usage of the memory manager
int main() {
    // Create a memory manager with 1MB of memory
    MemoryManager mm;
    memory_manager_init(&mm, malloc(1024 * 1024), 1024 * 1024);

    // Allocate 100 bytes from the memory manager
    void *ptr1 = memory_manager_alloc(&mm, 100);
    if (ptr1 == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Allocate another 200 bytes from the memory manager
    void *ptr2 = memory_manager_alloc(&mm, 200);
    if (ptr2 == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Free the first allocation
    memory_manager_free(&mm, ptr1);

    // Allocate another 150 bytes from the memory manager
    void *ptr3 = memory_manager_alloc(&mm, 150);
    if (ptr3 == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    // Free the second and third allocations
    memory_manager_free(&mm, ptr2);
    memory_manager_free(&mm, ptr3);

    // Free the memory manager
    free(mm.start);

    return 0;
}