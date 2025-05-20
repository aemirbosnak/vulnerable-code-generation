//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
void encrypt(char *input, char *key);
void decrypt(char *input, char *key);

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        printf("Usage: %s <input> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the input and key from the command line
    char *input = argv[1];
    char *key = argv[2];

    // Check if the key is long enough
    if (strlen(key) < 1) {
        printf("Error: Key must be at least one character long.\n");
        exit(EXIT_FAILURE);
    }

    // Encrypt the input
    encrypt(input, key);

    // Print the encrypted input
    printf("Encrypted: %s\n", input);

    // Decrypt the encrypted input
    decrypt(input, key);

    // Print the decrypted input
    printf("Decrypted: %s\n", input);

    // Exit successfully
    exit(EXIT_SUCCESS);
}

// Function to encrypt the input
void encrypt(char *input, char *key) {
    // Get the lengths of the input and key
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);

    // Loop through each character in the input
    for (size_t i = 0; i < input_len; i++) {
        // Get the current character from the input
        char c = input[i];

        // Get the current character from the key
        char k = key[i % key_len];

        // Encrypt the character
        c ^= k;

        // Update the input with the encrypted character
        input[i] = c;
    }
}

// Function to decrypt the input
void decrypt(char *input, char *key) {
    // Get the lengths of the input and key
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);

    // Loop through each character in the input
    for (size_t i = 0; i < input_len; i++) {
        // Get the current character from the input
        char c = input[i];

        // Get the current character from the key
        char k = key[i % key_len];

        // Decrypt the character
        c ^= k;

        // Update the input with the decrypted character
        input[i] = c;
    }
}