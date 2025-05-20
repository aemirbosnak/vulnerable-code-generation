//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *fin, *fout;
    char ch;

    // Open input file in read mode
    fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open output file in write mode
    fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        fclose(fin);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Encrypt or decrypt the file by XORing each character with the key
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout);
    }

    // Close both files
    fclose(fin);
    fclose(fout);
}

void displayUsage() {
    printf("Usage:\n");
    printf("  To encrypt: ./file_encryptor encrypt <input_file> <output_file> <key>\n");
    printf("  To decrypt: ./file_encryptor decrypt <input_file> <output_file> <key>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    char key = argv[4][0]; // Use first character of the provided key

    if (strcmp(operation, "encrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' encrypted to '%s' using key '%c'.\n", inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File '%s' decrypted to '%s' using key '%c'.\n", inputFile, outputFile, key);
    } else {
        displayUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}