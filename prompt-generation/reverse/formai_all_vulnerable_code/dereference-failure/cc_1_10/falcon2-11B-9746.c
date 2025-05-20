//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void generateKey() {
    char key[KEY_SIZE];
    int i;

    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + rand() % 26;
    }

    printf("Generated key: %s\n", key);
}

void encrypt(char *message, char *key) {
    char block[BLOCK_SIZE];
    int i;

    for (i = 0; i < strlen(message); i += BLOCK_SIZE) {
        memcpy(block, message + i, BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[j % KEY_SIZE];
        }
        printf("%s\n", block);
    }
}

void decrypt(char *ciphertext, char *key) {
    char block[BLOCK_SIZE];
    int i;

    for (i = 0; i < strlen(ciphertext); i += BLOCK_SIZE) {
        memcpy(block, ciphertext + i, BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[j % KEY_SIZE];
        }
        printf("%s\n", block);
    }
}

int main() {
    generateKey();
    char message[100];
    printf("Enter message: ");
    scanf("%s", message);
    encrypt(message, "K3Y");
    decrypt(message, "K3Y");
    return 0;
}