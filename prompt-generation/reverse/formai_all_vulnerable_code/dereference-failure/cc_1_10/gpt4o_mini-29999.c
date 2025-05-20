//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(const char *inputFile, const char *outputFile, char key);
void decrypt(const char *inputFile, const char *outputFile, char key);
void printUsage(const char *progName);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    char operation = argv[1][0];
    char key = argv[2][0];

    if (operation == 'e') {
        encrypt(argv[3], argv[4], key);
    } else if (operation == 'd') {
        decrypt(argv[3], argv[4], key);
    } else {
        printf("Invalid operation. Use 'e' for encrypt and 'd' for decrypt.\n");
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void encrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR operation for encryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("File %s has been encrypted to %s\n", inputFile, outputFile);
}

void decrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR operation for decryption (same as encryption)
    }

    fclose(inFile);
    fclose(outFile);
    printf("File %s has been decrypted to %s\n", inputFile, outputFile);
}

void printUsage(const char *progName) {
    printf("Usage: %s [e|d] [key] [inputFile] [outputFile]\n", progName);
    printf("e: encrypt\n");
    printf("d: decrypt\n");
    printf("key: single character key for XOR operation\n");
    printf("inputFile: name of the file to encrypt/decrypt\n");
    printf("outputFile: name of the file to write the output\n");
}