//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

// Function prototypes
void encrypt(FILE *inputFile, FILE *outputFile, const char *key);
void decrypt(FILE *inputFile, FILE *outputFile, const char *key);
void handleError(const char *message);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    const char *key = argv[4];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        handleError("Failed to open input file for reading.");
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        fclose(inputFile);
        handleError("Failed to open output file for writing.");
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(inputFile, outputFile, key);
        printf("File encrypted successfully: %s\n", outputFileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(inputFile, outputFile, key);
        printf("File decrypted successfully: %s\n", outputFileName);
    } else {
        fclose(inputFile);
        fclose(outputFile);
        handleError("Unknown operation. Use 'encrypt' or 'decrypt'.");
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}

void encrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength]; // XOR encryption
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }
}

void decrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength]; // XOR decryption
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }
}

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void printUsage() {
    printf("Usage: file_encryptor <operation> <input_file> <output_file> <key>\n");
    printf("Operation: 'encrypt' or 'decrypt'\n");
}