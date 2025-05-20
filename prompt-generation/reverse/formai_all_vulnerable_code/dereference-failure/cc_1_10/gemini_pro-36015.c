//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "my_secret_key"

// Function to encrypt a file
void encryptFile(FILE *inputFile, FILE *outputFile) {
    // Get the key length
    int keyLength = strlen(KEY);

    // Read the input file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        // Encrypt the buffer
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= KEY[i % keyLength];
        }

        // Write the encrypted buffer to the output file
        fputs(buffer, outputFile);
    }
}

// Function to decrypt a file
void decryptFile(FILE *inputFile, FILE *outputFile) {
    // Get the key length
    int keyLength = strlen(KEY);

    // Read the input file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), inputFile)) {
        // Decrypt the buffer
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] ^= KEY[i % keyLength];
        }

        // Write the decrypted buffer to the output file
        fputs(buffer, outputFile);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <encrypt/decrypt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input and output files
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    // Check if the files were opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return EXIT_FAILURE;
    }

    // Check if the user wants to encrypt or decrypt the file
    if (strcmp(argv[3], "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Invalid operation. Please specify \"encrypt\" or \"decrypt\".\n");
        return EXIT_FAILURE;
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}