//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32
#define SHA256_DIGEST_SIZE 64

// SHA-256 Functions
void sha256_transform(uint32_t state[8], const uint8_t data[]);
void sha256_init(uint32_t state[8]);
void sha256_update(uint32_t state[8], const uint8_t data[], size_t len);
void sha256_final(uint32_t state[8], uint8_t digest[SHA256_BLOCK_SIZE]);

// Constants defined in the SHA-256 specification
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b,
    0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01,
    0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7,
    0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152,
    0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
    0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c48,
    0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f,
    0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_init(uint32_t state[8]) {
    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;
}

void sha256_transform(uint32_t state[8], const uint8_t data[]) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t T1, T2;
    uint32_t m[64] = {0};

    for (int i = 0; i < 16; ++i)
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | data[i * 4 + 3];

    for (int i = 16; i < 64; ++i) {
        m[i] = m[i - 16] + m[i - 7] + (m[i - 15] >> 3) + (m[i - 2] >> 10);
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (int i = 0; i < 64; ++i) {
        T1 = h + (e >> 6) + (e << 26) + (f ^ (e & (g ^ f))) + K[i] + m[i];
        T2 = (a >> 2) + (a << 30) + (b ^ (c & (a ^ b)));
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
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

void sha256_update(uint32_t state[8], const uint8_t data[], size_t len) {
    size_t block_index = 0;
    while(len >= 64) {
        sha256_transform(state, &data[block_index]);
        block_index += 64;
        len -= 64;
    }

    if (len > 0) {
        memcpy(data + block_index, data, len);
    }
}

void sha256_final(uint32_t state[8], uint8_t digest[SHA256_BLOCK_SIZE]) {
    uint8_t buffer[64] = {0};
    uint64_t bitlen = 512; // 512 bits = 64 bytes

    // Append the '1' bit
    buffer[0] = 0x80;

    // Append length
    for (int i = 56; i < 64; ++i) {
        buffer[i] = (bitlen >> (8 * (63 - i))) & 0xFF;
    }

    sha256_transform(state, buffer);
    
    for (int i = 0; i < 8; ++i) {
        digest[i * 4] = (state[i] >> 24) & 0xFF;
        digest[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        digest[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        digest[i * 4 + 3] = state[i] & 0xFF;
    }
}

int main() {
    const char *message = "Hello, grateful world!";
    uint32_t state[8];
    uint8_t digest[SHA256_BLOCK_SIZE];

    sha256_init(state);
    sha256_update(state, (const uint8_t *)message, strlen(message));
    sha256_final(state, digest);

    printf("SHA-256 hash of \"%s\": ", message);
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}