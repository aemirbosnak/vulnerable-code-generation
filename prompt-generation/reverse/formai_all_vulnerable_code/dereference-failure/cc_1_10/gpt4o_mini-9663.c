//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *input, *output;
    int c;
    size_t keyLen = strlen(key);
    
    input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ key[index % keyLen], output);
        index++;
    }

    fclose(input);
    fclose(output);
    printf("Processed %s -> %s using key: '%s'\n", inputFile, outputFile, key);
}

void displayUsage() {
    printf("File Encryptor/Decryptor\n");
    printf("Usage: ./file_encryptor <encrypt|decrypt> <inputFile> <outputFile> <key>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    const char *key = argv[4];

    if (strcmp(operation, "encrypt") == 0) {
        encryptDecryptFile(inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        encryptDecryptFile(inputFile, outputFile, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        displayUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}