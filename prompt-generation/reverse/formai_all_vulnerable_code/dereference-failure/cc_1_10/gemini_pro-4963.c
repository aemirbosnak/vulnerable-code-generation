//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Custom memory management functions
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    memset(ptr, 0, size);  // Initialize memory to zero
    return ptr;
}

void my_free(void* ptr) {
    if (ptr) {
        free(ptr);
        ptr = NULL;  // Set pointer to NULL to indicate freed memory
    }
}

// Custom memory pool implementation
typedef struct {
    size_t size;
    void* base;
    void* current;
    void* end;
} memory_pool_t;

memory_pool_t* create_memory_pool(size_t size) {
    memory_pool_t* pool = my_malloc(sizeof(memory_pool_t));
    pool->size = size;
    pool->base = my_malloc(size);
    pool->current = pool->base;
    pool->end = pool->base + size;
    return pool;
}

void* memory_pool_alloc(memory_pool_t* pool, size_t size) {
    if (pool->current + size > pool->end) {
        fprintf(stderr, "Error: Out of memory in memory pool.\n");
        return NULL;
    }
    void* ptr = pool->current;
    pool->current += size;
    return ptr;
}

void memory_pool_free(memory_pool_t* pool) {
    my_free(pool->base);
    my_free(pool);
}

// Main program
int main() {
    // Memory management using custom functions
    int* arr = (int*) my_malloc(100 * sizeof(int));
    arr[0] = 42;
    printf("Custom malloc: %d\n", arr[0]);
    my_free(arr);

    // Memory management using memory pool
    memory_pool_t* pool = create_memory_pool(1024);
    int* pool_arr = (int*) memory_pool_alloc(pool, 100 * sizeof(int));
    pool_arr[0] = 21;
    printf("Memory pool alloc: %d\n", pool_arr[0]);
    memory_pool_free(pool);

    return 0;
}