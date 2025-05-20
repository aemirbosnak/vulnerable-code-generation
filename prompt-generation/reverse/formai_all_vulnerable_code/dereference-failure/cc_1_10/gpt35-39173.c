//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define SWAP(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

// Function to perform the SHA-256 hash
void sha256(const uint8_t *data, uint32_t length, uint8_t *hash) {
    // Initialize Hash Values (Section 5.3.1) 
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

    // Initialize Round Constants (Section 4.2.2)
    uint32_t k[64] = {
        0x428a2f98, 
        0x71374491, 
        0xb5c0fbcf, 
        0xe9b5dba5, 
        0x3956c25b, 
        0x59f111f1, 
        0x923f82a4, 
        0xab1c5ed5, 
        0xd807aa98, 
        0x12835b01, 
        0x243185be, 
        0x550c7dc3, 
        0x72be5d74, 
        0x80deb1fe, 
        0x9bdc06a7, 
        0xc19bf174, 
        0xe49b69c1, 
        0xefbe4786, 
        0x0fc19dc6, 
        0x240ca1cc, 
        0x2de92c6f, 
        0x4a7484aa, 
        0x5cb0a9dc, 
        0x76f988da, 
        0x983e5152, 
        0xa831c66d, 
        0xb00327c8, 
        0xbf597fc7, 
        0xc6e00bf3, 
        0xd5a79147, 
        0x06ca6351, 
        0x14292967, 
        0x27b70a85, 
        0x2e1b2138, 
        0x4d2c6dfc, 
        0x53380d13, 
        0x650a7354, 
        0x766a0abb, 
        0x81c2c92e, 
        0x92722c85, 
        0xa2bfe8a1, 
        0xa81a664b, 
        0xc24b8b70, 
        0xc76c51a3, 
        0xd192e819, 
        0xd6990624, 
        0xf40e3585, 
        0x106aa070, 
        0x19a4c116, 
        0x1e376c08, 
        0x2748774c, 
        0x34b0bcb5, 
        0x391c0cb3, 
        0x4ed8aa4a, 
        0x5b9cca4f, 
        0x682e6ff3, 
        0x748f82ee, 
        0x78a5636f, 
        0x84c87814, 
        0x8cc70208, 
        0x90befffa, 
        0xa4506ceb, 
        0xbef9a3f7, 
        0xc67178f2
    };

    // Initialize Values for Compression Loop (Section 6.2)
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h1;
    uint32_t i, j, T1, T2;

    // Step 1: Append Padding Bits (Section 5.1.1)
    uint64_t bit_count = length * 8;
    uint32_t padding_len = (bit_count % 512) < 448 ? 448 - bit_count % 512 : 960 - bit_count % 512;
    uint32_t new_byte_len = length + padding_len / 8 + 8;
    uint8_t *new_data = malloc(new_byte_len);
    memcpy(new_data, data, length);
    new_data[length] = 0x80;
    for (i = 1; i < padding_len / 8; i++)
        new_data[length + i] = 0x00;
    for (i = 0; i < 8; i++)
        new_data[length + padding_len / 8 + i] = (bit_count >> 56 - i * 8) & 0xff;

    // Step 2: Initialize Message Schedule (Section 6.2)
    for (i = 0; i < new_byte_len / 64; i++) {
        // Copy Chunk from Message to Message Schedule
        for (j = 0; j < 16; j++) {
            w[j] = (uint32_t)new_data[i * 64 + j * 4] << 24 |
                   (uint32_t)new_data[i * 64 + j * 4 + 1] << 16 |
                   (uint32_t)new_data[i * 64 + j * 4 + 2] << 8 |
                   (uint32_t)new_data[i * 64 + j * 4 + 3];
        }

        // Extend Message Schedule (Section 6.2)
        for (j = 16; j < 64; j++) {
            uint32_t s0 = ROTATE_LEFT(w[j - 15], 7) ^ ROTATE_LEFT(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = ROTATE_LEFT(w[j - 2], 17) ^ ROTATE_LEFT(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        // Initialize Working Variables to Current Hash Value (Section 6.2)
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h1 = h[7];

        // Compression Loop (Section 6.2)
        for (j = 0; j < 64; j++) {
            uint32_t S1 = ROTATE_LEFT(e, 6) ^ ROTATE_LEFT(e, 11) ^ ROTATE_LEFT(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h1 + S1 + ch + k[j] + w[j];
            uint32_t S0 = ROTATE_LEFT(a, 2) ^ ROTATE_LEFT(a, 13) ^ ROTATE_LEFT(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h1 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add Compressed Chunk to Current Hash Value
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h1;
    }

    // Return Hash Value (Section 6.2)
    for (i = 0; i < 8; i++) {
        hash[i * 4 + 0] = (h[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
        hash[i * 4 + 3] = h[i] & 0xff;
    }

    // Free Allocated Memory
    free(new_data);
}

int main() {
    uint8_t data[] = "This is a test message.";
    uint8_t hash[32];

    sha256(data, sizeof(data) - 1, hash);

    printf("SHA-256 Hash of \"%s\":\n", data);
    for (int i = 0; i < 32; i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}