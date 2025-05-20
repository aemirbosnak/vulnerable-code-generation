//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KEY_LENGTH 32
#define BLOCK_SIZE 8

void encrypt(unsigned char *plaintext, unsigned char *key) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            temp = plaintext[i + j];
            temp ^= key[(i / BLOCK_SIZE) % KEY_LENGTH] << (j * 2);
            plaintext[i + j] = temp;
        }
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *key) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < strlen(ciphertext); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            temp = ciphertext[i + j];
            temp ^= key[(i / BLOCK_SIZE) % KEY_LENGTH] >> (j * 2);
            ciphertext[i + j] = temp;
        }
    }
}

int main(int argc, char *argv[]) {
    unsigned char key[KEY_LENGTH], plaintext[100], ciphertext[100];
    int i;

    if (argc != 3) {
        printf("Usage: %s <key> <message>\n", argv[0]);
        return 1;
    }

    memcpy(key, argv[1], KEY_LENGTH);

    memcpy(plaintext, argv[2], strlen(argv[2]));

    encrypt(plaintext, key);

    printf("Encrypted message: ");
    for (i = 0; i < strlen(plaintext); i++) {
        printf("%.2x ", plaintext[i]);
    }
    printf("\n");

    decrypt(ciphertext, key);

    printf("Decrypted message: ");
    for (i = 0; i < strlen(plaintext); i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    return 0;
}