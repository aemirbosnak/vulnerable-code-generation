//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void xor_fish_keygen(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = rand() % 256;
        printf("Key[%d] = %02X\n", i, key[i]);
    }
}

void xor_fish_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        int block_len = i + BLOCK_SIZE < strlen(plaintext) ? BLOCK_SIZE : strlen(plaintext) - i;

        for (int j = 0; j < block_len; ++j) {
            ciphertext[i + j] = plaintext[i + j] ^ key[j % KEY_SIZE];
        }
    }
}

void xor_fish_decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i += BLOCK_SIZE) {
        int block_len = i + BLOCK_SIZE < strlen(ciphertext) ? BLOCK_SIZE : strlen(ciphertext) - i;

        for (int j = 0; j < block_len; ++j) {
            plaintext[i + j] = ciphertext[i + j] ^ key[j % KEY_SIZE];
        }
    }
}

int main() {
    unsigned char plaintext[] = "I love you but I must confess,\n"
                                 "I've fallen in love with another.\n";

    unsigned char *key = malloc(KEY_SIZE);
    xor_fish_keygen(key);

    unsigned char ciphertext[strlen(plaintext) + 1];
    unsigned char decrypted[strlen(plaintext) + 1];

    xor_fish_encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < strlen(ciphertext); ++i) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    xor_fish_decrypt(ciphertext, key, decrypted);

    printf("Decrypted: %s\n", decrypted);

    free(key);

    return 0;
}