//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_SIZE];
    int keySize;
    char iv[MAX_BLOCK_SIZE];
    int ivSize;
} BlockCipher;

void generateRandomKey(char* key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size - 1] = '\0';
}

void generateRandomIV(char* iv, int size) {
    for (int i = 0; i < size; i++) {
        iv[i] = rand() % 26 + 'a';
    }
    iv[size - 1] = '\0';
}

void encryptBlock(BlockCipher* cipher, char* plaintext, char* ciphertext) {
    int keySize = strlen(cipher->key);
    int ivSize = strlen(cipher->iv);
    int blockSize = strlen(plaintext);

    if (blockSize > MAX_BLOCK_SIZE) {
        printf("Error: Block size too large.\n");
        exit(1);
    }

    for (int i = 0; i < blockSize; i++) {
        ciphertext[i] = plaintext[i] ^ cipher->key[i % keySize];
    }
}

void decryptBlock(BlockCipher* cipher, char* ciphertext, char* plaintext) {
    int keySize = strlen(cipher->key);
    int ivSize = strlen(cipher->iv);
    int blockSize = strlen(ciphertext);

    if (blockSize > MAX_BLOCK_SIZE) {
        printf("Error: Block size too large.\n");
        exit(1);
    }

    for (int i = 0; i < blockSize; i++) {
        plaintext[i] = ciphertext[i] ^ cipher->key[i % keySize];
    }
}

int main() {
    BlockCipher cipher;
    generateRandomKey(cipher.key, MAX_KEY_SIZE);
    generateRandomIV(cipher.iv, MAX_BLOCK_SIZE);

    char plaintext[] = "Hello, world!";
    char ciphertext[MAX_BLOCK_SIZE];
    char decryptedText[MAX_BLOCK_SIZE];

    int plaintextSize = strlen(plaintext);
    int ciphertextSize = strlen(ciphertext);

    if (plaintextSize > MAX_BLOCK_SIZE) {
        printf("Error: Plaintext too large.\n");
        exit(1);
    }

    encryptBlock(&cipher, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decryptBlock(&cipher, ciphertext, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}