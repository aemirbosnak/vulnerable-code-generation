//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt data using a simple XOR cipher
void encrypt_decrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLength = strlen(key);
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength]; // XOR with the key character
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }
}

// Function to validate the command line input
int validateInput(int argc) {
    if (argc != 4) {
        printf("Usage: ./file_encryptor <input_file> <output_file> <encryption_key>\n");
        return 0;
    }
    return 1;
}

// Function to check if a file can be opened
int checkFile(FILE *file, const char *filename) {
    if (file == NULL) {
        perror(filename);
        return 0;
    }
    return 1;
}

// Main function to handle the program flow
int main(int argc, char *argv[]) {
    // Validate the number of arguments
    if (!validateInput(argc)) {
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    char *key = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!checkFile(inputFile, inputFileName)) {
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!checkFile(outputFile, outputFileName)) {
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Perform encryption or decryption
    printf("Encrypting file '%s' to '%s' using key '%s'...\n", inputFileName, outputFileName, key);
    encrypt_decrypt(inputFile, outputFile, key);
    
    printf("Encryption complete!\n");

    // Clean up file handles
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}