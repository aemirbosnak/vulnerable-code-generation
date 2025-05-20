//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/evp.h>

#define NUM_THREADS 4
#define BUFFER_SIZE 1024

typedef struct {
    int thread_id;
    char *input;
    unsigned char *output;
} ThreadData;

void *HashThread(void *threadargs) {
    ThreadData *td = (ThreadData*)threadargs;
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned int md_len;

    OpenSSL_add_all_digests();

    md = EVP_get_digestbyname("SHA256");
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, td->input, strlen(td->input));
    EVP_DigestFinal_ex(mdctx, td->output, &md_len);
    EVP_MD_CTX_free(mdctx);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./hash input_string\n");
        return 1;
    }

    char *input = argv[1];
    unsigned char *output = (unsigned char*)malloc(EVP_MAX_MD_SIZE);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].input = input + (i * BUFFER_SIZE);
        thread_data[i].output = output + (i * EVP_MAX_MD_SIZE / NUM_THREADS);
        pthread_create(&threads[i], NULL, HashThread, (void *)&thread_data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    EVP_cleanup();

    int output_size = EVP_MAX_MD_SIZE / NUM_THREADS;
    for (i = 0; i < output_size; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    free(output);

    return 0;
}