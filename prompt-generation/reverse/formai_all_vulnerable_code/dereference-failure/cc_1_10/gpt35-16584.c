//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>

/*
  This program implements the AES-256 encryption algorithm
*/

int main(int argc, char *argv[]) {

    if(argc < 3) {
        printf("Usage: %s <in_file> <out_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read input file
    FILE *input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Failed to open input file\n");
        exit(EXIT_FAILURE);
    }

    fseek(input_file, 0L, SEEK_END);
    int input_file_size = ftell(input_file);
    rewind(input_file);

    unsigned char *input_buffer = (unsigned char*) malloc(input_file_size);
    if(input_buffer == NULL) {
        printf("Failed to allocate input buffer\n");
        exit(EXIT_FAILURE);
    }

    int bytes_read = fread(input_buffer, 1, input_file_size, input_file);
    if(bytes_read != input_file_size) {
        printf("Failed to read input file\n");
        exit(EXIT_FAILURE);
    }

    fclose(input_file);

    // Prepare key and iv
    unsigned char *key = (unsigned char*) "thisisaverystrongkey";
    unsigned char *iv = (unsigned char*) "thisistheivector";

    EVP_CIPHER_CTX *ctx;

    // Create and initialize the context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    int max_output_size = input_file_size + EVP_MAX_BLOCK_LENGTH;
    unsigned char *output_buffer = (unsigned char*) malloc(max_output_size);
    if(output_buffer == NULL) {
        printf("Failed to allocate output buffer\n");
        exit(EXIT_FAILURE);
    }

    int output_size = 0;

    // Encrypt
    EVP_EncryptUpdate(ctx, output_buffer, &output_size, input_buffer, input_file_size);

    int final_output_size = 0;

    // Get the final output block
    EVP_EncryptFinal_ex(ctx, output_buffer + output_size, &final_output_size);

    output_size += final_output_size;

    // Write to output file
    FILE *output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Failed to open output file\n");
        exit(EXIT_FAILURE);
    }

    fwrite(output_buffer, 1, output_size, output_file);

    fclose(output_file);

    printf("Encryption successful\n");

    return 0;
}