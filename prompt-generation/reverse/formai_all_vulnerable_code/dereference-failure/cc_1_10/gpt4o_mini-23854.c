//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256
#define AES_BLOCK_SIZE 16

void handleErrors() {
    fprintf(stderr, "An error occurred!\n");
    exit(EXIT_FAILURE);
}

// Function to generate a random AES key
void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) {
        handleErrors();
    }
}

// Function to encrypt the plaintext using AES
void encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &enc_key) < 0) {
        handleErrors();
    }

    unsigned char iv[AES_BLOCK_SIZE];
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        handleErrors();
    }

    memcpy(ciphertext, iv, AES_BLOCK_SIZE);  // Prepend IV to ciphertext
    AES_cbc_encrypt(plaintext, ciphertext + AES_BLOCK_SIZE, strlen((char *)plaintext), &enc_key, iv, AES_ENCRYPT);
}

// Function to decrypt the ciphertext using AES
void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &dec_key) < 0) {
        handleErrors();
    }

    unsigned char iv[AES_BLOCK_SIZE];
    memcpy(iv, ciphertext, AES_BLOCK_SIZE);  // Extract IV from ciphertext
    AES_cbc_encrypt(ciphertext + AES_BLOCK_SIZE, plaintext, strlen((char *)ciphertext) - AES_BLOCK_SIZE, &dec_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];
    generate_key(key);

    unsigned char plaintext[] = "This is a secret message!";
    unsigned char ciphertext[sizeof(plaintext) + AES_BLOCK_SIZE]; // Extra space for IV
    unsigned char decryptedtext[sizeof(plaintext)];

    printf("Original Plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted Ciphertext (hex): ");
    for (size_t i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    decryptedtext[sizeof(plaintext) - 1] = '\0';  // Null-terminate the string
    printf("Decrypted Plaintext: %s\n", decryptedtext);

    return 0;
}