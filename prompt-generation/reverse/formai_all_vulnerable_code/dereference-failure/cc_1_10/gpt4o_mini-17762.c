//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to print usage
void printUsage(const char *programName) {
    printf("Usage: %s <input_file> <output_file> <key>\n", programName);
    printf("Encrypts the input file and writes to the output file using XOR encryption.\n");
}

// XOR encryption function
void xorEncryptDecrypt(char *buffer, size_t length, char key) {
    for (size_t i = 0; i < length; i++) {
        buffer[i] ^= key;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 4) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    char key = argv[3][0]; // Use the first character of the third argument as the encryption key

    // Open the input file for reading
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read from input file and encrypt
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        // Encrypt or decrypt buffer
        xorEncryptDecrypt(buffer, bytesRead, key);
        // Write encrypted data to output file
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully! Output written to %s\n", outputFileName);
    return EXIT_SUCCESS;
}