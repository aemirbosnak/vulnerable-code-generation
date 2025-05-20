//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt the file
void encryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *input_fp, *output_fp;
    unsigned char buffer[BUFFER_SIZE];
    unsigned char encryptedBuffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open the input file
    input_fp = fopen(inputFile, "rb");

    // Open the output file
    output_fp = fopen(outputFile, "wb");

    // If files couldn't be opened
    if (input_fp == NULL || output_fp == NULL) {
        printf("Could not open files.\n");
        exit(EXIT_FAILURE);
    }

    // Set the encryption key
    size_t keyLength = strlen(key);

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input_fp)) != 0) {
        // Encrypt the buffer with the given key
        for (size_t i = 0; i < bytesRead; i++) {
            encryptedBuffer[i] = buffer[i] ^ key[i % keyLength];
        }

        // Write the encrypted buffer to the output file
        fwrite(encryptedBuffer, 1, bytesRead, output_fp);

        // Clear the buffer
        memset(buffer, 0, BUFFER_SIZE);
        memset(encryptedBuffer, 0, BUFFER_SIZE);
    }

    // Close the files
    fclose(input_fp);
    fclose(output_fp);

    printf("File encryption completed successfully.\n");
}

// Main function
int main(int argc, char *argv[]) {
    char *inputFile, *outputFile, *key;

    if (argc < 4) {
        printf("Not enough arguments.\n");
        printf("Syntax: ./encrypt input_file output_file key\n");
        return 0;
    }

    // Get the arguments
    inputFile = argv[1];
    outputFile = argv[2];
    key = argv[3];

    // Encrypt the file
    encryptFile(inputFile, outputFile, key);

    return 0;
}