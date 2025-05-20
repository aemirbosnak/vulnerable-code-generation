//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
} context;

void init_context(context *ctx) {
    uint8_t i;
    for (i = 0; i < KEY_SIZE; i++) {
        ctx->key[i] = rand() % 256;
    }
    for (i = 0; i < BLOCK_SIZE; i++) {
        ctx->iv[i] = rand() % 256;
    }
}

void encrypt(context *ctx, uint8_t *plaintext, uint8_t *ciphertext) {
    uint8_t i, j;
    for (i = 0; i < strlen(plaintext); i++) {
        uint8_t temp = plaintext[i];
        for (j = 0; j < KEY_SIZE; j++) {
            temp = (temp + ctx->key[j]) % 256;
        }
        ciphertext[i] = temp;
    }
}

void decrypt(context *ctx, uint8_t *ciphertext, uint8_t *plaintext) {
    uint8_t i, j;
    for (i = 0; i < strlen(ciphertext); i++) {
        uint8_t temp = ciphertext[i];
        for (j = 0; j < KEY_SIZE; j++) {
            temp = (temp + ctx->key[j]) % 256;
        }
        plaintext[i] = temp;
    }
}

int main() {
    context ctx;
    uint8_t plaintext[] = "Hello, world!";
    uint8_t ciphertext[strlen(plaintext)];

    init_context(&ctx);
    encrypt(&ctx, plaintext, ciphertext);
    decrypt(&ctx, ciphertext, plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}