//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile) {
    // Read the input file
    FILE *input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error opening input file\n");
        return;
    }

    // Get the size of the input file
    fseek(input, 0, SEEK_END);
    long int fileSize = ftell(input);
    rewind(input);

    // Allocate memory for the encrypted file
    char *encryptedFile = (char *)malloc(fileSize);
    if (encryptedFile == NULL) {
        printf("Error allocating memory for encrypted file\n");
        return;
    }

    // Encrypt the file
    int i;
    for (i = 0; i < fileSize; i++) {
        encryptedFile[i] = inputFile[i] ^ KEY[i % strlen(KEY)];
    }

    // Close the input file
    fclose(input);

    // Write the encrypted file
    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error opening output file\n");
        return;
    }

    fwrite(encryptedFile, 1, fileSize, output);

    // Close the output file
    fclose(output);

    // Free the memory for the encrypted file
    free(encryptedFile);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile) {
    // Read the input file
    FILE *input = fopen(inputFile, "rb");
    if (input == NULL) {
        printf("Error opening input file\n");
        return;
    }

    // Get the size of the input file
    fseek(input, 0, SEEK_END);
    long int fileSize = ftell(input);
    rewind(input);

    // Allocate memory for the decrypted file
    char *decryptedFile = (char *)malloc(fileSize);
    if (decryptedFile == NULL) {
        printf("Error allocating memory for decrypted file\n");
        return;
    }

    // Decrypt the file
    int i;
    for (i = 0; i < fileSize; i++) {
        decryptedFile[i] = inputFile[i] ^ KEY[i % strlen(KEY)];
    }

    // Close the input file
    fclose(input);

    // Write the decrypted file
    FILE *output = fopen(outputFile, "wb");
    if (output == NULL) {
        printf("Error opening output file\n");
        return;
    }

    fwrite(decryptedFile, 1, fileSize, output);

    // Close the output file
    fclose(output);

    // Free the memory for the decrypted file
    free(decryptedFile);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [input file] [output file]\n", argv[0]);
        return 1;
    }

    // Get the command
    char *command = argv[1];

    // Get the input file
    char *inputFile = argv[2];

    // Get the output file
    char *outputFile = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(command, "encrypt") == 0) {
        encryptFile(inputFile, outputFile);
    } else if (strcmp(command, "decrypt") == 0) {
        decryptFile(inputFile, outputFile);
    } else {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}