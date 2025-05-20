//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HASH_SIZE 32
#define BLOCK_SIZE 64

typedef struct hash_ctx {
    unsigned char state[HASH_SIZE];
    unsigned int length;
    unsigned int index;
} hash_ctx;

void hash_init(hash_ctx *ctx) {
    ctx->index = 0;
    ctx->length = 0;
    memset(ctx->state, 0, HASH_SIZE);
}

void hash_update(hash_ctx *ctx, const unsigned char *data, unsigned int len) {
    const unsigned char *end = data + len;
    while (data < end) {
        ctx->state[ctx->index] ^= *data;
        ctx->index = (ctx->index + 1) % HASH_SIZE;
        ctx->length += 1;
        if (ctx->index == 0) {
            ctx->state[ctx->index] ^= (unsigned char)time(NULL);
        }
        data++;
    }
}

void hash_final(hash_ctx *ctx, unsigned char *digest) {
    const unsigned char *padding = (const unsigned char *)"\200";
    unsigned int padlen = (BLOCK_SIZE - ctx->length % BLOCK_SIZE) % BLOCK_SIZE;
    hash_update(ctx, padding, padlen);
    hash_update(ctx, (const unsigned char *)"\000", 1);
    memcpy(digest, ctx->state, HASH_SIZE);
}

int main() {
    hash_ctx ctx;
    hash_init(&ctx);
    const unsigned char *data = "Hello, world!";
    unsigned int len = strlen(data);
    hash_update(&ctx, (const unsigned char *)data, len);
    unsigned char digest[HASH_SIZE];
    hash_final(&ctx, digest);
    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}