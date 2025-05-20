//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT_KEY 0x12345678

void encryptFile(FILE *inputFile, FILE *outputFile) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch ^= ENCRYPT_KEY;
        fputc(ch, outputFile);
    }
}

void decryptFile(FILE *inputFile, FILE *outputFile) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch ^= ENCRYPT_KEY;
        fputc(ch, outputFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <input file> <output file>\n", argv[0]);
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
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return 1;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Operation successful.\n");
    return 0;
}