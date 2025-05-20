//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *inputFile, const char *outputFile, int shift) {
    FILE *inFile, *outFile;
    int ch;

    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        fclose(inFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(inFile)) != EOF) {
        // Encrypt/Decrypt character using Caesar cipher
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift + 26) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift + 26) % 26) + 'a';
        }
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void printUsage() {
    printf("Usage: file_encryptor <input_file> <output_file> <shift>\n");
    printf("  input_file   - The path to the input file\n");
    printf("  output_file  - The path to the output file\n");
    printf("  shift        - The number of characters to shift (positive for encryption, negative for decryption)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int shift = atoi(argv[3]);

    // Validate the shift value
    if (shift < -25 || shift > 25) {
        fprintf(stderr, "Shift value must be between -25 and 25.\n");
        return EXIT_FAILURE;
    }

    // Encrypt or decrypt the file based on shift value
    encryptDecryptFile(inputFile, outputFile, shift);

    printf("Operation completed successfully!\n");

    return EXIT_SUCCESS;
}