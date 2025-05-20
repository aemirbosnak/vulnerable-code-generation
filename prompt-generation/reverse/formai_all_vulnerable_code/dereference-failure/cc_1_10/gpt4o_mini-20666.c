//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32 // Size of the hash in bytes (256 bits)
#define BLOCK_SIZE 64 // Size of each block in bytes

// Function to rotate right
uint32_t rotate_right(uint32_t value, uint32_t count) {
    return (value >> count) | (value << (32 - count));
}

// Simple cryptographic hash function
void hash(const uint8_t *input, size_t length, uint8_t *output) {
    // Initial hash values
    uint32_t h[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t k[64] = {
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
        0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Preprocessing: Padding the input
    size_t total_length = length + 1; // Add one for the bit '1'
    while (total_length % BLOCK_SIZE != BLOCK_SIZE - 8) {
        total_length++;
    }
    
    uint8_t *padded_input = (uint8_t *)malloc(total_length);
    memcpy(padded_input, input, length);
    padded_input[length] = 0x80; // Append the bit '1'
    
    // Adding the length of the original message in bits
    uint64_t original_bit_length = length * 8;
    memcpy(padded_input + total_length - 8, &original_bit_length, sizeof(original_bit_length));

    // Processing in blocks
    for (size_t i = 0; i < total_length; i += BLOCK_SIZE) {
        // Prepare message schedule
        uint32_t w[64] = {0};
        for (size_t j = 0; j < 16; j++) {
            w[j] = (padded_input[i + j * 4] << 24) |
                   (padded_input[i + j * 4 + 1] << 16) |
                   (padded_input[i + j * 4 + 2] << 8) |
                   (padded_input[i + j * 4 + 3]);
        }
        for (size_t j = 16; j < 64; j++) {
            w[j] = w[j - 16] + w[j - 7] + 
                    rotate_right(w[j - 15], 7) + rotate_right(w[j - 2], 17);
        }

        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h0 = h[7];

        // Compression function main loop
        for (size_t j = 0; j < 64; j++) {
            uint32_t temp1 = h0 + rotate_right(e, 6) + 
                             ((e & f) ^ (~e & g)) + k[j] + w[j];
            uint32_t temp2 = rotate_right(a, 2) + 
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

        // Add the compressed chunk to the current hash value
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }

    // Produce the final hash value (big-endian)
    for (int i = 0; i < 8; i++) {
        output[i * 4]     = (h[i] >> 24) & 0xff;
        output[i * 4 + 1] = (h[i] >> 16) & 0xff;
        output[i * 4 + 2] = (h[i] >> 8) & 0xff;
        output[i * 4 + 3] = h[i] & 0xff;
    }

    free(padded_input);
}

// Helper function to print the hash
void print_hash(const uint8_t *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    const char *data = "Hello, World! This is a test of the cryptographic hash function.";
    
    uint8_t hash_output[HASH_SIZE];
    hash((const uint8_t *)data, strlen(data), hash_output);
    
    printf("Input: %s\n", data);
    printf("Hash: ");
    print_hash(hash_output);
    
    return 0;
}