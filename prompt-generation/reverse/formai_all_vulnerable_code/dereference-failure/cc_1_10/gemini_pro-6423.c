//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <pthread.h>

// Define the thread data structure
typedef struct {
    unsigned char *data;
    size_t data_len;
    unsigned char *hash;
} thread_data_t;

// Define the thread function
void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Create a SHA256 context
    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    // Update the context with the data
    SHA256_Update(&ctx, data->data, data->data_len);

    // Finalize the context and get the hash
    SHA256_Final(data->hash, &ctx);

    // Free the data
    free(data->data);
    free(data);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the file into memory
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    rewind(fp);

    unsigned char *data = (unsigned char *)malloc(file_size);
    if (data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(data, file_size, 1, fp);
    fclose(fp);

    // Create the thread data
    thread_data_t *thread_data = (thread_data_t *)malloc(sizeof(thread_data_t));
    if (thread_data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    thread_data->data = data;
    thread_data->data_len = file_size;
    thread_data->hash = (unsigned char *)malloc(SHA256_DIGEST_LENGTH);
    if (thread_data->hash == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Create the thread
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_func, thread_data) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join");
        return EXIT_FAILURE;
    }

    // Print the hash
    printf("SHA256 hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", thread_data->hash[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(thread_data->hash);
    free(thread_data);
    free(data);

    return EXIT_SUCCESS;
}