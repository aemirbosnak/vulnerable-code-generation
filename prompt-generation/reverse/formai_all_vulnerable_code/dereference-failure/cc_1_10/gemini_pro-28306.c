//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define u8 uint8_t
#define u32 uint32_t

const u32 IV[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

const u32 K[64] = {
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

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

void sha256(u8 *msg, u32 len, u8 *hash)
{
    u32 h[8];
    memcpy(h, IV, sizeof(IV));

    u32 w[64];
    for (u32 i = 0; i < len; i += 64) {
        memcpy(w, msg + i, 64);
        for (u32 j = 16; j < 64; j++) {
            u32 s0 = ROTR(w[j - 15], 7) ^ ROTR(w[j - 15], 18) ^ (w[j - 15] >> 3);
            u32 s1 = ROTR(w[j - 2], 17) ^ ROTR(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        u32 a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h_ = h[7];

        for (u32 j = 0; j < 64; j++) {
            u32 S1 = ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25);
            u32 ch = CH(e, f, g);
            u32 temp1 = h_ + S1 + ch + K[j] + w[j];
            u32 S0 = ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22);
            u32 maj = MAJ(a, b, c);
            u32 temp2 = S0 + maj;

            h_ = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_;
    }

    memcpy(hash, h, sizeof(h));
}

int main()
{
    u8 msg[] = "The quick brown fox jumps over the lazy dog";
    u32 len = strlen((char *)msg);
    u8 hash[32];
    sha256(msg, len, hash);

    printf("SHA-256 hash:\n");
    for (u32 i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}