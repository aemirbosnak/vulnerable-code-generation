//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Encrypting characters
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    encryptFile(inputFileName, outputFileName, 26 - shift); // Decrypts using inverse shift
}

void displayFileContents(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file for display");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file> <shift>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    int shift = atoi(argv[4]);

    if (shift < 0) {
        fprintf(stderr, "Shift must be a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        printf("Encrypting file: %s with shift: %d\n", inputFileName, shift);
        encryptFile(inputFileName, outputFileName, shift);
        printf("Encrypted content written to: %s\n", outputFileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        printf("Decrypting file: %s with shift: %d\n", inputFileName, shift);
        decryptFile(inputFileName, outputFileName, shift);
        printf("Decrypted content written to: %s\n", outputFileName);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    // Displaying the resulting file content
    printf("\nContents of the resulting file (%s):\n", outputFileName);
    displayFileContents(outputFileName);

    return EXIT_SUCCESS;
}