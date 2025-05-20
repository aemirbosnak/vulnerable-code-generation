//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to rotate bits of a 32-bit integer
static inline uint32_t rotate_bits(uint32_t value, uint32_t bits) {
    return (value << bits) | (value >> (32 - bits));
}

// Recursive function to calculate SHA-256 hash
void sha256_recursive(const uint8_t *message, size_t length, uint32_t state[8], size_t offset) {
    // Constants used in SHA-256 algorithm
    const uint32_t K[64] = {
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
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };
    
    // Buffer to hold message
    uint32_t buffer[16] = {0};
    
    // Fill buffer with next 64 bytes of message
    for (size_t i = 0; i < 16; i++) {
        buffer[i] = ((uint32_t) message[offset + i * 4] << 24) |
                    ((uint32_t) message[offset + i * 4 + 1] << 16) |
                    ((uint32_t) message[offset + i * 4 + 2] << 8) |
                    ((uint32_t) message[offset + i * 4 + 3]);
    }
    
    // Initialize working variables
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];
    
    // Perform 64 rounds of message processing
    for (size_t i = 0; i < 64; i++) {
        uint32_t S1 = rotate_bits(e, 6) ^ rotate_bits(e, 11) ^ rotate_bits(e, 25);
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + S1 + ch + K[i] + buffer[i % 16];
        uint32_t S0 = rotate_bits(a, 2) ^ rotate_bits(a, 13) ^ rotate_bits(a, 22);
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;
        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }
    
    // Update state with working variables
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
    
    // If there is more message to process, continue recursively
    if (offset + 64 < length) {
        sha256_recursive(message, length, state, offset + 64);
    }
}

// Function to calculate SHA-256 hash of a message
void sha256(const uint8_t *message, size_t length, uint8_t hash[32]) {
    // Initialize state variables
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    
    // Process message recursively
    sha256_recursive(message, length, state, 0);
    
    // Convert state variables to byte array
    uint8_t *hash_bytes = (uint8_t *) state;
    
    // Copy first 32 bytes of state to output hash
    memcpy(hash, hash_bytes, 32);
}

int main() {
    // Message to hash
    const char *message = "hello world";
    
    // Calculate hash of message
    uint8_t hash[32];
    sha256((uint8_t *) message, strlen(message), hash);
    
    // Print hash
    for (size_t i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}