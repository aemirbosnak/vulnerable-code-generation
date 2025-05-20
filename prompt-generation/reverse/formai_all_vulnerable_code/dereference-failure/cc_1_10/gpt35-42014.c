//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))

uint32_t fnv1a(const void *data, size_t len)
{
    const uint8_t *p = data;
    uint32_t h = 0x811c9dc5;

    for (size_t i = 0; i < len; i++)
    {
        h ^= p[i];
        h *= 0x01000193;
    }

    return h;
}

uint32_t sha1(const void *data, size_t len)
{
    const uint8_t *p = data;
    uint32_t h[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};

    uint32_t w[80];

    for (size_t i = 0; i < len; i += 64)
    {
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];

        for (size_t j = 0; j < 16; j++)
        {
            w[j] = (p[i + j * 4 + 0] << 24) |
                   (p[i + j * 4 + 1] << 16) |
                   (p[i + j * 4 + 2] << 8) |
                   (p[i + j * 4 + 3] << 0);
        }

        for (size_t j = 16; j < 80; j++)
        {
            w[j] = ROTL32(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
        }

        for (size_t j = 0; j < 80; j++)
        {
            uint32_t f, k;

            if (j < 20)
            {
                f = (b & c) | (~b & d);
                k = 0x5A827999;
            }
            else if (j < 40)
            {
                f = b ^ c ^ d;
                k = 0x6ED9EBA1;
            }
            else if (j < 60)
            {
                f = (b & c) | (b & d) | (c & d);
                k = 0x8F1BBCDC;
            }
            else
            {
                f = b ^ c ^ d;
                k = 0xCA62C1D6;
            }

            uint32_t temp = ROTL32(a, 5) + f + e + k + w[j];
            e = d;
            d = c;
            c = ROTL32(b, 30);
            b = a;
            a = temp;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
    }

    return h[0];
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Error: Please provide a string to hash\n");
        return 1;
    }

    char *input = argv[1];
    size_t len = strlen(input);

    uint32_t fnv = fnv1a(input, len);
    printf("FNV-1a hash of %s: 0x%08x\n", input, fnv);

    uint32_t sha = sha1(input, len);
    printf("SHA-1 hash of %s: 0x%08x\n", input, sha);

    return 0;
}