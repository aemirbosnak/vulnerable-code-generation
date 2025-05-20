//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_LENGTH 32
#define HASH_ALGORITHM "SHA-256"

typedef struct {
    char *message;
    size_t length;
} hash_context;

void hash_init(hash_context *ctx) {
    ctx->message = NULL;
    ctx->length = 0;
}

void hash_update(hash_context *ctx, const char *data, size_t len) {
    ctx->message = realloc(ctx->message, ctx->length + len + 1);
    strncat(ctx->message, data, len);
    ctx->length += len;
}

void hash_final(hash_context *ctx, char *digest) {
    char *message = ctx->message;
    size_t length = ctx->length;

    ctx->message = NULL;
    ctx->length = 0;

    EVP_Digest((unsigned char *)message, (unsigned int)length, (unsigned char *)digest, NULL, EVP_sha256(), NULL);
}

int main() {
    hash_context ctx;
    char digest[HASH_LENGTH];

    hash_init(&ctx);
    hash_update(&ctx, "The quick brown fox jumps over the lazy dog", 32);
    hash_update(&ctx, "123456789012345678901234567890", 32);
    hash_update(&ctx, "This is a test", 13);
    hash_final(&ctx, digest);

    printf("SHA-256 Digest: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", digest[i]);
    }

    return 0;
}