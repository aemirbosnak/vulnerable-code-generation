//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256
#define AES_BLOCK_SIZE 16
#define MAX_INPUT_SIZE 1024

// Function to generate a random AES key
unsigned char* generate_key() {
    unsigned char *key = (unsigned char*)malloc(AES_KEY_SIZE / 8);
    if (!key) {
        perror("Failed to allocate memory for key");
        exit(EXIT_FAILURE);
    }
    if (RAND_bytes(key, AES_KEY_SIZE / 8) != 1) {
        perror("Failed to generate random key");
        free(key);
        exit(EXIT_FAILURE);
    }
    return key;
}

// Function to encrypt the plaintext
void encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &enc_key) < 0) {
        perror("Failed to set encryption key");
        exit(EXIT_FAILURE);
    }

    unsigned char iv[AES_BLOCK_SIZE];
    if (RAND_bytes(iv, AES_BLOCK_SIZE) != 1) {
        perror("Failed to generate random IV");
        exit(EXIT_FAILURE);
    }

    memcpy(ciphertext, iv, AES_BLOCK_SIZE);
    AES_cbc_encrypt(plaintext, ciphertext + AES_BLOCK_SIZE, sizeof(plaintext), &enc_key, iv, AES_ENCRYPT);
}

// Function to decrypt the ciphertext
void decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &dec_key) < 0) {
        perror("Failed to set decryption key");
        exit(EXIT_FAILURE);
    }

    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, ciphertext, AES_BLOCK_SIZE);
    AES_cbc_encrypt(ciphertext + AES_BLOCK_SIZE, plaintext, sizeof(ciphertext), &dec_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char *key = generate_key();
    unsigned char plaintext[MAX_INPUT_SIZE];
    unsigned char ciphertext[MAX_INPUT_SIZE + AES_BLOCK_SIZE];
    unsigned char decryptedtext[MAX_INPUT_SIZE];

    // Input plaintext from user
    printf("Enter a plaintext message (max %d characters): ", MAX_INPUT_SIZE);
    fgets((char *)plaintext, MAX_INPUT_SIZE, stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // Remove newline character

    // Encrypt the plaintext
    encrypt(key, plaintext, ciphertext);
    printf("Encrypted message (in hex): ");
    for (int i = 0; i < sizeof(plaintext) + AES_BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(key, ciphertext, decryptedtext);
    printf("Decrypted message: %s\n", decryptedtext);

    // Clean up
    free(key);
    return 0;
}