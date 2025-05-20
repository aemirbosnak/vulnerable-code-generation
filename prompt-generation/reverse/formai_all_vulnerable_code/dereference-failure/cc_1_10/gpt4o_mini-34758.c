//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    int character;
    int i = 0;

    while ((character = fgetc(inputFile)) != EOF) {
        // XOR each character with the key character
        fputc(character ^ key[i % keyLength], outputFile);
        i++;
    }
}

void usage(const char *programName) {
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input file> <output file> <key>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFilePath = argv[2];
    const char *outputFilePath = argv[3];
    const char *key = argv[4];

    // Check key length
    if (strlen(key) == 0 || strlen(key) > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: Key must be between 1 and %d characters long.\n", MAX_KEY_LENGTH);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File encrypted successfully: %s\n", outputFilePath);
    } else if (strcmp(operation, "decrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File decrypted successfully: %s\n", outputFilePath);
    } else {
        usage(argv[0]);
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}