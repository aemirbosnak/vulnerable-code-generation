//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
int main(int argc, char *argv[])
{
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <key> <input file>\n", argv[0]);
        exit(1);
    }
    const char *key = argv[1];
    const char *filename = argv[2];
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening %s\n", filename);
        exit(1);
    }
    size_t file_size = 0;
    fseek(input, 0, SEEK_END);
    file_size = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *buffer = (char *)malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    size_t bytes_read = fread(buffer, 1, file_size, input);
    if (bytes_read!= file_size) {
        fprintf(stderr, "Error reading %s\n", filename);
        exit(1);
    }
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error creating cipher context\n");
        exit(1);
    }
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL)!= 1) {
        fprintf(stderr, "Error initializing encryption\n");
        exit(1);
    }
    int padding = -1;
    unsigned char *iv = (unsigned char *)malloc(EVP_CIPHER_iv_length(EVP_aes_256_cbc()));
    if (iv == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    if (EVP_EncryptUpdate(ctx, buffer, &bytes_read, buffer, &padding)!= 1) {
        fprintf(stderr, "Error encrypting data\n");
        exit(1);
    }
    EVP_CIPHER_CTX_cleanup(ctx);
    free(iv);
    fclose(input);
    if (buffer!= NULL) {
        free(buffer);
    }
    return 0;
}