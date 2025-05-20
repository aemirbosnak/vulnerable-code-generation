//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *filename, char *key) {
    // Open the file in read mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Create a buffer to store the encrypted data
    char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the data from the file into the buffer
    fread(buffer, 1, size, file);
    fclose(file);

    // Encrypt the data in the buffer
    for (int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Open the file in write mode
    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the encrypted data to the file
    fwrite(buffer, 1, size, file);
    fclose(file);

    // Free the buffer
    free(buffer);
}

// Function to decrypt a file
void decryptFile(char *filename, char *key) {
    // Open the file in read mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Create a buffer to store the decrypted data
    char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the data from the file into the buffer
    fread(buffer, 1, size, file);
    fclose(file);

    // Decrypt the data in the buffer
    for (int i = 0; i < size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Open the file in write mode
    file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the decrypted data to the file
    fwrite(buffer, 1, size, file);
    fclose(file);

    // Free the buffer
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encrypt/decrypt> <filename> <key>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *filename = argv[2];
    char *key = argv[3];

    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(filename, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(filename, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}