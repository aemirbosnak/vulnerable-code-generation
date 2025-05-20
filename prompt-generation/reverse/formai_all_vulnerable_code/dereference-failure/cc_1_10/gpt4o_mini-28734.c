//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt/decrypt the file
void xorCipher(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLen = strlen(key);
    int i = 0;
    int ch;

    // Process each character in the file
    while ((ch = fgetc(inputFile)) != EOF) {
        // XOR current character with key character
        fputc(ch ^ key[i % keyLen], outputFile);
        i++;
    }
}

// Function to display usage instructions
void displayUsage() {
    printf("Usage: file_encryptor <mode> <input_file> <output_file> <key>\n");
    printf("Modes:\n");
    printf("  -e : Encrypt the input file\n");
    printf("  -d : Decrypt the input file\n");
    printf("Example:\n");
    printf("  file_encryptor -e input.txt encrypted.txt mysecretkey\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage();
        return 1;
    }

    FILE *inputFile = fopen(argv[2], "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[3], "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    const char *mode = argv[1];
    const char *key = argv[4];

    if (strcmp(mode, "-e") == 0) {
        printf("Encrypting file...\n");
        xorCipher(inputFile, outputFile, key);
    } else if (strcmp(mode, "-d") == 0) {
        printf("Decrypting file...\n");
        xorCipher(inputFile, outputFile, key);
    } else {
        printf("Invalid mode. Use -e for encrypt or -d for decrypt.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    printf("Operation completed successfully.\n");

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}