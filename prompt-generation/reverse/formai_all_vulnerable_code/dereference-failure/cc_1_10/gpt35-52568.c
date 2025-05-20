//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32
#define SHA256_HASH_SIZE  32
#define SHA256_ROUNDS     64

// Initial hash values for SHA-256
uint32_t SHA256_INITIAL_HASH_VALUES[SHA256_HASH_SIZE/sizeof(uint32_t)] = 
{
    0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
    0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
};

// Function for SHA-256 rounds
uint32_t SHA256_ROUND(uint32_t x, uint32_t y, uint32_t z, uint32_t i)
{
    if (i < 16)
    {
        return (x & y) ^ (~x & z);
    }
    else
    {
        return (x & y) ^ (x & z) ^ (y & z);
    }
}

// Function for right rotate
uint32_t SHA256_ROR(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}

// Function to calculate SHA-256 hash of a message
void SHA256(uint8_t* message, uint32_t message_length, uint8_t* hash)
{
    // Initialize variables
    uint32_t h[SHA256_ROUNDS];
    for (int i = 0; i < SHA256_HASH_SIZE/sizeof(uint32_t); i++)
    {
        h[i] = SHA256_INITIAL_HASH_VALUES[i];
    }
    uint32_t w[SHA256_ROUNDS];
    uint32_t a, b, c, d, e, f, g, h0;

    // Pre-processing: pad message to 512-bit length
    uint64_t bit_length = message_length * 8;
    uint32_t padding_count = (448 - (message_length * 8 + 1) % 512) / 8 + 1;
    uint32_t padded_length = message_length + padding_count + 8;
    uint8_t* padded_message = (uint8_t*) calloc(padded_length, 1);
    memcpy(padded_message, message, message_length);
    padded_message[message_length] = 0x80;
    memcpy(padded_message + padded_length - 8, &bit_length, 8);

    // Message processing: iterate over 512-bit blocks
    for (int block_start = 0; block_start < padded_length; block_start += 64)
    {
        // Initialize message schedule
        for (int i = 0; i < 16; i++)
        {
            w[i] = *((uint32_t*) (padded_message + block_start + i*4));
        }
        for (int i = 16; i < SHA256_ROUNDS; i++)
        {
            w[i] = SHA256_ROR(w[i-2], 17) ^ SHA256_ROR(w[i-2], 19) ^ (w[i-2] >> 10);
            w[i] += w[i-7];
            w[i] += SHA256_ROR(w[i-15], 7) ^ SHA256_ROR(w[i-15], 18) ^ (w[i-15] >> 3);
            w[i] += w[i-16];
        }

        // Initialize working variables
        a = h[0]; b = h[1]; c = h[2]; d = h[3];
        e = h[4]; f = h[5]; g = h[6]; h0 = h[7];

        // Compression
        for (int i = 0; i < SHA256_ROUNDS; i++)
        {
            uint32_t t1 = h0 + SHA256_ROUND(e, f, g, i) + w[i] + 
                (i < 16 ? 0x428A2F98 : (i < 32 ? 0x71374491 : (i < 48 ? 0xB5C0FBCF : 0xE9B5DBA5)));
            uint32_t t2 = SHA256_ROUND(a, b, c, i) + 
                (i < 16 ? (d ^ 0x80000000) : (i < 64 ? (d & b) ^ (~d & c) : 0));

            h0 = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Compute intermediate hash value
        h[0] = a + h[0];
        h[1] = b + h[1];
        h[2] = c + h[2];
        h[3] = d + h[3];
        h[4] = e + h[4];
        h[5] = f + h[5];
        h[6] = g + h[6];
        h[7] = h0 + h[7];
    }

    // Output final hash value
    for (int i = 0; i < SHA256_HASH_SIZE/sizeof(uint32_t); i++)
    {
        *((uint32_t*) (hash + i*4)) = h[i];
    }

    // Free memory
    free(padded_message);
}

int main()
{
    // Example usage
    uint8_t message[] = "Hello, world!";
    uint8_t hash[SHA256_HASH_SIZE];
    SHA256(message, strlen(message), hash);

    printf("Message: %s\n", message);

    printf("Hash: ");
    for (int i = 0; i < SHA256_HASH_SIZE; i++)
    {
        printf("%02X", hash[i]);
    }
    printf("\n");

    return 0;
}