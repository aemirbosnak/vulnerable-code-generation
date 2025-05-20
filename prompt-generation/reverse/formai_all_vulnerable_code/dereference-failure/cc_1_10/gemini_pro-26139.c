//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator
void *my_malloc(size_t size) {
    // Allocate the memory
    void *ptr = malloc(size);

    // Check if the allocation was successful
    if (ptr == NULL) {
        // Print an error message and exit the program
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(1);
    }

    // Return the pointer to the allocated memory
    return ptr;
}

// Define a custom memory deallocator
void my_free(void *ptr) {
    // Free the memory
    free(ptr);
}

// Example of a more elegant wrapper for the standard library's realloc
void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    // Allocate a new chunk of memory using the custom allocator
    void *new_ptr = my_malloc(new_size);
    
    // Copy the contents of the old memory chunk to the new one
    memcpy(new_ptr, ptr, old_size);

    // Free the old memory chunk
    my_free(ptr);

    // Return a pointer to the new memory chunk
    return new_ptr;
}

// Example of a memory pool implementation
typedef struct memory_pool {
    void *base;
    size_t size;
    size_t used;
} memory_pool;

void *memory_pool_malloc(memory_pool *pool, size_t size) {
    // Check if there is enough space in the pool
    if (pool->used + size > pool->size) {
        // Reallocate the pool to a larger size
        pool->base = my_realloc(pool->base, pool->size, pool->size * 2);
        pool->size *= 2;
    }

    // Allocate the memory from the pool
    void *ptr = pool->base + pool->used;
    pool->used += size;

    // Return a pointer to the allocated memory
    return ptr;
}

void memory_pool_free(memory_pool *pool, void *ptr) {
    // Free the memory back to the pool
    pool->used -= (ptr - pool->base);
}

// Example usage
int main() {
    // Allocate memory using the custom allocator
    int *array = my_malloc(sizeof(int) * 10);

    // Reallocate the memory
    array = my_realloc(array, sizeof(int) * 10, sizeof(int) * 20);

    // Free the memory
    my_free(array);

    // Create a memory pool
    memory_pool pool;
    pool.base = my_malloc(4096);
    pool.size = 4096;
    pool.used = 0;

    // Allocate memory from the pool
    int *pool_array = memory_pool_malloc(&pool, sizeof(int) * 10);

    // Free the memory back to the pool
    memory_pool_free(&pool, pool_array);

    // Free the memory pool
    my_free(pool.base);

    return 0;
}