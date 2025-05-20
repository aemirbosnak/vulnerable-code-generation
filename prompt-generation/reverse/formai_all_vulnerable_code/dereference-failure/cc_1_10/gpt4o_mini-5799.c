//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the content
void xorCipher(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    int i = 0;
    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        // XOR the character with the key character (wrap around the key)
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }
}

// Function to perform encryption
void encryptFile(const char *inputFilename, const char *outputFilename, const char *key) {
    FILE *inputFile = fopen(inputFilename, "rb");
    if (!inputFile) {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilename, "wb");
    if (!outputFile) {
        perror("Unable to open output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    xorCipher(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully to %s\n", outputFilename);
}

// Function to perform decryption
void decryptFile(const char *inputFilename, const char *outputFilename, const char *key) {
    encryptFile(inputFilename, outputFilename, key); // Decrypting is the same as encrypting
    printf("File decrypted successfully to %s\n", outputFilename);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input file> <output file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *inputFilename = argv[2];
    const char *outputFilename = argv[3];
    const char *key = argv[4];

    // Perform encryption or decryption based on user input
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFilename, outputFilename, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFilename, outputFilename, key);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}