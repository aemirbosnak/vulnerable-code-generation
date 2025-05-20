//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Define macros for left rotations and endian conversion
#define LEFT_ROTATE(x, n) ((x << n) | (x >> (32 - n)))
#define BIG_ENDIAN_TO_LITTLE_ENDIAN(x) (((x & 0xff000000) >> 24) | ((x & 0x00ff0000) >> 8) | ((x & 0x0000ff00) << 8) | ((x & 0x000000ff) << 24))

// The SHA-256 constants
const uint32_t k[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// The hash function implementation
void sha256(char* message, uint32_t hash[8])
{
    // Initialize variables to hold the intermediate hash values
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];

    // Initialize the initial hash values
    hash[0] = 0x6a09e667;
    hash[1] = 0xbb67ae85;
    hash[2] = 0x3c6ef372;
    hash[3] = 0xa54ff53a;
    hash[4] = 0x510e527f;
    hash[5] = 0x9b05688c;
    hash[6] = 0x1f83d9ab;
    hash[7] = 0x5be0cd19;

    // Store message length and add padding if necessary
    uint64_t message_len = strlen(message) * 8;
    uint64_t num_blocks = ((message_len + 64) / 512) + 1;
    uint64_t total_len = num_blocks * 512;
    char* padded_message = calloc(total_len / 8, sizeof(char));
    memcpy(padded_message, message, message_len / 8);
    padded_message[message_len / 8] |= 0x80;
    *((uint64_t*) (padded_message + total_len - 64)) = BIG_ENDIAN_TO_LITTLE_ENDIAN(message_len);

    // Process each block of the message
    for (i = 0; i < num_blocks; i++)
    {
        // Load the message block into the message schedule
        for (j = 0; j < 16; j++)
        {
            m[j] = *((uint32_t*) (padded_message + (i * 512 / 8) + (j * 4)));
            m[j] = BIG_ENDIAN_TO_LITTLE_ENDIAN(m[j]);
        }
        for (j = 16; j < 64; j++)
        {
            uint32_t s0 = LEFT_ROTATE(m[j - 15], 7) ^ LEFT_ROTATE(m[j - 15], 18) ^ (m[j - 15] >> 3);
            uint32_t s1 = LEFT_ROTATE(m[j - 2], 17) ^ LEFT_ROTATE(m[j - 2], 19) ^ (m[j - 2] >> 10);
            m[j] = m[j - 16] + s0 + m[j - 7] + s1;
        }

        // Initialize the working variables
        a = hash[0];
        b = hash[1];
        c = hash[2];
        d = hash[3];
        e = hash[4];
        f = hash[5];
        g = hash[6];
        h = hash[7];

        // Perform the hash computation
        for (j = 0; j < 64; j++)
        {
            t1 = h + (LEFT_ROTATE(e, 6) ^ LEFT_ROTATE(e, 11) ^ LEFT_ROTATE(e, 25)) + ((e & f) ^ (~e & g)) + k[j] + m[j];
            t2 = (LEFT_ROTATE(a, 2) ^ LEFT_ROTATE(a, 13) ^ LEFT_ROTATE(a, 22)) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update the hash values
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    }

    // Free dynamically allocated memory
    free(padded_message);
}

// Driver program to test the hash function
int main()
{
    // Test message and expected hash value
    char message[] = "Hello, world!";
    uint32_t expected_hash[8] =
    {
        0xb94d27b9, 0x123c6a1d, 0x9c1f98f2, 0x813b5597,
        0xafee43c0, 0x1802be32, 0x9b75d18a, 0xd953f6cb
    };

    // Compute the hash value and compare with the expected value
    uint32_t hash[8];
    sha256(message, hash);
    for (int i = 0; i < 8; i++)
    {
        if (hash[i] != expected_hash[i])
        {
            printf("Hash function test failed!\n");
            return -1;
        }
    }
    printf("Hash function test passed!\n");

    return 0;
}