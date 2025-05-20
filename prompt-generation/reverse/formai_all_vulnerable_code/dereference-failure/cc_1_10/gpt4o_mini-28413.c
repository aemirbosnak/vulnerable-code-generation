//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define KEY 0xAA  // Simple XOR key for encryption and decryption

void encrypt(char *input, char *output) {
    FILE *inputFile = fopen(input, "rb");
    if (!inputFile) {
        perror("Unable to open input file for encryption");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(output, "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Unable to open output file for encryption");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY;  // Simple XOR encryption
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Encryption complete! Encrypted file: %s\n", output);
}

void decrypt(char *input, char *output) {
    FILE *inputFile = fopen(input, "rb");
    if (!inputFile) {
        perror("Unable to open input file for decryption");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(output, "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Unable to open output file for decryption");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY;  // Simple XOR decryption
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("Decryption complete! Decrypted file: %s\n", output);
}

void displayHelp() {
    printf("File Encryptor/Decryptor\n");
    printf("Usage:\n");
    printf("  ./file_encryptor -e <plaintext_file> <encrypted_file>\n");
    printf("  ./file_encryptor -d <encrypted_file> <decrypted_file>\n");
    printf("Options:\n");
    printf("  -e    Encrypts the specified file\n");
    printf("  -d    Decrypts the specified file\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        displayHelp();
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-e") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        displayHelp();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}