//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 64

typedef struct {
    uint32_t h1, h2, h3, h4;
    uint32_t count_low, count_high;
    uint8_t block[BLOCK_SIZE];
    uint32_t block_size;
} digest_ctx;

static const uint32_t k[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static inline uint32_t rotate_right(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

static inline uint32_t swap_uint32(uint32_t x)
{
    return ((x & 0x000000ff) << 24) |
           ((x & 0x0000ff00) << 8) |
           ((x & 0x00ff0000) >> 8) |
           ((x & 0xff000000) >> 24);
}

void sha256_transform(digest_ctx *ctx)
{
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t w[64];
    uint32_t t1, t2;
    uint32_t i;
    
    for (i = 0; i < 16; ++i)
        w[i] = swap_uint32(((uint32_t*)ctx->block)[i]);

    for (; i < 64; ++i)
        w[i] = rotate_right(w[i-2], 17) ^
               rotate_right(w[i-2], 19) ^
               (w[i-2] >> 10) ^
               w[i-7] ^
               rotate_right(w[i-15], 7) ^
               rotate_right(w[i-15], 18) ^
               (w[i-15] >> 3) ^
               w[i-16];

    a = ctx->h1;
    b = ctx->h2;
    c = ctx->h3;
    d = ctx->h4;
    e = 0;
    f = 0;
    g = 0;
    h = 0;

    for (i = 0; i < 64; ++i) {
        t1 = h + ((rotate_right(e, 6) ^ rotate_right(e, 11) ^ rotate_right(e, 25)) + ((e & f) ^ (~e & g)) + k[i] + w[i]);
        t2 = ((rotate_right(a, 2) ^ rotate_right(a, 13) ^ rotate_right(a, 22)) + ((a & b) ^ (a & c) ^ (b & c)));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->h1 += a;
    ctx->h2 += b;
    ctx->h3 += c;
    ctx->h4 += d;

    ctx->count_low += BLOCK_SIZE;
    if (ctx->count_low < BLOCK_SIZE)
        ctx->count_high++;

    memset(ctx->block, 0, BLOCK_SIZE);
    ctx->block_size = 0;
}

void sha256_init(digest_ctx *ctx)
{
    ctx->h1 = 0x6a09e667;
    ctx->h2 = 0xbb67ae85;
    ctx->h3 = 0x3c6ef372;
    ctx->h4 = 0xa54ff53a;
    ctx->count_low = 0;
    ctx->count_high = 0;
    ctx->block_size = 0;
}

void sha256_update(digest_ctx *ctx, const void *data, size_t size)
{
    const uint8_t *ptr = data;

    while (size > 0) {
        size_t block_fill = BLOCK_SIZE - ctx->block_size;
        if (size < block_fill)
            block_fill = size;

        memcpy(&ctx->block[ctx->block_size], ptr, block_fill);

        ctx->block_size += block_fill;
        ptr += block_fill;
        size -= block_fill;

        if (ctx->block_size == BLOCK_SIZE)
            sha256_transform(ctx);
    }
}

void sha256_final(digest_ctx *ctx, uint8_t *hash)
{
    size_t pad_fill;
    uint64_t bit_count_low, bit_count_high;
    uint8_t length_bytes[8];
    unsigned i;

    bit_count_low = ctx->count_low * 8;
    bit_count_high = ctx->count_high * 8;

    for (i = 0; i < 8; ++i) {
        length_bytes[i] = (uint8_t)(bit_count_low >> (56 - i * 8));
    }

    pad_fill = BLOCK_SIZE - ctx->block_size;
    if (pad_fill == 0 || pad_fill == BLOCK_SIZE) {
        pad_fill = BLOCK_SIZE;
    }

    sha256_update(ctx, "\x80", 1);

    while (ctx->block_size < pad_fill) {
        sha256_update(ctx, "\x00", 1);
    }

    sha256_update(ctx, length_bytes, 8);

    for (i = 0; i < 4; ++i) {
        hash[i] = (uint8_t)(ctx->h1 >> (24 - i * 8));
        hash[i+4] = (uint8_t)(ctx->h2 >> (24 - i * 8));
        hash[i+8] = (uint8_t)(ctx->h3 >> (24 - i * 8));
        hash[i+12] = (uint8_t)(ctx->h4 >> (24 - i * 8));
    }
}

int main(int argc, char **argv)
{
    int i;
    uint8_t hash[32];
    digest_ctx ctx;

    if (argc < 2) {
        printf("Usage: %s string\n", argv[0]);
        return 1;
    }

    sha256_init(&ctx);
    sha256_update(&ctx, argv[1], strlen(argv[1]));
    sha256_final(&ctx, hash);

    printf("Hash: ");
    for (i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}