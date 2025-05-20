//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char *message;
    char *key;
} message_t;

void init_key(message_t *msg) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        msg->key[i] = (i % 2 == 0) ? 'A' : 'a';
    }
}

void encrypt(message_t *msg) {
    int i, j;
    char temp[BLOCK_SIZE];
    for (i = 0; i < strlen(msg->message); i += BLOCK_SIZE) {
        j = BLOCK_SIZE;
        while (j-- > 0) {
            temp[j] = (msg->message[i + j] + msg->key[j]) % 'Z' + 'A';
        }
        for (; j < BLOCK_SIZE; j++) {
            temp[j] = temp[j - 1];
        }
        memcpy(msg->message + i, temp, BLOCK_SIZE);
    }
}

void decrypt(message_t *msg) {
    int i, j;
    char temp[BLOCK_SIZE];
    for (i = 0; i < strlen(msg->message); i += BLOCK_SIZE) {
        j = BLOCK_SIZE;
        while (j-- > 0) {
            temp[j] = (msg->message[i + j] - temp[j]) % 'Z' + 'A';
        }
        for (; j < BLOCK_SIZE; j++) {
            temp[j] = temp[j - 1];
        }
        memcpy(msg->message + i, temp, BLOCK_SIZE);
    }
}

int main() {
    message_t msg;
    init_key(&msg);
    printf("Original message: %s\n", msg.message);
    encrypt(&msg);
    printf("Encrypted message: %s\n", msg.message);
    decrypt(&msg);
    printf("Decrypted message: %s\n", msg.message);
    return 0;
}