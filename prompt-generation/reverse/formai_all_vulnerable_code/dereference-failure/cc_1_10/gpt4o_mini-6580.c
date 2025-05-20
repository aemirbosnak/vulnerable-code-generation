//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLen = strlen(key);
    int i = 0;
    int c;

    while ((c = fgetc(inputFile)) != EOF) {
        // XOR the character with the key character
        fputc(c ^ key[i % keyLen], outputFile);
        i++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    char key[256];
    printf("Enter the encryption key: ");
    if (fgets(key, sizeof(key), stdin) == NULL) {
        fprintf(stderr, "Failed to read key\n");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    // Remove newline character from key if present
    key[strcspn(key, "\n")] = 0;

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting the file...\n");
        encryptDecrypt(inputFile, outputFile, key);
        printf("File encrypted successfully!\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting the file...\n");
        encryptDecrypt(inputFile, outputFile, key);
        printf("File decrypted successfully!\n");
    } else {
        fprintf(stderr, "Unknown operation: %s. Use 'encrypt' or 'decrypt'.\n", operation);
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}