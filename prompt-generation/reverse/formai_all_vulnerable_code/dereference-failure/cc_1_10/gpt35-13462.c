//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n))) // Define a left rotation macro

// Initialize constants for the sha-256 hash function
const uint32_t K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Define the initial hash values for the sha-256 hash function
const uint32_t H[] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// Define the sigma0 and sigma1 functions used by the sha-256 hash function
uint32_t sigma0(uint32_t x)
{
    return ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22);
}

uint32_t sigma1(uint32_t x)
{
    return ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25);
}

// Define the sha-256 hash function
void sha256(const uint8_t *message, uint32_t message_length, uint8_t *hash)
{
    uint32_t W[64], a, b, c, d, e, f, g, h, T1, T2;

    // Initialize the working variables with the initial hash values
    a = H[0], b = H[1], c = H[2], d = H[3], e = H[4], f = H[5], g = H[6], h = H[7];

    // Pad the message with 1 bit followed by 0 bits until the message length is 448 bits mod 512
    uint64_t bit_length = message_length * 8;
    int padding_length = (message_length % 64 < 56) ? (56 - message_length % 64) : (120 - message_length % 64);
    uint8_t padding[padding_length + 8];
    padding[0] = 0x80;
    for (int i = 1; i < padding_length; i++)
        padding[i] = 0x00;
    for (int i = 0; i < 8; i++)
        padding[padding_length + i] = (bit_length >> (56 - i * 8)) & 0xff;

    // Process each 512-bit block of the padded message
    for (int i = 0; i < message_length + padding_length; i += 64)
    {
        // Prepare the message schedule W
        for (int t = 0; t < 16; t++)
            W[t] = (message[i + t * 4] << 24) | (message[i + t * 4 + 1] << 16) | (message[i + t * 4 + 2] << 8) | message[i + t * 4 + 3];
        for (int t = 16; t < 64; t++)
            W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16];

        // Update the working variables
        for (int t = 0; t < 64; t++)
        {
            T1 = h + sigma1(e) + ((e & f) ^ (~e & g)) + K[t] + W[t];
            T2 = sigma0(a) + ((a & b) ^ (a & c) ^ (b & c));
            h = g, g = f, f = e, e = d + T1, d = c, c = b, b = a, a = T1 + T2;
        }
        a += H[0], b += H[1], c += H[2], d += H[3], e += H[4], f += H[5], g += H[6], h += H[7];
    }

    // Copy the final hash state to the output buffer
    hash[0] = (a >> 24) & 0xff, hash[1] = (a >> 16) & 0xff, hash[2] = (a >> 8) & 0xff, hash[3] = a & 0xff;
    hash[4] = (b >> 24) & 0xff, hash[5] = (b >> 16) & 0xff, hash[6] = (b >> 8) & 0xff, hash[7] = b & 0xff;
    hash[8] = (c >> 24) & 0xff, hash[9] = (c >> 16) & 0xff, hash[10] = (c >> 8) & 0xff, hash[11] = c & 0xff;
    hash[12] = (d >> 24) & 0xff, hash[13] = (d >> 16) & 0xff, hash[14] = (d >> 8) & 0xff, hash[15] = d & 0xff;
    hash[16] = (e >> 24) & 0xff, hash[17] = (e >> 16) & 0xff, hash[18] = (e >> 8) & 0xff, hash[19] = e & 0xff;
    hash[20] = (f >> 24) & 0xff, hash[21] = (f >> 16) & 0xff, hash[22] = (f >> 8) & 0xff, hash[23] = f & 0xff;
    hash[24] = (g >> 24) & 0xff, hash[25] = (g >> 16) & 0xff, hash[26] = (g >> 8) & 0xff, hash[27] = g & 0xff;
    hash[28] = (h >> 24) & 0xff, hash[29] = (h >> 16) & 0xff, hash[30] = (h >> 8) & 0xff, hash[31] = h & 0xff;
}

int main()
{
    uint8_t message[] = "The quick brown fox jumps over the lazy dog";
    uint8_t hash[256/8];

    sha256(message, sizeof(message)-1, hash);

    printf("Message to hash: %s\n", message);
    printf("Hash length: %d\n", 256/8);
    printf("Hash: ");
    for (int i = 0; i < 256/8; i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}