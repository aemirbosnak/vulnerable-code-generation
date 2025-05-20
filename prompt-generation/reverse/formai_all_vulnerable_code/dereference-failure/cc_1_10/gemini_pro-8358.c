//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function to encrypt a file
void encryptFile(FILE *input, FILE *output, int key) {
    // Read a character from the input file
    char ch = fgetc(input);

    // If the end of the file is reached, stop
    if (ch == EOF) {
        return;
    }

    // Otherwise, encrypt the character and write it to the output file
    ch += key;
    fputc(ch, output);

    // Recursively encrypt the rest of the file
    encryptFile(input, output, key);
}

// Function to encrypt a file
void encrypt(const char *inputFileName, const char *outputFileName, int key) {
    // Open the input and output files
    FILE *input = fopen(inputFileName, "rb");
    FILE *output = fopen(outputFileName, "wb");

    // Check if the files were opened successfully
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Encrypt the file
    encryptFile(input, output, key);

    // Close the files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt(const char *inputFileName, const char *outputFileName, int key) {
    // Open the input and output files
    FILE *input = fopen(inputFileName, "rb");
    FILE *output = fopen(outputFileName, "wb");

    // Check if the files were opened successfully
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Decrypt the file
    encryptFile(input, output, -key);

    // Close the files
    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided
    if (argc != 5) {
        printf("Usage: %s encrypt/decrypt inputFile outputFile key\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the command line arguments
    char *command = argv[1];
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    int key = atoi(argv[4]);

    // Check if the key is valid
    if (key < 0 || key > 255) {
        printf("Error: Key must be between 0 and 255\n");
        exit(EXIT_FAILURE);
    }

    // Encrypt or decrypt the file
    if (strcmp(command, "encrypt") == 0) {
        encrypt(inputFileName, outputFileName, key);
    } else if (strcmp(command, "decrypt") == 0) {
        decrypt(inputFileName, outputFileName, key);
    } else {
        printf("Error: Invalid command\n");
        exit(EXIT_FAILURE);
    }

    // Exit successfully
    return EXIT_SUCCESS;
}