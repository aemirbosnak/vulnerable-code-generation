//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "secret"

// Function to encrypt a file
void encryptFile(char *inputFilename, char *outputFilename) {
    // Open the input file
    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", inputFilename);
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", outputFilename);
        exit(1);
    }

    // Get the file size
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, 1, fileSize, inputFile);

    // Encrypt the buffer
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, fileSize, outputFile);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *inputFilename, char *outputFilename) {
    // Open the input file
    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", inputFilename);
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", outputFilename);
        exit(1);
    }

    // Get the file size
    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating buffer\n");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, 1, fileSize, inputFile);

    // Decrypt the buffer
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, fileSize, outputFile);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified the input and output filenames
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [encrypt|decrypt] [input file] [output file]\n", argv[0]);
        exit(1);
    }

    // Check if the user specified the encryption or decryption mode
    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}