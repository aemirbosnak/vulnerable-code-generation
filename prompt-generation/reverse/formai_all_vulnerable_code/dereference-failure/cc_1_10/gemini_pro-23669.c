//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A Table of Symbols
char symbolTable[256] = {
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '|', '\\', '/', ':', ';', '"', '\'', ',', '<', '>', '.', '?', ' ',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
};

// Encrypt a File
void encryptFile(char *inputFileName, char *outputFileName, char *key) {
    // Open the Input File
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the Output File
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the Length of the Key
    int keyLength = strlen(key);

    // Read the Input File Byte by Byte
    unsigned char inputBuffer[1];
    while (fread(inputBuffer, 1, 1, inputFile) == 1) {
        // Encrypt the Byte
        unsigned char encryptedByte = inputBuffer[0] ^ key[rand() % keyLength];

        // Write the Encrypted Byte to the Output File
        fwrite(&encryptedByte, 1, 1, outputFile);
    }

    // Close the Input and Output Files
    fclose(inputFile);
    fclose(outputFile);
}

// Decrypt a File
void decryptFile(char *inputFileName, char *outputFileName, char *key) {
    // Open the Input File
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the Output File
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the Length of the Key
    int keyLength = strlen(key);

    // Read the Input File Byte by Byte
    unsigned char inputBuffer[1];
    while (fread(inputBuffer, 1, 1, inputFile) == 1) {
        // Decrypt the Byte
        unsigned char decryptedByte = inputBuffer[0] ^ key[rand() % keyLength];

        // Write the Decrypted Byte to the Output File
        fwrite(&decryptedByte, 1, 1, outputFile);
    }

    // Close the Input and Output Files
    fclose(inputFile);
    fclose(outputFile);
}

// Main Function
int main(int argc, char *argv[]) {
    // Check the Number of Arguments
    if (argc < 5) {
        printf("Usage: %s <encrypt/decrypt> <input file> <output file> <key>\n", argv[0]);
        exit(1);
    }

    // Get the Operation
    char *operation = argv[1];

    // Get the Input File Name
    char *inputFileName = argv[2];

    // Get the Output File Name
    char *outputFileName = argv[3];

    // Get the Key
    char *key = argv[4];

    // Encrypt or Decrypt the File
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFileName, outputFileName, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        exit(1);
    }

    return 0;
}