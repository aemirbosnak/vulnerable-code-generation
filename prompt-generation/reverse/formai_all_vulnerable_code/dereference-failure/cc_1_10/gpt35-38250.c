//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rounds Definition
#define ROUNDS 16

// Define Block Sizes
#define BLOCK_SIZE 64
#define BLOCK_BYTE_SIZE 8

// Constants
#define ROTL(x,y) (((x)<<(y))|((x)>>(sizeof(x)*BLOCK_BYTE_SIZE-(y))))

// SHA256 Round Constants
const unsigned int K[ROUNDS] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174
};

// SHA2 Functions
#define Ch(x, y, z) (((x) & (y)) ^ ((~x) & (z)))
#define Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define Sigma0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))
#define Sigma1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))
#define sigma0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ ((x) >> 3))
#define sigma1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ ((x) >> 10))

// Function Declarations
unsigned int* sha256_digest(const char* message);

// Main Function
int main() {
    // Test String
    char* message = "Hello, world!";

    // SHA256 Digest
    unsigned int* digest = sha256_digest(message);

    // Print Digest
    printf("Message Digest: ");

    for (int i = 0; i < 8; i++) {
        printf("%08x", digest[i]);
    }

    printf("\n");

    return 0;
}

unsigned int* sha256_digest(const char* message) {
    // Message Length (bits)
    unsigned int message_length = strlen(message) * BLOCK_BYTE_SIZE;

    // Padding
    unsigned int padding_length = ((BLOCK_SIZE - (message_length + 1) % BLOCK_SIZE) + BLOCK_SIZE) % BLOCK_SIZE;
    unsigned char* padded_message = calloc(message_length + padding_length + BLOCK_BYTE_SIZE, 1);

    memcpy(padded_message, message, message_length);
    padded_message[message_length] = 0x80;

    for (int i = 0; i < 8; i++) {
        padded_message[(message_length + padding_length + i)] = (message_length & (0xff << (56 - 8 * i))) >> (56 - 8 * i);
    }

    // Hash Computation
    unsigned int* digest = malloc(8 * sizeof(unsigned int));

    digest[0] = 0x6a09e667;
    digest[1] = 0xbb67ae85;
    digest[2] = 0x3c6ef372;
    digest[3] = 0xa54ff53a;
    digest[4] = 0x510e527f;
    digest[5] = 0x9b05688c;
    digest[6] = 0x1f83d9ab;
    digest[7] = 0x5be0cd19;

    // Chunk Processing
    for (int i = 0; i < (message_length + padding_length + BLOCK_BYTE_SIZE) / BLOCK_SIZE; i++) {
        unsigned int* chunk = (unsigned int*)(padded_message + i * BLOCK_SIZE);

        // Message Schedule
        unsigned int W[64];

        for (int j = 0; j < 16; j++) {
            W[j] = chunk[j];
        }

        for (int j = 16; j < 64; j++) {
            W[j] = sigma1(W[j - 2]) + W[j - 7] + sigma0(W[j - 15]) + W[j - 16];
        }

        // Working Variables
        unsigned int a = digest[0];
        unsigned int b = digest[1];
        unsigned int c = digest[2];
        unsigned int d = digest[3];
        unsigned int e = digest[4];
        unsigned int f = digest[5];
        unsigned int g = digest[6];
        unsigned int h = digest[7];

        // Compression
        for (int j = 0; j < ROUNDS; j++) {
            unsigned int T1 = h + Sigma1(e) + Ch(e, f, g) + K[j] + W[j];
            unsigned int T2 = Sigma0(a) + Maj(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // Update Digest
        digest[0] += a;
        digest[1] += b;
        digest[2] += c;
        digest[3] += d;
        digest[4] += e;
        digest[5] += f;
        digest[6] += g;
        digest[7] += h;
    }

    // Free Padded Message
    free(padded_message);

    return digest;
}