//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // Simple XOR key for encryption
#define BUFFER_SIZE 256

// Function to encrypt the data
void encryptData(char *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        buffer[i] ^= KEY; // XOR encryption
    }
}

// Function to decrypt the data
void decryptData(char *buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        buffer[i] ^= KEY; // XOR decryption
    }
}

// Function to process the file
void processFile(const char *inputFile, const char *outputFile, int encrypt) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (encrypt) {
            encryptData(buffer, bytesRead); // Encrypt data
        } else {
            decryptData(buffer, bytesRead); // Decrypt data
        }
        fwrite(buffer, 1, bytesRead, output);
    }

    fclose(input);
    fclose(output);
    
    if (encrypt) {
        printf("🔒 File '%s' has been encrypted to '%s'! 🎉\n", inputFile, outputFile);
    } else {
        printf("🔓 File '%s' has been decrypted to '%s'! 🎊\n", inputFile, outputFile);
    }
}

// Main function for user interaction
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int encrypt = strcmp(argv[1], "encrypt") == 0;

    processFile(argv[2], argv[3], encrypt);

    return EXIT_SUCCESS;
}