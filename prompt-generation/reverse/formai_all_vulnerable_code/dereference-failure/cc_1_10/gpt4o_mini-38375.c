//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY 0xAA // Simple XOR key for encryption/decryption

void print_usage() {
    printf("Usage: file_encryptor <encrypt/decrypt> <input_file> <output_file>\n");
}

void xor_encrypt_decrypt(FILE *input, FILE *output) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            buffer[i] ^= KEY; // XOR each byte with the key
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "encrypt") == 0) {
        printf("Encrypting file '%s'...\n", inputFileName);
        xor_encrypt_decrypt(inputFile, outputFile);
        printf("Encryption complete. Encrypted data written to '%s'.\n", outputFileName);
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Decrypting file '%s'...\n", inputFileName);
        xor_encrypt_decrypt(inputFile, outputFile);
        printf("Decryption complete. Decrypted data written to '%s'.\n", outputFileName);
    } else {
        print_usage();
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}