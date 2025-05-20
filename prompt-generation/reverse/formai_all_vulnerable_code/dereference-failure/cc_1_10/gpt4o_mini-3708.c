//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: paranoid
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define THREAD_COUNT 4
#define BUFFER_SIZE 10

// A structure to hold buffer and synchronization mechanisms.
typedef struct {
    char buffer[BUFFER_SIZE];
    int read_pos;
    int write_pos;
    pthread_mutex_t lock;
    pthread_cond_t can_read;
    pthread_cond_t can_write;
} SharedBuffer;

// Function prototypes
void* producer(void* param);
void* consumer(void* param);
void initialize_buffer(SharedBuffer* shared_buffer);

int main() {
    pthread_t producers[THREAD_COUNT];
    pthread_t consumers[THREAD_COUNT];
    SharedBuffer shared_buffer;

    initialize_buffer(&shared_buffer);

    // Creating producer and consumer threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&producers[i], NULL, producer, (void*)&shared_buffer);
        pthread_create(&consumers[i], NULL, consumer, (void*)&shared_buffer);
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    // Clean and release resources
    pthread_mutex_destroy(&shared_buffer.lock);
    pthread_cond_destroy(&shared_buffer.can_read);
    pthread_cond_destroy(&shared_buffer.can_write);

    return 0;
}

void initialize_buffer(SharedBuffer* shared_buffer) {
    memset(shared_buffer->buffer, 0, BUFFER_SIZE);
    shared_buffer->read_pos = 0;
    shared_buffer->write_pos = 0;
    pthread_mutex_init(&shared_buffer->lock, NULL);
    pthread_cond_init(&shared_buffer->can_read, NULL);
    pthread_cond_init(&shared_buffer->can_write, NULL);
}

void* producer(void* param) {
    SharedBuffer* shared_buffer = (SharedBuffer*)param;
    char msg[16];

    for (int i = 0; i < 20; i++) {
        // Simulate production time
        sleep(rand() % 3);
        
        snprintf(msg, sizeof(msg), "Item-%d", i);
        
        pthread_mutex_lock(&shared_buffer->lock);
        
        // Wait for space in buffer
        while ((shared_buffer->write_pos + 1) % BUFFER_SIZE == shared_buffer->read_pos) {
            pthread_cond_wait(&shared_buffer->can_write, &shared_buffer->lock);
        }
        
        // Write to the buffer
        shared_buffer->buffer[shared_buffer->write_pos] = strdup(msg)[0];
        printf("Produced: %s\n", msg);
        shared_buffer->write_pos = (shared_buffer->write_pos + 1) % BUFFER_SIZE;

        // Signal that an item has been produced
        pthread_cond_signal(&shared_buffer->can_read);
        pthread_mutex_unlock(&shared_buffer->lock);
    }
    return NULL;
}

void* consumer(void* param) {
    SharedBuffer* shared_buffer = (SharedBuffer*)param;
    
    for (int i = 0; i < 20; i++) {
        // Simulate consumption time
        sleep(rand() % 2);
        
        pthread_mutex_lock(&shared_buffer->lock);
        
        // Wait for items to be available
        while (shared_buffer->read_pos == shared_buffer->write_pos) {
            pthread_cond_wait(&shared_buffer->can_read, &shared_buffer->lock);
        }
        
        // Read from the buffer
        char item = shared_buffer->buffer[shared_buffer->read_pos];
        printf("Consumed: %c\n", item);
        shared_buffer->read_pos = (shared_buffer->read_pos + 1) % BUFFER_SIZE;

        // Signal that there's space in the buffer
        pthread_cond_signal(&shared_buffer->can_write);
        pthread_mutex_unlock(&shared_buffer->lock);
    }
    return NULL;
}