//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define SHA256_BLOCK_SIZE 32  // SHA256 outputs a 32 byte digest

// SHA-256 transformation constants
static const uint32_t k [] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x27a4baa,
    0x213c2d53, 0x890cf1e8, 0x9cbd779, 0xd358069b,
    0x06d06838, 0xa63f6e62, 0x0fcfff12, 0xa8d21fd9,
    0x3c6ea12b, 0x6cb12cbb, 0x9c7e80f5, 0xc9f14c59,
    0xffd231e2, 0x4e73dbf0, 0xaff07dd7, 0xcc3f33e0,
};

// Rightrotate macro
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))

void sha256_transform(uint32_t state[], const uint8_t data[]) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t temp1, temp2;
    uint32_t m[64];

    for (int i = 0; i < 16; ++i) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | 
               (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }
    for (int i = 16; i < 64; ++i) {
        m[i] = ROTR(m[i-2], 17) ^ ROTR(m[i-2], 19) ^ (m[i-2] >> 10) +
                 m[i-7] + ROTR(m[i-15], 7) ^ ROTR(m[i-15], 18) ^ (m[i-15] >> 3) +
                 m[i-16];
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
        temp1 = h + (ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25)) + 
                 ((e & f) ^ ((~e) & g)) + k[i] + m[i];
        temp2 = (ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22)) + 
                 ((a & b) ^ (a & c) ^ (b & c));

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

void sha256(const uint8_t *data, size_t len, uint8_t *hash) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    size_t original_len = len;

    // Padding the input data
    size_t block_len = ((original_len + 8) / 64 + 1) * 64;
    uint8_t *buffer = (uint8_t *) calloc(block_len, sizeof(uint8_t));
    memcpy(buffer, data, original_len);
    buffer[original_len] = 0x80;
    
    uint64_t bit_len = original_len * 8;
    memcpy(buffer + block_len - 8, &bit_len, sizeof(bit_len));

    for (size_t i = 0; i < block_len; i += 64) {
        sha256_transform(state, buffer + i);
    }

    // Produce final hash
    for(int i = 0; i < 8; ++i) {
        hash[i * 4] = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = state[i] & 0xff;
    }

    free(buffer);
}

void print_hash(uint8_t *hash) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    char input[256];
    uint8_t hash[SHA256_BLOCK_SIZE];

    printf("Welcome to the SHA-256 Hashing Funhouse!\n");
    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Removing the newline character if any

    sha256((uint8_t *)input, strlen(input), hash);

    printf("SHA-256 Hash: ");
    print_hash(hash);

    return 0;
}