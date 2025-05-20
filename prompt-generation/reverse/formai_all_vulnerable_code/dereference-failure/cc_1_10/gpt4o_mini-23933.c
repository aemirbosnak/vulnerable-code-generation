//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function prototypes
void encryptDecryptFile(const char *inputFile, const char *outputFile, char key);
void displayUsage();

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayUsage();
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    char key = argv[3][0]; // Use the first character of the key

    encryptDecryptFile(inputFile, outputFile, key);

    return 0;
}

// Function to perform the encryption/decryption
void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Process the input file in chunks
    while ((bytesRead = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, inFile)) > 0) {
        // Encrypt or decrypt the buffer using XOR with the key
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;
        }
        
        // Write the processed buffer to the output file
        fwrite(buffer, sizeof(unsigned char), bytesRead, outFile);
    }

    // Clean up
    fclose(inFile);
    fclose(outFile);

    printf("File processed successfully. %s -> %s\n", inputFile, outputFile);
}

// Function to display usage information
void displayUsage() {
    printf("Usage: file_encryptor <input_file> <output_file> <key>\n");
    printf("Encrypts or decrypts the input file using a simple XOR cipher with the given key\n");
}