//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void encryptDecrypt(char *input, char *output, char key) {
    FILE *inputFile = fopen(input, "rb");
    FILE *outputFile = fopen(output, "wb");
    
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    if (outputFile == NULL) {
        fclose(inputFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR operation for encryption and decryption
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    char key = 'K';  // Simple fixed key for XOR encryption

    if (strcmp(mode, "encrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' has been encrypted to '%s'.\n", inputFile, outputFile);
    } else if (strcmp(mode, "decrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' has been decrypted to '%s'.\n", inputFile, outputFile);
    } else {
        fprintf(stderr, "Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}