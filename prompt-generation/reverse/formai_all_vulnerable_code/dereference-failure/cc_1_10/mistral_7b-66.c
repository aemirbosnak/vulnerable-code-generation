//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 16

char key[KEY_SIZE];

void setKey(char *k) {
    strncpy(key, k, KEY_SIZE);
}

void leftRotate(char *str, int num) {
    char temp;
    for (int i = 0; i < num; i++) {
        temp = *(str);
        for (int j = 0; j < strlen(str) - 1; j++) {
            *(str + j) = *(str + j + 1);
        }
        *(str + strlen(str) - 1) = temp;
    }
}

void customEncrypt(char *plaintext, char *ciphertext) {
    int blockIndex = 0;
    for (int i = 0; i < strlen(plaintext) / BLOCK_SIZE * BLOCK_SIZE; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, plaintext + i, BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[(blockIndex + j) % KEY_SIZE];
        }
        memcpy(ciphertext + i, block, BLOCK_SIZE);
        blockIndex++;
    }
}

void customDecrypt(char *ciphertext, char *plaintext) {
    int blockIndex = 0;
    for (int i = 0; i < strlen(ciphertext) / BLOCK_SIZE * BLOCK_SIZE; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, ciphertext + i, BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[(blockIndex + j) % KEY_SIZE];
        }
        memcpy(plaintext + i, block, BLOCK_SIZE);
        blockIndex++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    setKey("customkey12345");

    char plaintext[100];
    strcpy(plaintext, argv[1]);

    char ciphertext[100];
    char decrypted[100];

    customEncrypt(plaintext, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    customDecrypt(ciphertext, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}