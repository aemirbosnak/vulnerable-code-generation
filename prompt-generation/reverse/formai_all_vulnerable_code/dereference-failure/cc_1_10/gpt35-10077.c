//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Define the size of the message digest in bytes
#define HASH_SIZE 32

// Define the number of rounds for the hash function
#define NUM_ROUNDS 10

// Define the block size (in bytes) of the input message
#define BLOCK_SIZE 64

// Define the initial values of the state variables
#define INIT_A 0x6a09e667
#define INIT_B 0xbb67ae85
#define INIT_C 0x3c6ef372
#define INIT_D 0xa54ff53a
#define INIT_E 0x510e527f
#define INIT_F 0x9b05688c
#define INIT_G 0x1f83d9ab
#define INIT_H 0x5be0cd19

// Define the rotation functions for 32-bit integers
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Define the choice, majority, and parity functions for 32-bit integers
#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define PAR(x, y, z) ((x) ^ (y) ^ (z))

// Define the SHA-256 message schedule constant values (in 32-bit words)
const uint32_t K[64] = {
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

// Define the SHA-256 hash function
void sha256(const uint8_t *msg, const size_t msg_len, uint8_t *hash) {
    // Initialize the state variables
    uint32_t a = INIT_A;
    uint32_t b = INIT_B;
    uint32_t c = INIT_C;
    uint32_t d = INIT_D;
    uint32_t e = INIT_E;
    uint32_t f = INIT_F;
    uint32_t g = INIT_G;
    uint32_t h = INIT_H;

    // Pad the input message
    size_t padded_len = (((msg_len + 8) / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    uint8_t *padded_msg = (uint8_t *) malloc(padded_len);
    memcpy(padded_msg, msg, msg_len);
    padded_msg[msg_len] = 0x80;
    for (size_t i = msg_len + 1; i < padded_len - 8; i++) {
        padded_msg[i] = 0x00;
    }
    uint64_t msg_bits = (uint64_t) msg_len * 8;
    for (size_t i = 0; i < 8; i++) {
        padded_msg[padded_len - 8 + i] = (msg_bits >> ((7 - i) * 8)) & 0xFF;
    }

    // Process each block of the padded message
    for (size_t i = 0; i < padded_len; i += BLOCK_SIZE) {
        // Initialize the message schedule
        uint32_t W[64];
        for (size_t j = 0; j < 16; j++) {
            W[j] = ((uint32_t) padded_msg[i + (j * 4) + 0] << 24) |
                   ((uint32_t) padded_msg[i + (j * 4) + 1] << 16) |
                   ((uint32_t) padded_msg[i + (j * 4) + 2] << 8) |
                   ((uint32_t) padded_msg[i + (j * 4) + 3] << 0);
        }
        for (size_t j = 16; j < 64; j++) {
            uint32_t s0 = ROTR(W[j - 15], 7) ^ ROTR(W[j - 15], 18) ^ (W[j - 15] >> 3);
            uint32_t s1 = ROTR(W[j - 2], 17) ^ ROTR(W[j - 2], 19) ^ (W[j - 2] >> 10);
            W[j] = W[j - 16] + s0 + W[j - 7] + s1;
        }

        // Initialize the working variables
        uint32_t A = a;
        uint32_t B = b;
        uint32_t C = c;
        uint32_t D = d;
        uint32_t E = e;
        uint32_t F = f;
        uint32_t G = g;
        uint32_t H = h;

        // Perform the main hash function
        for (size_t j = 0; j < NUM_ROUNDS; j++) {
            uint32_t s1 = ROTR(E, 6) ^ ROTR(E, 11) ^ ROTR(E, 25);
            uint32_t ch = CH(E, F, G);
            uint32_t temp1 = H + s1 + ch + K[j] + W[j];
            uint32_t s0 = ROTR(A, 2) ^ ROTR(A, 13) ^ ROTR(A, 22);
            uint32_t maj = MAJ(A, B, C);
            uint32_t temp2 = s0 + maj;

            H = G;
            G = F;
            F = E;
            E = D + temp1;
            D = C;
            C = B;
            B = A;
            A = temp1 + temp2;
        }

        // Update the state variables
        a += A;
        b += B;
        c += C;
        d += D;
        e += E;
        f += F;
        g += G;
        h += H;
    }

    // Store the hash value
    memcpy(hash, &a, 4);
    memcpy(hash + 4, &b, 4);
    memcpy(hash + 8, &c, 4);
    memcpy(hash + 12, &d, 4);
    memcpy(hash + 16, &e, 4);
    memcpy(hash + 20, &f, 4);
    memcpy(hash + 24, &g, 4);
    memcpy(hash + 28, &h, 4);

    // Free the padded message buffer
    free(padded_msg);
}

int main() {
    // Test the hash function
    uint8_t *msg = "Hello, world!";
    uint8_t hash[HASH_SIZE];
    sha256(msg, strlen(msg), hash);
    for (size_t i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}