//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "HappyDays"

// Define the encryption function
char *encrypt(char *plaintext) {
    // Create a buffer to hold the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Encrypt the plaintext using the key
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext) {
    // Create a buffer to hold the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Decrypt the ciphertext using the key
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }

    // Null-terminate the plaintext
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Get the input from the user
char *getInput() {
    // Create a buffer to hold the input
    char *input = malloc(100);

    // Get the input from the user
    printf("Enter the message you want to encrypt: ");
    fgets(input, 100, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Return the input
    return input;
}

// Print the output to the user
void printOutput(char *output) {
    // Print the output to the user
    printf("Encrypted message: %s\n", output);
}

int main() {
    // Get the input from the user
    char *plaintext = getInput();

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Decrypt the ciphertext
    char *decryptedText = decrypt(ciphertext);

    // Print the output to the user
    printOutput(ciphertext);
    printOutput(decryptedText);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedText);

    return 0;
}