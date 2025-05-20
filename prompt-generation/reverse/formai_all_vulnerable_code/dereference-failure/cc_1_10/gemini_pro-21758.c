//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "mysecretkey"

// Function to encrypt a string using a simple XOR cipher
void encrypt(char* plaintext, char* ciphertext) {
    // Get the length of the plaintext
    int len = strlen(plaintext);

    // Loop through each character in the plaintext
    for (int i = 0; i < len; i++) {
        // XOR the character with the corresponding character in the key
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }
}

// Function to decrypt a string using a simple XOR cipher
void decrypt(char* ciphertext, char* plaintext) {
    // Get the length of the ciphertext
    int len = strlen(ciphertext);

    // Loop through each character in the ciphertext
    for (int i = 0; i < len; i++) {
        // XOR the character with the corresponding character in the key
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }
}

int main() {
    // Define the plaintext and ciphertext strings
    char plaintext[] = "Hello, world!";
    char ciphertext[strlen(plaintext) + 1];

    // Encrypt the plaintext using the XOR cipher
    encrypt(plaintext, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher
    decrypt(ciphertext, plaintext);

    // Print the decrypted plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}