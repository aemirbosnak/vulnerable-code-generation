//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(const char *inputFile, const char *outputFile, char key);
void decrypt(const char *inputFile, const char *outputFile, char key);
void handleError(const char *message);
void processFile(const char *inputFile, const char *outputFile, char key, int mode);

// Constants for mode selection
#define ENCRYPT_MODE 1
#define DECRYPT_MODE 0

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <inputFile> <outputFile> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int mode;
    if (strcmp(argv[1], "encrypt") == 0) {
        mode = ENCRYPT_MODE;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        mode = DECRYPT_MODE;
    } else {
        fprintf(stderr, "Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    char key = argv[4][0]; // Take the first character as the key

    processFile(inputFile, outputFile, key, mode);

    return EXIT_SUCCESS;
}

void processFile(const char *inputFile, const char *outputFile, char key, int mode) {
    if (mode == ENCRYPT_MODE) {
        encrypt(inputFile, outputFile, key);
    } else {
        decrypt(inputFile, outputFile, key);
    }
}

void encrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) handleError("Error opening input file for encryption.");

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fclose(inFile);
        handleError("Error opening output file for encryption.");
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // Simple XOR encryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("Encryption complete. Output written to '%s'.\n", outputFile);
}

void decrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) handleError("Error opening input file for decryption.");

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fclose(inFile);
        handleError("Error opening output file for decryption.");
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // Simple XOR decryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("Decryption complete. Output written to '%s'.\n", outputFile);
}

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}