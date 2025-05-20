//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const char *key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function to encrypt a character using the Caesar cipher
char encrypt(char c) {
    // Find the index of the character in the key
    int index = c - 'A';

    // Shift the character by the key
    index = (index + strlen(key)) % strlen(key);

    // Return the encrypted character
    return key[index];
}

// Function to decrypt a character using the Caesar cipher
char decrypt(char c) {
    // Find the index of the character in the key
    int index = c - 'A';

    // Shift the character by the key
    index = (index - strlen(key)) % strlen(key);

    // Return the decrypted character
    return key[index];
}

// Function to encrypt a string using the Caesar cipher
char *encrypt_string(char *str) {
    // Allocate memory for the encrypted string
    char *encrypted = malloc(strlen(str) + 1);

    // Encrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        encrypted[i] = encrypt(str[i]);
    }

    // Terminate the encrypted string
    encrypted[strlen(str)] = '\0';

    // Return the encrypted string
    return encrypted;
}

// Function to decrypt a string using the Caesar cipher
char *decrypt_string(char *str) {
    // Allocate memory for the decrypted string
    char *decrypted = malloc(strlen(str) + 1);

    // Decrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        decrypted[i] = decrypt(str[i]);
    }

    // Terminate the decrypted string
    decrypted[strlen(str)] = '\0';

    // Return the decrypted string
    return decrypted;
}

int main() {
    // Get the plaintext from the user
    char *plaintext = malloc(100);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *encrypted = encrypt_string(plaintext);

    // Print the encrypted text
    printf("Encrypted text: %s\n", encrypted);

    // Decrypt the encrypted text
    char *decrypted = decrypt_string(encrypted);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decrypted);

    // Free the allocated memory
    free(plaintext);
    free(encrypted);
    free(decrypted);

    return 0;
}