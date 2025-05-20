//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    int key[KEY_SIZE];
    int block[BLOCK_SIZE];
} cipher_context;

void init_key(cipher_context *ctx, const char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        ctx->key[i] = (int)key[i];
    }
}

void encrypt(cipher_context *ctx, const char *plaintext) {
    int i, j, k;
    for (i = 0; i < BLOCK_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = (ctx->key[j] + plaintext[i]) % 26;
            ctx->block[i] = k;
        }
    }
}

void decrypt(cipher_context *ctx, const char *ciphertext) {
    int i, j, k;
    for (i = 0; i < BLOCK_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = (ctx->key[j] + ciphertext[i]) % 26;
            ctx->block[i] = k;
        }
    }
}

int main() {
    cipher_context ctx;
    init_key(&ctx, "THE QUICK BROWN FOX");
    char plaintext[] = "HELLO WORLD";
    char ciphertext[BLOCK_SIZE];

    encrypt(&ctx, plaintext);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = ctx.block[i];
    }

    decrypt(&ctx, ciphertext);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", ctx.block[i]);
    }
    return 0;
}