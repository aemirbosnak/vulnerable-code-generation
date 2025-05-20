//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Encrypt a single character
char encrypt(char c) {
    // Check if the character is a letter
    if (c >= 'A' && c <= 'Z') {
        // Shift the character forward by the amount specified by the key
        c += KEY[c - 'A'];
        // Wrap around if the character goes past 'Z'
        if (c > 'Z') {
            c -= 26;
        }
    }
    return c;
}

// Encrypt a string
char *encrypt_string(char *str) {
    // Allocate memory for the encrypted string
    char *encrypted = malloc(strlen(str) + 1);
    // Encrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        encrypted[i] = encrypt(str[i]);
    }
    // Add the null terminator
    encrypted[strlen(str)] = '\0';
    // Return the encrypted string
    return encrypted;
}

// Decrypt a single character
char decrypt(char c) {
    // Check if the character is a letter
    if (c >= 'A' && c <= 'Z') {
        // Shift the character backward by the amount specified by the key
        c -= KEY[c - 'A'];
        // Wrap around if the character goes before 'A'
        if (c < 'A') {
            c += 26;
        }
    }
    return c;
}

// Decrypt a string
char *decrypt_string(char *str) {
    // Allocate memory for the decrypted string
    char *decrypted = malloc(strlen(str) + 1);
    // Decrypt each character in the string
    for (int i = 0; i < strlen(str); i++) {
        decrypted[i] = decrypt(str[i]);
    }
    // Add the null terminator
    decrypted[strlen(str)] = '\0';
    // Return the decrypted string
    return decrypted;
}

// Main function
int main() {
    // Get the input string from the user
    char *str = malloc(100);
    printf("Enter the string to encrypt: ");
    fgets(str, 100, stdin);

    // Encrypt the string
    char *encrypted = encrypt_string(str);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the string
    char *decrypted = decrypt_string(encrypted);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted);

    // Free the allocated memory
    free(str);
    free(encrypted);
    free(decrypted);

    return 0;
}