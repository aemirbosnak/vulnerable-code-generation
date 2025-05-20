//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    char iv[BLOCK_SIZE];
} encryption_ctx;

void init_ctx(encryption_ctx *ctx) {
    memset(ctx->key, 0, KEY_SIZE);
    memset(ctx->iv, 0, BLOCK_SIZE);
}

void encrypt(encryption_ctx *ctx, char *plaintext) {
    int i, j, k;
    char *ciphertext = malloc(strlen(plaintext) * 2);

    for (i = 0; i < strlen(plaintext); i++) {
        j = plaintext[i] - 'a';
        k = (j + 1) % 26;
        ciphertext[i * 2] = k + 'a';
        ciphertext[i * 2 + 1] = k + 'a';
    }

    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(encryption_ctx *ctx, char *ciphertext) {
    int i, j, k;
    char *plaintext = malloc(strlen(ciphertext) * 2);

    for (i = 0; i < strlen(ciphertext); i++) {
        j = ciphertext[i] - 'a';
        k = (j - 1) % 26;
        plaintext[i * 2] = k + 'a';
        plaintext[i * 2 + 1] = k + 'a';
    }

    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    encryption_ctx ctx;
    char plaintext[] = "Hello, world!";

    init_ctx(&ctx);
    encrypt(&ctx, plaintext);
    decrypt(&ctx, plaintext);

    return 0;
}