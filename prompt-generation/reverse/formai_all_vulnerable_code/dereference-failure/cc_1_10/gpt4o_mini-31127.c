//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define THREAD_COUNT 3
#define BUFFER_SIZE 10

typedef struct {
    char **buffer;
    int size;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t full;
    pthread_cond_t empty;
} SharedBuffer;

void* producer(void* arg);
void* consumer(void* arg);
void cleanup(SharedBuffer *shared);

int main() {
    pthread_t producers[THREAD_COUNT], consumers[THREAD_COUNT];
    SharedBuffer shared;

    // Initialize the shared buffer
    shared.size = BUFFER_SIZE;
    shared.in = 0;
    shared.out = 0;
    shared.buffer = malloc(sizeof(char*) * BUFFER_SIZE);
    pthread_mutex_init(&shared.mutex, NULL);
    pthread_cond_init(&shared.full, NULL);
    pthread_cond_init(&shared.empty, NULL);

    // Create producer threads
    for (int i = 0; i < THREAD_COUNT; ++i) {
        if (pthread_create(&producers[i], NULL, producer, (void*)&shared) != 0) {
            perror("Failed to create producer thread");
            cleanup(&shared);
            return 1;
        }
    }

    // Create consumer threads
    for (int i = 0; i < THREAD_COUNT; ++i) {
        if (pthread_create(&consumers[i], NULL, consumer, (void*)&shared) != 0) {
            perror("Failed to create consumer thread");
            cleanup(&shared);
            return 1;
        }
    }

    // Join producer threads
    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(producers[i], NULL);
    }

    // Join consumer threads
    for (int i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(consumers[i], NULL);
    }

    // Cleanup
    cleanup(&shared);
    return 0;
}

void* producer(void* arg) {
    SharedBuffer* shared = (SharedBuffer*)arg;

    for (int i = 0; i < 5; ++i) { // Produce 5 items
        char* item = malloc(20 * sizeof(char));
        sprintf(item, "Item %d from Producer", i);

        // Lock the mutex for safe access
        pthread_mutex_lock(&shared->mutex);

        while (((shared->in + 1) % shared->size) == shared->out) {
            // Buffer is full, wait for consumers
            pthread_cond_wait(&shared->empty, &shared->mutex);
        }

        // Add item to the buffer
        shared->buffer[shared->in] = item;
        shared->in = (shared->in + 1) % shared->size;
        printf("Produced: %s\n", item);

        // Signal that buffer is not empty
        pthread_cond_signal(&shared->full);
        pthread_mutex_unlock(&shared->mutex);

        sleep(rand() % 2); // Sleep for a random time to simulate work
    }
    
    return NULL;
}

void* consumer(void* arg) {
    SharedBuffer* shared = (SharedBuffer*)arg;

    for (int i = 0; i < 5; ++i) { // Consume 5 items
        // Lock the mutex for safe access
        pthread_mutex_lock(&shared->mutex);

        while (shared->in == shared->out) {
            // Buffer is empty, wait for producers
            pthread_cond_wait(&shared->full, &shared->mutex);
        }

        // Remove item from the buffer
        char* item = shared->buffer[shared->out];
        shared->out = (shared->out + 1) % shared->size;
        printf("Consumed: %s\n", item);
        
        // Free the consumed item memory
        free(item);

        // Signal that buffer is not full
        pthread_cond_signal(&shared->empty);
        pthread_mutex_unlock(&shared->mutex);

        sleep(rand() % 2); // Sleep for a random time to simulate work
    }

    return NULL;
}

void cleanup(SharedBuffer *shared) {
    free(shared->buffer);
    pthread_mutex_destroy(&shared->mutex);
    pthread_cond_destroy(&shared->full);
    pthread_cond_destroy(&shared->empty);
}