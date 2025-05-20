//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // Simple XOR key for encryption and decryption
#define BUFFER_SIZE 256

void encryptDecryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    // Read the file in chunks
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, inputFile)) > 0) {
        // Encrypt/Decrypt each byte
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY;
        }
        // Write the processed buffer to the output file
        fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void printUsage() {
    printf("Usage: filecrypt <encrypt|decrypt> <input_file> <output_file>\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *operation = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];

    if (strcmp(operation, "encrypt") == 0) {
        encryptDecryptFile(inputFileName, outputFileName);
        printf("File encrypted successfully: %s -> %s\n", inputFileName, outputFileName);
    } else if (strcmp(operation, "decrypt") == 0) {
        encryptDecryptFile(inputFileName, outputFileName);
        printf("File decrypted successfully: %s -> %s\n", inputFileName, outputFileName);
    } else {
        printUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}