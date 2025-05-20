//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the XOR cipher
#define KEY "my_super_secret_key"

// Function to encrypt a string using the XOR cipher
char* xor_encrypt(char* plaintext) {
    // Get the length of the plaintext and key
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(KEY);

    // Allocate memory for the ciphertext
    char* ciphertext = malloc(plaintext_len + 1);

    // Loop through each character in the plaintext
    for (size_t i = 0; i < plaintext_len; i++) {
        // XOR the character with the corresponding character in the key
        ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
    }

    // Add null terminator to the end of the ciphertext
    ciphertext[plaintext_len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string using the XOR cipher
char* xor_decrypt(char* ciphertext) {
    // Get the length of the ciphertext and key
    size_t ciphertext_len = strlen(ciphertext);
    size_t key_len = strlen(KEY);

    // Allocate memory for the plaintext
    char* plaintext = malloc(ciphertext_len + 1);

    // Loop through each character in the ciphertext
    for (size_t i = 0; i < ciphertext_len; i++) {
        // XOR the character with the corresponding character in the key
        plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
    }

    // Add null terminator to the end of the plaintext
    plaintext[ciphertext_len] = '\0';

    // Return the plaintext
    return plaintext;
}

int main() {
    // Define the plaintext message
    char* plaintext = "Hello, world!";

    // Encrypt the plaintext using the XOR cipher
    char* ciphertext = xor_encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher
    char* decrypted_plaintext = xor_decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the memory allocated for the ciphertext and decrypted plaintext
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}