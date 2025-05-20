//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/sha.h>

#define NUM_THREADS 4
#define MAX_DATA_SIZE 1024

typedef struct {
    char *data;          // Pointer to the data segment to be processed
    size_t length;      // Length of the data segment
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Hash result
} ThreadData;

void *compute_hash(void *arg) {
    ThreadData *thread_data = (ThreadData *)arg;
    SHA256((unsigned char *)thread_data->data, thread_data->length, thread_data->hash);
    return NULL;
}

void merge_hashes(unsigned char *final_hash, unsigned char *hash1, unsigned char *hash2) {
    // Simple merge: Hash the concatenation of the two partial hashes.
    unsigned char combined_hash[SHA256_DIGEST_LENGTH * 2];
    memcpy(combined_hash, hash1, SHA256_DIGEST_LENGTH);
    memcpy(combined_hash + SHA256_DIGEST_LENGTH, hash2, SHA256_DIGEST_LENGTH);
    SHA256(combined_hash, sizeof(combined_hash), final_hash);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Prepare data
    char *input_data = argv[1];
    size_t data_length = strlen(input_data);
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    unsigned char final_hash[SHA256_DIGEST_LENGTH];

    // Split the input data into segments for each thread
    size_t segment_size = data_length / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].length = (i == NUM_THREADS - 1) ? (data_length - (segment_size * i)) : segment_size;
        thread_data[i].data = (char *)malloc(thread_data[i].length + 1);
        strncpy(thread_data[i].data, input_data + (segment_size * i), thread_data[i].length);
        thread_data[i].data[thread_data[i].length] = '\0';

        pthread_create(&threads[i], NULL, compute_hash, &thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine hashes from all threads
    memcpy(final_hash, thread_data[0].hash, SHA256_DIGEST_LENGTH);
    for (int i = 1; i < NUM_THREADS; i++) {
        merge_hashes(final_hash, final_hash, thread_data[i].hash);
    }

    // Print final hash
    printf("SHA256: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", final_hash[i]);
    }
    printf("\n");

    // Clean up
    for (int i = 0; i < NUM_THREADS; i++) {
        free(thread_data[i].data);
    }

    return EXIT_SUCCESS;
}