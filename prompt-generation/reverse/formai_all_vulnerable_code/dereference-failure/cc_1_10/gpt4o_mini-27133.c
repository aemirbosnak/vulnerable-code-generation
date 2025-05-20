//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Constants for the hash function
#define HASH_SIZE 32 // Output size in bytes (256 bits)
#define BLOCK_SIZE 64 // Block size for processing (512 bits)

uint8_t* sha256(const uint8_t* data, size_t len);
static void sha256_transform(uint32_t *state, const uint8_t *data);
static void sha256_init(uint32_t *state);
static void sha256_update(uint32_t *state, const uint8_t *data, size_t len);
static void sha256_final(uint32_t *state, uint8_t *digest);

// Function prototypes
void print_hash(uint8_t *hash);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string_to_hash>\n", argv[0]);
        return 1;
    }

    const char *input_string = argv[1];
    size_t input_length = strlen(input_string);
    
    uint8_t *hash = sha256((const uint8_t *)input_string, input_length);
    print_hash(hash);
    
    free(hash);
    return 0;
}

// Function to print the hash
void print_hash(uint8_t *hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// SHA-256 Hash function
uint8_t* sha256(const uint8_t* data, size_t len) {
    uint32_t state[8];
    uint8_t *digest = (uint8_t *)malloc(HASH_SIZE);
    
    sha256_init(state);
    sha256_update(state, data, len);
    sha256_final(state, digest);
    
    return digest;
}

// Initialize SHA256 state
static void sha256_init(uint32_t *state) {
    state[0] = 0x6a09e667;
    state[1] = 0xbb67ae85;
    state[2] = 0x3c6ef372;
    state[3] = 0xa54ff53a;
    state[4] = 0x510e527f;
    state[5] = 0x9b05688c;
    state[6] = 0x1f83d9ab;
    state[7] = 0x5be0cd19;
}

// Update hash state with data
static void sha256_update(uint32_t *state, const uint8_t *data, size_t len) {
    size_t i = 0;
    while (len > 0) {
        size_t to_copy = len < BLOCK_SIZE ? len : BLOCK_SIZE;
        sha256_transform(state, data + i);
        i += to_copy;
        len -= to_copy;
    }
}

// Finalize the SHA256 hash
static void sha256_final(uint32_t *state, uint8_t *digest) {
    for (int i = 0; i < 8; i++) {
        digest[i * 4 + 0] = (state[i] >> 24) & 0xff;
        digest[i * 4 + 1] = (state[i] >> 16) & 0xff;
        digest[i * 4 + 2] = (state[i] >> 8) & 0xff;
        digest[i * 4 + 3] = state[i] & 0xff;
    }
}

// SHA256 transformation algorithm for a 512-bit chunk
static void sha256_transform(uint32_t *state, const uint8_t *data) {
    // Constants
    static const uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 
        0x59f111f1, 0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 
        0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 
        0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 
        0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 
        0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 
        0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 
        0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116, 0x1e376c48, 
        0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa11, 0x5b9cca4f, 
        0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Variables
    uint32_t w[64] = {0};
    uint32_t a, b, c, d, e, f, g, h;

    for (int i = 0; i < 16; i++) {
        w[i] = ((uint32_t)data[i * 4] << 24) |
               ((uint32_t)data[i * 4 + 1] << 16) |
               ((uint32_t)data[i * 4 + 2] << 8) |
               (uint32_t)data[i * 4 + 3];
    }
    
    for (int i = 16; i < 64; i++) {
        uint32_t s0 = (w[i - 15] >> 7) | (w[i - 15] << (32 - 7));
        s0 ^= (w[i - 15] >> 18) | (w[i - 15] << (32 - 18));
        s0 ^= (w[i - 15] >> 3);
        
        uint32_t s1 = (w[i - 2] >> 17) | (w[i - 2] << (32 - 17));
        s1 ^= (w[i - 2] >> 19) | (w[i - 2] << (32 - 19));
        s1 ^= (w[i - 2] >> 10);
        
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
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
        uint32_t S1 = (e >> 6) | (e << (32 - 6));
        S1 ^= (e >> 11) | (e << (32 - 11));
        S1 ^= (e >> 25) | (e << (32 - 25));
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t temp1 = h + S1 + ch + k[i] + w[i];
        
        uint32_t S0 = (a >> 2) | (a << (32 - 2));
        S0 ^= (a >> 13) | (a << (32 - 13));
        S0 ^= (a >> 22) | (a << (32 - 22));
        uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp2 = S0 + maj;

        h = g; // Previous hash value
        g = f;
        f = e;
        e = d + temp1; // New hash values
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2; // Final update
    }
    
    // Add the compressed hash to the current state
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}