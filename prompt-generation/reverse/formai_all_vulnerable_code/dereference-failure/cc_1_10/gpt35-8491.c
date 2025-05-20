//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define CHAR_BIT 8
#define BLOCK_SIZE 64

// right rotate 
#define ROT_RIGHT(n, x) ((x >> n) | (x << (32 - n)))
// bitwise operations
#define CH(x, y, z) ((x & y) ^ ((~x) & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHR(n, x) (x >> n)
#define EP0(x) (ROT_RIGHT(2, x) ^ ROT_RIGHT(13, x) ^ ROT_RIGHT(22, x))
#define EP1(x) (ROT_RIGHT(6, x) ^ ROT_RIGHT(11, x) ^ ROT_RIGHT(25, x))
#define SIG0(x) (ROT_RIGHT(7, x) ^ ROT_RIGHT(18, x) ^ SHR(3, x))
#define SIG1(x) (ROT_RIGHT(17, x) ^ ROT_RIGHT(19, x) ^ SHR(10, x))

// digest structure
typedef struct {
    uint32_t h0;
    uint32_t h1;
    uint32_t h2;
    uint32_t h3;
} Digest;

// initialize constants for SHA-256
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

// functions for padding the message
void pad_message(uint8_t *message, uint64_t *message_len) {
    uint64_t orig_len = *message_len;
    uint64_t new_len = orig_len * 8 + 1 + 64;
    int padding = new_len % BLOCK_SIZE;
    if (padding != 0) {
        padding = BLOCK_SIZE - padding;
    }
    new_len += padding;
    uint8_t *padded_message = calloc(new_len / 8, sizeof(uint8_t));
    memcpy(padded_message, message, orig_len);
    padded_message[orig_len] = 0x80;
    for (int i = 1; i < padding; i++) {
        padded_message[new_len / 8 - i] = (uint8_t) orig_len;
        orig_len >>= CHAR_BIT;
    }
    padded_message[new_len / 8 - padding] = (uint8_t) orig_len;
    padded_message[new_len / 8 - padding + 1] = (uint8_t) (orig_len >> CHAR_BIT);
    *message_len = new_len;
    memcpy(message, padded_message, new_len / 8);
    free(padded_message);
}

// main hash function
void sha256(uint8_t *message, uint64_t message_len, Digest *digest) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t temp1, temp2;
    uint32_t W[64];
    memset(W, 0, sizeof W);
    a = digest->h0;
    b = digest->h1;
    c = digest->h2;
    d = digest->h3;
    for (int i = 0; i < message_len / BLOCK_SIZE; i++) {
        for (int j = 0; j < 16; j++) {
            W[j] = (message[i * BLOCK_SIZE + j * 4] << 24) |
                   (message[i * BLOCK_SIZE + j * 4 + 1] << 16) |
                   (message[i * BLOCK_SIZE + j * 4 + 2] << 8) |
                   (message[i * BLOCK_SIZE + j * 4 + 3]);
        }
        for (int j = 16; j < 64; j++) {
            W[j] = SIG1(W[j - 2]) + W[j - 7] + SIG0(W[j - 15]) + W[j - 16];
        }
        for (int j = 0; j < 64; j++) {
            temp1 = h + EP1(e) + CH(e, f, g) + K[j] + W[j];
            temp2 = EP0(a) + MAJ(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        digest->h0 += a;
        digest->h1 += b;
        digest->h2 += c;
        digest->h3 += d;
    }
}

// main function
int main() {
    Digest digest = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a};
    char message[] = "This is a test message for SHA-256";
    uint8_t *message_bytes = (uint8_t *) message;
    uint64_t message_len = strlen(message) * 8;
    pad_message(message_bytes, &message_len);
    sha256(message_bytes, message_len, &digest);
    printf("Hash value: %08x%08x%08x%08x\n", digest.h0, digest.h1, digest.h2, digest.h3);
    return 0;
}