//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

void encrypt(char *message, char *key) {
    int i, j;
    char *encrypted;
    encrypted = (char *)malloc(BLOCK_SIZE);
    for (i = 0; i < strlen(message); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            int key_index = j % KEY_SIZE;
            int message_index = i % BLOCK_SIZE;
            encrypted[j] = message[message_index] ^ key[key_index];
        }
        encrypted[BLOCK_SIZE - 1] = '\0';
        printf("%s\n", encrypted);
        free(encrypted);
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    char *decrypted;
    decrypted = (char *)malloc(BLOCK_SIZE);
    for (i = 0; i < strlen(message); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            int key_index = j % KEY_SIZE;
            int message_index = i % BLOCK_SIZE;
            decrypted[j] = message[message_index] ^ key[key_index];
        }
        decrypted[BLOCK_SIZE - 1] = '\0';
        printf("%s\n", decrypted);
        free(decrypted);
    }
}

int main() {
    char message[100];
    char key[100];
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}