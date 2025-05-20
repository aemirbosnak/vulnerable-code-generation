//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROT_LEFT(x, n) ((x) << (n)) | ((x) >> (32 - (n)))

uint32_t h[8];
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

char *bin_to_hex(uint32_t *bin, size_t len) {
    char *output = malloc(len * 8 + 1);
    for(int i = 0; i < len; i++) {
        sprintf(&output[i * 8], "%08x", bin[i]);
    }
    return output;
}

void sha256(char *message, uint32_t length) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h1, temp1, temp2;

    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

    int num_blocks = ((length + 9) / 64) + 1;
    uint32_t *padded = malloc(num_blocks * 64);
    memcpy(padded, message, length);
    padded[length] = 0x80;
    for(int i = length + 1; i < num_blocks * 64 - 8; i++) {
        padded[i] = 0;
    }
    uint64_t u = length * 8;
    padded[num_blocks * 64 - 8] = (u >> 56) & 0xff;
    padded[num_blocks * 64 - 7] = (u >> 48) & 0xff;
    padded[num_blocks * 64 - 6] = (u >> 40) & 0xff;
    padded[num_blocks * 64 - 5] = (u >> 32) & 0xff;
    padded[num_blocks * 64 - 4] = (u >> 24) & 0xff;
    padded[num_blocks * 64 - 3] = (u >> 16) & 0xff;
    padded[num_blocks * 64 - 2] = (u >> 8) & 0xff;
    padded[num_blocks * 64 - 1] = u & 0xff;

    for(int i = 0; i < num_blocks; i++) {
        for(int j = 0; j < 16; j++) {
            w[j] = (padded[i * 64 + j * 4 + 0] << 24)
                 | (padded[i * 64 + j * 4 + 1] << 16)
                 | (padded[i * 64 + j * 4 + 2] <<  8)
                 | (padded[i * 64 + j * 4 + 3] <<  0);
        }
        for(int j = 16; j < 64; j++) {
            uint32_t s0 = ROT_LEFT(w[j - 15], 7) ^ ROT_LEFT(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = ROT_LEFT(w[j - 2], 17) ^ ROT_LEFT(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }
        a = h[0]; b = h[1]; c = h[2]; d = h[3];
        e = h[4]; f = h[5]; g = h[6]; h1 = h[7];
        for (int j = 0; j < 64; j++) {
            temp1 = h1 + ROT_LEFT(e, 6) ^ ROT_LEFT(e, 11) ^ ROT_LEFT(e, 25);
            temp2 = ROT_LEFT(a, 2) ^ ROT_LEFT(a, 13) ^ ROT_LEFT(a, 22);
            temp1 += (e & f) ^ (~e & g) + k[j] + w[j];
            temp2 += (a & b) ^ (a & c) ^ (b & c);
            h1 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h1;
    }

    free(padded);
}

int main() {
    char message[] = "Hello, world!";
    sha256(message, strlen(message));
    printf("%s\n", bin_to_hex(h, 8));
    return 0;
}