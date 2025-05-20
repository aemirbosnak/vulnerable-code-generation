//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SHA256_BLOCK_SIZE 32  // SHA256 outputs a 32 byte hash

typedef struct {
    uint32_t state[8];         // State (A, B, C, D, E, F, G, H)
    uint32_t count[2];         // Count of bits (low-order, high-order)
    uint8_t buffer[64];        // Input buffer
} SHA256_CTX;

// SHA-256 initialization
void sha256_init(SHA256_CTX *ctx) {
    ctx->count[0] = ctx->count[1] = 0;

    // Initial hash values
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

// Rotate right helper function
static inline uint32_t ROTR(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

// SHA-256 transform function
void sha256_transform(SHA256_CTX *ctx, const uint8_t data[]) {
    uint32_t a, b, c, d, e, f, g, h, i, j;
    uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70995, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24c6caa, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t w[64];
    for (i = 0; i < 16; ++i) {
        w[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }

    for (i = 16; i < 64; ++i) {
        w[i] = w[i - 16] + (ROTR(w[i - 15], 7) ^ ROTR(w[i - 15], 18) ^ (w[i - 15] >> 3)) +
                           w[i - 7] + (ROTR(w[i - 2], 17) ^ ROTR(w[i - 2], 19) ^ (w[i - 2] >> 10));
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
        uint32_t t1 = h + (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25)) +
                      ((e & f) ^ (~e & g)) + k[i] + w[i];
        uint32_t t2 = (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22)) +
                      ((a & b) ^ (a & c) ^ (b & c));

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

// Update the SHA-256 context with new data
void sha256_update(SHA256_CTX *ctx, const uint8_t *data, size_t len) {
    size_t i = 0, index = (ctx->count[0] >> 3) & 0x3F;
    size_t part_len = 64 - index;

    ctx->count[0] += (len << 3);
    if (ctx->count[0] < (len << 3)) ctx->count[1]++;

    while (len >= part_len) {
        memcpy(&ctx->buffer[index], &data[i], part_len);
        sha256_transform(ctx, ctx->buffer);
        i += part_len;
        len -= part_len;
        index = 0;
        part_len = 64;
    }

    memcpy(&ctx->buffer[index], &data[i], len);
}

// Finalize the SHA-256 hash
void sha256_final(SHA256_CTX *ctx, uint8_t hash[]) {
    uint32_t index = (ctx->count[0] >> 3) & 0x3F;
    uint32_t pad_len = (index < 56) ? (56 - index) : (120 - index);

    // Append the message length as a 64-bit integer
    uint8_t padding[64] = {0x80};
    sha256_update(ctx, padding, pad_len);
    
    // Append the length of the original message
    uint8_t length[8];
    length[0] = (ctx->count[1] >> 24) & 0xFF;
    length[1] = (ctx->count[1] >> 16) & 0xFF;
    length[2] = (ctx->count[1] >> 8) & 0xFF;
    length[3] = (ctx->count[1]) & 0xFF;
    length[4] = (ctx->count[0] >> 24) & 0xFF;
    length[5] = (ctx->count[0] >> 16) & 0xFF;
    length[6] = (ctx->count[0] >> 8) & 0xFF;
    length[7] = (ctx->count[0]) & 0xFF;
    
    sha256_update(ctx, length, 8);

    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        hash[i] = (ctx->state[i / 4] >> ((3 - (i % 4)) * 8)) & 0xFF;
    }
}

// Function to print the SHA-256 hash
void print_hash(uint8_t hash[]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string to hash>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SHA256_CTX ctx;
    uint8_t hash[SHA256_BLOCK_SIZE];

    sha256_init(&ctx);
    sha256_update(&ctx, (uint8_t*)argv[1], strlen(argv[1]));
    sha256_final(&ctx, hash);

    printf("SHA-256 hash of '%s': ", argv[1]);
    print_hash(hash);

    return EXIT_SUCCESS;
}