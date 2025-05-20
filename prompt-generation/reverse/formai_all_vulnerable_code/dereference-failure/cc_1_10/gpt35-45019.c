//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ROTR(x,n) (((x) >> (n)) | ((x) << (32 - (n))))
#define ROTL(x,n) (((x) << (n)) | ((x) >> (32 - (n))))
#define CH(x,y,z) (((x) & (y)) ^ ((~x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define SHR(x,n) ((x) >> (n))
#define SIGMA0(x) (ROTR((x),2) ^ ROTR((x),13) ^ ROTR((x),22))
#define SIGMA1(x) (ROTR((x),6) ^ ROTR((x),11) ^ ROTR((x),25))
#define sigma0(x) (ROTR((x),7) ^ ROTR((x),18) ^ SHR((x),3))
#define sigma1(x) (ROTR((x),17) ^ ROTR((x),19) ^ SHR((x),10))

static const uint32_t K[] = {
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

void sha256_digest(const uint8_t *message, size_t message_len, uint8_t *digest) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    size_t new_message_len = message_len + 64 - ((message_len + 64) % 64);
    uint8_t *new_message = (uint8_t *)calloc(new_message_len + 8, sizeof(uint8_t));
    memcpy(new_message, message, message_len);
    new_message[message_len] = 0x80;

    uint64_t bit_len = message_len * 8;
    memcpy(new_message + new_message_len, &bit_len, 8);

    uint32_t *M = (uint32_t *)new_message;

    for (size_t i = 0; i < new_message_len; i += 64) {
        uint32_t W[64];

        memcpy(W, M + i / 4, 64);

        for (size_t j = 16; j < 64; j++)
            W[j] = sigma1(W[j - 2]) + W[j - 7] + sigma0(W[j - 15]) + W[j - 16];

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], H = h[7];

        for (size_t j = 0; j < 64; j++) {
            uint32_t T1 = H + SIGMA1(e) + CH(e, f, g) + K[j] + W[j];
            uint32_t T2 = SIGMA0(a) + MAJ(a, b, c);

            H = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += H;
    }

    memcpy(digest, h, 32);

    free(new_message);
}

int main() {
    uint8_t digest[32];
    sha256_digest("hello world", strlen("hello world"), digest);
    for (int i = 0; i < 32; i++)
        printf("%02x", digest[i]);
    printf("\n");
    return 0;
}