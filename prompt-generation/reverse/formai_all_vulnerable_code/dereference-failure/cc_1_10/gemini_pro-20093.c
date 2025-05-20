//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function encrypts a file using a XOR cipher
// The key is a 16-byte string
void encrypt_file(char *filename, char *key) {
    // Open the file in read/write mode
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, file);

    // Encrypt the file contents
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % 16];
    }

    // Write the encrypted file contents back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, file_size, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(buffer);
}

// This function decrypts a file using a XOR cipher
// The key is a 16-byte string
void decrypt_file(char *filename, char *key) {
    // Open the file in read/write mode
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, file);

    // Decrypt the file contents
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % 16];
    }

    // Write the decrypted file contents back to the file
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, file_size, file);

    // Close the file
    fclose(file);

    // Free the buffer
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s encrypt/decrypt filename key\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *filename = argv[2];
    char *key = argv[3];

    if (strlen(key) != 16) {
        printf("Error: Key must be 16 bytes long\n");
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(filename, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(filename, key);
    } else {
        printf("Error: Invalid operation\n");
        return 1;
    }

    return 0;
}