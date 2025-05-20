//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define custom memory management functions
void *my_malloc(size_t size) {
    void *ptr = malloc(size + sizeof(size_t));
    if (ptr == NULL) {
        return NULL;
    }

    // Store the size of the allocated memory at the beginning of the block
    size_t *header = (size_t *)ptr;
    *header = size;

    // Return a pointer to the data section of the block
    return ptr + sizeof(size_t);
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    // Get the size of the allocated memory from the header
    size_t *header = (size_t *)ptr - 1;
    size_t size = *header;

    // Free the entire block
    free(header);
}

// Define custom memory management configuration
#define MEMORY_POOL_SIZE 1024 * 1024 // 1 MB

void *memory_pool = NULL;
size_t memory_pool_used = 0;

// Custom memory allocator using a fixed-size memory pool
void *my_pool_malloc(size_t size) {
    if (memory_pool == NULL) {
        memory_pool = malloc(MEMORY_POOL_SIZE);
        if (memory_pool == NULL) {
            return NULL;
        }
    }

    // Check if there is enough free space in the pool
    if (memory_pool_used + size > MEMORY_POOL_SIZE) {
        return NULL;
    }

    // Allocate memory from the pool
    void *ptr = memory_pool + memory_pool_used;
    memory_pool_used += size;

    return ptr;
}

// Custom memory deallocator for the memory pool
void my_pool_free(void *ptr) {
    if (ptr >= memory_pool && ptr < memory_pool + MEMORY_POOL_SIZE) {
        // Adjust the memory pool used size
        memory_pool_used -= ptr - memory_pool;
    }
}

int main() {
    // Allocate memory using custom memory management functions
    int *ptr1 = (int *)my_malloc(sizeof(int));
    char *ptr2 = (char *)my_pool_malloc(100);

    // Use the allocated memory
    *ptr1 = 42;
    strcpy(ptr2, "Hello World!");

    // Free the allocated memory
    my_free(ptr1);
    my_pool_free(ptr2);

    // Display the allocated memory sizes
    printf("Allocated memory size using my_malloc: %lu bytes\n", sizeof(int));
    printf("Allocated memory size using my_pool_malloc: %lu bytes\n", 100);

    return 0;
}