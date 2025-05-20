//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define WORD_SIZE 4

// These constants represent the initial hash values for SHA-256
const unsigned int H[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

// This function rotates a 32-bit value right by a specified number of bits
unsigned int rotateRight(unsigned int value, unsigned int numBits) {
    return (value >> numBits) | (value << (32 - numBits));
}

// This function performs the SHA-256 hash on a given message
void sha256(unsigned char *message, unsigned int messageLength, unsigned char *hashResult) {
    // Initialize variables
    unsigned int a, b, c, d, e, f, g, h, i, j, t1, t2;
    unsigned int *w = (unsigned int *) malloc(BLOCK_SIZE);
    unsigned int *k = (unsigned int *) malloc(64 * WORD_SIZE);
    memcpy(k, (unsigned int []) {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    }, 64 * WORD_SIZE);

    unsigned int numBlocks = 1 + ((messageLength + 8) / BLOCK_SIZE);
    unsigned int paddedLength = BLOCK_SIZE * numBlocks;
    unsigned char *paddedMessage = (unsigned char *) malloc(paddedLength);
    memset(paddedMessage, 0, paddedLength);
    memcpy(paddedMessage, message, messageLength);
    paddedMessage[messageLength] = 0x80;
    *((unsigned long long *) (&paddedMessage[paddedLength - 8])) = messageLength * 8;

    // Initialize hash values
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    // Process each block of the message
    for (i = 0; i < numBlocks; i++) {
        // Prepare message schedule
        for (j = 0; j < 16; j++) {
            w[j] = ((unsigned int *) &paddedMessage[i * BLOCK_SIZE])[j];
        }
        for (j = 16; j < 64; j++) {
            w[j] = w[j - 16] + rotateRight(w[j - 15], 7) + w[j - 7] + rotateRight(w[j - 2], 17);
        }

        // Initialize working variables
        unsigned int t[8] = {a, b, c, d, e, f, g, h};

        // Perform main hash loop
        for (j = 0; j < 64; j++) {
            t1 = h + rotateRight(e, 6) + ((e & f) ^ ((~e) & g)) + k[j] + w[j];
            t2 = rotateRight(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update hash values
        a += t[0];
        b += t[1];
        c += t[2];
        d += t[3];
        e += t[4];
        f += t[5];
        g += t[6];
        h += t[7];
    }

    // Store hash result
    free(k);
    free(w);
    unsigned int *hashResultInts = (unsigned int *) hashResult;
    hashResultInts[0] = a;
    hashResultInts[1] = b;
    hashResultInts[2] = c;
    hashResultInts[3] = d;
    hashResultInts[4] = e;
    hashResultInts[5] = f;
    hashResultInts[6] = g;
    hashResultInts[7] = h;
}

// Test the hash function
int main() {
    char message[] = "Hello, world!";
    unsigned char hashResult[32];
    sha256((unsigned char *) message, strlen(message), hashResult);
    printf("Message: %s\nSHA-256 hash: ", message);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hashResult[i]);
    }
    printf("\n");
    return 0;
}