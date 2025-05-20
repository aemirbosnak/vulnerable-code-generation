//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator
void *my_malloc(size_t size) {
    // Allocate memory using the system's malloc function
    void *ptr = malloc(size);

    // If the allocation failed, return NULL
    if (ptr == NULL) {
        return NULL;
    }

    // Initialize the allocated memory to 0
    memset(ptr, 0, size);

    // Return the pointer to the allocated memory
    return ptr;
}

// Define a custom memory deallocator
void my_free(void *ptr) {
    // Deallocate the memory using the system's free function
    free(ptr);
}

// Define a custom memory reallocator
void *my_realloc(void *ptr, size_t new_size) {
    // Allocate new memory using the system's realloc function
    void *new_ptr = realloc(ptr, new_size);

    // If the reallocation failed, return NULL
    if (new_ptr == NULL) {
        return NULL;
    }

    // Copy the old memory to the new memory
    memcpy(new_ptr, ptr, new_size);

    // Deallocate the old memory
    my_free(ptr);

    // Return the pointer to the new memory
    return new_ptr;
}

// Define a custom memory pool
struct memory_pool {
    // The start of the memory pool
    void *start;

    // The end of the memory pool
    void *end;

    // The current pointer to the free memory
    void *free;
};

// Initialize a memory pool
void memory_pool_init(struct memory_pool *pool, void *start, size_t size) {
    // Set the start and end of the memory pool
    pool->start = start;
    pool->end = (char *)start + size;

    // Set the current pointer to the free memory
    pool->free = start;
}

// Allocate memory from a memory pool
void *memory_pool_malloc(struct memory_pool *pool, size_t size) {
    // Check if there is enough free memory
    if (pool->free + size > pool->end) {
        return NULL;
    }

    // Allocate the memory
    void *ptr = pool->free;

    // Increment the current pointer to the free memory
    pool->free += size;

    // Return the pointer to the allocated memory
    return ptr;
}

// Free memory to a memory pool
void memory_pool_free(struct memory_pool *pool, void *ptr) {
    // Check if the pointer is within the memory pool
    if (ptr < pool->start || ptr > pool->end) {
        return;
    }

    // Decrement the current pointer to the free memory
    pool->free = ptr;
}

// Main function
int main() {
    // Allocate memory using the custom memory allocator
    int *ptr1 = (int *)my_malloc(sizeof(int));

    // Reallocate memory using the custom memory reallocator
    ptr1 = (int *)my_realloc(ptr1, 2 * sizeof(int));

    // Free memory using the custom memory deallocator
    my_free(ptr1);

    // Initialize a memory pool
    struct memory_pool pool;
    memory_pool_init(&pool, malloc(1024), 1024);

    // Allocate memory from the memory pool
    int *ptr2 = (int *)memory_pool_malloc(&pool, sizeof(int));

    // Free memory to the memory pool
    memory_pool_free(&pool, ptr2);

    return 0;
}