//FormAI DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Struct for the buffer that holds the strings
typedef struct {
    char** buffer;
    size_t buffer_size;
    size_t read_index;
    size_t write_index;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
} Buffer;

// Create a new buffer
Buffer* new_buffer(size_t size) {
    Buffer* buffer = malloc(sizeof(Buffer));
    buffer->buffer = malloc(sizeof(char*) * size);
    buffer->buffer_size = size;
    buffer->read_index = 0;
    buffer->write_index = 0;
    sem_init(&buffer->full, 0, 0);
    sem_init(&buffer->empty, 0, size);
    pthread_mutex_init(&buffer->mutex, NULL);
    return buffer;
}

// Free the buffer
void free_buffer(Buffer* buffer) {
    sem_destroy(&buffer->full);
    sem_destroy(&buffer->empty);
    pthread_mutex_destroy(&buffer->mutex);
    for (size_t i = 0; i < buffer->buffer_size; i++) {
        free(buffer->buffer[i]);
    }
    free(buffer->buffer);
    free(buffer);
}

// Add a string to the buffer
void add_string(Buffer* buffer, const char* string) {
    sem_wait(&buffer->empty);
    pthread_mutex_lock(&buffer->mutex);

    // Copy the string into the buffer
    buffer->buffer[buffer->write_index] = malloc(strlen(string) + 1);
    strcpy(buffer->buffer[buffer->write_index], string);

    // Update the write index
    buffer->write_index++;
    if (buffer->write_index >= buffer->buffer_size) {
        buffer->write_index = 0;
    }

    pthread_mutex_unlock(&buffer->mutex);
    sem_post(&buffer->full);
}

// Read a string from the buffer
char* read_string(Buffer* buffer) {
    sem_wait(&buffer->full);
    pthread_mutex_lock(&buffer->mutex);

    // Get the string from the buffer
    char* string = buffer->buffer[buffer->read_index];

    // Update the read index
    buffer->read_index++;
    if (buffer->read_index >= buffer->buffer_size) {
        buffer->read_index = 0;
    }

    pthread_mutex_unlock(&buffer->mutex);
    sem_post(&buffer->empty);

    return string;
}

// Thread function that adds strings to the buffer
void* add_thread(void* arg) {
    Buffer* buffer = (Buffer*) arg;
    add_string(buffer, "Hello");
    add_string(buffer, "World");
    add_string(buffer, "This");
    add_string(buffer, "is");
    add_string(buffer, "an");
    add_string(buffer, "asynchronous");
    add_string(buffer, "program!");
    pthread_exit(NULL);
}

// Thread function that reads strings from the buffer
void* read_thread(void* arg) {
    Buffer* buffer = (Buffer*) arg;
    for (int i = 0; i < 7; i++) {
        char* string = read_string(buffer);
        printf("%s ", string);
        free(string);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    // Create the buffer
    Buffer* buffer = new_buffer(8);

    // Create the threads
    pthread_t add_tid, read_tid;
    pthread_create(&add_tid, NULL, add_thread, buffer);
    pthread_create(&read_tid, NULL, read_thread, buffer);

    // Wait for the threads to finish
    pthread_join(add_tid, NULL);
    pthread_join(read_tid, NULL);

    // Free the buffer
    free_buffer(buffer);

    return 0;
}