//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define ROTR(x, y) (((x) >> (y)) | ((x) << (32 - (y))))
#define SHR(x, y) ((x) >> (y))

#define Ch(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define Sigma0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define Sigma1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sigma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define sigma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256(const uint8_t *message, uint32_t len, uint32_t hash[8]) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;
    uint8_t *p, *end;

    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t len_bits = len * 8;

    for (i = 0; i < (len + 8 - 64); i += 64) {
        if (i < len) {
            memcpy(w, message + i, 64);
        }
        else {
            if (i == len) {
                w[0] = 0x80;
                for (j = 1; j < 64 - 4; j++) {
                    w[j] = 0x00;
                }
                w[15] = len_bits & 0xff;
                w[14] = (len_bits >> 8) & 0xff;
                w[13] = (len_bits >> 16) & 0xff;
                w[12] = (len_bits >> 24) & 0xff;
            }
            else {
                for (j = 0; j < 64; j++) {
                    w[j] = 0x00;
                }
            }
        }

        for (j = 16; j < 64; j++) {
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
        }

        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        for (j = 0; j < 64; j++) {
            t1 = h + Sigma1(e) + Ch(e, f, g) + K[j] + w[j];
            t2 = Sigma0(a) + Maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    for (i = 0; i < 8; i++) {
        hash[i] = H[i];
    }
}

int main(int argc, char **argv) {
    uint32_t hash[8];
    uint8_t data[] = "hello world";
    uint32_t data_len = strlen((const char*) data);

    printf("Hashing message: %s\n", data);

    sha256(data, data_len, hash);

    printf("Hash value: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}