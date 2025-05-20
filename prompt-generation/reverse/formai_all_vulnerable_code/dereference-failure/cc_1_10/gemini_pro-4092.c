//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "secret"

// Define the encryption function
char* encrypt(char* plaintext) {
    size_t len = strlen(plaintext);
    char* ciphertext = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Define the decryption function
char* decrypt(char* ciphertext) {
    size_t len = strlen(ciphertext);
    char* plaintext = malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }
    plaintext[len] = '\0';
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char* plaintext = malloc(100);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char* ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char* decryptedText = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decryptedText);

    // Free the allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedText);

    return 0;
}