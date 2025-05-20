//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption and decryption keys
#define ENCRYPTION_KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DECRYPTION_KEY "ZYXWVUTSRQPONMLKJIHGFEDCBA"

// Function to encrypt a string using the encryption key
char *encrypt(char *plaintext) {
    int i, length;
    char *ciphertext;

    // Calculate the length of the plaintext string
    length = strlen(plaintext);

    // Allocate memory for the ciphertext string
    ciphertext = (char *)malloc(length + 1);

    // Encrypt the plaintext string character by character
    for (i = 0; i < length; i++) {
        int index = plaintext[i] - 'A';
        ciphertext[i] = ENCRYPTION_KEY[index];
    }

    // Null-terminate the ciphertext string
    ciphertext[length] = '\0';

    // Return the ciphertext string
    return ciphertext;
}

// Function to decrypt a string using the decryption key
char *decrypt(char *ciphertext) {
    int i, length;
    char *plaintext;

    // Calculate the length of the ciphertext string
    length = strlen(ciphertext);

    // Allocate memory for the plaintext string
    plaintext = (char *)malloc(length + 1);

    // Decrypt the ciphertext string character by character
    for (i = 0; i < length; i++) {
        int index = ciphertext[i] - 'A';
        plaintext[i] = DECRYPTION_KEY[index];
    }

    // Null-terminate the plaintext string
    plaintext[length] = '\0';

    // Return the plaintext string
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext string from the user
    char plaintext[100];
    printf("Enter the plaintext string: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext string
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext string
    printf("The ciphertext string is: %s\n", ciphertext);

    // Decrypt the ciphertext string
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext string
    printf("The decrypted plaintext string is: %s\n", decrypted_plaintext);

    // Free the memory allocated for the ciphertext and decrypted plaintext strings
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}