//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void encrypt_decrypt(FILE *inputFile, FILE *outputFile, char *key) {
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;
    size_t keyLength = strlen(key);
    int i;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), MAX_BUFFER_SIZE, inputFile)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength];  // XOR encryption
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }
}

void print_usage(char *programName) {
    printf("Usage: %s <input_file> <output_file> <key>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    char *key = argv[3];
    encrypt_decrypt(inputFile, outputFile, key);

    printf("File encryption completed successfully!\n");

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}