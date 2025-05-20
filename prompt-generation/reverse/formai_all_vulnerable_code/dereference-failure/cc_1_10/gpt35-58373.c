//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Rotate left function
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Ch macro
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))

// Maj macro
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

// Sigma0 macro
#define SIG0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))

// Sigma1 macro
#define SIG1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))

// Sigma2 macro
#define sig0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ ((x) >> 3))

// Sigma3 macro
#define sig1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ ((x) >> 10))

// Message schedule array
static const uint32_t k[] = {
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

// Hash function
uint8_t *hash(const void *data, size_t data_len, uint8_t *hash_val) {
    // Initialize hash values
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    // Keep track of message length
    uint64_t bitlen = data_len * 8;

    // Preprocessing
    size_t new_len = data_len;
    while (new_len % 64 != 56) {
        new_len++;
    }
    uint8_t *msg = calloc(new_len + 8, 1);
    memcpy(msg, data, data_len);

    // Append bit length
    *((uint64_t *) (msg + new_len)) = bitlen;

    // Initialize variables
    uint32_t a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, t1 = 0, t2 = 0;
    uint32_t w[64];

    // Process each 512-bit block
    for (size_t i = 0; i < new_len; i += 64) {
        a = h0;
        b = h1;
        c = h2;
        d = h3;
        e = h4;
        f = h5;
        g = h6;
        h = h7;

        // Prepare message schedule
        for (size_t j = 0; j < 16; j++) {
            w[j] = ((uint32_t *) msg)[i / 4 + j];
        }
        for (size_t j = 16; j < 64; j++) {
            w[j] = sig1(w[j - 2]) + w[j - 7] + sig0(w[j - 15]) + w[j - 16];
        }

        // Computation of hash values
        for (size_t j = 0; j < 64; j++) {
            t1 = h + SIG1(e) + CH(e, f, g) + k[j] + w[j];
            t2 = SIG0(a) + MAJ(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update hash values
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }

    // Construct final hash value
    memcpy(hash_val, &h0, sizeof(uint32_t));
    memcpy(hash_val + 4, &h1, sizeof(uint32_t));
    memcpy(hash_val + 8, &h2, sizeof(uint32_t));
    memcpy(hash_val + 12, &h3, sizeof(uint32_t));
    memcpy(hash_val + 16, &h4, sizeof(uint32_t));
    memcpy(hash_val + 20, &h5, sizeof(uint32_t));
    memcpy(hash_val + 24, &h6, sizeof(uint32_t));
    memcpy(hash_val + 28, &h7, sizeof(uint32_t));

    free(msg);

    return hash_val;
}

int main() {
    char *msg = "hello world";
    uint8_t hash_val[32];
    hash(msg, strlen(msg), hash_val);

    // Printing the hash in hexadecimal format
    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash_val[i]);
    }
    printf("\n");

    return 0;
}