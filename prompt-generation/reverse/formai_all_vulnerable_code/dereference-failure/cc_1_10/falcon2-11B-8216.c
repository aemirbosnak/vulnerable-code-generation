//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encrypt(unsigned char *plaintext, unsigned char *key) {
    unsigned char *ciphertext = malloc(BLOCK_SIZE);
    unsigned char *block = ciphertext;
    unsigned char *key_block = key;
    unsigned char i;

    for (i = 0; i < BLOCK_SIZE; i++) {
        block[i] = plaintext[i] ^ key_block[i % KEY_SIZE];
        key_block += 1;
    }

    printf("Encrypted message: ");
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
}

void decrypt(unsigned char *ciphertext, unsigned char *key) {
    unsigned char *plaintext = malloc(BLOCK_SIZE);
    unsigned char *block = plaintext;
    unsigned char *key_block = key;
    unsigned char i;

    for (i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key_block[i % KEY_SIZE];
        key_block += 1;
    }

    printf("Decrypted message: ");
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    unsigned char key[KEY_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");
    printf("Plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", (unsigned char) i);
    }
    printf("\n");
    encrypt(key, key);
    printf("Encrypted message: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");
    decrypt(key, key);
    printf("Decrypted message: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", (unsigned char) i);
    }
    printf("\n");
    return 0;
}