//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the content of a file
void encryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");
    
    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    size_t keyLen = strlen(key);
    int ch;
    size_t i = 0;

    // Encrypting the file by XORing each byte with the key
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key[i % keyLen], outputFile);
        i++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

// Function to decrypt the content of a file
void decryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    encryptFile(inputFileName, outputFileName, key); // Decrypting is the same operation as encrypting
}

// Function to display usage information
void displayUsage(const char *programName) {
    printf("Usage: %s <action> <input_file> <output_file> <key>\n", programName);
    printf("Actions:\n");
    printf("  encrypt: To encrypt a file\n");
    printf("  decrypt: To decrypt a file\n");
}

int main(int argc, char **argv) {
    if (argc != 5) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];
    const char *key = argv[4];

    if (strcmp(action, "encrypt") == 0) {
        encryptFile(inputFileName, outputFileName, key);
        printf("File '%s' encrypted to '%s'.\n", inputFileName, outputFileName);
    } else if (strcmp(action, "decrypt") == 0) {
        decryptFile(inputFileName, outputFileName, key);
        printf("File '%s' decrypted to '%s'.\n", inputFileName, outputFileName);
    } else {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}