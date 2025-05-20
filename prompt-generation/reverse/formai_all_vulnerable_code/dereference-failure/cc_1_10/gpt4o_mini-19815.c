//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// SHA-256 Constants
const uint32_t k[64] = {
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
    0x19b4c8c2, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Function to perform right rotation
uint32_t right_rotate(uint32_t value, uint32_t count) {
    return (value >> count) | (value << (32 - count));
}

// SHA-256 computation on a message
void sha256(const uint8_t *data, size_t len, uint8_t *hash) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    size_t original_byte_len = len;
    size_t original_bit_len = original_byte_len * 8;

    // Preprocessing
    data = (uint8_t*) realloc((void*) data, original_byte_len + 1);
    ((uint8_t*) data)[original_byte_len] = 0x80; // Add a single '1' bit followed by '0's
    for (size_t i = original_byte_len + 1; i % 64 != 56; ++i) {
        ((uint8_t*) data)[i] = 0x00; // Fill with '0' bits
    }

    memcpy((uint8_t*) data + original_byte_len + 1 + (64 - 56), &original_bit_len, 8); // Append length

    // Process each 512-bit chunk
    for (size_t i = 0; i < (original_byte_len + 9 + (64 - 56)) / 64; ++i) {
        uint32_t w[64];
        for (size_t j = 0; j < 16; ++j) {
            w[j] = ((uint32_t*)data)[(i * 64)/4 + j];
        }
        for (size_t j = 16; j < 64; ++j) {
            w[j] = right_rotate(w[j-2], 17) ^ right_rotate(w[j-2], 19) ^ (w[j-7]) + 
                   (right_rotate(w[j-15], 7) ^ right_rotate(w[j-15], 18) ^ (w[j-15] >> 3)) + w[j-16];
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], h0 = h[7];

        for (size_t j = 0; j < 64; ++j) {
            uint32_t temp1 = h0 + (right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25)) + 
                             ((e & f) ^ (~e & g)) + k[j] + w[j];
            uint32_t temp2 = (right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22)) + 
                             ((a & b) ^ (a & c) ^ (b & c));
            h0 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }

    // Store the final hash value in hash
    for (size_t i = 0; i < 8; ++i) {
        hash[i * 4] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }

    // Free allocated memory
    free((void*) data);
}

void print_hash(uint8_t *hash) {
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t input_length = strlen(argv[1]);
    uint8_t *data = (uint8_t *)malloc(input_length);
    memcpy(data, argv[1], input_length);

    uint8_t hash[32]; 
    sha256(data, input_length, hash);
    
    printf("SHA-256 hash of '%s': ", argv[1]);
    print_hash(hash);

    free(data);
    return EXIT_SUCCESS;
}