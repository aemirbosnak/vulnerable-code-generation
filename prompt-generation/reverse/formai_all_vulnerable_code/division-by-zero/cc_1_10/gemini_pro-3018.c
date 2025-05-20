//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
int encryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *inputFilePtr = fopen(inputFile, "rb");
    if (inputFilePtr == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *outputFilePtr = fopen(outputFile, "wb");
    if (outputFilePtr == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Get the file size
    fseek(inputFilePtr, 0L, SEEK_END);
    long fileSize = ftell(inputFilePtr);
    rewind(inputFilePtr);

    // Allocate a buffer to hold the file contents
    char *buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, fileSize, 1, inputFilePtr);

    // Encrypt the buffer
    int keyLen = strlen(key);
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % keyLen];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, fileSize, 1, outputFilePtr);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(inputFilePtr);
    fclose(outputFilePtr);

    return 0;
}

// Function to decrypt a file
int decryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *inputFilePtr = fopen(inputFile, "rb");
    if (inputFilePtr == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *outputFilePtr = fopen(outputFile, "wb");
    if (outputFilePtr == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Get the file size
    fseek(inputFilePtr, 0L, SEEK_END);
    long fileSize = ftell(inputFilePtr);
    rewind(inputFilePtr);

    // Allocate a buffer to hold the file contents
    char *buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, fileSize, 1, inputFilePtr);

    // Decrypt the buffer
    int keyLen = strlen(key);
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= key[i % keyLen];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, fileSize, 1, outputFilePtr);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(inputFilePtr);
    fclose(outputFilePtr);

    return 0;
}

int main() {
    // Get the input file name
    char inputFile[256];
    printf("Enter the input file name: ");
    gets(inputFile);

    // Get the output file name
    char outputFile[256];
    printf("Enter the output file name: ");
    gets(outputFile);

    // Get the encryption key
    char key[256];
    printf("Enter the encryption key: ");
    gets(key);

    // Encrypt the file
    int result = encryptFile(inputFile, outputFile, key);
    if (result != 0) {
        printf("Error encrypting file\n");
        return -1;
    }

    // Decrypt the file
    result = decryptFile(outputFile, inputFile, key);
    if (result != 0) {
        printf("Error decrypting file\n");
        return -1;
    }

    printf("File encrypted and decrypted successfully\n");
    return 0;
}