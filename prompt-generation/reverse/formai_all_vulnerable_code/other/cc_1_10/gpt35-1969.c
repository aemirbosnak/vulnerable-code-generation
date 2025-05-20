//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Claude Shannon
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SHA256_BLOCK_SIZE 32
#define ROTRIGHT(word, shift) ((word >> shift) | (word << (32 - shift)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define EP0(x) (ROTRIGHT(x, 2) ^ ROTRIGHT(x, 13) ^ ROTRIGHT(x, 22))
#define EP1(x) (ROTRIGHT(x, 6) ^ ROTRIGHT(x, 11) ^ ROTRIGHT(x, 25))
#define SIG0(x) (ROTRIGHT(x, 7) ^ ROTRIGHT(x, 18) ^ (x >> 3))
#define SIG1(x) (ROTRIGHT(x, 17) ^ ROTRIGHT(x, 19) ^ (x >> 10))

uint32_t k[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_transform(uint32_t *state, const uint8_t data[])
{
    uint32_t w[64];
    uint32_t working[8];
    uint32_t a, b, c, d, e, f, g, h;
    int i, j;

    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        w[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
    }

    for (i = 16; i < 64; ++i) {
        w[i] = SIG1(w[i - 2]) + w[i - 7] + SIG0(w[i - 15]) + w[i - 16];
    }

    memcpy(working, state, SHA256_BLOCK_SIZE);

    for (i = 0; i < 64; ++i) {
        a = working[0];
        b = working[1];
        c = working[2];
        d = working[3];
        e = working[4];
        f = working[5];
        g = working[6];
        h = working[7];

        uint32_t t1 = h + EP1(e) + CH(e, f, g) + k[i] + w[i];
        uint32_t t2 = EP0(a) + MAJ(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;

        working[0] = a;
        working[1] = b;
        working[2] = c;
        working[3] = d;
        working[4] = e;
        working[5] = f;
        working[6] = g;
        working[7] = h;
    }

    for (i = 0; i < 8; ++i) {
        state[i] += working[i];
    }
}

void sha256(const uint8_t *data, size_t size, uint8_t *hash)
{
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint8_t block[64];
    size_t idx;
    uint32_t bitlen[2] = { ((uint32_t)size) << 3, 0 };

    for (idx = 0; idx < size; ++idx) {
        uint8_t ch = data[idx];
        uint32_t shift = (idx % 4) * 8;
        bitlen[0] |= ((uint32_t)ch) << (24 - shift);
    }

    block[63] = bitlen[0] & 0xff;
    block[62] = (bitlen[0] >> 8) & 0xff;
    block[61] = (bitlen[0] >> 16) & 0xff;
    block[60] = (bitlen[0] >> 24) & 0xff;
    block[59] = bitlen[1] & 0xff;
    block[58] = (bitlen[1] >> 8) & 0xff;
    block[57] = (bitlen[1] >> 16) & 0xff;
    block[56] = (bitlen[1] >> 24) & 0xff;

    size_t i;
    for (i = 0; i < size; ++i) {
        uint8_t ch = data[i];
        uint32_t shift = (i % 4) * 8;
        block[i % 64] = ch << shift;
        if (((i + 1) % 64) == 0) {
            sha256_transform(state, block);
        }
    }

    uint8_t padding = 0x80;
    size_t padding_size = (size % 64 < 56) ? (56 - size % 64) : (120 - size % 64);

    block[size % 64] = padding;
    memset(block + size % 64 + 1, 0x00, padding_size - 1);

    if (size % 64 >= 56) {
        sha256_transform(state, block);
        memset(block, 0x00, 56);
    }

    memcpy(block + 56, bitlen, 8);

    sha256_transform(state, block);

    for (i = 0; i < 32; ++i) {
        hash[i] = (state[i / 4] >> (24 - (i % 4) * 8)) & 0xff;
    }
}

int main()
{
    uint8_t data[] = "This is a sample message to be hashed using SHA-256 algorithm";
    size_t size = strlen((const char *)data);
    uint8_t hash[SHA256_BLOCK_SIZE];

    sha256(data, size, hash);

    int i;
    printf("Hash: ");
    for (i = 0; i < SHA256_BLOCK_SIZE; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}