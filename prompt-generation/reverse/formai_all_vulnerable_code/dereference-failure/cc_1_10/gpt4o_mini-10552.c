//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void encrypt(char *source, char *destination, int key) {
    FILE *srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    FILE *destFile = fopen(destination, "wb");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // Simple XOR encryption
        }
        fwrite(buffer, 1, bytesRead, destFile);
    }

    fclose(srcFile);
    fclose(destFile);
}

void decrypt(char *source, char *destination, int key) {
    // Decryption is the same process as encryption due to XOR nature.
    encrypt(source, destination, key);
}

void printUsage(const char *programName) {
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", programName);
    fprintf(stderr, "<encrypt|decrypt> - Specify operation\n");
    fprintf(stderr, "<input_file>     - File to encrypt or decrypt\n");
    fprintf(stderr, "<output_file>    - Result file\n");
    fprintf(stderr, "<key>           - Encryption/Decryption key (integer)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    int key = atoi(argv[4]);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(inputFile, outputFile, key);
        printf("File '%s' encrypted to '%s' using key %d.\n", inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(inputFile, outputFile, key);
        printf("File '%s' decrypted to '%s' using key %d.\n", inputFile, outputFile, key);
    } else {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}