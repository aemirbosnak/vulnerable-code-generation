//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

// Struct to hold data for the buffer
typedef struct {
    int *data;
    int max_size;
    int current_size;
} Buffer;

// Allocate memory for buffer
void buffer_init(Buffer *buffer, int max_size) {
    buffer->data = (int*) malloc(max_size * sizeof(int));
    buffer->max_size = max_size;
    buffer->current_size = 0;
}

// Deallocate memory for buffer
void buffer_destroy(Buffer *buffer) {
    free(buffer->data);
}

// Add item to buffer
void buffer_add(Buffer *buffer, int item) {
    if (buffer->current_size >= buffer->max_size) {
        printf("Buffer full!\n");
        return;
    }
    buffer->data[buffer->current_size] = item;
    buffer->current_size++;
}

// Remove item from buffer
int buffer_remove(Buffer *buffer) {
    if (buffer->current_size <= 0) {
        printf("Buffer empty!\n");
        return -1;
    }
    int item = buffer->data[buffer->current_size-1];
    buffer->current_size--;
    return item;
}

// Function for producer thread
void* producer(void* buffer_ptr) {
    Buffer *buffer = (Buffer*) buffer_ptr;
    int item = 0;
    while (1) {
        // Generate random item to add
        item = rand();
        printf("Producing item %d\n", item);
        // Add item to buffer
        buffer_add(buffer, item);
        // Sleep for random amount of time
        int sleep_time = rand() % 5;
        sleep(sleep_time);
    }
}

// Function for consumer thread
void* consumer(void* buffer_ptr) {
    Buffer *buffer = (Buffer*) buffer_ptr;
    int item = 0;
    while (1) {
        // Remove item from buffer
        item = buffer_remove(buffer);
        printf("Consuming item %d\n", item);
        // Sleep for random amount of time
        int sleep_time = rand() % 5;
        sleep(sleep_time);
    }
}

int main() {
    // Create buffer and initialize memory
    Buffer buffer;
    buffer_init(&buffer, BUFFER_SIZE);

    // Create producer and consumer threads
    pthread_t producer_thread;
    pthread_t consumer_thread;
    pthread_create(&producer_thread, NULL, producer, &buffer);
    pthread_create(&consumer_thread, NULL, consumer, &buffer);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Deallocate memory for buffer
    buffer_destroy(&buffer);

    return 0;
}