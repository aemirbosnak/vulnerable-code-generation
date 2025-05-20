//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Global variables
pthread_mutex_t mutex;
FILE *input_file, *output_file;
char *key;
int key_len;

// Function to encrypt a single character
char encrypt_char(char c) {
    return (c + key[c % key_len]) % 256;
}

// Function to encrypt a block of data
void *encrypt_block(void *args) {
    int start = *(int *)args;
    int end = start + 1024;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Encrypt the block
    for (int i = start; i < end; i++) {
        char c = fgetc(input_file);
        if (c == EOF) {
            break;
        }
        fputc(encrypt_char(c), output_file);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }
    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    // Get the key
    key = argv[3];
    key_len = strlen(key);

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread pool
    pthread_t threads[4];

    // Start the threads
    for (int i = 0; i < 4; i++) {
        int *start = malloc(sizeof(int));
        *start = i * 1024;
        pthread_create(&threads[i], NULL, encrypt_block, start);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}