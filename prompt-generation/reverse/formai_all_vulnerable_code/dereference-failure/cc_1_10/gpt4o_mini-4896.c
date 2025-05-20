//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to encrypt or decrypt data using XOR
void xorEncryptDecrypt(FILE *input, FILE *output, char key) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;  // XOR encryption/decryption
        }
        fwrite(buffer, sizeof(char), bytesRead, output);
    }
}

// Function to display usage instructions
void displayUsage(const char *programName) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", programName);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    char key = argv[4][0];  // First character of the key

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
        printf("Encrypting file '%s' to '%s' using key '%c'\n", inputFileName, outputFileName, key);
        xorEncryptDecrypt(inputFile, outputFile, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Decrypting file '%s' to '%s' using key '%c'\n", inputFileName, outputFileName, key);
        xorEncryptDecrypt(inputFile, outputFile, key);
    } else {
        printf("Invalid mode: %s\n", mode);
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Operation completed successfully.\n");
    return EXIT_SUCCESS;
}