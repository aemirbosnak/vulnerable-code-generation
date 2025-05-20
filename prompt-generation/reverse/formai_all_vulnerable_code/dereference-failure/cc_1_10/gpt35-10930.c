//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

// a custom implementation of the SHA-256 algorithm
void sha256(const char* message, uint32_t message_len, uint32_t hash[8]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    }; // initial hash values

    uint32_t k[64] = { // constants defined in the standard
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

    // split message into 512-bit chunks (16 32-bit words each)
    uint32_t chunks[16 * (message_len / 64 + 1)];
    uint32_t i, j;
    for (i = 0; i < message_len; i++)
        chunks[i / 4] |= ((uint32_t)message[i]) << ((i % 4) * 8);
    chunks[message_len / 4] |= 0x80 << ((message_len % 4) * 8);
    if ((message_len % 64) > 55) {
        // add a second chunk
        for (i = message_len / 64 + 1; i < (message_len / 64 + 2) * 16; i++)
            chunks[i] = 0;
        chunks[(message_len / 64 + 2) * 16 - 1] = message_len * 8;
    } else {
        chunks[message_len / 4 + 1] = 0;
        chunks[(message_len / 64 + 1) * 16 - 1] = message_len * 8;
    }

    // process each chunk
    uint32_t a, b, c, d, e, f, g, h_old;
    for (i = 0; i < message_len / 64 + 1; i++) {
        a = h[0]; b = h[1]; c = h[2]; d = h[3];
        e = h[4]; f = h[5]; g = h[6]; h_old = h[7];

        for (j = 0; j < 64; j++) {
            uint32_t tmp1 = h_old + (g ^ (b & (c ^ g))) + k[j] + chunks[i*16 + j%16];
            uint32_t tmp2 = (e & f) ^ ((~e) & g);
            uint32_t ch = (e & f) ^ ((~e) & h_old);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            h_old = g; g = f; f = e; e = d + tmp1;
            d = c; c = b; b = a; a = tmp1 + tmp2 + ch + maj;
        }

        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h_old;
    }

    // copy hash to return value
    for (i = 0; i < 8; i++)
        hash[i] = h[i];
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"message\"\n", argv[0]);
        return 1;
    }

    uint32_t hash[8];
    sha256(argv[1], strlen(argv[1]), hash);

    printf("Hash: ");
    for (int i = 0; i < 8; i++)
        printf("%08x", hash[i]);
    printf("\n");

    return 0;
}