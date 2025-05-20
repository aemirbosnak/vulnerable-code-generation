//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BLOCK_SIZE 512
#define MESSAGE_LENGTH_BITS 64

unsigned int rol(unsigned int x, unsigned int n)
{
    return (x << n) | (x >> (32 - n));
}

unsigned int create_w(unsigned char *m, unsigned int block, unsigned int i, unsigned int j)
{
    unsigned int w = m[block * BLOCK_SIZE + i * 4 + j];
    return w << 24 | (m[block * BLOCK_SIZE + i * 4 + j + 1] << 16) | (m[block * BLOCK_SIZE + i * 4 + j + 2] << 8) | (m[block * BLOCK_SIZE + i * 4 + j + 3] << 0);
}

unsigned int ch(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (~x & z);
}

unsigned int maj(unsigned int x, unsigned int y, unsigned int z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

unsigned int sigma_0(unsigned int x)
{
    return rol(x, 2) ^ rol(x, 13) ^ rol(x, 22);
}

unsigned int sigma_1(unsigned int x)
{
    return rol(x, 6) ^ rol(x, 11) ^ rol(x, 25);
}

unsigned int delta_0(unsigned int x)
{
    return rol(x, 7) ^ rol(x, 18) ^ (x >> 3);
}

unsigned int delta_1(unsigned int x)
{
    return rol(x, 17) ^ rol(x, 19) ^ (x >> 10);
}

void hash(unsigned char *m, int length, unsigned char *hash_values)
{
    unsigned int h0 = 0x6a09e667;
    unsigned int h1 = 0xbb67ae85;
    unsigned int h2 = 0x3c6ef372;
    unsigned int h3 = 0xa54ff53a;
    unsigned int h4 = 0x510e527f;
    unsigned int h5 = 0x9b05688c;
    unsigned int h6 = 0x1f83d9ab;
    unsigned int h7 = 0x5be0cd19;

    unsigned long long int l = length * 8;
    int block_count = ((length + 1 + 8 + BLOCK_SIZE - 1) / BLOCK_SIZE);
    unsigned int *w = (unsigned int *)malloc(64 * sizeof(unsigned int));

    int i, j, k;
    for (i = 0; i < block_count; i++) {
        memset(w, 0, 64 * sizeof(unsigned int));
        for (j = 0; j < 16 && (i * BLOCK_SIZE + j * 4) < length; j++)
            w[j] = create_w(m, i, j, 0);

        for (j = 16; j < 64; j++) {
            unsigned int s0 = delta_0(w[j - 15]);
            unsigned int s1 = delta_1(w[j - 2]);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        unsigned int a = h0;
        unsigned int b = h1;
        unsigned int c = h2;
        unsigned int d = h3;
        unsigned int e = h4;
        unsigned int f = h5;
        unsigned int g = h6;
        unsigned int h = h7;

        for (j = 0; j < 64; j++) {
            unsigned int e0 = sigma_0(a);
            unsigned int maj_res = maj(a, b, c);
            unsigned int t2 = e0 + maj_res;
            unsigned int e1 = sigma_1(e);
            unsigned int ch_res = ch(e, f, g);
            unsigned int t1 = h + e1 + ch_res + w[j] + ((unsigned int *)"\x42\x8a\x2b\x36\x48\x3d\xf0\xa5")[j];

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h0 = h0 + a;
        h1 = h1 + b;
        h2 = h2 + c;
        h3 = h3 + d;
        h4 = h4 + e;
        h5 = h5 + f;
        h6 = h6 + g;
        h7 = h7 + h;
    }

    free(w);

    memcpy(hash_values + 0, &h0, 4);
    memcpy(hash_values + 4, &h1, 4);
    memcpy(hash_values + 8, &h2, 4);
    memcpy(hash_values + 12, &h3, 4);
    memcpy(hash_values + 16, &h4, 4);
    memcpy(hash_values + 20, &h5, 4);
    memcpy(hash_values + 24, &h6, 4);
    memcpy(hash_values + 28, &h7, 4);
}

int main(int argc, char **argv)
{
    unsigned char m[] = "Hello, World!";
    int length = strlen((char *)m);
    unsigned char hash_values[32];
    memset(hash_values, 0, 32);

    hash(m, length, hash_values);

    printf("Message: %s\n", m);
    printf("Hash: ");
    int i;
    for (i = 0; i < 32; i++)
        printf("%02x", hash_values[i]);
    printf("\n");

    return 0;
}