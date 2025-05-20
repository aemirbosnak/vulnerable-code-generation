//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// SHA-256 Constants
#define SHA256_BLOCK_SIZE 32
#define SHA256_DIGEST_LENGTH 32

// SHA-256 functions and constants
static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x4e11b5c4, 0x761837f6, 0x9b0490ba,
    0xc66a1b38, 0xd192e819, 0xd6990624, 0xf40e3585,
    0x106aa070, 0x19a4c116, 0x1e376c48, 0x2748774c,
    0x34b0bcb5, 0x391c0cb3, 0x4ed8aa17, 0x5b9cca4f,
    0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814,
    0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
    0xc67178f2
};

// Rotate right function
uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

// SHA-256 transformation function
void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t w[64];
    
    for (int i = 0; i < 16; i++) {
        w[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) |
               (data[i * 4 + 2] << 8) | (data[i * 4 + 3]);
    }
    
    for (int i = 16; i < 64; i++) {
        w[i] = w[i - 16] + (rotr(w[i - 15], 7) ^ rotr(w[i - 15], 18) ^ (w[i - 15] >> 3)) +
               w[i - 7] + (rotr(w[i - 2], 17) ^ rotr(w[i - 2], 19) ^ (w[i - 2] >> 10));
    }

    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    for (int i = 0; i < 64; i++) {
        uint32_t t1 = h + (rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25)) + 
                      ((e & f) ^ (~e & g)) + k[i] + w[i];
        uint32_t t2 = (rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22)) + 
                      ((a & b) ^ (a & c) ^ (b & c));
        
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
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

// Main SHA-256 function
void sha256(const uint8_t *data, size_t len, uint8_t *hash) {
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    size_t numBlocks = (len + 8) / 64 + 1;

    uint8_t *buffer = (uint8_t *)calloc(numBlocks * 64, sizeof(uint8_t));
    
    memcpy(buffer, data, len);
    buffer[len] = 0x80;
    uint64_t bitLen = len * 8;
    
    memcpy(buffer + numBlocks * 64 - 8, &bitLen, sizeof(uint64_t));
    
    for (size_t i = 0; i < numBlocks; i++) {
        sha256_transform(state, buffer + i * 64);
    }

    for (int i = 0; i < 8; i++) {
        hash[i * 4]     = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = state[i] & 0xff;
    }

    free(buffer);
}

// Helper function to print the hash
void print_hash(uint8_t *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char input[1024];
    uint8_t hash[SHA256_BLOCK_SIZE];

    printf("Enter a string to hash: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character
    input[strcspn(input, "\n")] = 0; 

    sha256((uint8_t*)input, strlen(input), hash);
    
    printf("SHA-256 hash: ");
    print_hash(hash);
    
    return 0;
}