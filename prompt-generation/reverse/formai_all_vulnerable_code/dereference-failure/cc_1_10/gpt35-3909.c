//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define constants used in the hash function
#define ROTL(x, n) ((x << n) | (x >> (32 - n)))
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define BIG_CONSTANT(x) (x##LLU)

// Define the Mix Function F and G used in the hash function
#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))

// Define the shift values used in the hash function
static const uint32_t k[64] = {
    BIG_CONSTANT(0x428a2f98), BIG_CONSTANT(0x71374491), BIG_CONSTANT(0xb5c0fbcf), BIG_CONSTANT(0xe9b5dba5),
    BIG_CONSTANT(0x3956c25b), BIG_CONSTANT(0x59f111f1), BIG_CONSTANT(0x923f82a4), BIG_CONSTANT(0xab1c5ed5),
    BIG_CONSTANT(0xd807aa98), BIG_CONSTANT(0x12835b01), BIG_CONSTANT(0x243185be), BIG_CONSTANT(0x550c7dc3),
    BIG_CONSTANT(0x72be5d74), BIG_CONSTANT(0x80deb1fe), BIG_CONSTANT(0x9bdc06a7), BIG_CONSTANT(0xc19bf174),
    BIG_CONSTANT(0xe49b69c1), BIG_CONSTANT(0xefbe4786), BIG_CONSTANT(0x0fc19dc6), BIG_CONSTANT(0x240ca1cc),
    BIG_CONSTANT(0x2de92c6f), BIG_CONSTANT(0x4a7484aa), BIG_CONSTANT(0x5cb0a9dc), BIG_CONSTANT(0x76f988da),
    BIG_CONSTANT(0x983e5152), BIG_CONSTANT(0xa831c66d), BIG_CONSTANT(0xb00327c8), BIG_CONSTANT(0xbf597fc7),
    BIG_CONSTANT(0xc6e00bf3), BIG_CONSTANT(0xd5a79147), BIG_CONSTANT(0x06ca6351), BIG_CONSTANT(0x14292967),
    BIG_CONSTANT(0x27b70a85), BIG_CONSTANT(0x2e1b2138), BIG_CONSTANT(0x4d2c6dfc), BIG_CONSTANT(0x53380d13),
    BIG_CONSTANT(0x650a7354), BIG_CONSTANT(0x766a0abb), BIG_CONSTANT(0x81c2c92e), BIG_CONSTANT(0x92722c85),
    BIG_CONSTANT(0xa2bfe8a1), BIG_CONSTANT(0xa81a664b), BIG_CONSTANT(0xc24b8b70), BIG_CONSTANT(0xc76c51a3),
    BIG_CONSTANT(0xd192e819), BIG_CONSTANT(0xd6990624), BIG_CONSTANT(0xf40e3585), BIG_CONSTANT(0x106aa070),
    BIG_CONSTANT(0x19a4c116), BIG_CONSTANT(0x1e376c08), BIG_CONSTANT(0x2748774c), BIG_CONSTANT(0x34b0bcb5),
    BIG_CONSTANT(0x391c0cb3), BIG_CONSTANT(0x4ed8aa4a), BIG_CONSTANT(0x5b9cca4f), BIG_CONSTANT(0x682e6ff3),
    BIG_CONSTANT(0x748f82ee), BIG_CONSTANT(0x78a5636f), BIG_CONSTANT(0x84c87814), BIG_CONSTANT(0x8cc70208),
    BIG_CONSTANT(0x90befffa), BIG_CONSTANT(0xa4506ceb), BIG_CONSTANT(0xbef9a3f7), BIG_CONSTANT(0xc67178f2)
};

void sha256_transform(uint32_t *state, const uint8_t *data) {
    uint32_t a, b, c, d, e, f, g, h, t1, t2, m[64];
    uint32_t *w = m;

    // Copy the input data to the message schedule
    for (int i = 0; i < 16; i++) {
        w[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | data[i * 4 + 3];
    }

    // Extend the message schedule
    for (int i = 16; i < 64; i++) {
        w[i] = ROTR(w[i - 2], 17) ^ ROTR(w[i - 2], 19) ^ (w[i - 2] >> 10) +
               w[i - 7] + ROTR(w[i - 15], 7) ^ ROTR(w[i - 15], 18) ^ (w[i - 15] >> 3);
    }

    // Initialize the working variables
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    // Perform the compression function
    for (int i = 0; i < 64; i++) {
        t1 = h + G(e, f, g) + ROTR(e, 6) + w[i] + k[i];
        t2 = F(a, b, c) + ROTR(a, 2) + ((b & c) ^ (a & (b ^ c)));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Compute the intermediate hash value
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

void sha256_hash(const uint8_t *input, size_t len, uint8_t *output) {
    // Initialize the hash state
    uint32_t state[8] = {
        BIG_CONSTANT(0x6a09e667), BIG_CONSTANT(0xbb67ae85), BIG_CONSTANT(0x3c6ef372), BIG_CONSTANT(0xa54ff53a),
        BIG_CONSTANT(0x510e527f), BIG_CONSTANT(0x9b05688c), BIG_CONSTANT(0x1f83d9ab), BIG_CONSTANT(0x5be0cd19)
    };
    size_t i, j;
    uint8_t buffer[64];
    uint64_t bitlen = len * 8;

    // Process the input data in 64-byte blocks
    for (i = 0; i < len / 64; i++) {
        sha256_transform(state, &input[i * 64]);
    }

    // Process the remaining bytes in a single block with padding
    j = len % 64;
    memcpy(buffer, &input[i * 64], j);
    buffer[j] = 0x80;
    if (j >= 56) {
        sha256_transform(state, buffer);
        memset(buffer, 0, 64);
    }
    *(uint64_t *)(buffer + 56) = bitlen;
    sha256_transform(state, buffer);

    // Write the final hash value to the output buffer
    for (i = 0; i < 8; i++) {
        output[i * 4] = (state[i] >> 24) & 0xff;
        output[i * 4 + 1] = (state[i] >> 16) & 0xff;
        output[i * 4 + 2] = (state[i] >> 8) & 0xff;
        output[i * 4 + 3] = state[i] & 0xff;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t *input = (uint8_t *) malloc(len);
    fread(input, 1, len, file);
    fclose(file);

    uint8_t hash[32];
    sha256_hash(input, len, hash);

    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(input);

    return 0;
}