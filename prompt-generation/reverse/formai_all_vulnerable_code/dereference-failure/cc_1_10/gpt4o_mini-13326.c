//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32  // Size of the output hash in bytes (256 bits)
#define BLOCK_SIZE 64 // Size of each block (512 bits = 64 bytes)

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
    0x19b4c8f7, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Initial Hash Values
uint32_t h[8] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Function to perform the right rotation
uint32_t right_rotate(uint32_t value, uint32_t amount) {
    return (value >> amount) | (value << (32 - amount));
}

// SHA-256 Compression function
void sha256_transform(uint32_t state[8], const uint8_t data[BLOCK_SIZE]) {
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, hTemp;
    
    // Message schedule preparation
    for (int i = 0; i < 16; i++) {
        w[i] = ((uint32_t)data[i * 4] << 24) |
               ((uint32_t)data[i * 4 + 1] << 16) |
               ((uint32_t)data[i * 4 + 2] << 8) |
               ((uint32_t)data[i * 4 + 3]);
    }
    
    for (int i = 16; i < 64; i++) {
        w[i] = right_rotate(w[i - 2], 17) ^ right_rotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] += w[i - 7] + right_rotate(w[i - 15], 7) ^ right_rotate(w[i - 15], 18) ^ (w[i - 15] >> 3);
        w[i] += w[i - 16];
    }
    
    // Initialize working variables
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    hTemp = state[7];
    
    // Main loop
    for (int i = 0; i < 64; i++) {
        uint32_t t1 = hTemp + (right_rotate(e, 6) ^ right_rotate(e, 11) ^ right_rotate(e, 25)) + 
                      ((e & f) ^ (~e & g)) + k[i] + w[i];
        uint32_t t2 = (right_rotate(a, 2) ^ right_rotate(a, 13) ^ right_rotate(a, 22)) +
                      ((a & b) ^ (a & c) ^ (b & c));
        
        hTemp = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }
    
    // Add the compressed chunk to the current hash value
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += hTemp;
}

// SHA-256 Hash Function
void sha256(const uint8_t *input, size_t length, uint8_t output[HASH_SIZE]) {
    uint8_t buffer[BLOCK_SIZE];
    size_t input_len = length;
    
    // Padding the input
    size_t padded_size = ((input_len + 8) / BLOCK_SIZE + 1) * BLOCK_SIZE;
    uint8_t *padded_input = (uint8_t *)malloc(padded_size);
    memcpy(padded_input, input, length);
    
    padded_input[input_len] = 0x80; // Append the bit '1'
    memset(padded_input + input_len + 1, 0, padded_size - input_len - 9);
    
    // Append the length of the original message (in bits) at the end
    uint64_t bit_length = input_len * 8;
    memcpy(padded_input + padded_size - 8, &bit_length, 8);
    
    // Process each 512-bit (64 bytes) chunk
    for (size_t i = 0; i < padded_size; i += BLOCK_SIZE) {
        sha256_transform(h, padded_input + i);
    }
    
    // Produce the final hash value
    for (int i = 0; i < 8; i++) {
        output[i * 4] = (h[i] >> 24) & 0xff;
        output[i * 4 + 1] = (h[i] >> 16) & 0xff;
        output[i * 4 + 2] = (h[i] >> 8) & 0xff;
        output[i * 4 + 3] = h[i] & 0xff;
    }
    
    free(padded_input);
}

int main() {
    const char *message = "Hello, World!";
    uint8_t hash[HASH_SIZE];
    
    sha256((const uint8_t *)message, strlen(message), hash);
    
    printf("SHA-256 Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    return 0;
}