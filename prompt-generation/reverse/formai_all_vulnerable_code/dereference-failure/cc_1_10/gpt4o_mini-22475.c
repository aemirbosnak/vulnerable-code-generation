//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants for SHA-256
static const uint32_t k[64] = {
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
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x776ae1e0,
    0x7ca92f78, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Functions to perform bitwise operations
#define ROTATE_RIGHT(value, amount) (((value) >> (amount)) | ((value) << (32 - (amount))))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ ((x) >> 3))
#define SIGMA1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ ((x) >> 10))
#define DELTA0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define DELTA1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))

// Hash function
void sha256(const uint8_t *data, size_t len, uint8_t *hash) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    uint32_t w[64] = {0};
    size_t i, j, t;

    // Padding the input
    size_t original_byte_len = len;
    size_t original_bit_len = original_byte_len * 8;

    // Append the '1' bit
    len += 1;
    while ((len % 64) != 56) {
        len++;
    }

    size_t padded_len = len + 8;  // Include space for original length
    uint8_t *padded_data = calloc(padded_len, sizeof(uint8_t));
    memcpy(padded_data, data, original_byte_len);
    padded_data[original_byte_len] = 0x80;  // Add the '1' bit
    for (i = 0; i < 8; i++) {
        padded_data[padded_len - 1 - i] = (original_bit_len >> (i * 8)) & 0xff;
    }

    // Process the data in 512-bit chunks
    for (i = 0; i < padded_len / 64; i++) {
        for (j = 0; j < 16; j++) {
            w[j] = (padded_data[i * 64 + j * 4] << 24) |
                   (padded_data[i * 64 + j * 4 + 1] << 16) |
                   (padded_data[i * 64 + j * 4 + 2] << 8) |
                   (padded_data[i * 64 + j * 4 + 3]);
        }
        for (j = 16; j < 64; j++) {
            w[j] = SIGMA1(w[j - 2]) + w[j - 7] + SIGMA0(w[j - 15]) + w[j - 16];
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h8 = h[7];

        // Main loop
        for (j = 0; j < 64; j++) {
            uint32_t t1 = h8 + DELTA1(e) + CH(e, f, g) + k[j] + w[j];
            uint32_t t2 = DELTA0(a) + MAJ(a, b, c);
            h8 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Add the compressed chunk to the current hash value
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h8;
    }

    // Produce the final hash value (big-endian)
    for (i = 0; i < 8; i++) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }

    free(padded_data);
}

// Convert hash to hex string
void print_hash(uint8_t *hash) {
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Main function to demonstrate SHA-256 hashing
int main() {
    const char *input = "Hello, this is a test input for SHA-256 hashing!";
    size_t input_len = strlen(input);
    uint8_t hash[32]; // SHA-256 produces a 32 byte hash

    sha256((const uint8_t *)input, input_len, hash);
    printf("Input: %s\n", input);
    printf("SHA-256 Hash: ");
    print_hash(hash);

    return 0;
}