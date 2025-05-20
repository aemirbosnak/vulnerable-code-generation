//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a Caesar cipher
char* caesar_cipher_encrypt(char* plaintext, int key) {
    // Allocate memory for the ciphertext
    char* ciphertext = malloc(strlen(plaintext) + 1);

    // Encrypt the plaintext using a Caesar cipher
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + key;
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string using a Caesar cipher
char* caesar_cipher_decrypt(char* ciphertext, int key) {
    // Allocate memory for the plaintext
    char* plaintext = malloc(strlen(ciphertext) + 1);

    // Decrypt the ciphertext using a Caesar cipher
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] - key;
    }

    // Null-terminate the plaintext
    plaintext[strlen(ciphertext)] = '\0';

    // Return the plaintext
    return plaintext;
}

int main() {
    // Define the plaintext
    char* plaintext = "Hello, world!";

    // Define the key
    int key = 3;

    // Encrypt the plaintext using a Caesar cipher
    char* ciphertext = caesar_cipher_encrypt(plaintext, key);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using a Caesar cipher
    char* decrypted_plaintext = caesar_cipher_decrypt(ciphertext, key);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the memory allocated for the ciphertext and the decrypted plaintext
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}