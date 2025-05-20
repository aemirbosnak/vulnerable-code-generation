//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA  // Simple XOR key for encryption

// Function to encrypt or decrypt the file
void processFile(const char* inputFileName, const char* outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");
    
    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error: Could not open files!\n");
        exit(EXIT_FAILURE);
    }

    // Read and process the file byte by byte
    int byte;
    while ((byte = fgetc(inputFile)) != EOF) {
        fputc(byte ^ KEY, outputFile);  // XOR encryption/decryption
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Processing complete! Check the output file '%s'.\n", outputFileName);
}

// Function to display the program usage
void showUsage(const char* programName) {
    printf("Usage: %s <input_file> <output_file>\n", programName);
    printf("Encrypts or decrypts the provided file using XOR encryption.\n");
}

int main(int argc, char* argv[]) {
    printf("====================================\n");
    printf("         C File Encryptor          \n");
    printf("          Made with ❤  in C        \n");
    printf("====================================\n");

    // Check if the correct number of arguments are provided
    if (argc != 3) {
        showUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];

    printf("Going to process the input file: %s\n", inputFileName);
    printf("Output will be saved to: %s\n", outputFileName);

    // Encrypt or decrypt the file
    processFile(inputFileName, outputFileName);

    return EXIT_SUCCESS;
}