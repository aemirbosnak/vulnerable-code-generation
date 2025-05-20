//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey"
#define KEY_LENGTH 13

// Function to encrypt the file
void encryptFile(FILE* inputFile, FILE* outputFile) {
    char buffer[1024];
    int bufferSize = 0;
    while (fgets(buffer, sizeof(buffer), inputFile)!= NULL) {
        int bufferLength = strlen(buffer);
        for (int i = 0; i < bufferLength; i++) {
            buffer[i] = buffer[i] ^ KEY[i % KEY_LENGTH];
        }
        fwrite(buffer, sizeof(char), bufferLength, outputFile);
    }
}

// Function to decrypt the file
void decryptFile(FILE* inputFile, FILE* outputFile) {
    char buffer[1024];
    int bufferSize = 0;
    while (fgets(buffer, sizeof(buffer), inputFile)!= NULL) {
        int bufferLength = strlen(buffer);
        for (int i = 0; i < bufferLength; i++) {
            buffer[i] = buffer[i] ^ KEY[i % KEY_LENGTH];
        }
        fwrite(buffer, sizeof(char), bufferLength, outputFile);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt/decrypt] [input file] [output file]\n", argv[0]);
        return 1;
    }

    char* operation = argv[1];
    FILE* inputFile = fopen(argv[2], "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[3], "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Error: Invalid operation.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}