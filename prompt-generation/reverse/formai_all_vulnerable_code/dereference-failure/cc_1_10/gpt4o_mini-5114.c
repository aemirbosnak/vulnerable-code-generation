//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLen = strlen(key);
    char ch;
    int i = 0;

    while ((ch = fgetc(inputFile)) != EOF) {
        // XOR the character with the key
        fputc(ch ^ key[i % keyLen], outputFile);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    char key[256];

    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline character

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting %s to %s...\n", inputFileName, outputFileName);
        encryptDecrypt(inputFile, outputFile, key);
        printf("Encryption complete.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting %s to %s...\n", inputFileName, outputFileName);
        encryptDecrypt(inputFile, outputFile, key);
        printf("Decryption complete.\n");
    } else {
        printf("Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}