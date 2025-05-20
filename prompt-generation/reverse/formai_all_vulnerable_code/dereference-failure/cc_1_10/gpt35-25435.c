//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ROTATE_RIGHT(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t sigma_0(uint32_t x) {
    return ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22);
}

uint32_t sigma_1(uint32_t x) {
    return ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25);
}

uint32_t delta_0(uint32_t x) {
    return ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ (x >> 3);
}

uint32_t delta_1(uint32_t x) {
    return ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ (x >> 10);
}

void sha256(const char* msg, size_t msg_len, uint8_t* hash) {
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
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    uint32_t H[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint64_t bits_count = msg_len * 8;
    uint64_t total_bits = msg_len * 8 + 1 + 64;
    uint8_t *msg_padded = calloc(total_bits / 8, sizeof(uint8_t));

    memcpy(msg_padded, msg, msg_len);
    msg_padded[msg_len] = 0x80;

    size_t i = total_bits / 8 - 8;
    while (bits_count > 0) {
        msg_padded[i] = bits_count & 0xff;
        bits_count = bits_count >> 8;
        i--;
    }

    for (size_t chunk = 0; chunk < total_bits / (512 / 8); chunk++) {
        uint32_t w[64];
        for (size_t i = 0; i < 16; i++) {
            w[i] = ((uint32_t)msg_padded[chunk * 64 + i * 4] << 24) |
                   ((uint32_t)msg_padded[chunk * 64 + i * 4 + 1] << 16) |
                   ((uint32_t)msg_padded[chunk * 64 + i * 4 + 2] << 8) |
                   ((uint32_t)msg_padded[chunk * 64 + i * 4 + 3]);
        }

        for (size_t i = 16; i < 64; i++) {
            uint32_t s0 = delta_0(w[i - 15]);
            uint32_t s1 = delta_1(w[i - 2]);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }

        uint32_t a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

        for (size_t i = 0; i < 64; i++) {
            uint32_t S1 = sigma_1(e);
            uint32_t ch_res = ch(e, f, g);
            uint32_t temp1 = h + S1 + ch_res + K[i] + w[i];
            uint32_t S0 = sigma_0(a);
            uint32_t maj_res = maj(a, b, c);
            uint32_t temp2 = S0 + maj_res;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
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

    for (size_t i = 0; i < 8; i++) {
        hash[i * 4] = (uint8_t)(H[i] >> 24);
        hash[i * 4 + 1] = (uint8_t)(H[i] >> 16);
        hash[i * 4 + 2] = (uint8_t)(H[i] >> 8);
        hash[i * 4 + 3] = (uint8_t)(H[i]);
    }

    free(msg_padded);
}

int main() {
    char msg[] = "Hello, world!";
    uint8_t hash[32];

    sha256(msg, strlen(msg), hash);

    for (size_t i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    return 0;
}