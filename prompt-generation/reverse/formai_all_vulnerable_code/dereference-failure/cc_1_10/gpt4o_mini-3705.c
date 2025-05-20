//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 algorithm constants
static const uint32_t k[] = {
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
    0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t m[64];
    for (int i = 0; i < 16; ++i) {
        m[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) | data[i * 4 + 3];
    }
    for (int i = 16; i < 64; ++i) {
        m[i] = m[i - 16] + m[i - 7] +
               ((m[i - 15] >> 3) ^ (m[i - 15] << 29)) +
               ((m[i - 2] >> 10) ^ (m[i - 2] << 22));
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
        uint32_t S1 = (e >> 6) ^ (e << 26) ^ ((e & f) ^ (~e & g));
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + S1 + ch + k[i] + m[i];
        uint32_t S0 = (a >> 2) ^ (a << 30) ^ ((a & b) ^ (a & c) ^ (b & c));
        uint32_t temp2 = S0 + ((a & b) ^ (a & c) ^ (b & c));
        
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
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5b0b6470
    };

    size_t original_len = len;
    size_t orig_len_bytes = original_len * 8;
    
    uint8_t padded[64] = {0};
    size_t total_bytes = ((original_len + 8) / 64 + 1) * 64;
    
    memcpy(padded, data, original_len);
    padded[original_len] = 0x80; // Append the '1' bit
    if (total_bytes - 8 > original_len) {
        memset(padded + original_len + 1, 0, total_bytes - original_len - 9);
    }
    
    // Padding the length
    *(uint64_t*)(padded + total_bytes - 8) = __builtin_bswap64(orig_len_bytes);
    
    for (size_t i = 0; i < total_bytes / 64; ++i) {
        sha256_transform(state, padded + i * 64);
    }

    for (int i = 0; i < 8; ++i) {
        hash[i * 4] = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = state[i] & 0xff;
    }
}

void print_hash(const uint8_t *hash, size_t hash_len) {
    for (size_t i = 0; i < hash_len; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input = argv[1];
    size_t input_len = strlen(input);
    uint8_t hash[32];

    sha256((const uint8_t *)input, input_len, hash);

    printf("SHA-256 hash of '%s': ", input);
    print_hash(hash, sizeof(hash));

    return EXIT_SUCCESS;
}