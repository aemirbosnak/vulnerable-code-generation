//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void generate_key(unsigned char *key) {
    time_t now;
    time(&now);
    srand(now);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    unsigned char plaintext[BLOCK_SIZE] = "Hello, world!";
    unsigned char ciphertext[BLOCK_SIZE];

    encrypt(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}