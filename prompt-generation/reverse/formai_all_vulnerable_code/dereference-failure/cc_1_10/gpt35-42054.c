//FormAI DATASET v1.0 Category: Memory management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_BLOCKS 5
#define MAX_BUFFER_SIZE 1024

typedef struct {
    pthread_mutex_t *lock;
    char *buffer;
    int buffer_index;
    int buffer_size;
    int blocks_used[MAX_BLOCKS];
} MemoryManager;

void* allocate_memory(void* arg) {
    MemoryManager* memory_manager = (MemoryManager*) arg;

    pthread_mutex_lock(memory_manager->lock);

    int i, block_index = -1;
    for (i = 0; i < MAX_BLOCKS; i++) {
        if (memory_manager->blocks_used[i] == 0) {
            block_index = i;
            memory_manager->blocks_used[i] = 1;
            break;
        }
    }

    if (block_index == -1) {
        printf("No more memory blocks available!\n");
        pthread_mutex_unlock(memory_manager->lock);
        return NULL;
    }

    // Allocate memory block
    int block_size = rand() % (memory_manager->buffer_size - memory_manager->buffer_index + 1);
    char* block = &memory_manager->buffer[memory_manager->buffer_index];
    memory_manager->buffer_index += block_size;

    pthread_mutex_unlock(memory_manager->lock);

    printf("Allocated memory block at index %d with size %d\n", block - memory_manager->buffer, block_size);
    sleep(rand() % 3 + 1); // Simulate some work being done

    // Free memory block
    pthread_mutex_lock(memory_manager->lock);

    memory_manager->blocks_used[block_index] = 0;
    memory_manager->buffer_index -= block_size;

    pthread_mutex_unlock(memory_manager->lock);

    printf("Freed memory block at index %d with size %d\n", block - memory_manager->buffer, block_size);
    sleep(rand() % 3 + 1); // Simulate some work being done

    return NULL;
}

int main() {
    // Create memory manager
    MemoryManager memory_manager;
    memory_manager.lock = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(memory_manager.lock, NULL);

    memory_manager.buffer = (char*) malloc(MAX_BUFFER_SIZE * sizeof(char));
    memory_manager.buffer_index = 0;
    memory_manager.buffer_size = MAX_BUFFER_SIZE;

    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        memory_manager.blocks_used[i] = 0;
    }

    // Create threads to allocate and free memory blocks
    pthread_t threads[MAX_BLOCKS];
    for (i = 0; i < MAX_BLOCKS; i++) {
        pthread_create(&threads[i], NULL, allocate_memory, (void*) &memory_manager);
    }

    // Wait for threads to finish
    for (i = 0; i < MAX_BLOCKS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up memory manager
    pthread_mutex_destroy(memory_manager.lock);
    free(memory_manager.lock);
    free(memory_manager.buffer);

    return 0;
}