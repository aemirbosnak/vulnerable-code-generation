//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to encrypt or decrypt a file using XOR operation
void xorEncryptDecrypt(const char *inputFile, const char *outputFile, char *key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Cannot open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Cannot open output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    size_t keyLength = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLength]; // XOR encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, output);
    }

    fclose(input);
    fclose(output);
}

// Function to display usage of the program
void printUsage() {
    printf("Usage: file_encryptor <input_file> <output_file> <key>\n");
    printf("Encrypts the input file and writes the result to the output file.\n");
    printf("To decrypt, use the same program with the encrypted file and the same key.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    char *key = argv[3];

    xorEncryptDecrypt(inputFile, outputFile, key);

    printf("File \"%s\" has been successfully encrypted/decrypted to \"%s\".\n", inputFile, outputFile);

    return EXIT_SUCCESS;
}