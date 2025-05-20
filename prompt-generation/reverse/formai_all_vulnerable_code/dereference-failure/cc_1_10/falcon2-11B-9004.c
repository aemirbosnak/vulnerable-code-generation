//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 32
#define BLOCK_SIZE 16

void encrypt(char* plaintext, char* key) {
    int i, j;
    int blocks = strlen(plaintext) / BLOCK_SIZE;

    char* ciphertext = (char*) malloc(strlen(plaintext) + 1);

    for (i = 0; i < blocks; i++) {
        char* block = &plaintext[i * BLOCK_SIZE];
        for (j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i * BLOCK_SIZE + j] = block[j] ^ key[i * BLOCK_SIZE + j];
        }
    }

    ciphertext[strlen(plaintext)] = '\0';

    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char* ciphertext, char* key) {
    int i, j;
    int blocks = strlen(ciphertext) / BLOCK_SIZE;

    char* plaintext = (char*) malloc(strlen(ciphertext) + 1);

    for (i = 0; i < blocks; i++) {
        char* block = &ciphertext[i * BLOCK_SIZE];
        for (j = 0; j < BLOCK_SIZE; j++) {
            plaintext[i * BLOCK_SIZE + j] = block[j] ^ key[i * BLOCK_SIZE + j];
        }
    }

    plaintext[strlen(ciphertext)] = '\0';

    printf("Plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[100];
    char key[KEY_SIZE];
    char ciphertext[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(plaintext, key);
    decrypt(ciphertext, key);

    return 0;
}