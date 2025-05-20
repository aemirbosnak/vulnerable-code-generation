//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define KEY 0xAA // Simple XOR encryption key
#define BUFFER_SIZE 1024

// Function to encrypt or decrypt a file using XOR
void xorEncryptDecrypt(const char *inputFile, const char *outputFile) {
    FILE *inFile, *outFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open input file in read mode
    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open output file in write mode
    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        fclose(inFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read the file content
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY; // XOR each byte with the key
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    // Cleanup
    fclose(inFile);
    fclose(outFile);
}

// Function to display usage
void displayUsage() {
    printf("File Encryptor\n");
    printf("=================\n");
    printf("Usage: ./file_encryptor <encrypt|decrypt> <input file> <output file>\n");
    printf("  encrypt    : Encrypts the input file\n");
    printf("  decrypt    : Decrypts the input file (same operation as encrypt)\n");
    printf("Examples:\n");
    printf("  ./file_encryptor encrypt secret.txt secret.enc\n");
    printf("  ./file_encryptor decrypt secret.enc decrypted.txt\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];

    if (strcmp(mode, "encrypt") == 0 || strcmp(mode, "decrypt") == 0) {
        xorEncryptDecrypt(inputFile, outputFile);
        printf("File %s successfully!\n", strcmp(mode, "encrypt") == 0 ? "encrypted" : "decrypted");
    } else {
        displayUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}