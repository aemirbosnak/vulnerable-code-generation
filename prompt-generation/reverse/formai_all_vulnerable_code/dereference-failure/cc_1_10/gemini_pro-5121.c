//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Function to encrypt a string
char *encrypt(char *plaintext) {
    // Allocate memory for the ciphertext
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Iterate over each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the position of the character in the alphabet
        int pos = plaintext[i] - 'A';

        // Shift the character by the key
        int shifted_pos = (pos + strlen(KEY)) % 26;

        // Get the encrypted character
        ciphertext[i] = KEY[shifted_pos];
    }

    // Add the null terminator to the ciphertext
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
    // Allocate memory for the plaintext
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Iterate over each character in the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Get the position of the character in the alphabet
        int pos = ciphertext[i] - 'A';

        // Shift the character by the key
        int unshifted_pos = (pos - strlen(KEY)) % 26;

        // Get the decrypted character
        plaintext[i] = KEY[unshifted_pos];
    }

    // Add the null terminator to the plaintext
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}