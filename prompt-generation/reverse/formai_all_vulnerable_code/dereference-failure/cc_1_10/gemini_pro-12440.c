//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key to use for encryption/decryption
#define KEY "mykey"

// Function to encrypt a string using a simple XOR cipher
char *encrypt(char *plaintext) {
    size_t len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    strcpy(ciphertext, plaintext); // Copy the plaintext into the ciphertext

    // Loop through each character in the plaintext and XOR it with the key
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] ^= KEY[i % strlen(KEY)];
    }

    return ciphertext;
}

// Function to decrypt a string using a simple XOR cipher
char *decrypt(char *ciphertext) {
    size_t len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    strcpy(plaintext, ciphertext); // Copy the ciphertext into the plaintext

    // Loop through each character in the ciphertext and XOR it with the key
    for (size_t i = 0; i < len; i++) {
        plaintext[i] ^= KEY[i % strlen(KEY)];
    }

    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext using the XOR cipher
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}