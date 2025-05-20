//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations
unsigned char *encrypt(const unsigned char *plaintext, size_t plaintext_len, const unsigned char *key, size_t key_len);
unsigned char *decrypt(const unsigned char *ciphertext, size_t ciphertext_len, const unsigned char *key, size_t key_len);

int main(void) {
    // Define the plaintext and key
    const unsigned char plaintext[] = "Hello, world!";
    const unsigned char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Encrypt the plaintext using the key
    size_t ciphertext_len = 0;
    unsigned char *ciphertext = encrypt(plaintext, strlen(plaintext), key, strlen(key));

    // Print the ciphertext
    printf("Ciphertext: ");
    for (size_t i = 0; i < ciphertext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext using the key
    size_t plaintext_len = 0;
    unsigned char *decrypted_plaintext = decrypt(ciphertext, ciphertext_len, key, strlen(key));

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}

// Encrypt the plaintext using the key
unsigned char *encrypt(const unsigned char *plaintext, size_t plaintext_len, const unsigned char *key, size_t key_len) {
    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(plaintext_len + 1);

    // Initialize the ciphertext
    memcpy(ciphertext, plaintext, plaintext_len);

    // Encrypt the ciphertext using the key
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] ^= key[i % key_len];
    }

    // Return the ciphertext
    return ciphertext;
}

// Decrypt the ciphertext using the key
unsigned char *decrypt(const unsigned char *ciphertext, size_t ciphertext_len, const unsigned char *key, size_t key_len) {
    // Allocate memory for the decrypted plaintext
    unsigned char *decrypted_plaintext = malloc(ciphertext_len + 1);

    // Initialize the decrypted plaintext
    memcpy(decrypted_plaintext, ciphertext, ciphertext_len);

    // Decrypt the decrypted plaintext using the key
    for (size_t i = 0; i < ciphertext_len; i++) {
        decrypted_plaintext[i] ^= key[i % key_len];
    }

    // Return the decrypted plaintext
    return decrypted_plaintext;
}