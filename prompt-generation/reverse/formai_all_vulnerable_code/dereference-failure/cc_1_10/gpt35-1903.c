//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x,y) ((x >> y) | (x << (32 - y)))
#define BIGENDIAN32(x) (x)

// Initialize variables
static const uint32_t IV[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19,
};

// Define constants
static const uint32_t K[64] = {
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

uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t Sigma0(uint32_t x) {
    return ROTR32(x, 2) ^ ROTR32(x, 13) ^ ROTR32(x, 22);
}

uint32_t Sigma1(uint32_t x) {
    return ROTR32(x, 6) ^ ROTR32(x, 11) ^ ROTR32(x, 25);
}

uint32_t sigma0(uint32_t x) {
    return ROTR32(x, 7) ^ ROTR32(x, 18) ^ (x >> 3);
}

uint32_t sigma1(uint32_t x) {
    return ROTR32(x, 17) ^ ROTR32(x, 19) ^ (x >> 10);
}

void sha256_transform(const uint8_t *message, uint32_t *state) {
    uint32_t a, b, c, d, e, f, g, h, temp1, temp2, schedule[64];

    for (int i = 0; i < 16; i++) {
        schedule[i] = BIGENDIAN32(((uint32_t *)message)[i]);
    }

    for (int i = 16; i < 64; i++) {
        schedule[i] = schedule[i - 16] + sigma0(schedule[i - 15]) + schedule[i - 7] + sigma1(schedule[i - 2]);
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (int i = 0; i < 64; i++) {
        temp1 = h + Sigma1(e) + Ch(e, f, g) + K[i] + schedule[i];
        temp2 = Sigma0(a) + Maj(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

void sha256(const uint8_t *message, size_t length, uint8_t *hash) {
    uint32_t state[8];
    size_t remainders, i;

    state[0] = IV[0];
    state[1] = IV[1];
    state[2] = IV[2];
    state[3] = IV[3];
    state[4] = IV[4];
    state[5] = IV[5];
    state[6] = IV[6];
    state[7] = IV[7];

    for (i = 0; i < length / 64; i++) {
        sha256_transform(message + i * 64, state);
    }

    remainders = length % 64;
    uint8_t *remainder_message = (uint8_t *)malloc((remainders + 1) * sizeof(uint8_t));
    memcpy(remainder_message, message + i * 64, remainders);
    remainder_message[remainders] = 0x80;
    remainders = (remainders < 56) ? (56 - remainders) : (120 - remainders);
    for (int i = 0; i < remainders; i++) {
        remainder_message = realloc(remainder_message, (remainders + i + 1) * sizeof(uint8_t));
        remainder_message[remainders + i] = 0x00;
    }
    uint64_t messageLength = length * 8;
    for (int i = 56; i <= 63; i++) {
        remainder_message = realloc(remainder_message, (remainders + i + 1) * sizeof(uint8_t));
        remainder_message[remainders + i] = (messageLength >> ((63 - i) * 8)) & 0xFF;
    }

    sha256_transform(remainder_message, state);
    free(remainder_message);

    for (int i = 0; i < 8; i++) {
        hash[i * 4] = (state[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = state[i] & 0xFF;
    }
}

int main() {
    const char* message = "Hello World!";
    uint8_t hash[32];

    sha256((uint8_t *)message, strlen(message), hash);

    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}