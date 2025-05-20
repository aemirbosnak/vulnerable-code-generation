//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t state[8]; // State of the SHA-256 algorithm
    uint32_t count[2]; // Number of processed bits, mod 2^64
    unsigned char buffer[64]; // Input buffer for pending data
} SHA256_CTX;

// SHA-256 constants
const uint32_t K[64] = {
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
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};

// Helper function to rotate bits to the right
uint32_t right_rotate(uint32_t value, int count) {
    return (value >> count) | (value << (32 - count));
}

// Helper function to process a chunk of data
void process_chunk(SHA256_CTX *ctx, unsigned char chunk[64]) {
    uint32_t word[64];
    uint32_t a, b, c, d, e, f, g, h, temp1, temp2;
    int i;

    // Prepare the message schedule
    for (i = 0; i < 16; i++) {
        word[i] = chunk[i*4] << 24;
        word[i] |= chunk[i*4+1] << 16;
        word[i] |= chunk[i*4+2] << 8;
        word[i] |= chunk[i*4+3];
    }
    for (i = 16; i < 64; i++) {
        uint32_t s0 = right_rotate(word[i-15], 7) ^ right_rotate(word[i-15], 18) ^ (word[i-15] >> 3);
        uint32_t s1 = right_rotate(word[i-2], 17) ^ right_rotate(word[i-2], 19) ^ (word[i-2] >> 10);
        word[i] = word[i-16] + s0 + word[i-7] + s1;
    }

    // Initialize the hash values for this chunk
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    // Perform the hash computation for this chunk
    for (i = 0; i < 64; i++) {
        uint32_t S1 = right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25);
        uint32_t ch = (e & f) ^ (~e & g);
        temp1 = h + S1 + ch + K[i] + word[i];
        uint32_t S0 = right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    // Update the hash values for this chunk
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

// Initialize the SHA-256 context
void sha256_init(SHA256_CTX *ctx) {
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

// Update the SHA-256 context with input data
void sha256_update(SHA256_CTX *ctx, unsigned char *input, uint32_t length) {
    uint32_t i, index;

    for (i = 0; i < length; i++) {
        index = (ctx->count[0] >> 3) & 0x3f;
        ctx->buffer[index++] = input[i];
        ctx->count[0] += 8;
        if (index == 64) {
            process_chunk(ctx, ctx->buffer);
            memset(ctx->buffer, 0, 64);
        }
    }
    ctx->count[1] += length;
}

// Finalize the SHA-256 context and output the hash value
void sha256_final(SHA256_CTX *ctx, unsigned char hash[32]) {
    uint32_t i, index, pad_len;
    unsigned char bit_len[8];

    // Save the total number of bits
    for (i = 0; i < 8; i++) {
        bit_len[i] = (ctx->count[(i > 3)? 1: 0] >> ((7 - i) * 8)) & 0xff;
    }

    // Compute the padding length
    index = (ctx->count[0] >> 3) & 0x3f;
    pad_len = (index < 56)? (56 - index): (120 - index);

    // Apply the padding
    ctx->buffer[index++] = 0x80;
    while (index < 64) {
        ctx->buffer[index++] = 0x00;
    }
    process_chunk(ctx, ctx->buffer);
    memset(ctx->buffer, 0, 64);

    // Append the total number of bits
    memcpy(&ctx->buffer[56], bit_len, 8);
    process_chunk(ctx, ctx->buffer);

    // Copy the hash value to the output buffer
    for (i = 0; i < 32; i++) {
        hash[i] = (ctx->state[i>>2] >> ((3 - (i & 3)) * 8)) & 0xff;
    }
}

// Main function to test the SHA-256 implementation
int main(int argc, char *argv[]) {
    SHA256_CTX ctx;
    unsigned char hash[32];
    unsigned char *input;
    uint32_t input_len;
    int i;

    // Initialize the input buffer
    input = (unsigned char*) malloc(1000000);
    for (i = 0; i < 1000000; i++) {
        input[i] = (unsigned char)(i & 0xff);
    }
    input_len = 1000000;

    // Compute the SHA-256 hash of the input data
    sha256_init(&ctx);
    sha256_update(&ctx, input, input_len);
    sha256_final(&ctx, hash);

    // Print the hash value in hexadecimal format
    printf("SHA-256 hash value:");
    for (i = 0; i < 32; i++) {
        printf(" %02x", hash[i]);
    }
    printf("\n");

    return 0;
}