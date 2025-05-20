//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define BLOCK_SIZE 64
#define OUTPUT_SIZE 32

typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    unsigned char buffer[BLOCK_SIZE];
} SHA256_CTX;

const uint32_t K[] = {
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

void sha256_transform(SHA256_CTX *ctx, const unsigned char data[])
{
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];
    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        m[i] = (data[j] << 24) | (data[j+1] << 16) | (data[j+2] << 8) | (data[j+3]);
    }
    for ( ; i < 64; ++i) {
        m[i] = m[i-16] + m[i-7] + ROTL(m[i-15], 7) + ROTL(m[i-15], 18);
    }
    a = ctx->state[0], b = ctx->state[1], c = ctx->state[2], d = ctx->state[3];
    e = ctx->state[4], f = ctx->state[5], g = ctx->state[6], h = ctx->state[7];
    for (i = 0; i < 64; ++i) {
        t1 = h + ROTL(e, 6) + ((e&f)^((~e)&g)) + K[i] + m[i];
        t2 = ROTL(a, 2) + ((a&b)^(a&c)^(b&c));
        h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
    }
    ctx->state[0] += a, ctx->state[1] += b, ctx->state[2] += c, ctx->state[3] += d;
    ctx->state[4] += e, ctx->state[5] += f, ctx->state[6] += g, ctx->state[7] += h;
}

void sha256_init(SHA256_CTX *ctx)
{
    ctx->count[0] = ctx->count[1] = 0;
    ctx->state[0] = 0x6a09e667, ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372, ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f, ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab, ctx->state[7] = 0x5be0cd19;
}

void sha256_update(SHA256_CTX *ctx, const unsigned char data[], size_t len)
{
    uint32_t i, index = (uint32_t)((ctx->count[0] >> 3) & 0x3f);
    if ((ctx->count[0] += (uint32_t)(len << 3)) < (len << 3)) {
        ctx->count[1]++;
    }
    ctx->count[1] += (uint32_t)(len >> 29);
    for (i = 0; i < len; ++i) {
        ctx->buffer[index++] = data[i];
        if (index == BLOCK_SIZE) {
            sha256_transform(ctx, ctx->buffer);
            index = 0;
        }
    }
}

void sha256_final(unsigned char digest[], SHA256_CTX *ctx)
{
    uint32_t i, index = (uint32_t)((ctx->count[0] >> 3) & 0x3f);
    ctx->buffer[index++] = 0x80;
    if (index > 56) {
        memset(&ctx->buffer[index], 0, 64 - index);
        sha256_transform(ctx, ctx->buffer);
        index = 0;
    }
    memset(&ctx->buffer[index], 0, 56 - index);
    ctx->buffer[56] = (unsigned char)(ctx->count[1] >> 24);
    ctx->buffer[57] = (unsigned char)(ctx->count[1] >> 16);
    ctx->buffer[58] = (unsigned char)(ctx->count[1] >> 8);
    ctx->buffer[59] = (unsigned char)(ctx->count[1]);
    ctx->buffer[60] = (unsigned char)(ctx->count[0] >> 24);
    ctx->buffer[61] = (unsigned char)(ctx->count[0] >> 16);
    ctx->buffer[62] = (unsigned char)(ctx->count[0] >> 8);
    ctx->buffer[63] = (unsigned char)(ctx->count[0]);
    sha256_transform(ctx, ctx->buffer);
    for (i = 0; i < 8; ++i) {
        digest[i*4] = (unsigned char)(ctx->state[i] >> 24);
        digest[i*4+1] = (unsigned char)(ctx->state[i] >> 16);
        digest[i*4+2] = (unsigned char)(ctx->state[i] >> 8);
        digest[i*4+3] = (unsigned char)(ctx->state[i]);
    }
}

void sha256(const unsigned char data[], size_t len, unsigned char digest[OUTPUT_SIZE])
{
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, data, len);
    sha256_final(digest, &ctx);
}

int main(int argc, char *argv[])
{
    unsigned char digest[OUTPUT_SIZE];
    int i;
    if (argc < 2) {
        printf("Usage: %s string\n", argv[0]);
        return 1;
    }
    sha256((unsigned char*)argv[1], strlen(argv[1]), digest);
    printf("sha256(");
    for (i = 1; i < argc-1; ++i) {
        printf("%s", argv[i]);
    }
    printf("%s", argv[argc-1]);
    printf(") = ");
    for (i = 0; i < ARRAY_SIZE(digest); ++i) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}