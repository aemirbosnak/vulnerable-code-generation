//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

#define KEY_LENGTH 256
#define IV_LENGTH 16

int main(int argc, char *argv[]) {
    // Set up the key and IV
    char *key = (char *) malloc(sizeof(char) * KEY_LENGTH);
    char *iv = (char *) malloc(sizeof(char) * IV_LENGTH);

    // Generate random key and IV
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
    for (int i = 0; i < IV_LENGTH; i++) {
        iv[i] = rand() % 256;
    }

    // Set up the input and output files
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(1);
    }

    // Initialize the encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *) key, (unsigned char *) iv);

    // Set up the buffer for reading in data
    unsigned char *input_buffer = (unsigned char *) malloc(sizeof(unsigned char) * 1024);
    int read_len;

    // Loop through the input file, encrypting and writing out data
    do {
        read_len = fread(input_buffer, sizeof(unsigned char), 1024, input_file);

        if (ferror(input_file)) {
            fprintf(stderr, "Error reading input file\n");
            exit(1);
        }

        EVP_EncryptUpdate(ctx, input_buffer, &read_len, input_buffer, read_len);
        fwrite(input_buffer, sizeof(unsigned char), read_len, output_file);

    } while (read_len > 0);

    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, input_buffer, &read_len);
    fwrite(input_buffer, sizeof(unsigned char), read_len, output_file);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    fclose(input_file);
    fclose(output_file);
    free(input_buffer);
    free(key);
    free(iv);

    return 0;
}