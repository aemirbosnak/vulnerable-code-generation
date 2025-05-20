//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

// Define a structure to represent the memory block
typedef struct mem_block {
    size_t size;
    struct mem_block *next;
} mem_block_t;

// Define a global variable to represent the memory pool
mem_block_t *mem_pool = NULL;
pthread_mutex_t pool_lock;

// Allocate memory from the memory pool
void *async_malloc(size_t size) {
    mem_block_t *block = NULL;
    
    // Acquire the lock to prevent simultaneous accessing of the memory pool
    pthread_mutex_lock(&pool_lock);

    // Traverse the memory pool to find a block of appropriate size
    for (mem_block_t *curr = mem_pool; curr != NULL; curr = curr->next) {
        if (curr->size >= size) {
            block = curr;
            break;
        }
    }

    // If a block of appropriate size was found, use that block
    if (block != NULL) {
        // Remove the block from the memory pool
        if (block == mem_pool) {
            mem_pool = block->next;
        }
        else {
            for (mem_block_t *curr = mem_pool; curr != NULL; curr = curr->next) {
                if (curr->next == block) {
                    curr->next = block->next;
                    break;
                }
            }
        }
    }
    // If a block of appropriate size was not found, allocate a new block from the system heap
    else {
        block = (mem_block_t*) malloc(sizeof(mem_block_t) + size);
        if (block != NULL) {
            block->size = size;
        }
    }

    // Release the lock
    pthread_mutex_unlock(&pool_lock);

    // Return a pointer to the memory block
    return (void*) (block + 1);
}

// Free memory to the memory pool
void async_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    // Get a pointer to the memory block
    mem_block_t *block = (mem_block_t*) ptr - 1;

    // Acquire the lock to prevent simultaneous accessing of the memory pool
    pthread_mutex_lock(&pool_lock);

    // Add the memory block to the memory pool
    block->next = mem_pool;
    mem_pool = block;

    // Release the lock
    pthread_mutex_unlock(&pool_lock);
}

// Initialize the memory pool
void async_init(size_t size) {
    // Allocate a block of memory from the system heap
    void *mem = malloc(size);
    if (mem == NULL) {
        return;
    }

    // Initialize the memory block
    mem_block_t *block = (mem_block_t*) mem;
    block->size = size - sizeof(mem_block_t);
    block->next = NULL;

    // Set the memory pool pointer to the memory block
    mem_pool = block;

    // Initialize the lock
    pthread_mutex_init(&pool_lock, NULL);
}

// Test the memory management system
void *test_memory(void *args) {
    for (int i = 0; i < 100000; i++) {
        char *str = (char*) async_malloc(256);
        if (str != NULL) {
            strcpy(str, "This is a test string.");
            async_free(str);
        }
    }

    return NULL;
}

int main() {
    // Initialize the memory pool
    async_init(1024 * 1024);

    // Launch multiple threads to test the memory management system
    const int num_threads = 8;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, test_memory, NULL);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}