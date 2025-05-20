//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// An implementation of the SHA-256 Cryptographic Hash Function

#define ROTLEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTRIGHT(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x, 2) ^ ROTRIGHT(x, 13) ^ ROTRIGHT(x, 22))
#define EP1(x) (ROTRIGHT(x, 6) ^ ROTRIGHT(x, 11) ^ ROTRIGHT(x, 25))
#define SIG0(x) (ROTRIGHT(x, 7) ^ ROTRIGHT(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x, 17) ^ ROTRIGHT(x, 19) ^ ((x) >> 10))

const uint32_t K[] = {
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2,
};

void sha256_transform(const unsigned char *message, uint32_t *hash) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;

    for (i = 0, j = 0; i < 16; ++i, j += 4) {
        w[i] = (message[j] << 24) | (message[j+1] << 16) |
               (message[j+2] << 8) | (message[j+3]);
    }

    for (; i < 64; ++i) {
        w[i] = SIG1(w[i-2]) + w[i-7] + SIG0(w[i-15]) + w[i-16];
    }

    a = hash[0]; b = hash[1]; c = hash[2]; d = hash[3];
    e = hash[4]; f = hash[5]; g = hash[6]; h = hash[7];

    for (i = 0; i < 64; ++i) {
        t1 = h + EP1(e) + CH(e, f, g) + K[i] + w[i];
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

    hash[0] += a; hash[1] += b; hash[2] += c; hash[3] += d;
    hash[4] += e; hash[5] += f; hash[6] += g; hash[7] += h;
}

void sha256(unsigned char *message, uint32_t *hash) {
    unsigned char *padded_message;
    uint64_t message_bit_length, padded_message_length_in_bytes;
    uint32_t i;

    message_bit_length = strlen((char *)message) * 8;
    padded_message_length_in_bytes = ((message_bit_length + 512) / 1024) * 1024 / 8;
    padded_message = calloc(padded_message_length_in_bytes, 1);
    memcpy(padded_message, message, strlen(message));
    padded_message[strlen(message)] = 0x80;
    for (i = strlen(message) + 1; i < padded_message_length_in_bytes; ++i) {
        padded_message[i] = 0x00;
    }
    *(uint64_t *)(padded_message + padded_message_length_in_bytes - 8) = message_bit_length;

    for (i = 0; i < padded_message_length_in_bytes / 64; ++i) {
        sha256_transform(padded_message + i*64, hash);
    }

    free(padded_message);
}

int main() {
    uint32_t hash[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
    unsigned char *message;
    uint32_t i;

    message = "The quick brown fox jumps over the lazy dog";

    sha256(message, hash);

    for (i = 0; i < 8; ++i) {
        printf("%08x ", hash[i]);
    }
    printf("\n");

    return 0;
}