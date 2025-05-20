//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 32
#define BLOCK_SIZE 16

unsigned char key[KEY_SIZE];
unsigned char iv[BLOCK_SIZE];

void encrypt(unsigned char *plaintext, unsigned char *ciphertext, int length) {
    int i;
    for (i = 0; i < length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext, int length) {
    int i;
    for (i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    // Generate a random key
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    // Generate a random IV
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = rand() % 256;
    }

    // Plaintext to encrypt
    unsigned char plaintext[] = "Hello, world!";

    // Encrypted ciphertext
    unsigned char ciphertext[strlen(plaintext)];

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext, strlen(plaintext));

    // Decrypt the ciphertext
    unsigned char decryptedtext[strlen(plaintext)];
    decrypt(ciphertext, decryptedtext, strlen(ciphertext));

    // Print the decrypted plaintext
    printf("%s", decryptedtext);

    return 0;
}