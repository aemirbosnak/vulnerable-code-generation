//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious function to encrypt a string using a secret key
char *curious_encrypt(const char *plaintext, const char *key) {
    // Get the lengths of the plaintext and the key
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintext_len + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Initialize the ciphertext to the plaintext
    strcpy(ciphertext, plaintext);

    // XOR each character in the ciphertext with the corresponding character in the key
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] ^= key[i % key_len];
    }

    // Return the ciphertext
    return ciphertext;
}

// A curious function to decrypt a string using a secret key
char *curious_decrypt(const char *ciphertext, const char *key) {
    // Get the lengths of the ciphertext and the key
    size_t ciphertext_len = strlen(ciphertext);
    size_t key_len = strlen(key);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertext_len + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    // Initialize the plaintext to the ciphertext
    strcpy(plaintext, ciphertext);

    // XOR each character in the plaintext with the corresponding character in the key
    for (size_t i = 0; i < ciphertext_len; i++) {
        plaintext[i] ^= key[i % key_len];
    }

    // Return the plaintext
    return plaintext;
}

int main() {
    // Define a secret key
    const char *key = "A curious secret key";

    // Define a plaintext message
    const char *plaintext = "This is a curious message";

    // Encrypt the plaintext message using the secret key
    char *ciphertext = curious_encrypt(plaintext, key);
    if (ciphertext == NULL) {
        return EXIT_FAILURE;
    }

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the secret key
    char *decrypted_plaintext = curious_decrypt(ciphertext, key);
    if (decrypted_plaintext == NULL) {
        return EXIT_FAILURE;
    }

    // Print the decrypted plaintext
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}