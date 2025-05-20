//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encryptDecryptFile(const char* inputFileName, const char* outputFileName, char key);
void displayUsage(const char* programName);

int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Get input parameters
    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];
    char key = argv[3][0];  // Take the first character as the key

    // Call the encryption/decryption function
    encryptDecryptFile(inputFileName, outputFileName, key);

    printf("File encryption/decryption completed successfully!\n");
    return EXIT_SUCCESS;
}

// Function to encrypt or decrypt a file
void encryptDecryptFile(const char* inputFileName, const char* outputFileName, char key) {
    FILE* inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    int ch;
    // Read each character from the input file, encrypt/decrypt it, and write to output file
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key, outputFile); // XOR operation for encryption/decryption
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Function to display usage instructions
void displayUsage(const char* programName) {
    printf("Usage: %s <input_file> <output_file> <key_character>\n", programName);
    printf("Example: %s input.txt output.enc x\n", programName);
}