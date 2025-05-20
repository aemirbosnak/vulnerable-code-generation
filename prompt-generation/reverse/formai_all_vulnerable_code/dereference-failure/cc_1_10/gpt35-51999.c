//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to rotate bits of a number to the left
uint32_t rotate_left(uint32_t value, uint32_t shift) {
    return (value << shift) | (value >> (32 - shift));
}

// Function to perform message padding
uint32_t* pad_message(const uint8_t* message, uint64_t message_length) {
    uint64_t block_count = ((message_length + 9) / 64) + 1;
    uint32_t* message_blocks = calloc(block_count * 16, sizeof(uint32_t));
    memcpy(message_blocks, message, message_length);

    // Adding padding
    uint64_t bit_length = message_length * 8;
    uint32_t padding_byte = 0x80;
    int padding_offset = message_length % 64;
    if (padding_offset < 56)
        padding_offset = 56 - padding_offset;
    else
        padding_offset = 120 - padding_offset;
    message_blocks[message_length / 4] |= (padding_byte << (24 - (8 * (message_length % 4))));
    message_blocks[((padding_offset + message_length) / 4) + 1] = bit_length >> 32;
    message_blocks[((padding_offset + message_length) / 4) + 2] = bit_length & 0xFFFFFFFF;
    return message_blocks;
}

// Hash function
void sha256(const uint8_t* message, uint64_t message_length, uint8_t hash[32]) {
    // Initializing constants for SHA-256
    const uint32_t k[] = {
        0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
        0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
        0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
        0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
        0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
        0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
        0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
        0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
        0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
        0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
        0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
        0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
        0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
        0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
        0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
        0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
    };

    // Initializing hash values for SHA-256
    uint32_t h[] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };

    // Padding message
    uint32_t* message_blocks = pad_message(message, message_length);

    // Processing message in 512-bit blocks
    for (int i = 0; i < (message_length + 8) / 64; i++) {
        uint32_t* block = message_blocks + (i * 16);

        // Initializing hash values for current block
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h_ = h[7];

        // Processing message block
        for (int j = 0; j < 64; j++) {
            uint32_t t1 = h_ + k[j] + block[j % 16] + (
                           (((e >> 6) | (e << 26)) ^ ((e >> 11) | (e << 21)) ^ ((e >> 25) | (e << 7))) +
                           ((e & f) ^ (~e & g)));
            uint32_t t2 = (((a >> 2) | (a << 30)) ^ ((a >> 13) | (a << 19)) ^ ((a >> 22) | (a << 10))) +
                          ((a & b) ^ (a & c) ^ (b & c));
            h_ = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Updating hash values for current block
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_;
    }

    free(message_blocks);

    // Converting hash to bytes
    for (int i = 0; i < 8; i++) {
        hash[i * 4] = h[i] >> 24;
        hash[(i * 4) + 1] = (h[i] >> 16) & 0xFF;
        hash[(i * 4) + 2] = (h[i] >> 8) & 0xFF;
        hash[(i * 4) + 3] = h[i] & 0xFF;
    }
}

int main() {
    uint8_t message[] = "Hello, World!";
    uint8_t hash[32];
    sha256(message, strlen(message), hash);
    printf("Hash: ");
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}