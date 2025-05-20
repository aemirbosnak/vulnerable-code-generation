//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key to use for encryption
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Function to encrypt a string using a key
char *encrypt(char *plaintext) {
    // Create a buffer to store the encrypted text
    char *ciphertext = malloc(strlen(plaintext) + 1);

    // Loop through each character in the plaintext
    for (int i = 0; i < strlen(plaintext); i++) {
        // Get the index of the character in the key
        int keyIndex = plaintext[i] - 'A';

        // Encrypt the character using the key
        ciphertext[i] = KEY[keyIndex];
    }

    // Terminate the ciphertext with a null character
    ciphertext[strlen(plaintext)] = '\0';

    // Return the encrypted text
    return ciphertext;
}

// Function to decrypt a string using a key
char *decrypt(char *ciphertext) {
    // Create a buffer to store the decrypted text
    char *plaintext = malloc(strlen(ciphertext) + 1);

    // Loop through each character in the ciphertext
    for (int i = 0; i < strlen(ciphertext); i++) {
        // Get the index of the character in the key
        int keyIndex = strchr(KEY, ciphertext[i]) - KEY;

        // Decrypt the character using the key
        plaintext[i] = keyIndex + 'A';
    }

    // Terminate the plaintext with a null character
    plaintext[strlen(ciphertext)] = '\0';

    // Return the decrypted text
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char *plaintext = malloc(100);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decryptedtext = decrypt(ciphertext);

    // Print the decrypted text
    printf("The decrypted text is: %s\n", decryptedtext);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}