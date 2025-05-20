//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file and encrypt each byte
    int ch;
    int i = 0;
    while ((ch = fgetc(fin)) != EOF) {
        // XOR the byte with the key byte
        ch ^= key[i];

        // Increment the key index
        i = (i + 1) % keyLength;

        // Write the encrypted byte to the output file
        fputc(ch, fout);
    }

    // Close the input and output files
    fclose(fin);
    fclose(fout);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile, char *key) {
    // Open the input file
    FILE *fin = fopen(inputFile, "rb");
    if (fin == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *fout = fopen(outputFile, "wb");
    if (fout == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file and decrypt each byte
    int ch;
    int i = 0;
    while ((ch = fgetc(fin)) != EOF) {
        // XOR the byte with the key byte
        ch ^= key[i];

        // Increment the key index
        i = (i + 1) % keyLength;

        // Write the decrypted byte to the output file
        fputc(ch, fout);
    }

    // Close the input and output files
    fclose(fin);
    fclose(fout);
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 5) {
        printf("Usage: %s <encrypt/decrypt> <input file> <output file> <key>\n", argv[0]);
        exit(1);
    }

    // Get the operation (encrypt or decrypt)
    char *operation = argv[1];

    // Get the input file name
    char *inputFile = argv[2];

    // Get the output file name
    char *outputFile = argv[3];

    // Get the key
    char *key = argv[4];

    // Encrypt or decrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        exit(1);
    }

    // Exit successfully
    return 0;
}