//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile, const char *key);
void decryptFile(const char *inputFile, const char *outputFile, const char *key);
void handleError(const char *msg);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    // Getting the action, input file, output file, and key
    char *action = argv[1];
    const char *inputFile = argv[2];
    const char *outputFile = argv[3];
    const char *key = argv[4];

    if (strcmp(action, "encrypt") == 0) {
        encryptFile(inputFile, outputFile, key);
        printf("File '%s' has been encrypted and saved as '%s'.\n", inputFile, outputFile);
    } else if (strcmp(action, "decrypt") == 0) {
        decryptFile(inputFile, outputFile, key);
        printf("File '%s' has been decrypted and saved as '%s'.\n", inputFile, outputFile);
    } else {
        printf("Invalid action. Use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");

    if (!inFile || !outFile) {
        handleError("Error opening files for encryption.");
    }

    size_t keyLen = strlen(key);
    int ch;
    size_t index = 0;
    
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key[index % keyLen], outFile);
        index++;
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char *inputFile, const char *outputFile, const char *key) {
    // The decryption is identical to encryption: XOR with the same key.
    encryptFile(inputFile, outputFile, key);
}

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}