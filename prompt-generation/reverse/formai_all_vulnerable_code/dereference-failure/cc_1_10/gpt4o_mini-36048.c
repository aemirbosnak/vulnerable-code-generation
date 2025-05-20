//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *input, char *key, char *output);
void decrypt(char *input, char *key, char *output);

int main() {
    // Welcoming the user and explaining the program
    printf("Welcome to the Simple XOR Cipher Program!\n");
    printf("This program encrypts and decrypts strings using a basic XOR cipher.\n");

    // Allocate memory for inputs and outputs
    char *plaintext = (char *)malloc(256 * sizeof(char));
    char *key = (char *)malloc(256 * sizeof(char));
    char *ciphertext = (char *)malloc(256 * sizeof(char));
    char *decryptedtext = (char *)malloc(256 * sizeof(char));

    // Step 1: Get user input for plaintext
    printf("Please enter the plaintext (max 255 characters): ");
    fgets(plaintext, 256, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;  // Remove trailing newline

    // Step 2: Get user input for key
    printf("Please enter the encryption key (max 255 characters): ");
    fgets(key, 256, stdin);
    key[strcspn(key, "\n")] = 0;  // Remove trailing newline

    // Step 3: Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Step 4: Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    // Step 5: Clean up
    free(plaintext);
    free(key);
    free(ciphertext);
    free(decryptedtext);

    // Final message
    printf("Thank you for using the XOR Cipher Program! Goodbye!\n");
    return 0;
}

// Function to encrypt the input using the XOR cipher
void encrypt(char *input, char *key, char *output) {
    size_t inputLen = strlen(input);
    size_t keyLen = strlen(key);
    
    // We will loop over each character of the input
    for (size_t i = 0; i < inputLen; i++) {
        // XOR current character with a character from the key
        output[i] = input[i] ^ key[i % keyLen];
    }
    // Null terminate the output string
    output[inputLen] = '\0';
}

// Function to decrypt the input using the XOR cipher
void decrypt(char *input, char *key, char *output) {
    size_t inputLen = strlen(input);
    size_t keyLen = strlen(key);
    
    // To decrypt, we perform the same XOR operation
    for (size_t i = 0; i < inputLen; i++) {
        output[i] = input[i] ^ key[i % keyLen];
    }
    // Null terminate the output string
    output[inputLen] = '\0';
}