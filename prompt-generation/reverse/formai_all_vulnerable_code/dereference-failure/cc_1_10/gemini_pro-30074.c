//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 42

// Function to encrypt a file
void encryptFile(char *fileName) {
    // Open the file to be encrypted
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the encrypted data
    unsigned char *encryptedData = malloc(fileSize);
    if (encryptedData == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the data from the file into the buffer
    fread(encryptedData, 1, fileSize, file);
    fclose(file);

    // Encrypt the data
    for (int i = 0; i < fileSize; i++) {
        encryptedData[i] ^= KEY;
    }

    // Open the encrypted file for writing
    file = fopen("encrypted.txt", "wb");
    if (file == NULL) {
        perror("Error opening encrypted file");
        exit(1);
    }

    // Write the encrypted data to the file
    fwrite(encryptedData, 1, fileSize, file);
    fclose(file);

    // Free the allocated memory
    free(encryptedData);
}

// Function to decrypt a file
void decryptFile(char *fileName) {
    // Open the file to be decrypted
    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the decrypted data
    unsigned char *decryptedData = malloc(fileSize);
    if (decryptedData == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the data from the file into the buffer
    fread(decryptedData, 1, fileSize, file);
    fclose(file);

    // Decrypt the data
    for (int i = 0; i < fileSize; i++) {
        decryptedData[i] ^= KEY;
    }

    // Open the decrypted file for writing
    file = fopen("decrypted.txt", "wb");
    if (file == NULL) {
        perror("Error opening decrypted file");
        exit(1);
    }

    // Write the decrypted data to the file
    fwrite(decryptedData, 1, fileSize, file);
    fclose(file);

    // Free the allocated memory
    free(decryptedData);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt/decrypt> <file name>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(argv[2]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        exit(1);
    }

    return 0;
}