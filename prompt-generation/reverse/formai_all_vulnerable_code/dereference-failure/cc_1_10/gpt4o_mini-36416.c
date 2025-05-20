//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    int i = 0;
    
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    
    char key[256];
    printf("Enter the encryption key (max 255 characters): ");
    fgets(key, sizeof(key), stdin);
    
    // Removing the newline character if present
    key[strcspn(key, "\n")] = 0;

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", inputFileName);
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        fclose(inputFile);
        fprintf(stderr, "Error opening output file: %s\n", outputFileName);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting file %s to %s...\n", inputFileName, outputFileName);
        encryptDecrypt(inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting file %s to %s...\n", inputFileName, outputFileName);
        encryptDecrypt(inputFile, outputFile, key);
    } else {
        fprintf(stderr, "Invalid operation: %s. Use 'encrypt' or 'decrypt'.\n", operation);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Operation completed successfully.\n");

    return EXIT_SUCCESS;
}