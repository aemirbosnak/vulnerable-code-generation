//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ROUND 64 // Message block size
#define INIT_A 0x67452301 // Initial value of A
#define INIT_B 0xEFCDAB89 // Initial value of B
#define INIT_C 0x98BADCFE // Initial value of C
#define INIT_D 0x10325476 // Initial value of D

// Non-linear function F
#define F(X, Y, Z) (((X) & (Y)) | ((~X) & (Z)))

// Non-linear function G
#define G(X, Y, Z) (((X) & (Z)) | ((~Z) & (Y)))

// Non-linear function H
#define H(X, Y, Z) ((X) ^ (Y) ^ (Z))

// Non-linear function I
#define I(X, Y, Z) ((Y) ^ ((X) | (~Z)))

// Left Shift
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Hash function
void hash(uint8_t *message, uint32_t result[4]) {
    uint32_t a = INIT_A;
    uint32_t b = INIT_B;
    uint32_t c = INIT_C;
    uint32_t d = INIT_D;

    uint32_t *words;
    uint32_t length = strlen((const char *) message); // Length of message in bytes
    uint32_t padded_length = ((length + 8 + 63) / 64) * 64; // Padded length
    uint8_t *padded_message = calloc(padded_length, 1); // Padded message
    
    memcpy(padded_message, message, length);
    padded_message[length] = 0x80; // Padding: Append a 1 bit, followed by 0 bits
    *(uint32_t *) (padded_message + (padded_length - 8)) = length * 8; // Padding: Append length in bits as little endian

    words = (uint32_t *) padded_message;

    for (uint32_t i = 0; i < padded_length; i += ROUND) {
        uint32_t a1 = a;
        uint32_t b1 = b;
        uint32_t c1 = c;
        uint32_t d1 = d;

        for (int j = 0; j < 64; ++j) {
            uint32_t f, g;
            if (j < 16) {
                f = F(b1, c1, d1);
                g = j;
            } else if (j < 32) {
                f = G(b1, c1, d1);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = H(b1, c1, d1);
                g = (3 * j + 5) % 16;
            } else {
                f = I(b1, c1, d1);
                g = (7 * j) % 16;
            }

            uint32_t temp = d1;
            d1 = c1;
            c1 = b1;
            b1 = b1 + LEFT_ROTATE((a1 + f + words[g] + 0x5A827999), 7);
            a1 = temp;
        }

        a += a1;
        b += b1;
        c += c1;
        d += d1;
    }

    free(padded_message);

    result[0] = a;
    result[1] = b;
    result[2] = c;
    result[3] = d;
}

int main() {
    uint32_t result[4];
    uint8_t message[] = "This is an example of a unique cryptographic hash function.";

    hash(message, result);

    printf("Hash: %08X%08X%08X%08X\n", result[0], result[1], result[2], result[3]);

    return 0;
}