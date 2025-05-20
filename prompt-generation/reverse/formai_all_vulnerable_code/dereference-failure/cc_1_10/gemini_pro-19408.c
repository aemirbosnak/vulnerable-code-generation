//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption
#define KEY 123

// Encrypt a file using a simple XOR cipher
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *inputFile = fopen(input_file, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(output_file, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file one byte at a time
    unsigned char byte;
    while (fread(&byte, sizeof(unsigned char), 1, inputFile)) {
        // Encrypt the byte using XOR cipher
        byte ^= KEY;

        // Write the encrypted byte to the output file
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Decrypt a file using a simple XOR cipher
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *inputFile = fopen(input_file, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen(output_file, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file one byte at a time
    unsigned char byte;
    while (fread(&byte, sizeof(unsigned char), 1, inputFile)) {
        // Decrypt the byte using XOR cipher
        byte ^= KEY;

        // Write the decrypted byte to the output file
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    printf("File %s successfully %sed.\n", input_file, operation);

    return 0;
}