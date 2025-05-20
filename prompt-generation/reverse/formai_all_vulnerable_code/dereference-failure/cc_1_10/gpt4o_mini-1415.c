//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 128 // AES key length in bits
#define AES_BLOCK_SIZE 16   // AES block size in bytes

void handleErrors() {
    fprintf(stderr, "An error occurred!\n");
    exit(EXIT_FAILURE);
}

void generateAESKey(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) {
        handleErrors();
    }
}

void encrypt(unsigned char *input, unsigned char *output, unsigned char *key) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &enc_key) < 0) {
        handleErrors();
    }
    
    AES_encrypt(input, output, &enc_key);
}

void decrypt(unsigned char *input, unsigned char *output, unsigned char *key) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &dec_key) < 0) {
        handleErrors();
    }
    
    AES_decrypt(input, output, &dec_key);
}

void printByteArray(unsigned char *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", array[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8]; // Key for encryption and decryption
    unsigned char iv[AES_BLOCK_SIZE];       // Initialization vector
    unsigned char input[AES_BLOCK_SIZE];    // Input data (must be AES_BLOCK_SIZE)
    unsigned char output[AES_BLOCK_SIZE];   // Encrypted output
    unsigned char decrypted[AES_BLOCK_SIZE]; // Decrypted output

    // Initializing input data
    memcpy(input, "This is text!!", AES_BLOCK_SIZE);

    // Generate a AES key
    generateAESKey(key);
    // Generate an initialization vector
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        handleErrors();
    }

    // Display original input
    printf("Original input: ");
    printByteArray(input, AES_BLOCK_SIZE);

    // Encrypt the input
    encrypt(input, output, key);
    printf("Encrypted output: ");
    printByteArray(output, AES_BLOCK_SIZE);

    // Decrypt the output
    decrypt(output, decrypted, key);
    printf("Decrypted output: ");
    printByteArray(decrypted, AES_BLOCK_SIZE);

    return 0;
}