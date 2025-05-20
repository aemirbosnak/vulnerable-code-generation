//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Defining the size of the hash digest and the block size
#define HASH_SIZE 32
#define BLOCK_SIZE 64

// Define the rotate left macro
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Define the core hashing function
void core_hash(uint8_t *data, uint32_t length, uint8_t *hash)
{
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

    uint32_t w[64];

    uint32_t i, j;

    uint32_t a, b, c, d, e, f, g, h0;

    uint32_t s0, s1, ma, ch;

    // Pre-processing
    uint32_t padded_length = ((length + 8 + 63) / 64) * 64;
    uint8_t *padded_data = (uint8_t *)calloc(padded_length, sizeof(uint8_t));
    memcpy(padded_data, data, length);
    padded_data[length] = 0x80;
    *(uint64_t *)(padded_data + padded_length - 8) = length * 8;

    // Main loop
    for (i = 0; i < padded_length; i += BLOCK_SIZE) {
        // Prepare the message schedule
        for (j = 0; j < 16; j++) {
            w[j] = (padded_data[i + 4 * j] << 24)
                | (padded_data[i + 4 * j + 1] << 16)
                | (padded_data[i + 4 * j + 2] << 8)
                | (padded_data[i + 4 * j + 3]);
        }
        for (j = 16; j < 64; j++) {
            s0 = ROTL(w[j - 15], 7) ^ ROTL(w[j - 15], 18) ^ (w[j - 15] >> 3);
            s1 = ROTL(w[j - 2], 17) ^ ROTL(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // Initialize the working variables
        a = h[0]; b = h[1]; c = h[2]; d = h[3];
        e = h[4]; f = h[5]; g = h[6]; h0 = h[7];

        // Compression function
        for (j = 0; j < 64; j++) {
            s0 = ROTL(a, 2) ^ ROTL(a, 13) ^ ROTL(a, 22);
            ma = (a & b) ^ (a & c) ^ (b & c);
            ch = (e & f) ^ ((~e) & g);
            s1 = ROTL(e, 6) ^ ROTL(e, 11) ^ ROTL(e, 25);

            h0 = g;
            g = f;
            f = e;
            e = d + s1 + ch + w[j] + h0;
            d = c;
            c = b;
            b = a;
            a = s0 + ma + e;
        }

        // Update the hash values
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h0;
    }

    // Generate the hash digest
    for (i = 0; i < HASH_SIZE; i += 4) {
        hash[i] = (h[i / 4] >> 24) & 0xFF;
        hash[i + 1] = (h[i / 4] >> 16) & 0xFF;
        hash[i + 2] = (h[i / 4] >> 8) & 0xFF;
        hash[i + 3] = h[i / 4] & 0xFF;
    }

    // Free the memory
    free(padded_data);
}

// Define the main function to use the hash function
int main(int argc, char *argv[])
{
    // Define a string to hash
    char *message = "This is a message to hash.";

    // Hash the string
    uint8_t hash[HASH_SIZE];
    core_hash((uint8_t *)message, strlen(message), hash);

    // Print the hash digest
    uint32_t i;
    printf("Hash digest: ");
    for (i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}