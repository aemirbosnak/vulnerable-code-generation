//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16  // AES block size in bytes
#define KEY_SIZE 32    // AES key size in bytes (256-bit)

// Function to perform a simple XOR encryption
void xorEncrypt(char *data, const char *key, char *output, size_t length) {
    for (size_t i = 0; i < length; i++) {
        output[i] = data[i] ^ key[i % KEY_SIZE];
    }
}

// Function to generate a random key for encryption
void generateRandomKey(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Random byte
    }
}

// Function for printing bytes in hexadecimal
void printHex(const char *label, const char *data, size_t length) {
    printf("%s: ", label);
    for (size_t i = 0; i < length; i++) {
        printf("%02x ", (unsigned char)data[i]);
    }
    printf("\n");
}

// Function to simulate an encryption process
void encryptFile(const char *filename, const char *key) {
    FILE *inputFile = fopen(filename, "rb");
    if (!inputFile) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Allocate buffers for plaintext and ciphertext
    char *plaintext = malloc(fileSize);
    char *ciphertext = malloc(fileSize);

    if (!plaintext || !ciphertext) {
        perror("Failed to allocate memory");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    fread(plaintext, 1, fileSize, inputFile);
    fclose(inputFile);

    // Print original data in hex
    printHex("Original data", plaintext, fileSize);

    // Encrypt data
    xorEncrypt(plaintext, key, ciphertext, fileSize);

    // Print encrypted data in hex
    printHex("Encrypted data", ciphertext, fileSize);

    // Save encrypted data to a new file
    FILE *outputFile = fopen("encrypted_data.bin", "wb");
    if (!outputFile) {
        perror("Failed to open file for writing");
        free(plaintext);
        free(ciphertext);
        exit(EXIT_FAILURE);
    }

    fwrite(ciphertext, 1, fileSize, outputFile);
    fclose(outputFile);

    free(plaintext);
    free(ciphertext);
    printf("Encryption complete! Encrypted data saved to 'encrypted_data.bin'\n");
}

// Function to decrypt a previously encrypted file
void decryptFile(const char *filename, const char *key) {
    FILE *inputFile = fopen(filename, "rb");
    if (!inputFile) {
        perror("Failed to open file for reading");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char *ciphertext = malloc(fileSize);
    char *decryptedText = malloc(fileSize);

    if (!ciphertext || !decryptedText) {
        perror("Failed to allocate memory");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    fread(ciphertext, 1, fileSize, inputFile);
    fclose(inputFile);

    // Decrypt data
    xorEncrypt(ciphertext, key, decryptedText, fileSize);

    // Print decrypted data in hex
    printHex("Decrypted data", decryptedText, fileSize);

    // Save decrypted data to a new file
    FILE *outputFile = fopen("decrypted_data.txt", "wb");
    if (!outputFile) {
        perror("Failed to open file for writing");
        free(ciphertext);
        free(decryptedText);
        exit(EXIT_FAILURE);
    }

    fwrite(decryptedText, 1, fileSize, outputFile);
    fclose(outputFile);

    free(ciphertext);
    free(decryptedText);
    printf("Decryption complete! Decrypted data saved to 'decrypted_data.txt'\n");
}

int main() {
    char key[KEY_SIZE];
    generateRandomKey(key);

    // Assuming we want to encrypt 'input.txt'
    const char *inputFileName = "input.txt";

    encryptFile(inputFileName, key);
    decryptFile("encrypted_data.bin", key);

    return 0;
}