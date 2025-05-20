//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the SHA-256 constants (K) and initial hash values (H)
const uint32_t K[64] = {
    UINT32_C(0x428a2f98), UINT32_C(0x71374491), UINT32_C(0xb5c0fbcf), UINT32_C(0xe9b5dba5),
    UINT32_C(0x3956c25b), UINT32_C(0x59f111f1), UINT32_C(0x923f82a4), UINT32_C(0xab1c5ed5),
    UINT32_C(0xd807aa98), UINT32_C(0x12835b01), UINT32_C(0x243185be), UINT32_C(0x550c7dc3),
    UINT32_C(0x72be5d74), UINT32_C(0x80deb1fe), UINT32_C(0x9bdc06a7), UINT32_C(0xc19bf174),
    UINT32_C(0xe49b69c1), UINT32_C(0xefbe4786), UINT32_C(0x0fc19dc6), UINT32_C(0x240ca1cc),
    UINT32_C(0x2de92c6f), UINT32_C(0x4a7484aa), UINT32_C(0x5cb0a9dc), UINT32_C(0x76f988da),
    UINT32_C(0x983e5152), UINT32_C(0xa831c66d), UINT32_C(0xb00327c8), UINT32_C(0xbf597fc7),
    UINT32_C(0xc6e00bf3), UINT32_C(0xd5a79147), UINT32_C(0x06ca6351), UINT32_C(0x14292967),
    UINT32_C(0x27b70a85), UINT32_C(0x2e1b2138), UINT32_C(0x4d2c6dfc), UINT32_C(0x53380d13),
    UINT32_C(0x650a7354), UINT32_C(0x766a0abb), UINT32_C(0x81c2c92e), UINT32_C(0x92722c85),
    UINT32_C(0xa2bfe8a1), UINT32_C(0xa81a664b), UINT32_C(0xc24b8b70), UINT32_C(0xc76c51a3),
    UINT32_C(0xd192e819), UINT32_C(0xd6990624), UINT32_C(0xf40e3585), UINT32_C(0x106aa070),
    UINT32_C(0x19a4c116), UINT32_C(0x1e376c08), UINT32_C(0x2748774c), UINT32_C(0x34b0bcb5),
    UINT32_C(0x391c0cb3), UINT32_C(0x4ed8aa4a), UINT32_C(0x5b9cca4f), UINT32_C(0x682e6ff3),
    UINT32_C(0x748f82ee), UINT32_C(0x78a5636f), UINT32_C(0x84c87814), UINT32_C(0x8cc70208),
    UINT32_C(0x90befffa), UINT32_C(0xa4506ceb), UINT32_C(0xbef9a3f7), UINT32_C(0xc67178f2)
};

const uint32_t H[8] = {
    UINT32_C(0x6a09e667), UINT32_C(0xbb67ae85), UINT32_C(0x3c6ef372), UINT32_C(0xa54ff53a),
    UINT32_C(0x510e527f), UINT32_C(0x9b05688c), UINT32_C(0x1f83d9ab), UINT32_C(0x5be0cd19)
};

// Define some useful macros
#define ROTR(x, n) ((x) >> (n) | (x) << (32 - (n)))
#define CH(x, y, z) ((x) & (y)) ^ (~(x) & (z))
#define MAJ(x, y, z) ((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z))
#define EP0(x) ROTR((x), 2) ^ ROTR((x), 13) ^ ROTR((x), 22)
#define EP1(x) ROTR((x), 6) ^ ROTR((x), 11) ^ ROTR((x), 25)
#define SIG0(x) ROTR((x), 7) ^ ROTR((x), 18) ^ ((x) >> 3)
#define SIG1(x) ROTR((x), 17) ^ ROTR((x), 19) ^ ((x) >> 10)

// Define the SHA-256 message schedule (W)
void message_schedule(uint32_t* W, uint8_t* block) {
    for(int t = 0; t < 16; t++) {
        W[t] = (block[t * 4] << 24) | (block[t * 4 + 1] << 16) | (block[t * 4 + 2] << 8) | block[t * 4 + 3];
    }
    for(int t = 16; t < 64; t++) {
        W[t] = SIG1(W[t - 2]) + W[t - 7] + SIG0(W[t - 15]) + W[t - 16];
    }
}

// Define the SHA-256 compression function
void sha256_compress(uint32_t* H, uint32_t* W) {
    uint32_t a = H[0];
    uint32_t b = H[1];
    uint32_t c = H[2];
    uint32_t d = H[3];
    uint32_t e = H[4];
    uint32_t f = H[5];
    uint32_t g = H[6];
    uint32_t h = H[7];

    for(int t = 0; t < 64; t++) {
        uint32_t T1 = h + EP1(e) + CH(e, f, g) + K[t] + W[t];
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

// Define the main SHA-256 function
void sha256(uint8_t* message, size_t len, uint8_t* digest) {
    // Pad the message
    int padded_len = (((len + 8) / 64) + 1) * 64;
    uint8_t* padded_message = calloc(padded_len, sizeof(uint8_t));
    memcpy(padded_message, message, len);
    padded_message[len] = 0x80;
    uint64_t bit_len = len * 8;
    memcpy(padded_message + padded_len - 8, &bit_len, 8);

    // Initialize the hash values
    uint32_t H_copy[8];
    memcpy(H_copy, H, sizeof(H));

    // Process each block
    for(int i = 0; i < padded_len; i += 64) {
        uint32_t W[64];
        message_schedule(W, padded_message + i);
        sha256_compress(H_copy, W);
    }

    // Write the final hash value to the digest
    for(int i = 0; i < 8; i++) {
        digest[i * 4] = H_copy[i] >> 24;
        digest[i * 4 + 1] = (H_copy[i] >> 16) & 0xFF;
        digest[i * 4 + 2] = (H_copy[i] >> 8) & 0xFF;
        digest[i * 4 + 3] = H_copy[i] & 0xFF;
    }

    // Free the padded message buffer
    free(padded_message);
}

// Test the SHA-256 function
int main() {
    uint8_t message[] = "Hello, world!";
    uint8_t digest[32];
    sha256(message, sizeof(message) - 1, digest);
    printf("Message: %s\n", message);
    printf("Digest: ");
    for(int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}