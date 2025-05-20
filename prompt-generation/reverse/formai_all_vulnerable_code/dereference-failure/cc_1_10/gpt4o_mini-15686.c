//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, sizeof(unsigned char), bytesRead, output);
    }

    fclose(input);
    fclose(output);
}

void printUsage(char *programName) {
    printf("Usage: %s <input_file> <output_file> <key>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    char key = argv[3][0];  // Use the first character of the key

    encryptDecryptFile(inputFile, outputFile, key);

    printf("File encrypted/decrypted successfully. Output file: %s\n", outputFile);
    return EXIT_SUCCESS;
}