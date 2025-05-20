//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MY_SECRET_KEY"

// Function to encrypt a string using the XOR cipher
char *xor_encrypt(const char *plaintext) {
    // Get the length of the plaintext
    size_t len = strlen(plaintext);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(len + 1);
    if (ciphertext == NULL) {
        fprintf(stderr, "Error allocating memory for ciphertext.\n");
        return NULL;
    }

    // Encrypt the plaintext using the XOR cipher
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }

    // Null-terminate the ciphertext
    ciphertext[len] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string using the XOR cipher
char *xor_decrypt(const char *ciphertext) {
    // Get the length of the ciphertext
    size_t len = strlen(ciphertext);

    // Allocate memory for the plaintext
    char *plaintext = malloc(len + 1);
    if (plaintext == NULL) {
        fprintf(stderr, "Error allocating memory for plaintext.\n");
        return NULL;
    }

    // Decrypt the ciphertext using the XOR cipher
    for (size_t i = 0; i < len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }

    // Null-terminate the plaintext
    plaintext[len] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main(void) {
    // Define the plaintext
    char *plaintext = "Hello, world!";

    // Encrypt the plaintext using the XOR cipher
    char *ciphertext = xor_encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the XOR cipher
    char *decrypted_plaintext = xor_decrypt(ciphertext);

    // Print the plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the memory allocated for the ciphertext and the plaintext
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}