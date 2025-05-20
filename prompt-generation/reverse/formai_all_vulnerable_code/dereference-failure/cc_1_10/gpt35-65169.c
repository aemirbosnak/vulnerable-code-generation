//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

uint32_t sig0(uint32_t x) {
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

uint32_t sig1(uint32_t x) {
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

uint32_t Sha256Sum(uint8_t* data, size_t len) {
    uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t K[64] = {
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
        0xc67178f2};

    uint32_t* M = (uint32_t*)malloc(sizeof(uint32_t)*64);

    size_t new_len;
    // new_len = len + 1 (bit '1' at the end) + k bits '0' (512 bits is enough)
    for (new_len = len*8 + 1; new_len%512!=448; new_len++);
    new_len /= 8;

    uint8_t* new_data = (uint8_t*)malloc(new_len + 64);
    memset(new_data, 0, new_len+64);
    memcpy(new_data, data, len);
    new_data[len] = 0x80;

    uint32_t bits_len = 8*len;
    memcpy(new_data + new_len, &bits_len, 4);

    for(size_t offset=0; offset<new_len; offset += (512/8)) {
        memcpy(M, new_data+offset, 64);

        uint32_t T1, T2, W[64];

        for(int i=0; i<16; i++)
            W[i] = M[i];

        for(int i=16; i<64; i++)
            W[i] = sig1(W[i-2]) + W[i-7] + sig0(W[i-15]) + W[i-16];

        uint32_t a = H[0];
        uint32_t b = H[1];
        uint32_t c = H[2];
        uint32_t d = H[3];
        uint32_t e = H[4];
        uint32_t f = H[5];
        uint32_t g = H[6];
        uint32_t h = H[7];

        for(int i=0; i<64; i++) {
            T1 = h + sig1(e) + ch(e, f, g) + K[i] + W[i];
            T2 = sig0(a) + maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    free(new_data);
    free(M);

    char result[64];
    for(int i=0; i<8; i++)
        sprintf(result+i*8, "%08x", H[i]);

    printf("SHA256 sum: %s\n", result);
}

int main() {
    Sha256Sum("Hello, world!", strlen("Hello, world!"));
    return 0;
}