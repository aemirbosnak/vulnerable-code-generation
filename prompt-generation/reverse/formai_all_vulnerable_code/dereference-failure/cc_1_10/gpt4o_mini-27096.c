//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#define CHUNK_SIZE 1024
#define MAX_THREADS 4
#define FILENAME "input.txt"

typedef struct {
    char *buffer;
    size_t length;
    unsigned int checksum;
} Chunk;

typedef struct {
    Chunk *chunk;
    int thread_id;
} ThreadData;

// Function to calculate checksum for a given chunk
unsigned int calculate_checksum(const char *data, size_t length) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function that each thread will run to calculate the checksum of its chunk
void *thread_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    Chunk *chunk = data->chunk;
    chunk->checksum = calculate_checksum(chunk->buffer, chunk->length);
    printf("Thread %d: Checksum of chunk is %u\n", data->thread_id, chunk->checksum);
    pthread_exit(NULL);
}

// Function to read the file in chunks and start threads for checksum calculation
void process_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    Chunk chunks[MAX_THREADS];
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    size_t bytes_read;
    int chunk_count = 0;

    while ((bytes_read = fread(chunks[chunk_count].buffer, 1, CHUNK_SIZE, file)) > 0) {
        chunks[chunk_count].length = bytes_read;
        chunks[chunk_count].buffer = malloc(CHUNK_SIZE);
        memcpy(chunks[chunk_count].buffer, chunks[chunk_count].buffer, bytes_read);

        // Create a thread to calculate the checksum of this chunk
        thread_data[chunk_count].chunk = &chunks[chunk_count];
        thread_data[chunk_count].thread_id = chunk_count;

        if (pthread_create(&threads[chunk_count], NULL, thread_function, &thread_data[chunk_count])) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }

        chunk_count++;
        if (chunk_count >= MAX_THREADS) {
            break; // Prevent exceeding max thread count
        }
    }

    // Join threads after processing
    for (int i = 0; i < chunk_count; i++) {
        pthread_join(threads[i], NULL);
        free(chunks[i].buffer); // Free allocated memory for the buffer
    }

    fclose(file);

    // Combine checksums to get the final checksum
    unsigned int final_checksum = 0;
    for (int i = 0; i < chunk_count; i++) {
        final_checksum += chunks[i].checksum;
    }

    printf("Final checksum: %u\n", final_checksum);
}

int main() {
    process_file(FILENAME);
    return 0;
}