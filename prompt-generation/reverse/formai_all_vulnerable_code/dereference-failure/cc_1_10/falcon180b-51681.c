//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: statistical
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

void encrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE && i + j < strlen(plaintext); j++) {
            ciphertext[i + j] = plaintext[i + j] ^ key[j];
        }
    }
}

void decrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *plaintext) {
    for (int i = 0; i < strlen(ciphertext); i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE && i + j < strlen(ciphertext); j++) {
            plaintext[i + j] = ciphertext[i + j] ^ key[j];
        }
    }
}

int main() {
    unsigned char key[KEY_SIZE];
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