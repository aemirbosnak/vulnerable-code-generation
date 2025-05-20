//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <openssl/md5.h>

// Define a struct to hold the input and output parameters for each thread
typedef struct {
    char* input;
    char* output;
} ThreadParams;

// The number of threads to use
#define NUM_THREADS 4

// The length of the input string to hash
#define INPUT_LEN 10000000

void* hash_function(void* arg) {
    ThreadParams* params = (ThreadParams*) arg;
    unsigned char md5_hash[MD5_DIGEST_LENGTH];

    // Calculate MD5 hash of the input string
    MD5((unsigned char*) params->input, strlen(params->input), md5_hash);

    // Convert hash to hex string
    char md5_string[MD5_DIGEST_LENGTH * 2 + 1];
    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(md5_string + i * 2, "%02x", md5_hash[i]);
    }

    // Copy output to params struct
    params->output = strdup(md5_string);

    pthread_exit(NULL);
}

int main(void) {
    // Generate random input string
    char* input = calloc(INPUT_LEN + 1, sizeof(char));
    int i;
    for (i = 0; i < INPUT_LEN; i++) {
        input[i] = (char) (rand() % 26 + 'a');
    }

    // Split input string into chunks for each thread
    int chunk_size = INPUT_LEN / NUM_THREADS;
    ThreadParams params[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        params[i].input = input + i * chunk_size;
        params[i].output = NULL;
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, hash_function, (void*) &params[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Combine hash outputs from each thread
    char* combined_hash = calloc(MD5_DIGEST_LENGTH * 2 + 1, sizeof(char));
    for (i = 0; i < NUM_THREADS; i++) {
        strcat(combined_hash, params[i].output);
    }

    // Calculate final MD5 hash of combined hash strings
    unsigned char final_hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*) combined_hash, strlen(combined_hash), final_hash);

    // Print final hash in hexadecimal
    printf("Final hash: ");
    for (i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", final_hash[i]);
    }
    printf("\n");

    // Free memory
    free(combined_hash);
    for (i = 0; i < NUM_THREADS; i++) {
        free(params[i].output);
    }
    free(input);

    return 0;
}