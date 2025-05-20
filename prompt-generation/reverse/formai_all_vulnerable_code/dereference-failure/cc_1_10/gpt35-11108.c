//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WORD_SIZE 4
#define BLOCK_SIZE 64

typedef unsigned int WORD;
typedef unsigned long long int LLWORD;

#define ROTLEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

LLWORD H[8] = {
    0x6a09e667f3bcc908, 0xbb67ae8584caa73b,
    0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
    0x510e527fade682d1, 0x9b05688c2b3e6c1f,
    0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
};

WORD K[64] = { 
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

void sha256_transform(WORD *message) {
    int i;
    WORD W[64];
    WORD a, b, c, d, e, f, g, h, T1, T2;

    for (i = 0; i < 16; ++i)
        W[i] = message[i];

    for (i = 16; i < 64; ++i)
        W[i] = W[i-16] + ROTLEFT(W[i-15], 7) \
            + W[i-7] + ROTLEFT(W[i-2], 15);
        
    a = H[0], b = H[1], c = H[2], d = H[3];
    e = H[4], f = H[5], g = H[6], h = H[7];

    for (i = 0; i < 64; ++i) {
        T1 = h + K[i] + W[i];
        T1 += ROTLEFT(e, 6) ^ ROTLEFT(e, 11) ^ ROTLEFT(e, 25);
        T1 += (e & f) ^ ((~e) & g);
        T2 = ROTLEFT(a, 2) ^ ROTLEFT(a, 13) ^ ROTLEFT(a, 22);
        T2 += (a & b) ^ (a & c) ^ (b & c);

        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    H[0] += a, H[1] += b, H[2] += c, H[3] += d;
    H[4] += e, H[5] += f, H[6] += g, H[7] += h;
}


void sha256(const char *message, unsigned int message_length, char *hash) {
    unsigned int i, bit_len;
    WORD len, bit_len_len;
    WORD *message_sched = (WORD*)malloc(BLOCK_SIZE*sizeof(WORD));

    H[0] = 0x6a09e667, H[1] = 0xbb67ae85, H[2] = 0x3c6ef372, H[3] = 0xa54ff53a,
    H[4] = 0x510e527f, H[5] = 0x9b05688c, H[6] = 0x1f83d9ab, H[7] = 0x5be0cd19;

    for (len = 0; len < message_length / WORD_SIZE; ++len)
        ((WORD*)message_sched)[len] = ((WORD*)message)[len];

    message_sched[len] = 0x80;

    for (i = len+1; i < 14; ++i)
        message_sched[i] = 0;

    bit_len = message_length * 8;
    message_sched[14] = bit_len;
    message_sched[15] = bit_len >> 32;
    bit_len_len = 16;

    for (i = 0; i < bit_len_len / (BLOCK_SIZE/WORD_SIZE); ++i) 
        sha256_transform(&message_sched[i*16]);

    for (i = 0; i < 8; ++i)
        sprintf(&hash[i*8], "%08x", H[i]);

    free(message_sched);
}

int main() {
    char message[] = "Hello, World!";
    char hash[65];
    sha256(message, strlen(message), hash);
    printf("SHA256 Hash = %s\n", hash);
    return 0;
}