//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(const char *inputFile, const char *outputFile, const char *key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    
    if (inFile == NULL || outFile == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    size_t keyLength = strlen(key);
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inFile)) > 0) {
        for (i = 0; i < bytesRead; ++i) {
            buffer[i] ^= key[i % keyLength]; // XOR encryption
        }
        fwrite(buffer, sizeof(char), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decrypt(const char *inputFile, const char *outputFile, const char *key) {
    // Decrypting is the same as encrypting with XOR
    encrypt(inputFile, outputFile, key);
}

void printUsage(char *programName) {
    printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *action = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    char *key = argv[4];

    if (strcmp(action, "encrypt") == 0) {
        encrypt(inputFile, outputFile, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt(inputFile, outputFile, key);
        printf("File decrypted successfully.\n");
    } else {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}