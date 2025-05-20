//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    char block[BLOCK_SIZE];
} encryption_ctx;

void init_ctx(encryption_ctx *ctx) {
    memset(ctx->key, 0, KEY_SIZE);
    memset(ctx->block, 0, BLOCK_SIZE);
}

void encrypt(encryption_ctx *ctx, const char *plaintext) {
    int i, j, k;
    for (i = 0; i < strlen(plaintext); i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = (i + j) % KEY_SIZE;
            ctx->block[j] = plaintext[i] ^ ctx->key[k];
        }
        memcpy(ctx->block, ctx->block + j, BLOCK_SIZE - j);
    }
}

void decrypt(encryption_ctx *ctx, const char *ciphertext) {
    int i, j, k;
    for (i = 0; i < strlen(ciphertext); i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = (i + j) % KEY_SIZE;
            ctx->block[j] = ciphertext[i] ^ ctx->key[k];
        }
        memcpy(ctx->block, ctx->block + j, BLOCK_SIZE - j);
    }
}

int main() {
    encryption_ctx ctx;
    init_ctx(&ctx);

    char plaintext[] = "Hello, World!";
    char ciphertext[strlen(plaintext) * BLOCK_SIZE];

    encrypt(&ctx, plaintext);
    memcpy(ciphertext, ctx.block, strlen(plaintext) * BLOCK_SIZE);

    decrypt(&ctx, ciphertext);

    printf("%s\n", ctx.block);

    return 0;
}