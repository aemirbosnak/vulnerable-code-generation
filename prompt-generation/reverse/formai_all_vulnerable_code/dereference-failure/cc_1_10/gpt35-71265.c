//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))

#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))

#define F(x, y, z) ((x & y) | ((~x) & z))

#define G(x, y, z) ((x & z) | (y & (~z)))

#define H(x, y, z) (x ^ y ^ z)

#define I(x, y, z) (y ^ (x | (~z)))

#define FF(a, b, c, d, x, s, ac)               \
    {                                          \
        a += F(b, c, d) + x + ac;               \
        a = ROTL32(a, s);                      \
        a += b;                                 \
    }

#define GG(a, b, c, d, x, s, ac)               \
    {                                          \
        a += G(b, c, d) + x + ac;               \
        a = ROTL32(a, s);                      \
        a += b;                                 \
    }

#define HH(a, b, c, d, x, s, ac)               \
    {                                          \
        a += H(b, c, d) + x + ac;               \
        a = ROTL32(a, s);                      \
        a += b;                                 \
    }

#define II(a, b, c, d, x, s, ac)               \
    {                                          \
        a += I(b, c, d) + x + ac;               \
        a = ROTL32(a, s);                      \
        a += b;                                 \
    }

struct md5_hash
{
    uint32_t A, B, C, D;
};

void md5_init(struct md5_hash *hash)
{
    hash->A = 0x67452301;
    hash->B = 0xEFCDAB89;
    hash->C = 0x98BADCFE;
    hash->D = 0x10325476;
}

void md5_hash_data(char *data, uint32_t *hash, size_t size)
{
    struct md5_hash h;

    md5_init(&h);

    size_t new_len, offset;
    uint32_t w[16], a, b, c, d, i;

    new_len = ((((size + 8) / 64) + 1) * 64) - 8;
    char *msg = (char *)malloc(new_len + 64);

    memcpy(msg, data, size);

    msg[size] = (unsigned char)0x80;

    for (i = size + 1; i < new_len; i++)
        msg[i] = 0;

    uint64_t bits_len = 8 * size;
    memcpy(msg + new_len, &bits_len, 8);

    offset = 0;
    while (offset < new_len)
    {
        for (i = 0; i < 16; i++)
            w[i] = (uint32_t)((msg[offset + i * 4]) | (msg[offset + i * 4 + 1] << 8) | (msg[offset + i * 4 + 2] << 16) | (msg[offset + i * 4 + 3] << 24));

        a = h.A;
        b = h.B;
        c = h.C;
        d = h.D;

        FF(a, b, c, d, w[0], 7, 0xd76aa478);
        FF(d, a, b, c, w[1], 12, 0xe8c7b756);
        FF(c, d, a, b, w[2], 17, 0x242070db);
        FF(b, c, d, a, w[3], 22, 0xc1bdceee);
        FF(a, b, c, d, w[4], 7, 0xf57c0faf);
        FF(d, a, b, c, w[5], 12, 0x4787c62a);
        FF(c, d, a, b, w[6], 17, 0xa8304613);
        FF(b, c, d, a, w[7], 22, 0xfd469501);
        FF(a, b, c, d, w[8], 7, 0x698098d8);
        FF(d, a, b, c, w[9], 12, 0x8b44f7af);
        FF(c, d, a, b, w[10], 17, 0xffff5bb1);
        FF(b, c, d, a, w[11], 22, 0x895cd7be);
        FF(a, b, c, d, w[12], 7, 0x6b901122);
        FF(d, a, b, c, w[13], 12, 0xfd987193);
        FF(c, d, a, b, w[14], 17, 0xa679438e);
        FF(b, c, d, a, w[15], 22, 0x49b40821);

        GG(a, b, c, d, w[1], 5, 0xf61e2562);
        GG(d, a, b, c, w[6], 9, 0xc040b340);
        GG(c, d, a, b, w[11], 14, 0x265e5a51);
        GG(b, c, d, a, w[0], 20, 0xe9b6c7aa);
        GG(a, b, c, d, w[5], 5, 0xd62f105d);
        GG(d, a, b, c, w[10], 9, 0x02441453);
        GG(c, d, a, b, w[15], 14, 0xd8a1e681);
        GG(b, c, d, a, w[4], 20, 0xe7d3fbc8);
        GG(a, b, c, d, w[9], 5, 0x21e1cde6);
        GG(d, a, b, c, w[14], 9, 0xc33707d6);
        GG(c, d, a, b, w[3], 14, 0xf4d50d87);
        GG(b, c, d, a, w[8], 20, 0x455a14ed);
        GG(a, b, c, d, w[13], 5, 0xa9e3e905);
        GG(d, a, b, c, w[2], 9, 0xfcefa3f8);
        GG(c, d, a, b, w[7], 14, 0x676f02d9);
        GG(b, c, d, a, w[12], 20, 0x8d2a4c8a);

        HH(a, b, c, d, w[5], 4, 0xfffa3942);
        HH(d, a, b, c, w[8], 11, 0x8771f681);
        HH(c, d, a, b, w[11], 16, 0x6d9d6122);
        HH(b, c, d, a, w[14], 23, 0xfde5380c);
        HH(a, b, c, d, w[1], 4, 0xa4beea44);
        HH(d, a, b, c, w[4], 11, 0x4bdecfa9);
        HH(c, d, a, b, w[7], 16, 0xf6bb4b60);
        HH(b, c, d, a, w[10], 23, 0xbebfbc70);
        HH(a, b, c, d, w[13], 4, 0x289b7ec6);
        HH(d, a, b, c, w[0], 11, 0xeaa127fa);
        HH(c, d, a, b, w[3], 16, 0xd4ef3085);
        HH(b, c, d, a, w[6], 23, 0x04881d05);
        HH(a, b, c, d, w[9], 4, 0xd9d4d039);
        HH(d, a, b, c, w[12], 11, 0xe6db99e5);
        HH(c, d, a, b, w[15], 16, 0x1fa27cf8);
        HH(b, c, d, a, w[2], 23, 0xc4ac5665);

        II(a, b, c, d, w[0], 6, 0xf4292244);
        II(d, a, b, c, w[7], 10, 0x432aff97);
        II(c, d, a, b, w[14], 15, 0xab9423a7);
        II(b, c, d, a, w[5], 21, 0xfc93a039);
        II(a, b, c, d, w[12], 6, 0x655b59c3);
        II(d, a, b, c, w[3], 10, 0x8f0ccc92);
        II(c, d, a, b, w[10], 15, 0xffeff47d);
        II(b, c, d, a, w[1], 21, 0x85845dd1);
        II(a, b, c, d, w[8], 6, 0x6fa87e4f);
        II(d, a, b, c, w[15], 10, 0xfe2ce6e0);
        II(c, d, a, b, w[6], 15, 0xa3014314);
        II(b, c, d, a, w[13], 21, 0x4e0811a1);
        II(a, b, c, d, w[4], 6, 0xf7537e82);
        II(d, a, b, c, w[11], 10, 0xbd3af235);
        II(c, d, a, b, w[2], 15, 0x2ad7d2bb);
        II(b, c, d, a, w[9], 21, 0xeb86d391);

        h.A += a;
        h.B += b;
        h.C += c;
        h.D += d;

        offset += 64;
    }

    hash[0] = h.A;
    hash[1] = h.B;
    hash[2] = h.C;
    hash[3] = h.D;
}

int main()
{
    char *input_string = "This is a sample input string for testing.";
    size_t size = strlen(input_string);
    uint32_t hash[4];

    md5_hash_data(input_string, hash, size);

    printf("The MD5 hash of the input string is: %08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3]);

    return 0;
}