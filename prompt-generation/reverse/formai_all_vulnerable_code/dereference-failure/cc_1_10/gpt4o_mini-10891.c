//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x5A  // Simple XOR key for illustration purposes
#define BUFFER_SIZE 1024

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);
void processFile(const char *inputFile, const char *outputFile, int mode);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage();
        return 1;
    }

    const char *mode = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(mode, "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printUsage();
        return 1;
    }

    printf("Operation completed successfully!\n");
    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile) {
    processFile(inputFile, outputFile, 1);  // Mode 1 for encrypt
}

void decryptFile(const char *inputFile, const char *outputFile) {
    processFile(inputFile, outputFile, 0);  // Mode 0 for decrypt
}

void processFile(const char *inputFile, const char *outputFile, int mode) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY; // Simple XOR encryption/decryption
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void printUsage() {
    printf("Usage: ./file_encryptor <encrypt|decrypt> <input_file> <output_file>\n");
    printf("    encrypt   : To encrypt the file\n");
    printf("    decrypt   : To decrypt the file\n");
}