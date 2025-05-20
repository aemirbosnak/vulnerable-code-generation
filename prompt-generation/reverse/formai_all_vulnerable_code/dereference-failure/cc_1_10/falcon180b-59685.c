//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *key, unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
    for (int i = 0; i < plaintext_len; i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, plaintext + i, BLOCK_SIZE);

        unsigned char temp[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            temp[j] = block[j] ^ key[j % KEY_SIZE];
        }

        memcpy(ciphertext + i, temp, BLOCK_SIZE);
    }
}

void decrypt(unsigned char *key, unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
    for (int i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, ciphertext + i, BLOCK_SIZE);

        unsigned char temp[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            temp[j] = block[j] ^ key[j % KEY_SIZE];
        }

        memcpy(plaintext + i, temp, BLOCK_SIZE);
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    unsigned char plaintext[] = "Hello, world!";
    int plaintext_len = strlen(plaintext);

    unsigned char ciphertext[plaintext_len];
    encrypt(key, plaintext, plaintext_len, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    unsigned char decrypted_text[plaintext_len];
    decrypt(key, ciphertext, plaintext_len, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}