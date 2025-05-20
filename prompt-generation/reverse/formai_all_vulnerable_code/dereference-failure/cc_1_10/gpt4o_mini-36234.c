//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the file using XOR cipher
void xorCipher(const char *inputFilePath, const char *outputFilePath, char key) {
    FILE *inputFile = fopen(inputFilePath, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    int byte;
    while ((byte = fgetc(inputFile)) != EOF) {
        fputc(byte ^ key, outputFile); // XOR operation
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Function to display usage information
void displayUsage(const char *programName) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", programName);
    printf("Example: %s encrypt myfile.txt myfile.enc A\n", programName);
    printf("Example: %s decrypt myfile.enc myfile.txt A\n", programName);
}

// Main function for the program
int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *inputFilePath = argv[2];
    char *outputFilePath = argv[3];
    char key = argv[4][0]; // Only use the first character as the key

    if (strcmp(operation, "encrypt") == 0) {
        xorCipher(inputFilePath, outputFilePath, key);
        printf("Successfully encrypted '%s' to '%s' using key '%c'.\n", inputFilePath, outputFilePath, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        xorCipher(inputFilePath, outputFilePath, key);
        printf("Successfully decrypted '%s' to '%s' using key '%c'.\n", inputFilePath, outputFilePath, key);
    } else {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}