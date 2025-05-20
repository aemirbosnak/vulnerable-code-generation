//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 128

void printUsage() {
    printf("Usage: fileencryptor <encrypt|decrypt> <filename> <key>\n");
}

void xorEncryptDecrypt(FILE* inputFile, FILE* outputFile, const char* key) {
    int keyLength = strlen(key);
    int i = 0;
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        // Perform XOR operation with the key
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    char* operation = argv[1];
    char* filename = argv[2];
    char* key = argv[3];

    if (strlen(key) > MAX_KEY_LENGTH) {
        fprintf(stderr, "Error: Key length exceeds maximum allowed length of %d characters.\n", MAX_KEY_LENGTH);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Determine output filename
    char outputFilename[256];
    snprintf(outputFilename, sizeof(outputFilename), "%s.%s", filename, 
             strcmp(operation, "encrypt") == 0 ? "enc" : "dec");
    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Perform encryption or decryption
    if (strcmp(operation, "encrypt") == 0) {
        xorEncryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' encrypted successfully to '%s'.\n", filename, outputFilename);
    } else if (strcmp(operation, "decrypt") == 0) {
        xorEncryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' decrypted successfully to '%s'.\n", filename, outputFilename);
    } else {
        fprintf(stderr, "Error: Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    // Clean up
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}