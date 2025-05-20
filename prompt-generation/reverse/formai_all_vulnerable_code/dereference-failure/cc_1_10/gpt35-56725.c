//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Function to perform left rotate on a 32-bit integer */
uint32_t leftRotate(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32 - c));
}

/* Function to generate sha256 hash for a given input message */
void sha256(const char* message, uint32_t hash[]) {

    const uint32_t k[] = {
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

    uint32_t h[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h_temp;
    uint32_t s0, s1, maj, ch, temp1, temp2;
    uint32_t i, j;

    size_t messageLen = strlen(message);
    size_t paddedLen = ((messageLen + 8) / 64 + 1) * 64;
    uint8_t* paddedMsg = (uint8_t*) calloc(paddedLen, sizeof(uint8_t));
    memcpy(paddedMsg, message, messageLen);
    paddedMsg[messageLen] = 0x80;
    uint32_t bitLen = messageLen * 8;
    memcpy(paddedMsg + paddedLen - 8, &bitLen, sizeof(uint32_t));

    for (i = 0; i < paddedLen; i += 64) {
        for (j = 0; j < 16; j++) {
            w[j] = ((uint32_t)paddedMsg[i + j * 4]) << 24;
            w[j] |= ((uint32_t)paddedMsg[i + j * 4 + 1]) << 16;
            w[j] |= ((uint32_t)paddedMsg[i + j * 4 + 2]) << 8;
            w[j] |= ((uint32_t)paddedMsg[i + j * 4 + 3]);
        }
        for (j = 16; j < 64; j++) {
            s0 = leftRotate(w[j - 15], 7) ^ leftRotate(w[j - 15], 18) ^ (w[j - 15] >> 3);
            s1 = leftRotate(w[j - 2], 17) ^ leftRotate(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }
        a = h[0], b = h[1], c = h[2], d = h[3];
        e = h[4], f = h[5], g = h[6], h_temp = h[7];

        for (j = 0; j < 64; j++) {
            s0 = leftRotate(a, 2) ^ leftRotate(a, 13) ^ leftRotate(a, 22);
            maj = (a & b) ^ (a & c) ^ (b & c);
            temp2 = s0 + maj;
            s1 = leftRotate(e, 6) ^ leftRotate(e, 11) ^ leftRotate(e, 25);
            ch = (e & f) ^ ((~e) & g);
            temp1 = h_temp + s1 + ch + k[j] + w[j];

            h_temp = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h[0] += a, h[1] += b, h[2] += c, h[3] += d;
        h[4] += e, h[5] += f, h[6] += g, h[7] += h_temp;
    }

    memcpy(hash, h, sizeof(uint32_t) * 8);
    free(paddedMsg);
}

int main() {

    char message[1024];
    printf("Enter the message to be hashed: ");
    fgets(message, 1024, stdin);

    uint32_t hash[8];
    sha256(message, hash);

    printf("The SHA-256 hash of the message \"%s\" is:\n", message);
    printf("%08x%08x%08x%08x%08x%08x%08x%08x\n", hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);

    return 0;
}