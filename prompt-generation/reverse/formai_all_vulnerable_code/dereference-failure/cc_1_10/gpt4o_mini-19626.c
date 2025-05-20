//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define KEY_LENGTH 16
#define HDR_SIZE 5

// Function prototypes
void generateKey(char *key);
void encrypt(char *inputFile, char *outputFile, char *key);
void decrypt(char *inputFile, char *outputFile, char *key);
void displayBanner();
void showError(const char *message);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        showError("Usage: ./cyberEncrypt <encrypt/decrypt> <input_file> <output_file>");
        return EXIT_FAILURE;
    }

    char *action = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    char key[KEY_LENGTH + 1];
    generateKey(key);

    if (strcmp(action, "encrypt") == 0) {
        displayBanner();
        encrypt(inputFile, outputFile, key);
        printf("Encryption complete! Key used: %s\n", key);
    } else if (strcmp(action, "decrypt") == 0) {
        displayBanner();
        decrypt(inputFile, outputFile, key);
        printf("Decryption complete! Key used: %s\n", key);
    } else {
        showError("Invalid action. Use 'encrypt' or 'decrypt'.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void displayBanner() {
    printf("========================================\n");
    printf("       CYBERPUNK FILE ENCRYPTOR        \n");
    printf("========================================\n");
    printf("         (c)2023 DarkNet Systems       \n");
    printf("========================================\n\n");
}

void showError(const char *message) {
    fprintf(stderr, "ERROR: %s\n", message);
}

void generateKey(char *key) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char *inputFile, char *outputFile, char *key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        showError("Could not open input file for reading.");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        fclose(input);
        showError("Could not open output file for writing.");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Write the key header
    fwrite(key, sizeof(char), KEY_LENGTH, output);

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % KEY_LENGTH]; // XOR for encryption
        }
        fwrite(buffer, sizeof(char), bytesRead, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *inputFile, char *outputFile, char *key) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        showError("Could not open input file for reading.");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        fclose(input);
        showError("Could not open output file for writing.");
        exit(EXIT_FAILURE);
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read the key header
    char fileKey[KEY_LENGTH + 1];
    fread(fileKey, sizeof(char), KEY_LENGTH, input);
    fileKey[KEY_LENGTH] = '\0'; // Null terminate the key

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= fileKey[i % KEY_LENGTH]; // XOR for decryption
        }
        fwrite(buffer, sizeof(char), bytesRead, output);
    }

    fclose(input);
    fclose(output);
}