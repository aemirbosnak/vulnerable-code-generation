//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32

// Forward declarations
void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len);
void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, int key_len);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <plaintext> <key> <encrypt/decrypt> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the plaintext, key, and operation from the command line arguments
    char *plaintext = argv[1];
    char *key = argv[2];
    char *operation = argv[3];
    char *output_file = argv[4];

    // Check if the key is valid
    int key_len = strlen(key);
    if (key_len < 1 || key_len > MAX_KEY_SIZE) {
        fprintf(stderr, "Error: Key must be between 1 and %d characters long.\n", MAX_KEY_SIZE);
        return EXIT_FAILURE;
    }

    // Check if the operation is valid
    if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
        fprintf(stderr, "Error: Operation must be either \"encrypt\" or \"decrypt\".\n");
        return EXIT_FAILURE;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        return EXIT_FAILURE;
    }

    // Perform the encryption or decryption
    if (strcmp(operation, "encrypt") == 0) {
        encrypt(plaintext, strlen(plaintext), key, key_len);
        fwrite(plaintext, strlen(plaintext), 1, output);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(plaintext, strlen(plaintext), key, key_len);
        fwrite(plaintext, strlen(plaintext), 1, output);
    }

    // Close the output file
    fclose(output);

    return EXIT_SUCCESS;
}

// Encrypt the plaintext using the given key
void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, int key_len) {
    for (int i = 0; i < plaintext_len; i++) {
        plaintext[i] ^= key[i % key_len];
    }
}

// Decrypt the ciphertext using the given key
void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, int key_len) {
    for (int i = 0; i < ciphertext_len; i++) {
        ciphertext[i] ^= key[i % key_len];
    }
}