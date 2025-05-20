//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory manager struct
typedef struct {
    void *start;
    size_t size;
    void *end;
} memory_manager;

// Create a new memory manager
memory_manager *create_memory_manager(size_t size) {
    memory_manager *mm = malloc(sizeof(memory_manager));
    if (!mm) {
        return NULL;
    }
    mm->start = malloc(size);
    if (!mm->start) {
        free(mm);
        return NULL;
    }
    mm->size = size;
    mm->end = mm->start + size;
    return mm;
}

// Destroy a memory manager
void destroy_memory_manager(memory_manager *mm) {
    if (!mm) {
        return;
    }
    free(mm->start);
    free(mm);
}

// Allocate memory from the memory manager
void *malloc_protected(memory_manager *mm, size_t size) {
    if (!mm || size > mm->size) {
        return NULL;
    }
    void *ptr = mm->start;
    mm->start += size;
    return ptr;
}

// Free memory from the memory manager
void free_protected(memory_manager *mm, void *ptr) {
    if (!mm || ptr < mm->start || ptr > mm->end) {
        return;
    }
    mm->start = ptr;
}

// Example usage
int main() {
    // Create a memory manager
    memory_manager *mm = create_memory_manager(1024);
    if (!mm) {
        return 1;
    }

    // Allocate some memory from the memory manager
    int *array = malloc_protected(mm, 100 * sizeof(int));
    if (!array) {
        destroy_memory_manager(mm);
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    // Free the allocated memory
    free_protected(mm, array);

    // Destroy the memory manager
    destroy_memory_manager(mm);

    return 0;
}