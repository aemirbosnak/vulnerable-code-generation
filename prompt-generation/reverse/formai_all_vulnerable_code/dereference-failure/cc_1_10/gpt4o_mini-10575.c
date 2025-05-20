//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function prototypes
void printUsage(const char *programName);
void encryptFile(const char *inputFileName, const char *outputFileName, int key);
void decryptFile(const char *inputFileName, const char *outputFileName, int key);
void xorCipher(char *data, size_t dataSize, int key);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    int key = atoi(argv[4]);

    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFileName, outputFileName, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName, key);
    } else {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void printUsage(const char *programName) {
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", programName);
}

void encryptFile(const char *inputFileName, const char *outputFileName, int key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        xorCipher(buffer, bytesRead, key);
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

void decryptFile(const char *inputFileName, const char *outputFileName, int key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        xorCipher(buffer, bytesRead, key);
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File decrypted successfully: %s -> %s\n", inputFileName, outputFileName);
}

void xorCipher(char *data, size_t dataSize, int key) {
    for (size_t i = 0; i < dataSize; i++) {
        data[i] ^= key;
    }
}