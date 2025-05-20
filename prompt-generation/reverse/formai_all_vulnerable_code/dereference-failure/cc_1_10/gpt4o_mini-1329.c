//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char key) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR cipher
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }
}

void displayUsage() {
    printf("Usage: ./file_encryptor <input_file> <output_file> <key>\n");
    printf("Example: ./file_encryptor plaintext.txt encrypted.txt 'K'\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage();
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    char key = argv[3][0];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    encryptDecrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption complete!\n");
    printf("Encrypted data has been written to '%s'\n", outputFileName);
    
    return 0;
}