//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 8

void encrypt(char *message, int message_length, char *key) {
    int i, j;
    char block[BLOCK_SIZE];

    for (i = 0, j = 0; i < message_length; i += BLOCK_SIZE, j++) {
        if (i + BLOCK_SIZE > message_length) {
            block[j] = '\0';
            strcat(message, block);
            break;
        }
        strncpy(block, &message[i], BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            block[k] = block[k] ^ key[k % strlen(key)];
        }
        strcat(message, block);
    }
}

void decrypt(char *message, int message_length, char *key) {
    int i, j;
    char block[BLOCK_SIZE];

    for (i = 0, j = 0; i < message_length; i += BLOCK_SIZE, j++) {
        if (i + BLOCK_SIZE > message_length) {
            block[j] = '\0';
            strcat(message, block);
            break;
        }
        strncpy(block, &message[i], BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            block[k] = block[k] ^ key[k % strlen(key)];
        }
        strcat(message, block);
    }
}

int main() {
    char message[] = "Hello, world!";
    int message_length = strlen(message);

    encrypt(message, message_length, KEY);
    printf("Encrypted message: %s\n", message);

    decrypt(message, message_length, KEY);
    printf("Decrypted message: %s\n", message);

    return 0;
}