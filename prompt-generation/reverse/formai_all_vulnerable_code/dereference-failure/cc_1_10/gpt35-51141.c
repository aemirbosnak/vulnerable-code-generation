//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))

#define FINALIZER_MIX_CONSTANT 0x9e3779b9

#define FINALIZER_MIX_CONSTANT_2 0xb7e15163

typedef struct {
    uint32_t h[8];
    uint32_t total_len;
    uint32_t len;
    uint8_t block[128];
} sha256_ctx;

static const uint32_t k[64] = {
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

void sha256_transform(sha256_ctx *ctx, const uint8_t *data) {
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    for (i = 0; i < 16; i++) {
        j = i * 4;
        m[i] = (data[j] << 24) | (data[j + 1] << 16) |
               (data[j + 2] << 8) | data[j + 3];
    }

    for (; i < 64; i++) {
        m[i] = m[i - 16] + m[i - 7] + ROTL(m[i - 15], 7) +
               ROTL(m[i - 15], 18);
    }

    a = ctx->h[0];
    b = ctx->h[1];
    c = ctx->h[2];
    d = ctx->h[3];
    e = ctx->h[4];
    f = ctx->h[5];
    g = ctx->h[6];
    h = ctx->h[7];

    for (i = 0; i < 64; i++) {
        t1 = h + ROTL(e, 6) + ((e & f) ^ ((~e) & g)) +
             k[i] + m[i];
        t2 = ROTL(a, 2) + ((a & b) ^ (a & c) ^ (b & c));

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->h[0] += a;
    ctx->h[1] += b;
    ctx->h[2] += c;
    ctx->h[3] += d;
    ctx->h[4] += e;
    ctx->h[5] += f;
    ctx->h[6] += g;
    ctx->h[7] += h;
}

void sha256_init(sha256_ctx *ctx) {
    ctx->h[0] = 0x6a09e667;
    ctx->h[1] = 0xbb67ae85;
    ctx->h[2] = 0x3c6ef372;
    ctx->h[3] = 0xa54ff53a;
    ctx->h[4] = 0x510e527f;
    ctx->h[5] = 0x9b05688c;
    ctx->h[6] = 0x1f83d9ab;
    ctx->h[7] = 0x5be0cd19;

    ctx->total_len = 0;
    ctx->len = 0;
}

void sha256_update(sha256_ctx *ctx, const uint8_t *data, size_t len) {
    size_t i;

    for (i = 0; i < len; i++) {
        ctx->block[ctx->len++] = data[i];
        if (ctx->len == 64) {
            sha256_transform(ctx, ctx->block);
            ctx->total_len += 512;
            ctx->len = 0;
        }
    }
}

void sha256_final(sha256_ctx *ctx, uint8_t *hash) {
    uint32_t i;

    i = ctx->len;

    /* Pad whatever is left in the buffer. */
    if (ctx->len < 56) {
        ctx->block[i++] = 0x80;
        while (i < 56) ctx->block[i++] = 0x00;
    } else {
        ctx->block[i++] = 0x80;
        while (i < 64) ctx->block[i++] = 0x00;
        sha256_transform(ctx, ctx->block);
        memset(ctx->block, 0, 56);
    }

    /* Append to the padding the total message's length in bits and transform. */
    ctx->total_len += ctx->len * 8;
    ctx->block[63] = ctx->total_len;
    ctx->block[62] = ctx->total_len >> 8;
    ctx->block[61] = ctx->total_len >> 16;
    ctx->block[60] = ctx->total_len >> 24;
    ctx->block[59] = 0;
    ctx->block[58] = 0;
    ctx->block[57] = 0;
    ctx->block[56] = 0;
    sha256_transform(ctx, ctx->block);

    /* Since this implementation uses little endian byte ordering and MD uses big endian,
       reverse all the bytes when copying the final state to the output hash. */
    for (i = 0; i < 4; ++i) {
        hash[i] = (ctx->h[0] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 4] = (ctx->h[1] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 8] = (ctx->h[2] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 12] = (ctx->h[3] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 16] = (ctx->h[4] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 20] = (ctx->h[5] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 24] = (ctx->h[6] >> (24 - i * 8)) & 0x000000ff;
        hash[i + 28] = (ctx->h[7] >> (24 - i * 8)) & 0x000000ff;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    sha256_ctx ctx;
    uint8_t hash[32];

    sha256_init(&ctx);
    sha256_update(&ctx, (uint8_t *) argv[1], strlen(argv[1]));
    sha256_final(&ctx, hash);

    printf("SHA-256 hash of '%s': \n", argv[1]);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}