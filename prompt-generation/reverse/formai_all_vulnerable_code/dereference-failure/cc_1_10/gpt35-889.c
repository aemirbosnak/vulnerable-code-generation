//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: minimalist
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTR(x,n) ((x) >> (n) | (x) << (32 - (n)))
#define ROTL(x,n) ((x) << (n) | (x) >> (32 - (n)))

#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define SHR(x,n) ((x) >> (n))
#define S0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define S1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

#define BSWAP(x) (((x) << 24) | (((x) << 8) & 0xff0000) | \
                  (((x) >> 8) & 0xff00) | ((x) >> 24))

#define SHA256_BLOCK_SIZE 64

typedef struct {
    uint32_t total[2];
    uint32_t state[8];
    uint8_t buffer[SHA256_BLOCK_SIZE];
} sha256_ctx;

void sha256_transform(sha256_ctx *ctx, const uint8_t *data) {
    uint32_t a, b, c, d, e, f, g, h, t1, t2, i, m[64];

    for (i = 0; i < 16; i++)
        m[i] = BSWAP(*(uint32_t *)(data + i * 4));
    for (; i < 64; i++)
        m[i] = S1(m[i - 2]) + m[i - 7] + S0(m[i - 15]) + m[i - 16];

    a = ctx->state[0], b = ctx->state[1], c = ctx->state[2], d = ctx->state[3];
    e = ctx->state[4], f = ctx->state[5], g = ctx->state[6], h = ctx->state[7];

    for (i = 0; i < 64; i++) {
        t1 = h + CH(e, f, g) + S1(e) + m[i] + i;
        t2 = MAJ(a, b, c) + S0(a);
        h = g, g = f, f = e, e = d + t1;
        d = c, c = b, b = a, a = t1 + t2;
    }

    ctx->state[0] += a, ctx->state[1] += b, ctx->state[2] += c, ctx->state[3] += d;
    ctx->state[4] += e, ctx->state[5] += f, ctx->state[6] += g, ctx->state[7] += h;
}

void sha256_init(sha256_ctx *ctx) {
    memset(ctx, 0x00, sizeof(sha256_ctx));
}

void sha256_update(sha256_ctx *ctx, const uint8_t *data, size_t len) {
    uint32_t i, p, n;

    p = ctx->total[0] % SHA256_BLOCK_SIZE;
    ctx->total[0] += len, n = SHA256_BLOCK_SIZE - p;

    if (len < n) memcpy(ctx->buffer + p, data, len);
    else {
        memcpy(ctx->buffer + p, data, n);
        sha256_transform(ctx, ctx->buffer);
        for (i = n; i + SHA256_BLOCK_SIZE - 1 < len; i += SHA256_BLOCK_SIZE)
            sha256_transform(ctx, data + i);
        p = 0;
    }

    memcpy(ctx->buffer + p, data + i, len - i);
}

void sha256_final(sha256_ctx *ctx, uint8_t *hash) {
    uint32_t i, p;

    p = ctx->total[0] % SHA256_BLOCK_SIZE;
    ctx->buffer[p++] = 0x80;

    if (p > SHA256_BLOCK_SIZE - 8) {
        memset(ctx->buffer + p, 0x00, SHA256_BLOCK_SIZE - p);
        sha256_transform(ctx, ctx->buffer);
        p = 0;
    }

    memset(ctx->buffer + p, 0x00, SHA256_BLOCK_SIZE - 8 - p);
    memcpy(ctx->buffer + SHA256_BLOCK_SIZE - 8, &ctx->total[0], 4);
    memcpy(ctx->buffer + SHA256_BLOCK_SIZE - 4, &ctx->total[1], 4);
    sha256_transform(ctx, ctx->buffer);

    for (i = 0; i < 8; i++)
        *((uint32_t *)hash + i) = BSWAP(ctx->state[i]);
}

int main() {
    char message[] = "Hello, world!";
    uint8_t hash[32];
    sha256_ctx ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, message, strlen(message));
    sha256_final(&ctx, hash);

    printf("Message: %s\n", message);
    printf("SHA256 hash: ");
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}