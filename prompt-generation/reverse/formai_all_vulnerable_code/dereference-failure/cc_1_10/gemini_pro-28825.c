//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *plaintext;
    char *key;
    char *ciphertext;
} EncryptionContext;

EncryptionContext *init_context(char *plaintext, char *key) {
    EncryptionContext *ctx = malloc(sizeof(EncryptionContext));
    ctx->plaintext = strdup(plaintext);
    ctx->key = strdup(key);
    ctx->ciphertext = malloc(strlen(plaintext) + 1);
    return ctx;
}

void free_context(EncryptionContext *ctx) {
    free(ctx->plaintext);
    free(ctx->key);
    free(ctx->ciphertext);
    free(ctx);
}

int encrypt(EncryptionContext *ctx) {
    int i, j, k;
    char *plaintext = ctx->plaintext;
    char *key = ctx->key;
    char *ciphertext = ctx->ciphertext;

    for (i = 0, j = 0, k = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ key[j++];
        if (j == strlen(key)) {
            j = 0;
            key[k++] = ciphertext[i];
        }
    }
    ciphertext[i] = '\0';

    return 0;
}

int decrypt(EncryptionContext *ctx) {
    int i, j, k;
    char *ciphertext = ctx->ciphertext;
    char *key = ctx->key;
    char *plaintext = ctx->plaintext;

    for (i = 0, j = 0, k = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] ^ key[j++];
        if (j == strlen(key)) {
            j = 0;
            key[k++] = plaintext[i];
        }
    }
    plaintext[i] = '\0';

    return 0;
}

int main() {
    char *plaintext = "Hello, world!";
    char *key = "secret";
    EncryptionContext *ctx = init_context(plaintext, key);

    encrypt(ctx);
    printf("Ciphertext: %s\n", ctx->ciphertext);

    decrypt(ctx);
    printf("Plaintext: %s\n", ctx->plaintext);

    free_context(ctx);

    return 0;
}