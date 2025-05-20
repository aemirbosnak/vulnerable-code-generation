//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ROTATE_RIGHT(value, amount) (((value) >> (amount)) | ((value) << (32 - (amount))))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ ((x) >> 3))
#define SIGMA1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ ((x) >> 10))
#define sigma0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define sigma1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))

static const uint32_t K[64] = {
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
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3, 
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2  
};

void sha256(const uint8_t *data, size_t len, uint8_t hash[32]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19  
    };

    uint64_t bitlen = len * 8;
    size_t new_len = len + 1 + ((len + 8) % 64 < 56 ? 56 : 120) - (len % 64);
    uint8_t *msg = calloc(new_len, sizeof(uint8_t));
    memcpy(msg, data, len);
    msg[len] = 0x80;
    *(uint64_t*)&msg[new_len - 8] = __builtin_bswap64(bitlen);

    for (size_t i = 0; i < new_len / 64; ++i) {
        uint32_t w[64] = { 0 };
        for (size_t j = 0; j < 16; ++j)
            w[j] = __builtin_bswap32(*(uint32_t*)&msg[i * 64 + j * 4]);
        for (size_t j = 16; j < 64; ++j)
            w[j] = SIGMA1(w[j - 2]) + w[j - 7] + SIGMA0(w[j - 15]) + w[j - 16];

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h0 = h[7];

        for (size_t j = 0; j < 64; ++j) {
            uint32_t temp1 = h0 + sigma1(e) + CH(e, f, g) + K[j] + w[j];
            uint32_t temp2 = sigma0(a) + MAJ(a, b, c);
            h0 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
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

    for (size_t i = 0; i < 8; ++i)
        *(uint32_t*)&hash[i * 4] = __builtin_bswap32(h[i]);
    
    free(msg);
}

int main() {
    const char *input = "Hello, world!";
    uint8_t hash[32];
    
    sha256((const uint8_t *)input, strlen(input), hash);
    
    printf("SHA-256 hash of \"%s\": ", input);
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");
    
    return 0;
}