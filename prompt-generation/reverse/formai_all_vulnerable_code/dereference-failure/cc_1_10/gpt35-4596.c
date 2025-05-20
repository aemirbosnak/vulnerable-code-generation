//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
// C Cryptographic Hash Function Example Program
// Retro Style Implementation

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define the block size and hash size for the hash function
#define BLOCK_SIZE 64
#define HASH_SIZE 32

// Define the initial hash values for the hash function
#define INIT_HASH_0 0x6a09e667
#define INIT_HASH_1 0xbb67ae85
#define INIT_HASH_2 0x3c6ef372
#define INIT_HASH_3 0xa54ff53a
#define INIT_HASH_4 0x510e527f
#define INIT_HASH_5 0x9b05688c
#define INIT_HASH_6 0x1f83d9ab
#define INIT_HASH_7 0x5be0cd19

// Define the round constant values for the hash function
const uint32_t ROUND_CONST[64] = {
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

// Define the rotate functions for the hash function
#define ROT_LEFT(x, n) ((x << n) | (x >> (32 - n)))
#define ROT_RIGHT(x, n) ((x >> n) | (x << (32 - n)))

// Define the function prototypes for the hash function
void hash(uint8_t *message, uint32_t length, uint8_t *digest);

// Main function
int main() {

    // Define the test message and expected hash
    uint8_t *message = "The quick brown fox jumps over the lazy dog";
    uint8_t expected_digest[HASH_SIZE] = {0x2f, 0xd4, 0xe1, 0xc6, 0x7a, 0x2d, 0x28, 0xfc, 
                                          0xed, 0x84, 0x9e, 0xe1, 0xbb, 0x76, 0xe7, 0x39, 
                                          0x1b, 0x93, 0xeb, 0x12, 0x30, 0x75, 0x16, 0x89, 
                                          0xcf, 0x91, 0x00, 0x6e, 0x24, 0x4e, 0x8d, 0x2f};

    // Define an array to hold the resulting hash
    uint8_t digest[HASH_SIZE];

    // Call the hash function with the test message
    hash(message, strlen(message), digest);

    // Compare the resulting hash with the expected hash
    int match = memcmp(digest, expected_digest, HASH_SIZE);

    // Print the test results
    printf("Message: %s\n", message);
    printf("Expected Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", expected_digest[i]);
    }
    printf("\nResulting Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    if (match == 0) {
        printf("Test Passed!\n");
    } else {
        printf("Test Failed!\n");
    }

    return 0;
}

// Hash function implementation
void hash(uint8_t *message, uint32_t length, uint8_t *digest) {

    // Define the working variables and temporary variable for the hash function
    uint32_t hash_values[8] = {INIT_HASH_0, INIT_HASH_1, INIT_HASH_2, INIT_HASH_3, INIT_HASH_4, INIT_HASH_5, INIT_HASH_6, INIT_HASH_7};
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, temp1, temp2;

    // Pad the message to a multiple of the block size
    uint32_t padded_length = length;
    if (padded_length % BLOCK_SIZE < 56) {
        padded_length += BLOCK_SIZE - (padded_length % BLOCK_SIZE);
    } else {
        padded_length += 2 * BLOCK_SIZE - (padded_length % BLOCK_SIZE);
    }
    uint8_t *padded_message = (uint8_t *) malloc(padded_length);
    memcpy(padded_message, message, length);
    padded_message[length] = 0x80;
    for (int i = length + 1; i < padded_length - 8; i++) {
        padded_message[i] = 0x00;
    }
    uint64_t bit_length = length * 8;
    memcpy(padded_message + padded_length - 8, &bit_length, 8);

    // Process each block of the padded message
    for (int i = 0; i < padded_length; i += BLOCK_SIZE) {

        // Calculate the initial message schedule
        for (int t = 0; t < 16; t++) {
            w[t] = (padded_message[i + 4 * t] << 24) | (padded_message[i + 4 * t + 1] << 16) | (padded_message[i + 4 * t + 2] << 8) | (padded_message[i + 4 * t + 3]);
        }
        for (int t = 16; t < 64; t++) {
            w[t] = ROT_RIGHT(w[t - 15], 7) ^ ROT_RIGHT(w[t - 15], 18) ^ (w[t - 15] >> 3);
            w[t] += ROT_RIGHT(w[t - 2], 17) ^ ROT_RIGHT(w[t - 2], 19) ^ (w[t - 2] >> 10);
            w[t] += w[t - 16] + w[t - 7] + ROUND_CONST[t];
        }

        // Initialize working variables with the previous hash values
        a = hash_values[0];
        b = hash_values[1];
        c = hash_values[2];
        d = hash_values[3];
        e = hash_values[4];
        f = hash_values[5];
        g = hash_values[6];
        h = hash_values[7];

        // Main loop of the hash function
        for (int t = 0; t < 64; t++) {
            temp1 = h + (ROT_RIGHT(e, 6) ^ ROT_RIGHT(e, 11) ^ ROT_RIGHT(e, 25)) + ((e & f) ^ ((~e) & g)) + ROUND_CONST[t] + w[t];
            temp2 = (ROT_RIGHT(a, 2) ^ ROT_RIGHT(a, 13) ^ ROT_RIGHT(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Update the hash values with the recent hash calculations
        hash_values[0] += a;
        hash_values[1] += b;
        hash_values[2] += c;
        hash_values[3] += d;
        hash_values[4] += e;
        hash_values[5] += f;
        hash_values[6] += g;
        hash_values[7] += h;
    }

    // Copy the final hash values to the hash digest
    for (int i = 0; i < 8; i++) {
        digest[4 * i] = (hash_values[i] >> 24) & 0xff;
        digest[4 * i + 1] = (hash_values[i] >> 16) & 0xff;
        digest[4 * i + 2] = (hash_values[i] >> 8) & 0xff;
        digest[4 * i + 3] = hash_values[i] & 0xff;
    }

    // Free the memory allocated for padding the message
    free(padded_message);
}