//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

void xor(char* data, int size, unsigned char key) {
    for (int i = 0; i < size; i++) {
        data[i] ^= key;
    }
}

void encryptDecrypt(char* data, int size, unsigned char key, int mode) {
    if (mode == ENCRYPT) {
        xor(data, size, key);
    } else if (mode == DECRYPT) {
        xor(data, size, key);
    } else {
        printf("Invalid mode. Please specify ENCRYPT or DECRYPT.\n");
    }
}

char* generateRandomKey(int size) {
    char* key = malloc(size);
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256;
    }
    return key;
}

int main() {
    char* plaintext = "Hello, world!";
    unsigned char key = 0x42;
    int plaintextSize = strlen(plaintext);

    // Encrypt the plaintext
    encryptDecrypt(plaintext, plaintextSize, key, ENCRYPT);
    printf("Encrypted text: %s\n", plaintext);

    // Decrypt the encrypted text
    encryptDecrypt(plaintext, plaintextSize, key, DECRYPT);
    printf("Decrypted text: %s\n", plaintext);

    // Generate a random key
    int keySize = 16;
    char* randomKey = generateRandomKey(keySize);

    // Encrypt the plaintext with the random key
    encryptDecrypt(plaintext, plaintextSize, randomKey, ENCRYPT);
    printf("Encrypted text with random key: %s\n", plaintext);

    // Decrypt the encrypted text with the random key
    encryptDecrypt(plaintext, plaintextSize, randomKey, DECRYPT);
    printf("Decrypted text with random key: %s\n", plaintext);

    return 0;
}