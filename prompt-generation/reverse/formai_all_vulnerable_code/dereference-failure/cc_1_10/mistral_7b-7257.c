//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void xor_key(unsigned char *data, unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        data[i] ^= key[i];
    }
}

void left_rotate(unsigned char *data, int shift) {
    unsigned char temp;
    for (int i = 0; i < BLOCK_SIZE - shift; i++) {
        temp = data[i];
        for (int j = i; j < i + shift; j++) {
            data[j] = data[j + 1];
        }
        data[i + shift] = temp;
    }
}

void feistel_encrypt(unsigned char *plaintext, unsigned char *key) {
    unsigned char left[BLOCK_SIZE], right[BLOCK_SIZE];

    memcpy(left, plaintext, BLOCK_SIZE);
    memcpy(right, plaintext + BLOCK_SIZE, BLOCK_SIZE);

    for (int i = 0; i < 4; i++) {
        xor_key(left, key);
        left_rotate(left, 1);
        xor_key(right, key + i * KEY_SIZE);
    }

    memcpy(plaintext, right, BLOCK_SIZE);
    memcpy(plaintext + BLOCK_SIZE, left, BLOCK_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        return 1;
    }

    unsigned char *plaintext = (unsigned char *)malloc(2 * BLOCK_SIZE);
    unsigned char *key = (unsigned char *)malloc(KEY_SIZE);

    memcpy(plaintext, argv[1], strlen(argv[1]) + 1);
    memcpy(key, argv[2], KEY_SIZE);

    unsigned char ciphertext[2 * BLOCK_SIZE];
    memset(ciphertext, 0, 2 * BLOCK_SIZE);

    feistel_encrypt(plaintext, key);

    printf("Plaintext: ");
    for (int i = 0; i < 2 * BLOCK_SIZE; i++) {
        if (i > 0 && i % BLOCK_SIZE == 0) {
            printf(" ");
        }
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    printf("Ciphertext: ");
    for (int i = 0; i < 2 * BLOCK_SIZE; i++) {
        if (i > 0 && i % BLOCK_SIZE == 0) {
            printf(" ");
        }
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    free(plaintext);
    free(key);
    free(ciphertext);

    return 0;
}