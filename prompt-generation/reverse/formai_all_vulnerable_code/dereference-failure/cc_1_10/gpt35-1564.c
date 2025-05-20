//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(n, x) ((x >> n) | (x << (32 - n)))

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t sigma0(uint32_t x) {
    return ROTR(2, x) ^ ROTR(13, x) ^ ROTR(22, x);
}

uint32_t sigma1(uint32_t x) {
    return ROTR(6, x) ^ ROTR(11, x) ^ ROTR(25, x);
}

uint32_t delta0(uint32_t x) {
    return ROTR(7, x) ^ ROTR(18, x) ^ (x >> 3);
}

uint32_t delta1(uint32_t x) {
    return ROTR(17, x) ^ ROTR(19, x) ^ (x >> 10);
}

void sha256(const uint8_t *message, uint32_t len, uint8_t *digest) {
    uint32_t K[] = {
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
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
    };

    uint32_t H[] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19,
    };

    uint32_t W[64] = {0};
    uint32_t a, b, c, d, e, f, g, h, T1, T2;

    uint8_t *ptr;
    uint32_t i, j;

    uint32_t len_bits = len * 8;
    uint32_t num_blocks = (((len + 8) + 64) / 512) + 1;

    uint8_t *msg = (uint8_t *) calloc(num_blocks * 512 / 8, 1);
    memcpy(msg, message, len);
    msg[len] = 0x80;

    ptr = msg + (num_blocks * 512 / 8 - 8);
    ptr[0] = (len_bits >> 24) & 0xFF;
    ptr[1] = (len_bits >> 16) & 0xFF;
    ptr[2] = (len_bits >> 8) & 0xFF;
    ptr[3] = len_bits & 0xFF;

    for (i = 0; i < num_blocks; i++) {
        ptr = msg + (i * 512 / 8);
        for (j = 0; j < 16; j++) {
            W[j] = (ptr[j * 4] << 24) |
                   (ptr[j * 4 + 1] << 16) |
                   (ptr[j * 4 + 2] << 8) |
                   (ptr[j * 4 + 3]);
        }
        for (j = 16; j < 64; j++) {
            W[j] = delta1(W[j - 2]) + W[j - 7] +
                   delta0(W[j - 15]) + W[j - 16];
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
            T1 = h + sigma1(e) + ch(e, f, g) + K[j] + W[j];
            T2 = sigma0(a) + maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
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

    ptr = digest;
    for (i = 0; i < 8; i++) {
        *ptr++ = (H[i] >> 24) & 0xFF;
        *ptr++ = (H[i] >> 16) & 0xFF;
        *ptr++ = (H[i] >> 8) & 0xFF;
        *ptr++ = H[i] & 0xFF;
    }

    free(msg);
}

int main() {
    char input[100];
    printf("Enter a string to hash: ");
    fgets(input, 100, stdin);

    uint8_t digest[32];
    sha256(input, strlen(input), digest);

    printf("Hash result: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}