//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_LENGTH];
    char iv[BLOCK_SIZE];
} AES_CTX;

void encrypt(AES_CTX *ctx, char *data, int data_len) {
    int i, j;
    char state[BLOCK_SIZE];
    for (i = 0; i < data_len; i += BLOCK_SIZE) {
        memcpy(state, data + i, BLOCK_SIZE);
        for (j = 0; j < BLOCK_SIZE; j++) {
            state[j] ^= ctx->iv[j];
        }
        AES_encrypt(state, ctx->key);
        memcpy(data + i, state, BLOCK_SIZE);
    }
}

void decrypt(AES_CTX *ctx, char *data, int data_len) {
    int i, j;
    char state[BLOCK_SIZE];
    for (i = 0; i < data_len; i += BLOCK_SIZE) {
        memcpy(state, data + i, BLOCK_SIZE);
        AES_decrypt(state, ctx->key);
        for (j = 0; j < BLOCK_SIZE; j++) {
            state[j] ^= ctx->iv[j];
        }
        memcpy(data + i, state, BLOCK_SIZE);
    }
}

int main() {
    char key[KEY_LENGTH] = "mysecretkey12345";
    char iv[BLOCK_SIZE] = "1234567890123456";
    AES_CTX ctx;
    memcpy(ctx.key, key, KEY_LENGTH);
    memcpy(ctx.iv, iv, BLOCK_SIZE);

    char data[] = "Hello, world!";
    int data_len = strlen(data);

    encrypt(&ctx, data, data_len);

    printf("Encrypted data: %s\n", data);

    decrypt(&ctx, data, data_len);

    printf("Decrypted data: %s\n", data);

    return 0;
}