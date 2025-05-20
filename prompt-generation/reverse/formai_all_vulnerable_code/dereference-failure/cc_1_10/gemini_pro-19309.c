//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input and output files
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long fileSize = ftell(fin);
    rewind(fin);

    // Create a buffer to hold the file data
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file data into the buffer
    fread(buffer, fileSize, 1, fin);

    // Encrypt the file data
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted data to the output file
    fwrite(buffer, fileSize, 1, fout);

    // Close the files
    fclose(fin);
    fclose(fout);
    free(buffer);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input and output files
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(fin, 0, SEEK_END);
    long fileSize = ftell(fin);
    rewind(fin);

    // Create a buffer to hold the file data
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the file data into the buffer
    fread(buffer, fileSize, 1, fin);

    // Decrypt the file data
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted data to the output file
    fwrite(buffer, fileSize, 1, fout);

    // Close the files
    fclose(fin);
    fclose(fout);
    free(buffer);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input file> <output file> <key> <encrypt/decrypt>\n", argv[0]);
        exit(1);
    }

    // Get the input and output file names, key, and mode
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    char *key = argv[3];
    char *mode = argv[4];

    // Check if the mode is valid
    if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        exit(1);
    }

    // Encrypt or decrypt the file
    if (strcmp(mode, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
    } else {
        decryptFile(inputFile, outputFile, key);
    }

    return 0;
}