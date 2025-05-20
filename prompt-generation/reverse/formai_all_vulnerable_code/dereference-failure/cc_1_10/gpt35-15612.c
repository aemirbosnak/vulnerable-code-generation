//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n)))

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t sigma0(uint32_t x) {
    return ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22);
}

uint32_t sigma1(uint32_t x) {
    return ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25);
}

uint32_t delta0(uint32_t x) {
    return ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3);
}

uint32_t delta1(uint32_t x) {
    return ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10);
}

void sha256_hash(const char *message, uint32_t hash[8]) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, t1, t2;

    uint32_t k[64] = {
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

    hash[0] = 0x6a09e667;
    hash[1] = 0xbb67ae85;
    hash[2] = 0x3c6ef372;
    hash[3] = 0xa54ff53a;
    hash[4] = 0x510e527f;
    hash[5] = 0x9b05688c;
    hash[6] = 0x1f83d9ab;
    hash[7] = 0x5be0cd19;

    uint32_t len = strlen(message) * 8;
    uint32_t padlen = ((len + 64) / 512 + 1) * 512 - 64;
    char *padded_message = calloc(padlen / 8, 1);
    strcpy(padded_message, message);
    padded_message[strlen(message)] = 0x80;
    *((uint32_t *)(padded_message + padlen - 8)) = len;

    for (int i = 0; i < padlen / 512; i++) {
        for (int j = 0; j < 16; j++) {
            w[j] = ((uint32_t *)padded_message)[i * 16 + j];
        }
        for (int j = 16; j < 64; j++) {
            w[j] = delta1(w[j-2]) + w[j-7] + delta0(w[j-15]) + w[j-16];
        }

        a = hash[0];
        b = hash[1];
        c = hash[2];
        d = hash[3];
        e = hash[4];
        f = hash[5];
        g = hash[6];
        h = hash[7];

        for (int j = 0; j < 64; j++) {
            t1 = h + sigma1(e) + ch(e, f, g) + k[j] + w[j];
            t2 = sigma0(a) + maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    }

    free(padded_message);
}

int main() {
    uint32_t hash[8];
    sha256_hash("Hello, world!", hash);
    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n",
        hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
    return 0;
}