//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the encryption key
#define KEY "MySuperSecretKey"

// Define the block size
#define BLOCK_SIZE 16

// Function to encrypt a block of data
void encrypt_block(unsigned char *block, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

// Function to decrypt a block of data
void decrypt_block(unsigned char *block, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

// Function to encrypt a stream of data
void encrypt_stream(unsigned char *data, unsigned int length, unsigned char *key) {
    for (int i = 0; i < length; i += BLOCK_SIZE) {
        encrypt_block(data + i, key);
    }
}

// Function to decrypt a stream of data
void decrypt_stream(unsigned char *data, unsigned int length, unsigned char *key) {
    for (int i = 0; i < length; i += BLOCK_SIZE) {
        decrypt_block(data + i, key);
    }
}

// Function to generate a random key
void generate_key(unsigned char *key) {
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Main function
int main() {
    // Plaintext to be encrypted
    char plaintext[] = "Hello, world!";

    // Generate a random key
    unsigned char key[BLOCK_SIZE];
    generate_key(key);

    // Encrypt the plaintext
    unsigned char ciphertext[strlen(plaintext)];
    encrypt_stream(ciphertext, strlen(plaintext), key);

    // Decrypt the ciphertext
    unsigned char decryptedtext[strlen(plaintext)];
    decrypt_stream(decryptedtext, strlen(plaintext), key);

    // Print the plaintext, ciphertext, and decryptedtext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decryptedtext: %s\n", decryptedtext);

    return 0;
}