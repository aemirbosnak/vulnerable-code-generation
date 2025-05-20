//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char* inputFileName, char* outputFileName, char* key) {
    FILE* inputFile = fopen(inputFileName, "rb");
    FILE* outputFile = fopen(outputFileName, "wb");

    // Check if files opened successfully
    if (inputFile == NULL) {
        printf("Error: Could not open input file '%s'.\n", inputFileName);
        exit(1);
    }

    if (outputFile == NULL) {
        printf("Error: Could not open output file '%s'.\n", outputFileName);
        exit(1);
    }

    // Read input file and encrypt data
    char buffer[100];
    int keyLength = strlen(key);
    int keyIndex = 0;
    int bytesRead = 0;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            // XOR with key
            buffer[i] ^= key[keyIndex];
            keyIndex = (keyIndex + 1) % keyLength;
        }

        // Write encrypted data to output file
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption successful.\n");
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: encrypt <input file> <output file> <encryption key>\n");
        exit(1);
    }

    char* inputFileName = argv[1];
    char* outputFileName = argv[2];
    char* key = argv[3];

    encryptFile(inputFileName, outputFileName, key);

    return 0;
}