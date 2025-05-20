//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROT_LEFT(x,n) ((x << n) | (x >> (32-n)))
#define CH(x,y,z)   ((x & y) ^ (~x & z))
#define MAJ(x,y,z)  ((x & y) ^ (x & z) ^ (y & z))

// SHA256 implementation
void sha256(const char* message, uint32_t* hash)
{
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;

    const uint32_t k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    const int64_t len = strlen(message);
    const int64_t padded_len = ((len + 8) / 64 + 1) * 64;
    uint8_t* padded_msg = calloc(padded_len, 1);
    memcpy(padded_msg, message, len);
    padded_msg[len] = 0x80;
    uint32_t* len_ptr = (uint32_t*)&padded_msg[padded_len-8];
    *len_ptr = (uint32_t)(len * 8);
    *len_ptr = (*len_ptr << 24) | ((*len_ptr & 0xff00) << 8) | ((*len_ptr & 0xff0000) >> 8) | (*len_ptr >> 24);

    a = 0x6a09e667;
    b = 0xbb67ae85;
    c = 0x3c6ef372;
    d = 0xa54ff53a;
    e = 0x510e527f;
    f = 0x9b05688c;
    g = 0x1f83d9ab;
    h = 0x5be0cd19;

    for (i = 0; i < padded_len; i += 64)
    {
        for (j = 0; j < 16; ++j)
        {
            w[j] = (uint32_t)padded_msg[i+j*4];
            w[j] = (w[j] << 24) | ((w[j] & 0xff00) << 8) | ((w[j] & 0xff0000) >> 8) | (w[j] >> 24);
        }
        for (j = 16; j < 64; ++j)
        {
            uint32_t s0 = ROT_LEFT(w[j-15], 7) ^ ROT_LEFT(w[j-15], 18) ^ (w[j-15] >> 3);
            uint32_t s1 = ROT_LEFT(w[j-2], 17) ^ ROT_LEFT(w[j-2], 19) ^ (w[j-2] >> 10);
            w[j] = w[j-16] + s0 + w[j-7] + s1;
        }

        for (j = 0; j < 64; ++j)
        {
            t1 = h + CH(e,f,g) + ROT_LEFT(e,6) + k[j] + w[j];
            t2 = MAJ(a,b,c) + ROT_LEFT(a,11);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    }

    free(padded_msg);
}

int main()
{
    char message[] = "This is a test message.";
    uint32_t hash[8] = {0};

    sha256(message, hash);

    printf("Hash: %08x%08x%08x%08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

    return 0;
}