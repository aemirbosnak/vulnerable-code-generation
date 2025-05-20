//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 0x1234

// Function to encrypt a single character
char encryptChar(char ch) {
    // XOR the character with the encryption key
    return ch ^ KEY;
}

// Function to encrypt a string
char* encryptString(char* str) {
    // Get the length of the string
    int len = strlen(str);

    // Allocate memory for the encrypted string
    char* encryptedStr = malloc(len + 1);

    // Encrypt each character in the string
    for (int i = 0; i < len; i++) {
        encryptedStr[i] = encryptChar(str[i]);
    }

    // Add the null-terminator to the encrypted string
    encryptedStr[len] = '\0';

    // Return the encrypted string
    return encryptedStr;
}

// Function to decrypt a single character
char decryptChar(char ch) {
    // XOR the character with the encryption key
    return ch ^ KEY;
}

// Function to decrypt a string
char* decryptString(char* str) {
    // Get the length of the string
    int len = strlen(str);

    // Allocate memory for the decrypted string
    char* decryptedStr = malloc(len + 1);

    // Decrypt each character in the string
    for (int i = 0; i < len; i++) {
        decryptedStr[i] = decryptChar(str[i]);
    }

    // Add the null-terminator to the decrypted string
    decryptedStr[len] = '\0';

    // Return the decrypted string
    return decryptedStr;
}

// Main function
int main() {
    // Get the plaintext from the user
    char* plaintext = "Hello World!";

    // Encrypt the plaintext
    char* encryptedStr = encryptString(plaintext);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encryptedStr);

    // Decrypt the encrypted string
    char* decryptedStr = decryptString(encryptedStr);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decryptedStr);

    // Free the allocated memory
    free(encryptedStr);
    free(decryptedStr);

    return 0;
}