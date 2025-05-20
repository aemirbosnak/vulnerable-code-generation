//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt data using XOR
void encrypt_decrypt(char *inputBuffer, char *outputBuffer, char key, size_t size) {
    for(size_t i = 0; i < size; i++) {
        outputBuffer[i] = inputBuffer[i] ^ key; // XOR encryption/decryption
    }
}

// Function to read data from the source file
size_t read_data(const char *sourceFile, char *buffer) {
    FILE *file = fopen(sourceFile, "rb");
    if (!file) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    fclose(file);
    return bytesRead;
}

// Function to write encrypted data to the output file
void write_data(const char *destinationFile, char *buffer, size_t size) {
    FILE *file = fopen(destinationFile, "wb");
    if (!file) {
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, sizeof(char), size, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <source file> <destination file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *sourceFile = argv[1];
    const char *destinationFile = argv[2];
    char key = argv[3][0];  // We only use the first character as the key

    char inputBuffer[BUFFER_SIZE];
    char outputBuffer[BUFFER_SIZE];

    // Read the data from the source file
    size_t bytesRead = read_data(sourceFile, inputBuffer);

    // Encrypt the data
    encrypt_decrypt(inputBuffer, outputBuffer, key, bytesRead);

    // Write the encrypted data to the destination file
    write_data(destinationFile, outputBuffer, bytesRead);

    printf("File encrypted successfully: %s -> %s\n", sourceFile, destinationFile);
    return EXIT_SUCCESS;
}