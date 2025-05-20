//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256
#define AES_BLOCK_SIZE 16

void handleErrors(void) {
    fprintf(stderr, "An error occurred during encryption/decryption process.\n");
    exit(EXIT_FAILURE);
}

// Function to encrypt plaintext using AES
void encrypt(const uint8_t *key, const uint8_t *iv, const uint8_t *plaintext, uint8_t *ciphertext, size_t plaintext_len) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &encryptKey) < 0) {
        handleErrors();
    }

    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &encryptKey, (uint8_t *)iv, AES_ENCRYPT);
}

// Function to decrypt ciphertext using AES
void decrypt(const uint8_t *key, const uint8_t *iv, const uint8_t *ciphertext, uint8_t *plaintext, size_t ciphertext_len) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &decryptKey) < 0) {
        handleErrors();
    }

    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &decryptKey, (uint8_t *)iv, AES_DECRYPT);
}

void generateRandomBytes(uint8_t *buffer, size_t length) {
    if (!RAND_bytes(buffer, length)) {
        handleErrors();
    }
}

void printHex(const uint8_t *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    const char *message = "The quick brown fox jumps over the lazy dog";
    size_t message_len = strlen(message);
    size_t padded_len = ((message_len / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE;

    uint8_t *plaintext = (uint8_t *)malloc(padded_len);
    uint8_t *ciphertext = (uint8_t *)malloc(padded_len);
    uint8_t *decryptedtext = (uint8_t *)malloc(padded_len);
    uint8_t key[AES_KEY_SIZE / 8];
    uint8_t iv[AES_BLOCK_SIZE];

    // Padding the plaintext
    memset(plaintext, 0, padded_len);
    memcpy(plaintext, message, message_len);

    // Generate a random key and IV
    generateRandomBytes(key, sizeof(key));
    generateRandomBytes(iv, sizeof(iv));

    printf("Original message: %s\n", message);
    printf("Key: ");
    printHex(key, sizeof(key));
    printf("IV: ");
    printHex(iv, sizeof(iv));

    // Encrypt the plaintext
    encrypt(key, iv, plaintext, ciphertext, padded_len);
    
    printf("Ciphertext: ");
    printHex(ciphertext, padded_len);

    // Decrypt the ciphertext
    decrypt(key, iv, ciphertext, decryptedtext, padded_len);

    printf("Decrypted message: %s\n", decryptedtext);

    // Free allocated memory
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}