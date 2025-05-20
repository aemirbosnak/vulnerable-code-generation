//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayUsage() {
    printf("Usage: file_encryptor <input_file> <output_file> <key>\n");
    printf("Encrypts the input file and saves it to output file using the given key.\n");
}

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    int keyIndex = 0;
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        char encryptedChar = ch ^ key[keyIndex];
        fputc(encryptedChar, outputFile);
        keyIndex = (keyIndex + 1) % keyLength; // Cycle through the key
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage();
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    const char *key = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    encryptDecrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption/Decryption completed successfully!\n");
    return 0;
}