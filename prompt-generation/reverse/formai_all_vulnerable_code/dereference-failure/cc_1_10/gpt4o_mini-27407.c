//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants for the hash computation
#define MD5_BLOCK_SIZE 64
#define MD5_DIGEST_SIZE 16

// Left-rotate function for MD5
static inline uint32_t left_rotate(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32 - c));
}

// Helper functions for MD5 operations
static uint32_t F(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}
static uint32_t G(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}
static uint32_t H(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}
static uint32_t I(uint32_t x, uint32_t y, uint32_t z) {
    return y ^ (x | ~z);
}

// Transformation function for MD5
void md5_transform(uint32_t state[4], const uint8_t block[MD5_BLOCK_SIZE]) {
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t x[16];
 
    // Copy block to x
    for (int i = 0; i < 16; i++) {
        x[i] = ((uint32_t)block[i * 4]) |
               ((uint32_t)block[i * 4 + 1] << 8) |
               ((uint32_t)block[i * 4 + 2] << 16) |
               ((uint32_t)block[i * 4 + 3] << 24);
    }

    // Perform operations
    // For each of the four rounds in MD5
    for (int i = 0; i < 64; i++) {
        uint32_t f, g;
        if (i < 16) {
            f = F(b, c, d);
            g = i;
        } else if (i < 32) {
            f = G(b, c, d);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = H(b, c, d);
            g = (3 * i + 5) % 16;
        } else {
            f = I(b, c, d);
            g = (7 * i) % 16;
        }
        
        f += a + x[g] + ((uint32_t[]){0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
                                       0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
                                       0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
                                       0x6ca6351, 0x14292967, 0x27b1a6b, 0x2441453}[i]) + 0; // Values from the original standard

        a = d;
        d = c;
        c = b;
        b += left_rotate(f, (uint32_t[]){7, 12, 17, 22, 7, 12, 17, 22,
                                           7, 12, 17, 22, 7, 12, 17, 22,
                                           5, 9, 14, 20, 5, 9, 14, 20,
                                           5, 9, 14, 20, 5, 9, 14, 20,
                                           4, 11, 16, 23, 4, 11, 16, 23,
                                           4, 11, 16, 23, 4, 11, 16, 23}[i]);
    }
    
    // Add the transformed values to the state
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

// MD5 hash function
void md5(const uint8_t *input, size_t length, uint8_t output[MD5_DIGEST_SIZE]) {
    // Initialize state
    uint32_t state[4] = {
        0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476
    };
    
    // Process input
    size_t padded_length = ((length + 8) / MD5_BLOCK_SIZE + 1) * MD5_BLOCK_SIZE;
    uint8_t *padded = (uint8_t *)calloc(padded_length, 1);
    memcpy(padded, input, length);
    padded[length] = 0x80; // Append the bit '1'

    // Set length
    uint64_t bit_length = length * 8;
    for (int i = 0; i < 8; i++) {
        padded[padded_length - 8 + i] = (uint8_t)(bit_length >> (i * 8));
    }

    // Process each 512-bit block
    for (size_t offset = 0; offset < padded_length; offset += MD5_BLOCK_SIZE) {
        md5_transform(state, padded + offset);
    }

    // Store the result
    for (int i = 0; i < 4; i++) {
        output[i * 4] = (uint8_t)(state[i]);
        output[i * 4 + 1] = (uint8_t)(state[i] >> 8);
        output[i * 4 + 2] = (uint8_t)(state[i] >> 16);
        output[i * 4 + 3] = (uint8_t)(state[i] >> 24);
    }

    // Clean up
    free(padded);
}

// Helper function to print the hash in hex format
void print_hash(const uint8_t *hash) {
    for (int i = 0; i < MD5_DIGEST_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    const char *message = "Hello, World!";
    uint8_t hash[MD5_DIGEST_SIZE];

    // Calculate MD5 hash
    md5((const uint8_t *)message, strlen(message), hash);
    
    // Print the result
    printf("MD5 hash of '%s': ", message);
    print_hash(hash);

    return 0;
}