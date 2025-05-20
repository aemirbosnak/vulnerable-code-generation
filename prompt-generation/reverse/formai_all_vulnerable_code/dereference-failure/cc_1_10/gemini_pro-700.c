//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32_t;

#define ROTL32(x,n) (((x) << (n)) | ((x) >> (32-(n))))

static uint32_t *k = NULL;

void mdk4_init(void)
{
    k = (uint32_t *)malloc(sizeof(uint32_t) * 80);
    for (int i = 0; i < 80; i++) {
        k[i] = 0x5a827999 + i * 0x013198a2;
    }
}

void mdk4_hash(uint32_t *h, const unsigned char *m, uint32_t len)
{
    uint32_t w[80], a, b, c, d, e;
    for (int i = 0; i < len; i += 64) {
        for (int j = 0; j < 16; j++) {
            w[j] = m[i + 4 * j] << 24 | m[i + 4 * j + 1] << 16 | m[i + 4 * j + 2] << 8 | m[i + 4 * j + 3];
        }
        for (int j = 16; j < 80; j++) {
            w[j] = ROTL32(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
        }
        a = h[0]; b = h[1]; c = h[2]; d = h[3]; e = h[4];
        for (int j = 0; j < 80; j++) {
            uint32_t f, g;
            if (j < 20) {
                f = (b & c) | ((~b) & d);
                g = 15;
            } else if (j < 40) {
                f = b ^ c ^ d;
                g = 16;
            } else if (j < 60) {
                f = (b & c) | (b & d) | (c & d);
                g = 23;
            } else {
                f = b ^ c ^ d;
                g = 26;
            }
            uint32_t temp = ROTL32(a, g) + f + e + k[j] + w[j];
            e = d; d = c; c = ROTL32(b, 22); b = a; a = temp;
        }
        h[0] += a; h[1] += b; h[2] += c; h[3] += d; h[4] += e;
    }
}

int main(int argc, char **argv)
{
    mdk4_init();
    uint32_t h[5] = {0x01234567, 0x89abcdef, 0xfedcba98, 0x76543210, 0xdeadbeef};
    mdk4_hash(h, argv[1], strlen(argv[1]));
    printf("%08x%08x%08x%08x%08x\n", h[0], h[1], h[2], h[3], h[4]);
    return 0;
}