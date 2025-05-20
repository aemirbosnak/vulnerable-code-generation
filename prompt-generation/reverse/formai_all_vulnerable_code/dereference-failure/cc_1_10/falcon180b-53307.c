//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE] = { 0 };
        strncpy(block, plaintext + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            ciphertext[j + k] = block[k] ^ key[k];
        }
    }
}

void decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE] = { 0 };
        strncpy(block, ciphertext + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            plaintext[j + k] = block[k] ^ key[k];
        }
    }
}

int main() {
    unsigned char key[KEY_SIZE] = { 0 };
    generate_key(key);

    unsigned char plaintext[] = "Hello, world!";
    unsigned char ciphertext[strlen(plaintext)];

    encrypt(key, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    unsigned char decrypted_text[strlen(plaintext)];
    decrypt(key, ciphertext, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}