//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 24

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
} AES_context;

void init_context(AES_context *ctx) {
    ctx->key[0] = 0x01;
    ctx->key[1] = 0x02;
    ctx->key[2] = 0x03;
    ctx->key[3] = 0x04;
    ctx->key[4] = 0x05;
    ctx->key[5] = 0x06;
    ctx->key[6] = 0x07;
    ctx->key[7] = 0x08;
    ctx->key[8] = 0x09;
    ctx->key[9] = 0x0A;
    ctx->key[10] = 0x0B;
    ctx->key[11] = 0x0C;
    ctx->key[12] = 0x0D;
    ctx->key[13] = 0x0E;
    ctx->key[14] = 0x0F;
    ctx->key[15] = 0x10;

    ctx->iv[0] = 0x01;
    ctx->iv[1] = 0x02;
    ctx->iv[2] = 0x03;
    ctx->iv[3] = 0x04;
    ctx->iv[4] = 0x05;
    ctx->iv[5] = 0x06;
    ctx->iv[6] = 0x07;
    ctx->iv[7] = 0x08;
    ctx->iv[8] = 0x09;
    ctx->iv[9] = 0x0A;
    ctx->iv[10] = 0x0B;
    ctx->iv[11] = 0x0C;
    ctx->iv[12] = 0x0D;
    ctx->iv[13] = 0x0E;
    ctx->iv[14] = 0x0F;
    ctx->iv[15] = 0x10;
}

void encrypt(AES_context *ctx, const uint8_t *plaintext, uint8_t *ciphertext) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        uint8_t temp = plaintext[i] ^ ctx->key[i % KEY_SIZE];
        ciphertext[i] = temp;
    }
}

void decrypt(AES_context *ctx, const uint8_t *ciphertext, uint8_t *plaintext) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        uint8_t temp = ciphertext[i] ^ ctx->key[i % KEY_SIZE];
        plaintext[i] = temp;
    }
}

int main() {
    AES_context ctx;
    init_context(&ctx);

    uint8_t plaintext[] = "This is a secret message!";
    uint8_t ciphertext[strlen(plaintext)];

    encrypt(&ctx, plaintext, ciphertext);

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    decrypt(&ctx, ciphertext, plaintext);

    printf("Decrypted message: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    return 0;
}