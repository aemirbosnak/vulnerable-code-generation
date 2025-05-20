//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt or decrypt the data
void processFile(const char *inputFile, const char *outputFile, char key) {
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

    // Read and process file content byte by byte
    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile);  // XOR encryption/decryption
    }

    fclose(inFile);
    fclose(outFile);
    printf("File processed successfully: %s -> %s\n", inputFile, outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <inputfile> <outputfile> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    char key = argv[4][0]; // First character of the provided key

    if (strcmp(mode, "encrypt") == 0) {
        processFile(inputFile, outputFile, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        processFile(inputFile, outputFile, key);
    } else {
        fprintf(stderr, "Invalid mode: %s. Use 'encrypt' or 'decrypt'.\n", mode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}