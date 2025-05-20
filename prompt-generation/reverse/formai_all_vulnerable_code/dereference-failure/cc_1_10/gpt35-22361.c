//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define BUF_SIZE 4096

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [key] [input_file] [output_file]\n", argv[0]);
        return -1;
    }

    // Get the key
    unsigned char key[32];
    memset(key, 0, 32);
    strncpy((char*) key, argv[1], 32);

    // Open the input file
    FILE* input_file = fopen(argv[2], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: could not open input file '%s'.\n", argv[2]);
        return -1;
    }

    // Open the output file
    FILE* output_file = fopen(argv[3], "wb");
    if (!output_file) {
        fprintf(stderr, "Error: could not open output file '%s'.\n", argv[3]);
        fclose(input_file);
        return -1;
    }

    // Initialize the encryption context
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 256, &aes_key) != 0) {
        fprintf(stderr, "Error: could not set AES key.\n");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }

    // Read data from the input file, encrypt it, and write it to the output file
    unsigned char buffer[BUF_SIZE];
    char encrypted[BUF_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUF_SIZE, input_file)) > 0) {
        memset(encrypted, 0, BUF_SIZE);
        AES_encrypt(buffer, encrypted, &aes_key);
        fwrite(encrypted, sizeof(unsigned char), bytes_read, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}