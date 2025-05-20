//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

// Function to encrypt or decrypt a file
int encryptDecryptFile(char *fileName, char *key, int mode) {
    FILE *file = fopen(fileName, mode == ENCRYPT ? "rb" : "wb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, 1, bytesRead, file);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

// Function to get the encryption/decryption key from the user
char *getKey() {
    char *key = malloc(1024);
    if (key == NULL) {
        perror("Error allocating memory for key");
        return NULL;
    }

    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    return key;
}

// Function to print the usage information
void printUsage() {
    printf("Usage: %s <file name> <key> <mode>\n", __FILE__);
    printf("Mode: 0 for decryption, 1 for encryption\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    char *fileName = argv[1];
    char *key = argv[2];
    int mode = atoi(argv[3]);

    if (mode != ENCRYPT && mode != DECRYPT) {
        printf("Invalid mode\n");
        printUsage();
        return EXIT_FAILURE;
    }

    if (encryptDecryptFile(fileName, key, mode) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    printf("File %s successfully %s.\n", fileName, mode == ENCRYPT ? "encrypted" : "decrypted");
    return EXIT_SUCCESS;
}