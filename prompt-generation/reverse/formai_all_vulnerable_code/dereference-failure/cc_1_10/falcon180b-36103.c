//Falcon-180B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 8
#define PADDING_CHAR '*'

void encrypt(char *message, int message_length) {
    int i, j, k;
    char buffer[BLOCK_SIZE + 1];
    char padding = PADDING_CHAR;

    for (i = 0; i < message_length; i += BLOCK_SIZE) {
        memset(buffer, 0, BLOCK_SIZE + 1);
        strncat(buffer, message + i, BLOCK_SIZE);
        strcat(buffer, &padding);

        for (j = 0; j < BLOCK_SIZE; j++) {
            message[i + j] ^= KEY[j % strlen(KEY)];
        }
    }
}

void decrypt(char *message, int message_length) {
    int i, j, k;
    char buffer[BLOCK_SIZE + 1];
    char padding = PADDING_CHAR;

    for (i = 0; i < message_length; i += BLOCK_SIZE) {
        memset(buffer, 0, BLOCK_SIZE + 1);
        strncat(buffer, message + i, BLOCK_SIZE);
        strcat(buffer, &padding);

        for (j = 0; j < BLOCK_SIZE; j++) {
            message[i + j] ^= KEY[j % strlen(KEY)];
        }
    }
}

int main() {
    char message[100] = "This is a secret message";
    int message_length = strlen(message);

    printf("Original message: %s\n", message);
    encrypt(message, message_length);
    printf("Encrypted message: %s\n", message);
    decrypt(message, message_length);
    printf("Decrypted message: %s\n", message);

    return 0;
}