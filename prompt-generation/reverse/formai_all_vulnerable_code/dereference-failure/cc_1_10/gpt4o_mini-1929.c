//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 Constants
#define SHA256_BLOCK_SIZE 32
#define SHA256_HASH_SIZE 64
#define SHA256_ROTL(a,b) (((a) >> (b)) | ((a) << (32 - (b))))
#define SHA256_S0(x) (SHA256_ROTL(x, 7) ^ SHA256_ROTL(x, 18) ^ ((x) >> 3))
#define SHA256_S1(x) (SHA256_ROTL(x, 17) ^ SHA256_ROTL(x, 19) ^ ((x) >> 10))
#define SHA256_F0(x,y,z) ((x) & (y)) ^ ((~(x)) & (z))
#define SHA256_F1(x,y,z) ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))

// Predefined SHA-256 constants
uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Function declarations
void sha256(const uint8_t *data, size_t length, uint8_t *hash);
void print_hash(const uint8_t *hash);
void sha256_transform(uint32_t state[8], const uint8_t data[]);

// Main function
int main() {
    char input[1024];
    uint8_t hash[SHA256_BLOCK_SIZE];

    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);
    
    // Strip newline character
    input[strcspn(input, "\n")] = 0;

    sha256((const uint8_t *)input, strlen(input), hash);
    print_hash(hash);

    return 0;
}

// SHA-256 Hash Function
void sha256(const uint8_t *data, size_t length, uint8_t *hash) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Padding and initializing variables
    uint64_t bit_length = length * 8;
    size_t new_length = length + 1 + ((length % 64 < 56) ? (56 - (length % 64)) : (120 - (length % 64)));
    uint8_t *buffer = (uint8_t *)calloc(new_length + 8, 1);
    memcpy(buffer, data, length);
    buffer[length] = 0x80;
    memcpy(buffer + new_length, &bit_length, sizeof(bit_length));

    // Process each chunk
    for (size_t i = 0; i < new_length; i += 64) {
        sha256_transform(state, buffer + i);
    }

    // Convert state to hash
    for (size_t i = 0; i < 8; i++) {
        hash[i * 4]     = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = (state[i]) & 0xff;
    }

    free(buffer);
}

// SHA-256 Transformation function
void sha256_transform(uint32_t state[8], const uint8_t data[]) {
    uint32_t m[64];
    for (size_t i = 0; i < 16; i++) {
        m[i] = ((uint32_t)data[i * 4] << 24) |
               ((uint32_t)data[i * 4 + 1] << 16) |
               ((uint32_t)data[i * 4 + 2] << 8) |
               ((uint32_t)data[i * 4 + 3]);
    }
    for (size_t i = 16; i < 64; i++) {
        m[i] = SHA256_S1(m[i - 2]) + m[i - 7] + SHA256_S0(m[i - 15]) + m[i - 16];
    }

    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];

    for (size_t i = 0; i < 64; i++) {
        uint32_t T1 = h + SHA256_S1(e) + SHA256_F1(e, f, g) + K[i] + m[i];
        uint32_t T2 = SHA256_S0(a) + SHA256_F0(a, b, c);
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

// Print the hash in hexadecimal format
void print_hash(const uint8_t *hash) {
    printf("SHA-256 Hash: ");
    for (size_t i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}