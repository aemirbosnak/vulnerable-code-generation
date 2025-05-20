//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// SHA-256 Constants
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

// SHA-256 Functions
uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

uint32_t sig0(uint32_t x) {
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

uint32_t sig1(uint32_t x) {
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

uint32_t theta0(uint32_t x) {
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

uint32_t theta1(uint32_t x) {
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

// SHA-256 Hash Function
void sha256(const unsigned char *msg, size_t len, unsigned char *hash) {
    // Initialize variables
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t w[64]; // Message schedule
    uint32_t a, b, c, d, e, f, g, h0, h1, h2, h3, h4, h5, h6, h7; // Working variables
    uint32_t t1, t2; // Temporary variables

    uint32_t i, j;

    size_t new_len;
    unsigned char *padded_msg;

    // Pad the message
    new_len = len + 1 + 8;
    new_len += (new_len % 64 == 0) ? 0 : (64 - new_len % 64);
    padded_msg = (unsigned char*)calloc(new_len, sizeof(unsigned char));
    memcpy(padded_msg, msg, len);
    padded_msg[len] = 0x80;
    for (i = len + 1; i < new_len - 8; i++) {
        padded_msg[i] = 0;
    }
    memcpy(padded_msg + new_len - 8, &len, sizeof(len) * 8);

    // Process the message in 512-bit blocks
    for (i = 0; i < new_len; i += 64) {
        // Load the block into the message schedule
        for (j = 0; j < 16; j++) {
            w[j] = ((uint32_t)padded_msg[i + j * 4] << 24) |
                   ((uint32_t)padded_msg[i + j * 4 + 1] << 16) |
                   ((uint32_t)padded_msg[i + j * 4 + 2] << 8) |
                   ((uint32_t)padded_msg[i + j * 4 + 3]);
        }
        for (j = 16; j < 64; j++) {
            w[j] = theta1(w[j - 2]) + w[j - 7] + theta0(w[j - 15]) + w[j - 16];
        }

        // Initialize the working variables
        a = h[0]; b = h[1]; c = h[2]; d = h[3]; e = h[4]; f = h[5]; g = h[6]; h0 = h[7];

        // Perform the hash computation
        for (j = 0; j < 64; j++) {
            t1 = h0 + sig1(e) + ch(e, f, g) + K[j] + w[j];
            t2 = sig0(a) + maj(a, b, c);
            h0 = g; g = f; f = e; e = d + t1; d = c; c = b; b = a; a = t1 + t2;
        }

        // Update the hash values
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h0;
    }

    // Output the hash as a byte array
    memcpy(hash, h, 32);

    // Free memory
    free(padded_msg);
}

int main() {
    const char *msg = "Hello World!";
    unsigned char hash[32];

    sha256((const unsigned char*)msg, strlen(msg), hash);

    printf("Message: %s\n", msg);
    printf("Hash: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}