//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x,y) ((x >> y) | (x << (32 - y)))
#define ROTL64(x,y) ((x << y) | (x >> (64 - y)))
#define ROTR64(x,y) ((x >> y) | (x << (64 - y)))

static const uint8_t CRYPTONITE_PERMUTE_TABLE[] = {
    0x0e, 0x0b, 0x0d, 0x09, 0x06, 0x03, 0x08, 0x0c,
    0x02, 0x05, 0x07, 0x00, 0x0a, 0x01, 0x0f, 0x04
};

static const uint32_t CRYPTONITE_SBOX[] = {
    0xbc9f1d34, 0x10e40514, 0xac3bafec, 0x1bdc9376,
    0xf7c3e141, 0xed52575c, 0x3208a0c7, 0x7d7b8f75,
    0x762a0b77, 0x211ae6bd, 0x1d7ad170, 0x5219ee11,
    0x749bc4ae, 0x8db93205, 0xcdc8b4bb, 0x09ee20eb
};

static inline uint32_t cryptonite_sbox(uint32_t x) {
    return CRYPTONITE_SBOX[x & 0x0f] ^ CRYPTONITE_SBOX[x >> 4];
}

static uint32_t cryptonite_permute(uint32_t x) {
    uint32_t y = 0;
    int i;

    for (i = 0; i < 16; i++) {
        if (x & (1 << i)) {
            y |= 1 << CRYPTONITE_PERMUTE_TABLE[i];
        }
    }

    return y;
}

void cryptonite(uint8_t *data, size_t len, uint8_t *md) {
    uint32_t *state;
    uint32_t a, b, c, d, e, f, g, h, x, y, z;
    size_t i;

    // Initial values
    a = 0x6a09e667;
    b = 0xbb67ae85;
    c = 0x3c6ef372;
    d = 0xa54ff53a;
    e = 0x510e527f;
    f = 0x9b05688c;
    g = 0x1f83d9ab;
    h = 0x5be0cd19;

    // Set up the message schedule
    uint32_t w[64];
    const int K[] = {
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

    state = (uint32_t *) md;
    for (i = 0; i < 8; i++) {
        state[i] = 0;
    }

    for (i = 0; i < len; i += 64) {
        // Initialize the message schedule
        for (x = i, y = 0; y < 16; x += 4, y++) {
            w[y] = (data[x] << 24) | (data[x + 1] << 16)
                 | (data[x + 2] << 8) | data[x + 3];
        }

        for (; y < 64; y++) {
            w[y] = cryptonite_sbox(ROTR32(w[y - 2], 17) ^ ROTR32(w[y - 2], 19) ^ (w[y - 2] >> 10))
                 + w[y - 7]
                 + cryptonite_sbox(ROTR32(w[y - 15], 7) ^ ROTR32(w[y - 15], 18) ^ (w[y - 15] >> 3))
                 + w[y - 16];
        }

        // Run the encryption algorithm
        for (x = 0; x < 64; x++) {
            z = h + ROTR32(e, 6) + ROTR32(e, 11) + ROTR32(e, 25) + ((e & f) ^ (~e & g)) + K[x] + w[x];
            a += ROTL32(z, 2) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + z;
            d = c;
            c = b;
            b = a;
            a = z + ((b & c) | ((~b) & d));
        }

        // Update the message digest
        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;
        state[4] += e;
        state[5] += f;
        state[6] += g;
        state[7] += h;
    }
}

int main(int argc, char **argv) {
    // Input message
    char *msg = "Hello, World!";

    // Calculate the hash
    uint8_t hash[32];
    cryptonite((uint8_t *) msg, strlen(msg), hash);

    // Print the hash
    int i;
    for (i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}