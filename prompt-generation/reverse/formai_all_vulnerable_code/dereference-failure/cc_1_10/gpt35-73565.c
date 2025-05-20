//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Definition of SHA-256 constants
uint32_t K[64] = {
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

// Define SHA-256 functions
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHR(x, n) ((x) >> (n))
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define EP1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

// SHA-256 hash function
void sha256(const uint8_t *message, uint32_t len, uint32_t hash[8]) {
    // Initialize hash values
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Pre-processing
    uint32_t bits_len = len * 8;
    uint32_t padding_len = (bits_len % 512 < 448) ? (448 - bits_len % 512) : (960 - bits_len % 512);
    uint32_t total_len = bits_len + padding_len + 64;
    uint8_t *padded_msg = calloc(total_len / 8, sizeof(uint8_t));
    memcpy(padded_msg, message, len);
    padded_msg[len] = 0x80;
    for (uint32_t i = 0; i < padding_len / 8; i++) {
        padded_msg[len + 1 + i] = 0x00;
    }
    for (uint32_t i = 0; i < 8; i++) {
        padded_msg[total_len / 8 - 8 + i] = (bits_len >> 8 * (7 - i)) & 0xff;
    }

    // Process message in 512-bit chunks
    for (uint32_t i = 0; i < total_len / 512; i++) {
        uint32_t W[64];
        for (uint32_t j = 0; j < 16; j++) {
            W[j] = (padded_msg + i * 64)[4 * j] << 24 |
                   (padded_msg + i * 64)[4 * j + 1] << 16 |
                   (padded_msg + i * 64)[4 * j + 2] << 8 |
                   (padded_msg + i * 64)[4 * j + 3];
        }
        for (uint32_t j = 16; j < 64; j++) {
            W[j] = SIG1(W[j - 2]) + W[j - 7] + SIG0(W[j - 15]) + W[j - 16];
        }

        uint32_t a = H[0];
        uint32_t b = H[1];
        uint32_t c = H[2];
        uint32_t d = H[3];
        uint32_t e = H[4];
        uint32_t f = H[5];
        uint32_t g = H[6];
        uint32_t h = H[7];

        for (uint32_t j = 0; j < 64; j++) {
            uint32_t T1 = h + EP1(e) + CH(e, f, g) + K[j] + W[j];
            uint32_t T2 = EP0(a) + MAJ(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    // Output the hash value
    for (uint32_t i = 0; i < 8; i++) {
        hash[i] = H[i];
    }

    // Free memory
    free(padded_msg);
}

int main() {
    // Test the hash function
    uint8_t message[] = "Hello, world!";
    uint32_t hash[8];
    sha256(message, strlen((char *) message), hash);
    printf("Hash value: %08x%08x%08x%08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
    return 0;
}