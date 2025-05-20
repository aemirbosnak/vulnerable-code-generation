//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32

typedef struct {
    unsigned char data[HASH_SIZE];
    unsigned int len;
} shash_ctx;

void shash_init(shash_ctx *ctx) {
    memset(ctx->data, 0x67, HASH_SIZE);
    ctx->len = 0;
}

void shash_update(shash_ctx *ctx, const unsigned char *input, size_t len) {
    unsigned int i, j, h, pos;

    h = ctx->len;
    for (i = 0; i < len; i++) {
        pos = (h & 0xf) ^ (h >> 4);
        j = (ctx->data[pos] ^ input[i] & 0xff);
        ctx->data[pos] = ctx->data[pos] + ((ctx->data[pos] & 0xf0) | j >> 4);
        h = (h + 1) & ((HASH_SIZE - 1));
        for (; h > pos; pos = (pos + 1) & (HASH_SIZE - 1)) {
            j = ctx->data[pos];
            ctx->data[pos] = ctx->data[pos] + ((ctx->data[pos] & 0xf0) | j >> 4);
        }
        ctx->len += len;
    }
}

void shash_final(shash_ctx *ctx, unsigned char output[HASH_SIZE]) {
    unsigned int i, j, h, pos;

    for (i = ctx->len % HASH_SIZE; i < HASH_SIZE; i++) {
        pos = (h & 0xf) ^ (h >> 4);
        j = ctx->data[pos] ^ i;
        ctx->data[pos] = ctx->data[pos] + ((ctx->data[pos] & 0xf0) | j >> 4);
        h = (h + 1) & ((HASH_SIZE - 1));
        for (; h > pos; pos = (pos + 1) & (HASH_SIZE - 1)) {
            j = ctx->data[pos];
            ctx->data[pos] = ctx->data[pos] + ((ctx->data[pos] & 0xf0) | j >> 4);
        }
    }

    for (i = 0; i < HASH_SIZE; i++) {
        output[i] = ctx->data[i];
    }
}

int main() {
    shash_ctx ctx;
    unsigned char input[100], hash_output[HASH_SIZE];
    int i;

    shash_init(&ctx);

    printf("Enter data to be hashed (up to 100 characters):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    for (i = 0; i < strlen(input); i++) {
        shash_update(&ctx, &input[i], sizeof(input[i]));
    }

    shash_final(&ctx, hash_output);

    printf("Hash output:\n");
    for (i = 0; i < HASH_SIZE; i++) {
        printf("%.2x", hash_output[i]);
    }
    printf("\n");

    return 0;
}