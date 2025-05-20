//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x,n) (((x) << (n)) | ((x) >> (32-(n))))
#define CH(x,y,z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTATE_LEFT(x,30) ^ ROTATE_LEFT(x,19) ^ ROTATE_LEFT(x,10))
#define EP1(x) (ROTATE_LEFT(x,26) ^ ROTATE_LEFT(x,21) ^ ROTATE_LEFT(x,7))
#define SIG0(x) (ROTATE_LEFT(x,25) ^ ROTATE_LEFT(x,14) ^ ((x) >> 3))
#define SIG1(x) (ROTATE_LEFT(x,15) ^ ROTATE_LEFT(x,13) ^ ((x) >> 10))

static const uint32_t k[64] = 
{ 
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

void sha256(uint8_t *message, uint32_t *hash)
{
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;
    uint32_t hh[8] =
    {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    for(i = 0; i < 16; i++)
    {
        w[i] = (message[(i * 4) + 0] << 24);
        w[i] |= (message[(i * 4) + 1] << 16);
        w[i] |= (message[(i * 4) + 2] << 8);
        w[i] |= (message[(i * 4) + 3]);
    }

    for(i = 16; i < 64; i++)
    {
        w[i] = SIG1(w[i-2]) + w[i-7] + SIG0(w[i-15]) + w[i-16];
    }

    a = hh[0];
    b = hh[1];
    c = hh[2];
    d = hh[3];
    e = hh[4];
    f = hh[5];
    g = hh[6];
    h = hh[7];

    for(i = 0; i < 64; i++)
    {
        t1 = h + EP1(e) + CH(e, f, g) + k[i] + w[i];
        t2 = EP0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    hash[0] = hh[0] + a;
    hash[1] = hh[1] + b;
    hash[2] = hh[2] + c;
    hash[3] = hh[3] + d;
    hash[4] = hh[4] + e;
    hash[5] = hh[5] + f;
    hash[6] = hh[6] + g;
    hash[7] = hh[7] + h;
}

int main()
{
    uint8_t message[] = "This is a test message";
    uint32_t hash[8];
    int i;

    sha256(message, hash);

    printf("SHA-256 Hash: ");

    for(i = 0; i < 8; i++)
    {
        printf("%08x", hash[i]);
    }

    printf("\n");

    return 0;
}