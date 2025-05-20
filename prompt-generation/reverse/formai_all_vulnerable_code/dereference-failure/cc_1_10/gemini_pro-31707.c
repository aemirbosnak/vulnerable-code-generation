//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long fileSize = ftell(fin);
    rewind(fin);

    // Create a buffer to hold the file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, 1, fileSize, fin);

    // Encrypt the buffer
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % KEY_SIZE];
    }

    // Write the encrypted contents to the output file
    fwrite(buffer, 1, fileSize, fout);

    // Close the files
    fclose(fin);
    fclose(fout);

    // Free the buffer
    free(buffer);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long fileSize = ftell(fin);
    rewind(fin);

    // Create a buffer to hold the file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, 1, fileSize, fin);

    // Decrypt the buffer
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % KEY_SIZE];
    }

    // Write the decrypted contents to the output file
    fwrite(buffer, 1, fileSize, fout);

    // Close the files
    fclose(fin);
    fclose(fout);

    // Free the buffer
    free(buffer);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 5) {
        printf("Usage: %s <encrypt|decrypt> <input file> <output file> <key>\n", argv[0]);
        exit(1);
    }

    // Get the operation
    char *operation = argv[1];

    // Get the input file
    char *inputFile = argv[2];

    // Get the output file
    char *outputFile = argv[3];

    // Get the key
    char *key = argv[4];

    // Check the key length
    if (strlen(key) != KEY_SIZE) {
        printf("Error: Key must be %d characters long\n", KEY_SIZE);
        exit(1);
    }

    // Encrypt or decrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, key);
    } else {
        printf("Error: Invalid operation\n");
        exit(1);
    }

    return 0;
}