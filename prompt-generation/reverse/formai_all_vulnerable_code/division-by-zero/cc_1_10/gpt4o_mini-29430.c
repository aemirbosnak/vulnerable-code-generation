//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char *key) {
    int keyLength = strlen(key);
    int i = 0;
    
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }
}

void displayInstructions() {
    printf("C File Encryptor\n");
    printf("Usage: ./encryptor <input_file> <output_file> <key>\n");
    printf("Encrypts the input file using the provided key and saves to the output file.\n");
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 4) {
        displayInstructions();
        return EXIT_FAILURE;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char *key = argv[3];

    // Open the input file for reading
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Unable to open input file %s\n", inputFileName);
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Unable to open output file %s\n", outputFileName);
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Perform encryption/decryption
    encryptDecrypt(inputFile, outputFile, key);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Processing complete. Encrypted data has been saved to %s\n", outputFileName);
    return EXIT_SUCCESS;
}