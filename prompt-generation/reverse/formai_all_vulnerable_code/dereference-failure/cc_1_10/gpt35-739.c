//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdint.h>
#include <stdbool.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))

// Constants for SHA-256
const uint32_t K[64] = {
    0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B,
    0x59F111F1, 0x923F82A4, 0xAB1C5ED5, 0xD807AA98, 0x12835B01,
    0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7,
    0xC19BF174, 0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
    0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA, 0x983E5152,
    0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147,
    0x06CA6351, 0x14292967, 0x27B70A85, 0x2E1B2138, 0x4D2C6DFC,
    0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
    0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819,
    0xD6990624, 0xF40E3585, 0x106AA070, 0x19A4C116, 0x1E376C08,
    0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F,
    0x682E6FF3, 0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
    0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

// Functions for SHA-256
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t Sigma0(uint32_t x) {
    return ROTL32(x, 2) ^ ROTL32(x, 13) ^ ROTL32(x, 22);
}

uint32_t Sigma1(uint32_t x) {
    return ROTL32(x, 6) ^ ROTL32(x, 11) ^ ROTL32(x, 25);
}

uint32_t sigma0(uint32_t x) {
    return ROTL32(x, 7) ^ ROTL32(x, 18) ^ (x >> 3);
}

uint32_t sigma1(uint32_t x) {
    return ROTL32(x, 17) ^ ROTL32(x, 19) ^ (x >> 10);
}

void sha256_transform(uint32_t state[8], const uint8_t block[64]) {
    uint32_t W[64];
    uint32_t A, B, C, D, E, F, G, H;

    for (int i = 0; i < 16; i++) {
        W[i] = (uint32_t) block[i * 4] << 24;
        W[i] |= (uint32_t) block[i * 4 + 1] << 16;
        W[i] |= (uint32_t) block[i * 4 + 2] << 8;
        W[i] |= (uint32_t) block[i * 4 + 3];
    }

    for (int i = 16; i < 64; i++) {
        W[i] = sigma1(W[i - 2]) + W[i - 7] + sigma0(W[i - 15]) + W[i - 16];
    }

    A = state[0];
    B = state[1];
    C = state[2];
    D = state[3];
    E = state[4];
    F = state[5];
    G = state[6];
    H = state[7];

    for (int i = 0; i < 64; i++) {
        uint32_t t1 = H + Sigma1(E) + Ch(E, F, G) + K[i] + W[i];
        uint32_t t2 = Sigma0(A) + Maj(A, B, C);
        H = G;
        G = F;
        F = E;
        E = D + t1;
        D = C;
        C = B;
        B = A;
        A = t1 + t2;
    }

    state[0] += A;
    state[1] += B;
    state[2] += C;
    state[3] += D;
    state[4] += E;
    state[5] += F;
    state[6] += G;
    state[7] += H;
}

void sha256(const uint8_t *message, uint32_t len, uint8_t hash[32]) {
    uint32_t state[] = {
        0x6A09E667,
        0xBB67AE85,
        0x3C6EF372,
        0xA54FF53A,
        0x510E527F,
        0x9B05688C,
        0x1F83D9AB,
        0x5BE0CD19
    };
    uint64_t bitlen = len * 8;
    uint8_t padding[64] = {0x80};
    uint8_t length_padding[8];

    for (int i = 0; i < 8; i++) {
        length_padding[7 - i] = (bitlen >> (i * 8)) & 0xFF;
    }

    int initial_length = len;
    len += 1;
    while (len % 64 != 56) {
        len++;
    }
    len += 8;

    uint8_t *message_padded = (uint8_t *) malloc(len);
    memcpy(message_padded, message, initial_length);
    memcpy(message_padded + initial_length, padding, len - (initial_length + 8));
    memcpy(message_padded + len - 8, length_padding, 8);

    for (uint32_t i = 0; i < len; i += 64) {
        sha256_transform(state, message_padded + i);
    }

    for (int i = 0; i < 8; i++) {
        hash[i * 4] = (state[i] >> 24) & 0xFF;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        hash[i * 4 + 3] = state[i] & 0xFF;
    }

    free(message_padded);
}

int main() {
    const uint8_t *message = "Hello, World!";
    uint8_t hash[32];
    sha256(message, strlen((const char *)message), hash);

    printf("Hash of \"%s\": ", message);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}