//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <pthread.h>

#define BUFSIZE 1024

struct thread_data {
    unsigned char *input;
    int input_len;
    unsigned char *key;
    unsigned char *iv;
    int *output_len;
    unsigned char **output;
};

void *encrypt(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    if (ctx == NULL) {
        fprintf(stderr, "Couldn't create EVP context\n");
        exit(EXIT_FAILURE);
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, data->key, data->iv) == 0) {
        fprintf(stderr, "Error while initializing encryption\n");
        exit(EXIT_FAILURE);
    }

    unsigned char *cipher = malloc(BUFSIZE);
    int cipher_len;

    if (EVP_EncryptUpdate(ctx, cipher, &cipher_len, data->input, data->input_len) == 0) {
        fprintf(stderr, "Error while encrypting data\n");
        exit(EXIT_FAILURE);
    }

    int outlen;
    if (EVP_EncryptFinal_ex(ctx, cipher + cipher_len, &outlen) == 0) {
        fprintf(stderr, "Error while finalizing encryption\n");
        exit(EXIT_FAILURE);
    }
    cipher_len += outlen;

    EVP_CIPHER_CTX_free(ctx);

    *data->output = cipher;
    *data->output_len = cipher_len;

    pthread_exit(NULL);
}

int main() {
    unsigned char *input = (unsigned char *) "This is a test string\n";
    int input_len = strlen((char *) input);
    unsigned char *key = (unsigned char *) "mysecretkey";
    unsigned char *iv = (unsigned char *) "myiv";

    int output_len = 0;
    unsigned char *output = NULL;

    pthread_t thread;
    struct thread_data data = {input, input_len, key, iv, &output_len, &output};

    if (pthread_create(&thread, NULL, encrypt, (void *) &data) != 0) {
        fprintf(stderr, "Couldn't create thread\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread, NULL) != 0) {
        fprintf(stderr, "Couldn't join thread\n");
        exit(EXIT_FAILURE);
    }

    printf("Encrypted message: ");
    for (int i = 0; i < output_len; i++) {
        printf("%02x ", output[i]);
    }
    printf("\n");

    free(output);

    return 0;
}