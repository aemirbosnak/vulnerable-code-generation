//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLen = strlen(key);
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % keyLen];
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }
}

void printUsage(char *progName) {
    printf("Usage: %s <input_file> <output_file> <key> <mode>\n", progName);
    printf("Mode: 'encrypt' or 'decrypt'\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char *key = argv[3];
    char *mode = argv[4];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_decrypt(inputFile, outputFile, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        encrypt_decrypt(inputFile, outputFile, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode specified.\n");
        printUsage(argv[0]);
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}