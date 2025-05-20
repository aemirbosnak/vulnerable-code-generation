//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration settings for the encryption
#define BUFFER_SIZE 1024
#define ENCRYPTION_KEY 0xAA // Simple XOR key (0xAA)

void encryptDecrypt(char *data, size_t dataSize) {
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] ^= ENCRYPTION_KEY; // XOR encryption and decryption
    }
}

void processFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        fclose(inputFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read from the input file, encrypt, and write to the output file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        encryptDecrypt(buffer, bytesRead);
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

// Function to decrypt the file (just a wrapper to processFile)
void decryptFile(const char *inputFileName, const char *outputFileName) {
    processFile(inputFileName, outputFileName);
    printf("File decrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

// Function to display usage instructions
void displayUsage(const char *programName) {
    printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        processFile(inputFileName, outputFileName);
    } else if (strcmp(mode, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName);
    } else {
        printf("Invalid mode: %s. Choose 'encrypt' or 'decrypt'.\n", mode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}