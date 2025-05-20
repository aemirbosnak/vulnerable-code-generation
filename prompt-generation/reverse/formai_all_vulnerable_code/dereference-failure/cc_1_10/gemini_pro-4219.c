//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encryptBlock(unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key) {
    int i;
    unsigned int temp;

    for (i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
}

void decryptBlock(unsigned char *ciphertext, unsigned char *plaintext, unsigned char *key) {
    int i;
    unsigned int temp;

    for (i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
}

void encrypt(unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key, int plaintext_len) {
    int i;
    unsigned char *paddedPlaintext;

    // Pad the plaintext to a multiple of the block size
    paddedPlaintext = malloc(plaintext_len + (BLOCK_SIZE - (plaintext_len % BLOCK_SIZE)));
    memcpy(paddedPlaintext, plaintext, plaintext_len);
    memset(paddedPlaintext + plaintext_len, 0, BLOCK_SIZE - (plaintext_len % BLOCK_SIZE));

    // Encrypt each block of the plaintext
    for (i = 0; i < plaintext_len; i += BLOCK_SIZE) {
        encryptBlock(paddedPlaintext + i, ciphertext + i, key);
    }

    free(paddedPlaintext);
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext, unsigned char *key, int ciphertext_len) {
    int i;
    unsigned char *paddedCiphertext;

    // Pad the ciphertext to a multiple of the block size
    paddedCiphertext = malloc(ciphertext_len + (BLOCK_SIZE - (ciphertext_len % BLOCK_SIZE)));
    memcpy(paddedCiphertext, ciphertext, ciphertext_len);
    memset(paddedCiphertext + ciphertext_len, 0, BLOCK_SIZE - (ciphertext_len % BLOCK_SIZE));

    // Decrypt each block of the ciphertext
    for (i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
        decryptBlock(paddedCiphertext + i, plaintext + i, key);
    }

    free(paddedCiphertext);
}

int main(int argc, char *argv[]) {
    unsigned char key[KEY_SIZE] = {0};
    unsigned char plaintext[1024] = {0};
    unsigned char ciphertext[1024] = {0};
    int plaintext_len;
    int ciphertext_len;

    if (argc < 2) {
        printf("Usage: %s plaintext\n", argv[0]);
        return 1;
    }

    // Get the plaintext from the command line
    plaintext_len = strlen(argv[1]);
    strncpy(plaintext, argv[1], plaintext_len);

    // Generate a random key
    if (RAND_bytes(key, KEY_SIZE) != 1) {
        printf("Error generating random key\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext, key, plaintext_len);
    ciphertext_len = plaintext_len;

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, plaintext, key, ciphertext_len);

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}