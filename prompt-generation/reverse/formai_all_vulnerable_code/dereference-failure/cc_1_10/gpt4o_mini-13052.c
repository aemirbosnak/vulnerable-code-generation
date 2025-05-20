//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32
#define SHA256_ROUNDS 64

// SHA256 Constants
static const uint32_t k[SHA256_ROUNDS] = {
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
    0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Helper functions
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sigma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define sigma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

void sha256(const uint8_t *data, size_t len, uint8_t hash[SHA256_BLOCK_SIZE]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    
    size_t numBlocks = (len + 9 + 64) / 64;
    uint8_t *block = malloc(numBlocks * 64);
    memcpy(block, data, len);
    
    // Append a bit '1' to the message
    block[len] = 0x80;
    memset(block + len + 1, 0, (numBlocks * 64) - len - 1);

    // Append the length of the original message in bits at the end
    uint64_t bitsLen = len * 8;
    memcpy(block + (numBlocks * 64) - 8, &bitsLen, 8);
    
    for (size_t i = 0; i < numBlocks; i++) {
        uint32_t w[64] = {0};
        for (size_t j = 0; j < 16; j++) {
            w[j] = (block[i * 64 + j * 4] << 24) |
                   (block[i * 64 + j * 4 + 1] << 16) |
                   (block[i * 64 + j * 4 + 2] << 8) |
                   (block[i * 64 + j * 4 + 3]);
        }
        
        for (size_t j = 16; j < 64; j++) {
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
        }
        
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h0 = h[7];

        for (size_t j = 0; j < SHA256_ROUNDS; j++) {
            uint32_t t1 = h0 + SIGMA1(e) + CH(e, f, g) + k[j] + w[j];
            uint32_t t2 = SIGMA0(a) + MAJ(a, b, c);
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

    free(block);

    for (int i = 0; i < 8; i++) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = (h[i]) & 0xff;
    }
}

void printHash(uint8_t hash[SHA256_BLOCK_SIZE]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256((uint8_t *)argv[1], strlen(argv[1]), hash);
    printf("SHA-256 hash of '%s': ", argv[1]);
    printHash(hash);
    
    return 0;
}