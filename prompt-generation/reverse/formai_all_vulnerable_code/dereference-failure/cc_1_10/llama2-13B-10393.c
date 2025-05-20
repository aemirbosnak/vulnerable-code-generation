//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 24

void randomize(uint8_t *key, uint8_t *iv) {
    uint8_t random[KEY_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        random[i] = (uint8_t)rand();
    }
    memcpy(key, random, KEY_SIZE);
    memcpy(iv, random, KEY_SIZE);
}

void encrypt(uint8_t *plaintext, uint8_t *ciphertext, uint8_t *key, uint8_t *iv) {
    for (int i = 0; i < strlen(plaintext); i++) {
        uint8_t block = plaintext[i];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block ^= key[j];
        }
        ciphertext[i] = block;
    }
}

void decrypt(uint8_t *ciphertext, uint8_t *plaintext, uint8_t *key, uint8_t *iv) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        uint8_t block = ciphertext[i];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block ^= key[j];
        }
        plaintext[i] = block;
    }
}

int main() {
    uint8_t plaintext[] = "Hello, world!";
    uint8_t ciphertext[strlen(plaintext)];
    uint8_t key[KEY_SIZE];
    uint8_t iv[KEY_SIZE];

    randomize(key, iv);
    encrypt(plaintext, ciphertext, key, iv);
    decrypt(ciphertext, plaintext, key, iv);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}