//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY "mysecretkey"

// Function to encrypt or decrypt the data using XOR operation
void xorCipher(const char *inputBuffer, char *outputBuffer, size_t length, const char *key) {
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < length; ++i) {
        outputBuffer[i] = inputBuffer[i] ^ key[i % keyLength];
    }
}

// Function to process the file and perform encryption or decryption
void processFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Could not open output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    char inputBuffer[BUFFER_SIZE];
    char outputBuffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read, process (encrypt/decrypt), and write to output file
    while ((bytesRead = fread(inputBuffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        xorCipher(inputBuffer, outputBuffer, bytesRead, KEY);
        fwrite(outputBuffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Main function to handle command-line arguments and invoke processing function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];

    // Determine if we need to encrypt or decrypt
    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting file: %s to %s\n", inputFileName, outputFileName);
        processFile(inputFileName, outputFileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting file: %s to %s\n", inputFileName, outputFileName);
        processFile(inputFileName, outputFileName);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        exit(EXIT_FAILURE);
    }

    printf("Operation completed successfully.\n");
    return 0;
}