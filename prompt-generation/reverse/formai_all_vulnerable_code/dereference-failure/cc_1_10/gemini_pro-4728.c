//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
char *encrypt(char *plaintext, char *key);
void print_help();

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 3) {
        print_help();
        return EXIT_FAILURE;
    }

    char *plaintext = argv[1];
    char *key = argv[2];

    // Encrypt the plaintext using the key
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Clean up
    free(ciphertext);

    return EXIT_SUCCESS;
}

// Function to encrypt the plaintext using the key
char *encrypt(char *plaintext, char *key) {
    // Create a buffer to store the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Loop through each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the corresponding character from the key
        char keyChar = key[i % strlen(key)];

        // XOR the plaintext character with the key character
        ciphertext[i] = plaintext[i] ^ keyChar;
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to print usage information
void print_help() {
    printf("Usage: %s plaintext key\n", __FILE__);
    printf("Encrypts plaintext using the given key.\n");
}