//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "YOUR_ENCRYPTION_KEY"

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile) {
    // Open the input and output files
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(1);
    }

    // Read the input file into a buffer
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *buffer = malloc(fileSize);
    fread(buffer, fileSize, 1, input);
    fclose(input);

    // Encrypt the buffer using the encryption key
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, fileSize, 1, output);
    fclose(output);
    free(buffer);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile) {
    // Open the input and output files
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(1);
    }

    // Read the input file into a buffer
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *buffer = malloc(fileSize);
    fread(buffer, fileSize, 1, input);
    fclose(input);

    // Decrypt the buffer using the encryption key
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, fileSize, 1, output);
    fclose(output);
    free(buffer);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        printf("Usage: %s encrypt/decrypt inputFile outputFile\n", argv[0]);
        return 1;
    }

    // Get the encryption/decryption mode
    char *mode = argv[1];

    // Get the input and output file names
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(mode, "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(mode, "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Invalid mode: %s\n", mode);
        return 1;
    }

    return 0;
}