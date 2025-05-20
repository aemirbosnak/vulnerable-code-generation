//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 64
#define HASH_SIZE 32

typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    unsigned char buffer[BLOCK_SIZE];
} SHA256_CTX;

const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6ef372f, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void initialize(SHA256_CTX *ctx);
void update(SHA256_CTX *ctx, const unsigned char *data, size_t len);
void final(SHA256_CTX *ctx, unsigned char hash[HASH_SIZE]);
void transform(SHA256_CTX *ctx, const unsigned char data[BLOCK_SIZE]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    SHA256_CTX ctx;
    unsigned char hash[HASH_SIZE];
    char *input = argv[1];

    initialize(&ctx);
    update(&ctx, (unsigned char *)input, strlen(input));
    final(&ctx, hash);

    printf("SHA-256 hash of '%s': ", input);
    for (int i = 0; i < HASH_SIZE; i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}

void initialize(SHA256_CTX *ctx) {
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
    
    ctx->count[0] = 0;
    ctx->count[1] = 0;
}

void update(SHA256_CTX *ctx, const unsigned char *data, size_t len) {
    size_t i, j;

    j = (ctx->count[0] >> 3) & 0x3F;
    if ((ctx->count[0] += (len << 3)) < (len << 3))
        ctx->count[1]++;
    ctx->count[1] += (len >> 29);

    size_t partLen = BLOCK_SIZE - j;

    if (len < partLen) {
        memcpy(&ctx->buffer[j], data, len);
        return;
    }
    memcpy(&ctx->buffer[j], data, partLen);
    transform(ctx, ctx->buffer);

    for (i = partLen; i + BLOCK_SIZE <= len; i += BLOCK_SIZE) {
        transform(ctx, &data[i]);
    }
    memcpy(ctx->buffer, &data[i], len - i);
}

void final(SHA256_CTX *ctx, unsigned char hash[HASH_SIZE]) {
    unsigned int i, j;
    unsigned char bits[8];
    size_t index, padLen;

    for (i = 0; i < 8; i++) {
        bits[i] = (ctx->count[i / 4] >> ((3 - (i % 4)) * 8)) & 0xFF;
    }

    index = (ctx->count[0] >> 3) & 0x3F;
    padLen = (index < 56) ? (56 - index) : (120 - index);
    update(ctx, (unsigned char *)"\x80", 1);
    memset(&ctx->buffer[index], 0, padLen);
    update(ctx, bits, 8);

    for (i = 0; i < 8; i++) {
        hash[i * 4] = (ctx->state[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (ctx->state[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (ctx->state[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = ctx->state[i] & 0xFF;
    }
}

void transform(SHA256_CTX *ctx, const unsigned char data[BLOCK_SIZE]) {
    uint32_t a, b, c, d, e, f, g, h, t1, t2, m[64];

    for (int i = 0; i < 16; i++) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }

    for (int i = 16; i < 64; i++) {
        m[i] = m[i - 16] + (m[i - 7]) +
               ((m[i - 15] >> 3) ^ (m[i - 15] << 13) ^ (m[i - 15] >> 10)) +
               ((m[i - 2] >> 17) ^ (m[i - 2] << 15) ^ (m[i - 2] >> 19));
    }

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    for (int i = 0; i < 64; i++) {
        t1 = h + ((e >> 6) ^ (e << 26) ^ ((e & f) ^ (~e & g))) + k[i] + m[i];
        t2 = ((a >> 2) ^ (a << 30) ^ ((a & b) ^ (a & c) ^ (b & c)));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}