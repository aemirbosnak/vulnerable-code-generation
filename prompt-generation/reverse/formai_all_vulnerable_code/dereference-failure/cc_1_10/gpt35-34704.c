//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WORD_SIZE 32
#define BLOCK_SIZE 512
#define WORDS_PER_BLOCK (BLOCK_SIZE/WORD_SIZE)
#define HASH_SIZE 256

uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (WORD_SIZE - n));
}

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t ep0(uint32_t x) {
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

uint32_t ep1(uint32_t x) {
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

uint32_t sigma0(uint32_t x) {
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

uint32_t sigma1(uint32_t x) {
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

void sha256(uint8_t *message, int message_len, uint8_t *hash) {
    uint32_t h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
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
    uint32_t w[WORDS_PER_BLOCK];
    int padded_len = ((message_len + 8) / BLOCK_SIZE + 1) * BLOCK_SIZE;
    uint8_t padded[padded_len];
    memset(padded, 0, padded_len);
    memcpy(padded, message, message_len);
    padded[message_len] = 0x80;
    uint64_t bit_len = message_len * 8;
    memcpy(padded + padded_len - 8, &bit_len, sizeof(uint64_t));
    for (int i = 0; i < padded_len / BLOCK_SIZE; i++) {
        uint32_t *block = (uint32_t *)(padded + i * BLOCK_SIZE);
        for (int j = 0; j < WORDS_PER_BLOCK; j++) {
            if (j < 16) {
                w[j] = block[j];
            } else {
                w[j] = sigma1(w[j-2]) + w[j-7] + sigma0(w[j-15]) + w[j-16];
            }
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h0 = h[7];
        for (int j = 0; j < 64; j++) {
            uint32_t t1 = h0 + ep1(e) + ch(e, f, g) + k[j] + w[j];
            uint32_t t2 = ep0(a) + maj(a, b, c);
            h0 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }
    for (int i = 0; i < HASH_SIZE / WORD_SIZE; i++) {
        memcpy(hash + i * sizeof(uint32_t), h + i, sizeof(uint32_t));
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <message>\n", argv[0]);
        exit(1);
    }
    uint8_t message[strlen(argv[1])];
    memcpy(message, argv[1], strlen(argv[1]));
    uint8_t hash[HASH_SIZE / 8];
    sha256(message, strlen(argv[1]), hash);
    printf("hash: ");
    for (int i = 0; i < HASH_SIZE / 8; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}