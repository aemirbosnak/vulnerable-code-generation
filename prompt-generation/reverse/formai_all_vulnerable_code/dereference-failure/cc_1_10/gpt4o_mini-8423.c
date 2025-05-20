//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTRIGHT(a,b) ((a >> b) | (a << (32 - b)))
#define SHFRIGHT(a,b) (a >> b)
#define CH(x,y,z) ((x & y) ^ ((~x) & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIG0(x) (ROTRIGHT(x, 7) ^ ROTRIGHT(x, 18) ^ SHFRIGHT(x, 3))
#define SIG1(x) (ROTRIGHT(x, 17) ^ ROTRIGHT(x, 19) ^ SHFRIGHT(x, 10))
#define sig0(x) (ROTRIGHT(x, 1) ^ ROTRIGHT(x, 8) ^ SHFRIGHT(x, 7))
#define sig1(x) (ROTRIGHT(x, 19) ^ ROTRIGHT(x, 61) ^ SHFRIGHT(x, 6))

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
    0x19b4c79c, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void hash(const uint8_t *msg, size_t len, uint8_t digest[32]) {
    uint32_t w[64] = {0};
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint32_t a, b, c, d, e, f, g, h0, t1, t2;

    for (size_t i = 0; i < len; i+=64) {
        size_t block_size = len - i < 64 ? len - i : 64;

        memcpy(w, msg + i, block_size);
        if (block_size < 64) {
            w[block_size / 4] |= 0x80 << (24 - (block_size % 4) * 8);
            if (block_size <= 56) {
                memset(w + 15, 0, 64 - block_size - 1);
                size_t total_length = len * 8;
                w[15] = total_length;
            } else {
                memset(w + 16, 0, 64 - block_size);
                size_t total_length = len * 8;
                w[15] = total_length;
                // Process the next block
            }
        }

        for (size_t j = 16; j < 64; j++) {
            w[j] = sig1(w[j - 2]) + w[j - 7] + sig0(w[j - 15]) + w[j - 16];
        }

        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h0 = h[7];

        for (size_t j = 0; j < 64; j++) {
            t1 = h0 + SIG1(e) + CH(e, f, g) + k[j] + w[j];
            t2 = SIG0(a) + MAJ(a, b, c);
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

    for (int i = 0; i < 8; i++) {
        digest[i * 4] = (h[i] >> 24) & 0xff;
        digest[i * 4 + 1] = (h[i] >> 16) & 0xff;
        digest[i * 4 + 2] = (h[i] >> 8) & 0xff;
        digest[i * 4 + 3] = h[i] & 0xff;
    }
}

void print_hash(uint8_t digest[32]) {
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return 1;
    }

    uint8_t digest[32];

    printf("Hash for: %s\n", argv[1]);
    hash((uint8_t *)argv[1], strlen(argv[1]), digest);
    print_hash(digest);

    return 0;
}