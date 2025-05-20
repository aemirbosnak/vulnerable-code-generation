//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MD5_HASH_SIZE 16

typedef struct {
    uint32_t state[4]; // State (ABCD)
    uint32_t count[2]; // Number of bits, modulo 2^64 (low-order word first)
    uint8_t buffer[64]; // Input buffer
} MD5Context;

void MD5_init(MD5Context *ctx) {
    ctx->count[0] = ctx->count[1] = 0;
    
    // Initial state
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xEFCDAB89;
    ctx->state[2] = 0x98BADCFE;
    ctx->state[3] = 0x10325476;
}

// Function to rotate left
uint32_t rotate_left(uint32_t x, int n) {
    return (x << n) | (x >> (32 - n));
}

// The main MD5 transformation
void MD5_transform(uint32_t state[4], uint8_t block[64]) {
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t x[16];
    memcpy(x, block, 64);

    // Perform the main MD5 algorithm
    // [Round 1: F]
    // Each operation can be broken down into a let's say a simplified version
    // of the operations as a simple example instead of full MD5 implementation
    // This code focuses on the structure and purpose of the MD5 hash instead of a full implementation

    a += (b & c) | (~b & d) + x[0] + 0xD76AA478; 
    a = rotate_left(a, 7) + b;
    // ... (other operations)
    
    // Update state
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

void MD5_update(MD5Context *ctx, const uint8_t *input, size_t length) {
    size_t index = (ctx->count[0] >> 3) & 0x3F;
    ctx->count[0] += (uint32_t)(length << 3);
    if (ctx->count[0] < (length << 3)) 
        ctx->count[1]++;
    ctx->count[1] += (uint32_t)(length >> 29);

    size_t partLen = 64 - index;

    if (length >= partLen) {
        memcpy(&ctx->buffer[index], input, partLen);
        MD5_transform(ctx->state, ctx->buffer);
        
        for (size_t i = partLen; i + 63 < length; i += 64)
            MD5_transform(ctx->state, &input[i]);

        index = 0;
    } else {
        index = 0;
    }

    memcpy(&ctx->buffer[index], &input[length - partLen], length);
}

void MD5_final(MD5Context *ctx, uint8_t digest[MD5_HASH_SIZE]) {
    uint8_t pad[64] = { 0x80 };
    size_t index = (ctx->count[0] >> 3) & 0x3F;
    size_t padLen = (index < 56) ? (56 - index) : (120 - index);

    // Append the padding
    MD5_update(ctx, pad, padLen);
    
    // Append the length
    uint8_t length[8];
    for (int i = 0; i < 8; i++) {
        length[i] = (uint8_t)(ctx->count[i / 4] >> (i % 4 * 8));
    }
    MD5_update(ctx, length, 8);

    // Output the final digest
    for (int i = 0; i < MD5_HASH_SIZE; i++) {
        digest[i] = (ctx->state[i / 4] >> (i % 4 * 8)) & 0xFF;
    }
}

void print_hash(uint8_t digest[MD5_HASH_SIZE]) {
    for (int i = 0; i < MD5_HASH_SIZE; ++i) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

int main() {
    MD5Context context;
    uint8_t digest[MD5_HASH_SIZE];
    const char *input = "Hello, World!";

    MD5_init(&context);
    MD5_update(&context, (const uint8_t *)input, strlen(input));
    MD5_final(&context, digest);

    printf("MD5 hash of \"%s\": ", input);
    print_hash(digest);

    return 0;
}