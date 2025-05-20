//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
    printf("Usage: file_encryptor <key> <input_file> <output_file>\n");
    printf("key - the key to use for encryption/decryption\n");
    printf("input_file - the file to encrypt/decrypt\n");
    printf("output_file - the result of the encryption/decryption\n");
}

void encrypt_file(char *key, char *input_file, char *output_file) {
    FILE *input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Failed to open input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    FILE *output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Failed to open output file: %s\n", output_file);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    size_t key_size = strlen(key);
    size_t input_size;
    unsigned char *input_buffer;
    unsigned char *output_buffer = (unsigned char*) malloc(sizeof(unsigned char) * 1024);
    unsigned char *key_buffer = (unsigned char*) malloc(key_size * sizeof(unsigned char));
    memcpy(key_buffer, key, key_size);

    while ((input_size = fread(input_buffer, sizeof(unsigned char), 1024, input_fp)) > 0) {
        for (size_t i = 0; i < input_size; i++) {
            output_buffer[i] = input_buffer[i] ^ key_buffer[i % key_size];
        }
        fwrite(output_buffer, sizeof(unsigned char), input_size, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    free(input_buffer);
    free(output_buffer);
    free(key_buffer);
}

void decrypt_file(char *key, char *input_file, char *output_file) {
    // Decryption is the same as encryption, just flip the input and output buffers
    encrypt_file(key, input_file, output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return(EXIT_FAILURE);
    }
    
    char *key = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    encrypt_file(key, input_file, output_file);

    printf("File successfully encrypted\n");

    return EXIT_SUCCESS;
}