//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define BUFFER_SIZE 10 // Maximum buffer size

// Circular buffer structure
typedef struct {
   int *buffer; // Buffer where elements are stored
   int size; // Size of the buffer
   int head; // Index of the first element
   int tail; // Index of the last element
   int count; // Number of elements in the buffer
   pthread_mutex_t lock; // Mutex for thread safety
   pthread_cond_t not_empty; // Condition variable for waiting on non-empty buffer
   pthread_cond_t not_full; // Condition variable for waiting on non-full buffer
} circular_buffer_t;

// Initialize the circular buffer
void init_circular_buffer(circular_buffer_t* buffer, int size) {
    // Allocate memory for buffer and set attributes
    buffer->buffer = (int*) malloc(size * sizeof(int));
    buffer->size = size;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    // Initialize mutex and condition variables
    pthread_mutex_init(&buffer->lock, NULL);
    pthread_cond_init(&buffer->not_empty, NULL);
    pthread_cond_init(&buffer->not_full, NULL);
}

// Free memory used by circular buffer
void free_circular_buffer(circular_buffer_t* buffer) {
    free(buffer->buffer);
    pthread_mutex_destroy(&buffer->lock);
    pthread_cond_destroy(&buffer->not_empty);
    pthread_cond_destroy(&buffer->not_full);
}

// Add element to the circular buffer
void push_circular_buffer(circular_buffer_t* buffer, int element) {
    pthread_mutex_lock(&buffer->lock);
    while (buffer->count == buffer->size) {
        // Wait for buffer to not be full
        pthread_cond_wait(&buffer->not_full, &buffer->lock);
    }
    buffer->buffer[buffer->tail] = element;
    buffer->tail = (buffer->tail + 1) % buffer->size;
    buffer->count++;
    // Notify waiting threads that buffer is not empty
    pthread_cond_signal(&buffer->not_empty);
    pthread_mutex_unlock(&buffer->lock);
}

// Remove element from the circular buffer
int pop_circular_buffer(circular_buffer_t* buffer) {
    pthread_mutex_lock(&buffer->lock);
    while (buffer->count == 0) {
        // Wait for buffer to not be empty
        pthread_cond_wait(&buffer->not_empty, &buffer->lock);
    }
    int element = buffer->buffer[buffer->head];
    buffer->head = (buffer->head + 1) % buffer->size;
    buffer->count--;
    // Notify waiting threads that buffer is not full
    pthread_cond_signal(&buffer->not_full);
    pthread_mutex_unlock(&buffer->lock);
    return element;
}

// Thread function to add elements to the buffer
void* push_elements(void* args) {
    circular_buffer_t* buffer = (circular_buffer_t*) args;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        push_circular_buffer(buffer, i);
        printf("Pushed element %d to buffer\n", i);
    }
    pthread_exit(NULL);
}

// Thread function to remove elements from the buffer
void* pop_elements(void* args) {
    circular_buffer_t* buffer = (circular_buffer_t*) args;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        int element = pop_circular_buffer(buffer);
        printf("Popped element %d from buffer\n", element);
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize circular buffer
    circular_buffer_t buffer;
    init_circular_buffer(&buffer, BUFFER_SIZE);

    // Create threads to push and pop elements from the buffer
    pthread_t push_thread, pop_thread;
    pthread_create(&push_thread, NULL, push_elements, &buffer);
    pthread_create(&pop_thread, NULL, pop_elements, &buffer);

    // Wait for threads to finish
    pthread_join(push_thread, NULL);
    pthread_join(pop_thread, NULL);

    // Free memory used by circular buffer
    free_circular_buffer(&buffer);

    return 0;
}