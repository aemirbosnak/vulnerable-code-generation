//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTR(x,n) ((x >> n) | (x << (32 - n)))  /* Right rotate */

/* SHA-256 Constants */
const uint32_t K[] = {
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

/* SHA-256 Functions */
#define CH(x,y,z) ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define S0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define S1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define s0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define s1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

/* Initial hash values */
const uint32_t H[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
        };

/* SHA-256 message parsing */
void sha256_parse(uint8_t *data, uint32_t len, uint32_t *words)
{
    uint32_t i;
    int j;
    uint32_t val;

    for (i = 0; i < len / 4; i++)
    {
        val = 0;
        for (j = 3; j >= 0; j--)
            val = (val << 8) + *(data++);
        words[i] = val;
    }
}

/* Perform SHA-256 hash */
void sha256_hash(uint8_t *message, uint32_t len, uint8_t *hash)
{
    uint32_t i, j;
    uint32_t words[64];
    uint32_t a, b, c, d, e, f, g, h, t1, t2;

    /* Append padding */
    uint32_t new_len = len << 3;
    int append_len = (new_len % 512 < 448) ? (448 - new_len % 512) : (960 - new_len % 512);
    uint8_t *msg = (uint8_t*) malloc(len + append_len + 64);
    memcpy(msg, message, len);
    msg[len] = 0x80;
    memset(msg + len + 1, 0, append_len - 7);
    for (i = 0; i < 8; i++)
        msg[len + append_len - 7 + i] = (uint8_t) (new_len >> 8 * (7 - i));

    /* Initialize hash */
    uint32_t H_copy[8];
    memcpy(H_copy, H, sizeof(H));
    a = H_copy[0], b = H_copy[1], c = H_copy[2], d = H_copy[3];
    e = H_copy[4], f = H_copy[5], g = H_copy[6], h = H_copy[7];

    /* Parse message into 16-word blocks */
    for (i = 0; i < len / 64; i++)
    {
        sha256_parse(msg + i * 64, 64, words);

        /* Extend to 64 words */
        for (j = 16; j < 64; j++)
            words[j] = s1(words[j-2]) + words[j-7] + s0(words[j-15]) + words[j-16];

        /* Compression function */
        for (j = 0; j < 64; j++)
        {
            t1 = h + S1(e) + CH(e, f, g) + K[j] + words[j];
            t2 = S0(a) + MAJ(a, b, c);
            h = g, g = f, f = e, e = d + t1, d = c, c = b, b = a, a = t1 + t2;
        }

        /* Update hash */
        H_copy[0] = a + H_copy[0];
        H_copy[1] = b + H_copy[1];
        H_copy[2] = c + H_copy[2];
        H_copy[3] = d + H_copy[3];
        H_copy[4] = e + H_copy[4];
        H_copy[5] = f + H_copy[5];
        H_copy[6] = g + H_copy[6];
        H_copy[7] = h + H_copy[7];
    }

    /* Store hash */
    for (i = 0; i < 8; i++)
        for (j = 0; j < 4; j++)
            *(hash++) = (uint8_t) (H_copy[i] >> 8 * (3 - j));
}

/* Example usage */
int main(int argc, char **argv)
{
    uint8_t message[] = {'H','e','l','l','o',',',' ','w','o','r','l','d','!','\n'};
    uint8_t hash[32];

    sha256_hash(message, sizeof(message), hash);

    int i;
    for (i = 0; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}