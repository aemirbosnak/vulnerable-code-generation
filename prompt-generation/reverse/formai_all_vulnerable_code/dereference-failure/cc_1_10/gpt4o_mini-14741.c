//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SHA256_BLOCK_SIZE 32
#define SHA256_HASH_STRING_SIZE (SHA256_BLOCK_SIZE * 2 + 1)

typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    uint8_t buffer[64];
} SHA256_CTX;

static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76c52b44,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b6c8c2, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_init(SHA256_CTX *ctx) {
    ctx->count[0] = ctx->count[1] = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

static void sha256_transform(SHA256_CTX *ctx, const uint8_t data[]) {
    uint32_t a, b, c, d, e, f, g, h, i, j;
    uint32_t T1, T2;
    uint32_t m[64];

    for (i = 0; i < 16; ++i) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }

    for (i = 16; i < 64; ++i) {
        m[i] = m[i - 16] + (m[i - 7]) + (m[i - 15] >> 7 ^ m[i - 15] << 25) + (m[i - 2] >> 17 ^ m[i - 2] << 15);
    }

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    for (i = 0; i < 64; ++i) {
        T1 = h + (e >> 6 ^ e << 26) + ((e & f) ^ (~e & g)) + k[i] + m[i];
        T2 = (a >> 2 ^ a << 30) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
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

void sha256_update(SHA256_CTX *ctx, const uint8_t *data, size_t len) {
    size_t i, index, partLen;

    index = (ctx->count[0] >> 3) & 0x3F;
    ctx->count[0] += (uint32_t) len << 3;
    
    if (ctx->count[0] < (len << 3)) {
        ctx->count[1]++;
    }
    ctx->count[1] += (uint32_t)(len >> 29);

    partLen = 64 - index;

    if (len >= partLen) {
        memcpy(&ctx->buffer[index], data, partLen);
        sha256_transform(ctx, ctx->buffer);
        
        for (i = partLen; i + 63 < len; i += 64) {
            sha256_transform(ctx, &data[i]);
        }
        
        index = 0;
    } else {
        i = 0;
    }

    memcpy(&ctx->buffer[index], &data[i], len - i);
}

void sha256_final(SHA256_CTX *ctx, uint8_t hash[]) {
    uint8_t bits[8];
    size_t index, padLen;

    for (index = 0; index < 8; index++) {
        bits[index] = (ctx->count[index >= 4 ? 0 : 1] >> ((7 - (index % 4)) * 8)) & 0xFF;
    }

    index = (ctx->count[0] >> 3) & 0x3F;
    padLen = (index < 56) ? (56 - index) : (120 - index);
    
    static const uint8_t padding[64] = {0x80};
    sha256_update(ctx, padding, padLen);
    sha256_update(ctx, bits, 8);

    for (index = 0; index < SHA256_BLOCK_SIZE; index++) {
        hash[index] = (ctx->state[index / 4] >> ((3 - (index % 4)) * 8)) & 0xFF;
    }
}

void print_hash(uint8_t hash[]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string_to_hash>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SHA256_CTX ctx;
    uint8_t hash[SHA256_BLOCK_SIZE];

    sha256_init(&ctx);
    sha256_update(&ctx, (const uint8_t *)argv[1], strlen(argv[1]));
    sha256_final(&ctx, hash);

    printf("SHA-256 hash: ");
    print_hash(hash);

    return EXIT_SUCCESS;
}