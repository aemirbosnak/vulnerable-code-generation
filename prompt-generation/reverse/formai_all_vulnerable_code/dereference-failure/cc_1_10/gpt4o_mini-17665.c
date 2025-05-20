//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 32   // Size of hash in bytes
#define BLOCK_SIZE 64  // Size of a single block in bytes
#define FINAL_SIZE 56  // Size of data to append for the final block

// Structure to hold the state of our hash function
typedef struct {
    uint32_t state[8]; // Holds the state of the hash
    uint64_t count;     // Number of bits processed
    uint8_t buffer[BLOCK_SIZE]; // Buffer for data to process
} HashState;

// Constants defined in the SHA-256 specification
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc67178f2
};

// Function to rotate a 32-bit integer right
uint32_t rightRotate(uint32_t value, uint32_t amount) {
    return (value >> amount) | (value << (32 - amount));
}

// Function to process a single block of data
void processBlock(HashState *hash, const uint8_t *block) {
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h;
    int t;

    // Prepare the message schedule
    for (t = 0; t < 16; t++) {
        W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) |
               (block[t * 4 + 2] << 8) | block[t * 4 + 3];
    }
    for (t = 16; t < 64; t++) {
        W[t] = rightRotate(W[t - 2], 17) ^ rightRotate(W[t - 2], 19) ^ (W[t - 2] >> 10);
        W[t] += W[t - 7] + rightRotate(W[t - 16], 7) ^ rightRotate(W[t - 16], 18) ^ (W[t - 16] >> 3);
        W[t] += W[t - 16];
    }

    // Initialize the working variables to current hash value
    a = hash->state[0];
    b = hash->state[1];
    c = hash->state[2];
    d = hash->state[3];
    e = hash->state[4];
    f = hash->state[5];
    g = hash->state[6];
    h = hash->state[7];

    // Main loop
    for (t = 0; t < 64; t++) {
        uint32_t T1 = h + (rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25)) + 
                      ((e & f) ^ (~e & g)) + K[t] + W[t];
        uint32_t T2 = (rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22)) + 
                      ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    // Add the compressed values back to the current hash value
    hash->state[0] += a;
    hash->state[1] += b;
    hash->state[2] += c;
    hash->state[3] += d;
    hash->state[4] += e;
    hash->state[5] += f;
    hash->state[6] += g;
    hash->state[7] += h;
}

// Initialize the hash state
void initHash(HashState *hash) {
    hash->count = 0;
    hash->state[0] = 0x6a09e667;
    hash->state[1] = 0xbb67ae85;
    hash->state[2] = 0x3c6ef372;
    hash->state[3] = 0xa54ff53a;
    hash->state[4] = 0x510e527f;
    hash->state[5] = 0x9b05688c;
    hash->state[6] = 0x1f83d9ab;
    hash->state[7] = 0x5be0cd19;
}

// Finalize and produce the hash value
void finalizeHash(HashState *hash, uint8_t *output) {
    uint64_t bitCount = hash->count * 8;
    size_t paddingSize = (bitCount % 512 < 448) ? (448 - (bitCount % 512) + 512) : (960 - (bitCount % 512));
    uint8_t padding[BLOCK_SIZE] = {0};
    
    // Append the '1' bit
    padding[0] = 0x80;
    
    // Append the length
    for (int i = 0; i < 8; i++) {
        padding[paddingSize - 8 + i] = (bitCount >> (56 - i * 8)) & 0xFF;
    }
    
    // Process the padding blocks
    processBlock(hash, padding);
    
    // Produce the final hash value
    for (int i = 0; i < 8; i++) {
        output[i * 4] = (hash->state[i] >> 24) & 0xFF;
        output[i * 4 + 1] = (hash->state[i] >> 16) & 0xFF;
        output[i * 4 + 2] = (hash->state[i] >> 8) & 0xFF;
        output[i * 4 + 3] = hash->state[i] & 0xFF;
    }
}

// Main function to demonstrate the hash function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string to hash>\n", argv[0]);
        return 1;
    }

    HashState hashState;
    uint8_t digest[HASH_SIZE];

    // Initialize the hash state
    initHash(&hashState);
    
    // Process the input string
    size_t inputLength = strlen(argv[1]);
    hashState.count = inputLength;    
    processBlock(&hashState, (uint8_t *)argv[1]);
    
    // Finalize and obtain the hash
    finalizeHash(&hashState, digest);

    // Print the resulting hash in hex format
    printf("SHA-256 Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}