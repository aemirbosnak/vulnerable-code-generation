//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_KEY_LENGTH 1024

// Generates a random key of the specified length.
uint8_t *generate_key(size_t length) {
    uint8_t *key = malloc(length);
    for (size_t i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

// Encrypts a message using the XOR cipher.
uint8_t *encrypt_xor(uint8_t *message, uint8_t *key) {
    size_t message_length = strlen(message);
    size_t key_length = strlen(key);
    uint8_t *ciphertext = malloc(message_length);
    for (size_t i = 0; i < message_length; i++) {
        ciphertext[i] = message[i] ^ key[i % key_length];
    }
    return ciphertext;
}

// Decrypts a ciphertext using the XOR cipher.
uint8_t *decrypt_xor(uint8_t *ciphertext, uint8_t *key) {
    size_t ciphertext_length = strlen(ciphertext);
    size_t key_length = strlen(key);
    uint8_t *plaintext = malloc(ciphertext_length);
    for (size_t i = 0; i < ciphertext_length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_length];
    }
    return plaintext;
}

int main() {
    // Generate a random key.
    uint8_t *key = generate_key(MAX_KEY_LENGTH);

    // Encrypt a message using the XOR cipher.
    uint8_t *message = (uint8_t *)"Hello, world!";
    uint8_t *ciphertext = encrypt_xor(message, key);

    // Decrypt the ciphertext using the XOR cipher.
    uint8_t *plaintext = decrypt_xor(ciphertext, key);

    // Print the original message, the ciphertext, and the decrypted plaintext.
    printf("Original message: %s\n", message);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", plaintext);

    // Free the allocated memory.
    free(key);
    free(ciphertext);
    free(plaintext);

    return 0;
}