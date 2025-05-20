//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Custom memory manager
typedef struct {
    void* base;
    size_t size;
    void* free_list;
} MemoryManager;

// Initialize memory manager
void mm_init(MemoryManager* mm, void* base, size_t size) {
    mm->base = base;
    mm->size = size;
    mm->free_list = NULL;
}

// Allocate memory from manager
void* mm_alloc(MemoryManager* mm, size_t size) {
    // Check for free list
    void* block = mm->free_list;
    if (block != NULL) {
        mm->free_list = *(void**)block;
        return block;
    }

    // Check for available space
    if (mm->size >= size) {
        void* block = mm->base;
        mm->base += size;
        mm->size -= size;
        return block;
    }

    // Out of memory
    return NULL;
}

// Free memory to manager
void mm_free(MemoryManager* mm, void* block) {
    *(void**)block = mm->free_list;
    mm->free_list = block;
}

// Main program
int main() {
    // Allocate a memory manager
    MemoryManager mm;
    mm_init(&mm, malloc(1024), 1024);

    // Allocate and free some blocks
    int* block1 = (int*)mm_alloc(&mm, sizeof(int));
    *block1 = 42;

    double* block2 = (double*)mm_alloc(&mm, sizeof(double));
    *block2 = 3.14;

    mm_free(&mm, block1);
    mm_free(&mm, block2);

    // Print the current memory usage
    printf("Current memory usage: %lu bytes\n", mm.size);

    // Free the memory manager
    free(mm.base);

    return 0;
}