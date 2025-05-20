//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define BYTE_SIZE 8
#define KEY_SIZE 32

void encrypt(char *plaintext, char *key, char *ciphertext) {
    // Convert plaintext and key to bytes
    char *plaintextBytes = (char*)malloc(BLOCK_SIZE);
    char *keyBytes = (char*)malloc(KEY_SIZE);
    char *ciphertextBytes = (char*)malloc(BLOCK_SIZE);
    memset(plaintextBytes, 0, BLOCK_SIZE);
    memset(keyBytes, 0, KEY_SIZE);
    memset(ciphertextBytes, 0, BLOCK_SIZE);

    // Convert plaintext and key to bytes
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintextBytes[i % BLOCK_SIZE] = plaintext[i];
        keyBytes[i % KEY_SIZE] = key[i];
    }

    // Initialize XOR operation
    char xorResult = 0;

    // Encrypt plaintext bytes using XOR operation with key bytes
    for (int i = 0; i < BLOCK_SIZE; i++) {
        xorResult ^= plaintextBytes[i];
        ciphertextBytes[i] = xorResult ^ keyBytes[i % KEY_SIZE];
    }

    // Convert ciphertext bytes back to characters
    int ciphertextLength = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertextLength++;
        ciphertext[ciphertextLength] = ciphertextBytes[i];
    }

    // Free allocated memory
    free(plaintextBytes);
    free(keyBytes);
    free(ciphertextBytes);
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    // Convert ciphertext and key to bytes
    char *ciphertextBytes = (char*)malloc(BLOCK_SIZE);
    char *keyBytes = (char*)malloc(KEY_SIZE);
    char *plaintextBytes = (char*)malloc(BLOCK_SIZE);
    memset(ciphertextBytes, 0, BLOCK_SIZE);
    memset(keyBytes, 0, KEY_SIZE);
    memset(plaintextBytes, 0, BLOCK_SIZE);

    // Convert ciphertext and key to bytes
    for (int i = 0; i < strlen(ciphertext); i++) {
        ciphertextBytes[i % BLOCK_SIZE] = ciphertext[i];
        keyBytes[i % KEY_SIZE] = key[i];
    }

    // Initialize XOR operation
    char xorResult = 0;

    // Decrypt ciphertext bytes using XOR operation with key bytes
    for (int i = 0; i < BLOCK_SIZE; i++) {
        xorResult ^= ciphertextBytes[i];
        plaintextBytes[i] = xorResult ^ keyBytes[i % KEY_SIZE];
    }

    // Convert plaintext bytes back to characters
    int plaintextLength = 0;
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintextLength++;
        plaintext[plaintextLength] = plaintextBytes[i];
    }

    // Free allocated memory
    free(ciphertextBytes);
    free(keyBytes);
    free(plaintextBytes);
}

int main() {
    // Example usage
    char plaintext[] = "Hello, World!";
    char key[] = "secret";
    char ciphertext[BLOCK_SIZE];
    char plaintext2[BLOCK_SIZE];

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext2);
    printf("Plaintext: %s\n", plaintext2);

    return 0;
}