//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
} context;

void init_context(context *ctx) {
    uint8_t *key = ctx->key;
    uint8_t *iv = ctx->iv;
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() & 0xFF;
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = rand() & 0xFF;
    }
}

void encrypt(context *ctx, uint8_t *plaintext, uint8_t *ciphertext) {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = ctx->key[i];
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = ctx->iv[i];
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp = plaintext[i] ^ iv[i];
        plaintext[i] = temp ^ key[i % KEY_SIZE];
    }
    for (int i = BLOCK_SIZE; i < strlen(plaintext); i++) {
        plaintext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i];
    }
}

int main() {
    context ctx;
    uint8_t plaintext[50];
    uint8_t ciphertext[50];

    srand(time(NULL));

    init_context(&ctx);

    // Plaintext
    for (int i = 0; i < 50; i++) {
        plaintext[i] = i % 2 == 0 ? 'a' : 'b';
    }

    // Encrypt
    encrypt(&ctx, plaintext, ciphertext);

    // Print ciphertext
    for (int i = 0; i < 50; i++) {
        printf("%c", ciphertext[i]);
    }

    return 0;
}