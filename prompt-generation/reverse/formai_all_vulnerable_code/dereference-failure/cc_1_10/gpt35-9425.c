//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ada Lovelace
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Rotates x by n bits
#define ROTL(x,n) ((x << n) | (x >> (32 - n)))

// Hash function based on SHA-256
void cryptohash(char *message, uint32_t *hash) {
    // Initialize constants
    uint32_t k[] = {
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
    uint32_t h[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint8_t *msg = (uint8_t *) message;
    uint32_t i, j, t1, t2, ch, maj, a, b, c, d, e, f, g, h0, h1, h2, h3, h4, h5, h6, h7;
    uint32_t w[64];
    // Compute number of blocks
    uint64_t len = strlen(message);
    uint64_t blocks = ((len + 8) / 64) + 1;
    uint64_t new_len = blocks * 64;
    uint8_t *new_msg = (uint8_t *) malloc(new_len);
    // Pad message
    memcpy(new_msg, msg, len);
    new_msg[len] = 0x80;
    for (i = len + 1; i < new_len - 8; i++) {
        new_msg[i] = 0;
    }
    // Append length
    uint64_t *bit_len = (uint64_t *) (new_msg + new_len - 8);
    *bit_len = len * 8;
    // Hash blocks
    for (i = 0; i < blocks; i++) {
        // Prepare message schedule
        for (j = 0; j < 16; j++) {
            w[j] = ((uint32_t *) new_msg)[i * 16 + j];
        }
        for (j = 16; j < 64; j++) {
            w[j] = w[j - 16] + ROTL((w[j - 15] ^ w[j - 7]) ^ ROTL(w[j - 2], 17), 3) + ROTL(w[j - 16], 19);
        }
        // Initialize working variables
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h0 = h[7];
        // Compression loop
        for (j = 0; j < 64; j++) {
            t1 = h0 + ROTL(e, 6) + ((e & f) ^ (~e & g)) + k[j] + w[j];
            t2 = ROTL(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
            h0 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        // Update hash values
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }
    // Convert hash values to big-endian
    for (i = 0; i < 8; i++) {
        hash[i] = (h[i] >> 24) | ((h[i] >> 8) & 0xff00) | ((h[i] << 8) & 0xff0000) | (h[i] << 24);
    }
    free(new_msg);
}

int main() {
    // Test vector
    char *message = "The quick brown fox jumps over the lazy dog";
    uint32_t hash[8];
    cryptohash(message, hash);
    printf("Hash: %08x%08x%08x%08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
    return 0;
}