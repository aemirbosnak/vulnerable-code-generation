//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

// rotate left function
#define ROTL(x, r) ((x << r) | (x >> (32 - r)))

// SHA-256 constants (section 4.2.2 of FIPS 180-4)
const uint32_t K[] = {
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

// SHA-256 functions (section 4.1.2 of FIPS 180-4)
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t Sigma0(uint32_t x) {
    return ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22);
}

uint32_t Sigma1(uint32_t x) {
    return ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25);
}

uint32_t sigma0(uint32_t x) {
    return ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3);
}

uint32_t sigma1(uint32_t x) {
    return ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10);
}

// SHA-256 hash function (section 6.2 of FIPS 180-4)
void sha256_hash(uint8_t *data, size_t len, uint32_t *hash) {
    // initial hash values (section 5.3.3 of FIPS 180-4)
    uint32_t H[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // message schedule (section 6.2.2 of FIPS 180-4)
    uint32_t W[64];

    // process message in 512-bit chunks (section 6.2.2 of FIPS 180-4)
    for (size_t i = 0; i < len; i += 64) {
        // prepare message schedule
        for (size_t t = 0; t < 16; ++t) {
            W[t] = (data[i + t*4 + 0] << 24) | (data[i + t*4 + 1] << 16) | (data[i + t*4 + 2] << 8) | (data[i + t*4 + 3]);
        }
        for (size_t t = 16; t < 64; ++t) {
            W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16];
        }

        // initialize hash value for this chunk
        uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

        // main loop (section 6.2.2 of FIPS 180-4)
        for (size_t t = 0; t < 64; ++t) {
            uint32_t T1 = h + Sigma1(e) + Ch(e, f, g) + K[t] + W[t];
            uint32_t T2 = Sigma0(a) + Maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // update hash value
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // compute final hash value
    hash[0] = H[0];
    hash[1] = H[1];
    hash[2] = H[2];
    hash[3] = H[3];
    hash[4] = H[4];
    hash[5] = H[5];
    hash[6] = H[6];
    hash[7] = H[7];
}

int main() {
    // message to hash
    char *message = "Hello, world!";

    // allocate memory for hash output
    uint32_t *hash = malloc(8 * sizeof(uint32_t));

    // hash message using SHA-256
    sha256_hash((uint8_t *)message, strlen(message), hash);

    // print hash output
    printf("SHA-256 hash of \"%s\":\n", message);
    for (int i = 0; i < 8; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    // free memory
    free(hash);

    return 0;
}