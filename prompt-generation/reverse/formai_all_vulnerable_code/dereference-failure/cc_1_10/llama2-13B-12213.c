//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_MEMORY 1024
#define MAX_THREADS 4

// Structure to represent a memory block
typedef struct {
    void *address;
    size_t size;
} memory_block_t;

// Array to store all memory blocks
memory_block_t memory_blocks[MAX_MEMORY];

// Semaphore to synchronize access to memory blocks
sem_t sem;

// Function to allocate a memory block
void * alloc_memory(size_t size) {
    // Check if there is enough memory available
    if (size > MAX_MEMORY) {
        printf("Out of memory!\n");
        return NULL;
    }

    // Search for a free memory block of the requested size
    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory_blocks[i].size == 0 || memory_blocks[i].size > size) {
            continue;
        }

        // Found a free memory block, allocate it
        memory_block_t *block = &memory_blocks[i];
        block->size = size;
        block->address = malloc(size);
        if (block->address == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }

        // Signal the semaphore to indicate that a memory block is available
        sem_post(&sem);

        // Return the allocated memory block
        return block->address;
    }

    // If no free memory block is found, allocate a new one
    memory_block_t *block = malloc(size);
    if (block == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Initialize the memory block
    block->size = size;
    block->address = malloc(size);
    if (block->address == NULL) {
        free(block);
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Signal the semaphore to indicate that a memory block is available
    sem_post(&sem);

    // Return the allocated memory block
    return block->address;
}

// Function to deallocate a memory block
void dealloc_memory(void *address) {
    // Find the memory block that contains the given address
    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory_blocks[i].address == address) {
            // Found the memory block, deallocate it
            free(memory_blocks[i].address);
            memory_blocks[i].address = NULL;
            memory_blocks[i].size = 0;

            // Signal the semaphore to indicate that a memory block is available
            sem_post(&sem);

            return;
        }
    }

    // If the given address is not found, print an error message
    printf("Invalid memory address\n");
}

// Thread function to allocate and deallocate memory
void * alloc_dealloc_memory(void *arg) {
    // Get the memory block size and the number of threads
    size_t size = *((size_t *)arg);
    int num_threads = *((int *)arg);

    // Allocate memory blocks for each thread
    void **memory_blocks_ptr = malloc(num_threads * sizeof(void *));
    for (int i = 0; i < num_threads; i++) {
        memory_blocks_ptr[i] = alloc_memory(size);
    }

    // Deallocate memory blocks for each thread
    for (int i = 0; i < num_threads; i++) {
        dealloc_memory(memory_blocks_ptr[i]);
    }

    // Free the memory blocks array
    free(memory_blocks_ptr);

    // Signal the semaphore to indicate that all memory blocks are deallocated
    sem_post(&sem);

    return NULL;
}

int main() {
    // Initialize the semaphore
    sem_init(&sem, 0, MAX_MEMORY);

    // Create num_threads threads that allocate and deallocate memory
    int num_threads = 4;
    pthread_t threads[num_threads];
    void *memory_blocks_ptr[num_threads];
    for (int i = 0; i < num_threads; i++) {
        memory_blocks_ptr[i] = malloc(100);
        pthread_create(&threads[i], NULL, alloc_dealloc_memory, (void *)&memory_blocks_ptr[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the remaining memory blocks
    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory_blocks[i].address == NULL) {
            printf("Memory block %p is free\n", memory_blocks[i].address);
        } else {
            printf("Memory block %p is occupied\n", memory_blocks[i].address);
        }
    }

    return 0;
}