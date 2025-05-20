//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Create a custom memory manager with a dynamic memory pool
typedef struct MemoryPool {
    void* memory;
    size_t size;
    size_t used;
} MemoryPool;

// Initialize the memory pool
void memoryPoolInit(MemoryPool* pool, size_t size) {
    pool->memory = malloc(size);
    pool->size = size;
    pool->used = 0;
}

// Allocate memory from the pool
void* memoryPoolAlloc(MemoryPool* pool, size_t size) {
    if (pool->used + size > pool->size) {
        return NULL;  // Out of memory
    }
    void* ptr = pool->memory + pool->used;
    pool->used += size;
    return ptr;
}

// Free memory back to the pool
void memoryPoolFree(MemoryPool* pool, void* ptr) {
    if (ptr < pool->memory || ptr >= pool->memory + pool->size) {
        return;  // Invalid pointer
    }
    size_t offset = ptr - pool->memory;
    if (offset + pool->used == pool->size) {
        pool->used = offset;
    }
}

// Demonstrate the memory pool
int main() {
    MemoryPool pool;
    memoryPoolInit(&pool, 1024);  // Initialize the pool with 1KB

    // Allocate memory from the pool
    int* arr = (int*)memoryPoolAlloc(&pool, sizeof(int) * 10);
    if (arr == NULL) {
        printf("Out of memory!\n");
        return 1;
    }

    // Access and modify the allocated memory
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    // Print the allocated array
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    memoryPoolFree(&pool, arr);

    // Check if the memory has been returned to the pool
    if (pool.used == 0) {
        printf("Memory successfully returned to the pool!\n");
    }

    return 0;
}