//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SHA256_BLOCK_SIZE 32  // SHA256 outputs a 32 byte digest
#define SHA256_ROTL(a, b) ((a >> b) | (a << (32 - b)))

// SHA256 constants
static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fb57c8c, 0x106aa070,
    0x19b4c79b, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// SHA256 context structure
typedef struct {
    uint32_t state[8];
    uint32_t count[2];
    uint8_t buffer[64];
} SHA256_CTX;

// Initialize SHA256 context
void SHA256_Init(SHA256_CTX *context) {
    context->count[0] = 0;
    context->count[1] = 0;

    context->state[0] = 0x6a09e667;
    context->state[1] = 0xbb67ae85;
    context->state[2] = 0x3c6ef372;
    context->state[3] = 0xa54ff53a;
    context->state[4] = 0x510e527f;
    context->state[5] = 0x9b05688c;
    context->state[6] = 0x1f83d9ab;
    context->state[7] = 0x5be0cd19;
}

// Transform function
void SHA256_Transform(SHA256_CTX *context, const uint8_t data[]) {
    uint32_t a, b, c, d, e, f, g, h, temp1, temp2;
    uint32_t m[64];

    for (int i = 0; i < 16; ++i) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }
    for (int i = 16; i < 64; ++i) {
        m[i] = SHA256_ROTL(m[i - 16], 7) ^ SHA256_ROTL(m[i - 16], 18) ^ (m[i - 16] >> 3) + m[i - 7] + SHA256_ROTL(m[i - 15], 17) ^ SHA256_ROTL(m[i - 15], 19) ^ (m[i - 15] >> 10);
    }

    a = context->state[0];
    b = context->state[1];
    c = context->state[2];
    d = context->state[3];
    e = context->state[4];
    f = context->state[5];
    g = context->state[6];
    h = context->state[7];

    for (int i = 0; i < 64; ++i) {
        temp1 = h + (SHA256_ROTL(e, 6) ^ SHA256_ROTL(e, 11) ^ SHA256_ROTL(e, 25)) + ((e & f) ^ (~e & g)) + k[i] + m[i];
        temp2 = (SHA256_ROTL(a, 2) ^ SHA256_ROTL(a, 13) ^ SHA256_ROTL(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    context->state[4] += e;
    context->state[5] += f;
    context->state[6] += g;
    context->state[7] += h;
}

// Update SHA256 context with message
void SHA256_Update(SHA256_CTX *context, const uint8_t *data, size_t len) {
    size_t index = (context->count[0] >> 3) & 0x3F;
    if ((context->count[0] += (len << 3)) < (len << 3)) {
        context->count[1]++;
    }
    context->count[1] += (len >> 29);

    size_t partLen = 64 - index;
    size_t i = 0;

    if (len >= partLen) {
        memcpy(&context->buffer[index], data, partLen);
        SHA256_Transform(context, context->buffer);
        for (i = partLen; i + 63 < len; i += 64) {
            SHA256_Transform(context, &data[i]);
        }
        index = 0;
    }
    else {
        i = 0;
    }

    memcpy(&context->buffer[index], &data[i], len - i);
}

// Finalize the SHA256 hash
void SHA256_Final(uint8_t digest[SHA256_BLOCK_SIZE], SHA256_CTX *context) {
    uint8_t padding[64] = {0x80}; // Start with a single '1' bit
    uint64_t bits = context->count[0];

    size_t index = (context->count[0] >> 3) & 0x3F;
    size_t padLen = (index < 56) ? (56 - index) : (120 - index);

    SHA256_Update(context, padding, padLen);
    for (int i = 0; i < 8; i++) {
        padding[i] = (bits >> (56 - i * 8)) & 0xFF;
    }
    SHA256_Update(context, padding, 8);

    for (int i = 0; i < 8; i++) {
        digest[i * 4] = (context->state[i] >> 24) & 0xFF;
        digest[i * 4 + 1] = (context->state[i] >> 16) & 0xFF;
        digest[i * 4 + 2] = (context->state[i] >> 8) & 0xFF;
        digest[i * 4 + 3] = context->state[i] & 0xFF;
    }
}

// Main function to demonstrate SHA256 hashing
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    SHA256_CTX context;
    uint8_t digest[SHA256_BLOCK_SIZE];

    SHA256_Init(&context);
    SHA256_Update(&context, (uint8_t *)argv[1], strlen(argv[1]));
    SHA256_Final(digest, &context);

    printf("SHA256(\"%s\") = ", argv[1]);
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}