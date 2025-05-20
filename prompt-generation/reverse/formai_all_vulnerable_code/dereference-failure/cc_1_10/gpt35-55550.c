//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint32_t rol(uint32_t val, uint32_t shift) {
    return (val << shift) | (val >> (32 - shift));
}

uint32_t sha1_hash(const uint8_t* data, size_t len) {
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    uint32_t* words = calloc(16, sizeof(*words));
    const uint8_t* data_end = data + len;
    while (data < data_end) {
        for (int i = 0; i < 16 && data < data_end; i++) {
            words[i] = (words[i] << 8) | *data++;
        }

        for (int i = 16; i < 80; i++) {
            words[i] = rol(words[i - 3] ^ words[i - 8] ^ words[i - 14] ^ words[i - 16], 1);
        }

        uint32_t a = h0, b = h1, c = h2, d = h3, e = h4;
        for (int i = 0; i < 80; i++) {
            uint32_t f, k;
            if (i < 20) {
                f = (b & c) | ((~b) & d);
                k = 0x5A827999;
            } else if (i < 40) {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = rol(a, 5) + f + e + k + words[i];
            e = d;
            d = c;
            c = rol(b, 30);
            b = a;
            a = temp;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }

    free(words);

    return h0 ^ h1 ^ h2 ^ h3 ^ h4;
}

int main() {
    printf("%x\n", sha1_hash("Hello, world!", 13));
    return 0;
}