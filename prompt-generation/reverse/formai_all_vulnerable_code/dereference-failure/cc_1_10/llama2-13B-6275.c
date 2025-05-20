//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
} aes_context;

void aes_init(aes_context *ctx, const uint8_t *key, size_t key_len) {
    // Generate a random IV
    ctx->iv[0] = (uint8_t)rand();
    ctx->iv[1] = (uint8_t)rand();
    ctx->iv[2] = (uint8_t)rand();
    ctx->iv[3] = (uint8_t)rand();
    ctx->key[0] = key[0];
    ctx->key[1] = key[1];
    ctx->key[2] = key[2];
    ctx->key[3] = key[3];
}

void aes_encrypt(aes_context *ctx, const uint8_t *plaintext, uint8_t *ciphertext) {
    size_t i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp = plaintext[i] ^ ctx->iv[i];
        for (j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i * BLOCK_SIZE + j] = temp ^ ctx->key[j];
        }
    }
}

void aes_decrypt(aes_context *ctx, const uint8_t *ciphertext, uint8_t *plaintext) {
    size_t i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp = ciphertext[i] ^ ctx->iv[i];
        for (j = 0; j < BLOCK_SIZE; j++) {
            plaintext[i * BLOCK_SIZE + j] = temp ^ ctx->key[j];
        }
    }
}

int main() {
    uint8_t key[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t plaintext[] = "Hello, World!";
    uint8_t ciphertext[BLOCK_SIZE];
    aes_context ctx;

    aes_init(&ctx, key, sizeof(key));
    aes_encrypt(&ctx, plaintext, ciphertext);
    printf("Encrypted message: ");
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    aes_decrypt(&ctx, ciphertext, plaintext);
    printf("Decrypted message: ");
    for (size_t i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    return 0;
}