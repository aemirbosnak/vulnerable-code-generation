//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Constants for SHA-256 */
const uint32_t K[] = {
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

/* SHA-256 functions */
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define Ch(x,y,z)   ((x & y) ^ (~x & z))
#define Maj(x,y,z)  ((x & y) ^ (x & z) ^ (y & z))
#define Sig0(x)     (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define Sig1(x)     (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define sig0(x)     (ROTR(x, 7) ^ ROTR(x, 18) ^ (x >> 3))
#define sig1(x)     (ROTR(x, 17) ^ ROTR(x, 19) ^ (x >> 10))

void sha256(const char* input, uint32_t output[8]) {
    /* Preprocessing */
    uint32_t message[16];
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t a, b, c, d, e, f, g, h_, s0, s1, t1, t2;
    uint32_t i, j;

    uint64_t bit_len = strlen(input) * 8;
    int padding_len = (bit_len % 512 < 448 ? 448 : 960) - (bit_len % 512);
    int num_blocks = ((bit_len + padding_len + 64) / 512);

    char* message_padded = (char*)calloc(num_blocks * 64 / 8, 1);
    memcpy(message_padded, input, strlen(input));

    /* Append the bit '1' to the message */
    message_padded[strlen(input)] = 0x80;

    /* Append 0 ≤ k < 512 bits '0', such that the resulting message length in bits
     * is congruent to −64 ≡ 448 (mod 512)
     */
    for (i = strlen(input) + 1; i < num_blocks * 64 / 8 - 8; i++) {
        message_padded[i] = 0x00;
    }

    /* Append length of message */
    message_padded[((num_blocks * 64)/8) - 1] = bit_len         & 0xFF;
    message_padded[((num_blocks * 64)/8) - 2] = (bit_len >> 8)  & 0xFF;
    message_padded[((num_blocks * 64)/8) - 3] = (bit_len >> 16) & 0xFF;
    message_padded[((num_blocks * 64)/8) - 4] = (bit_len >> 24) & 0xFF;
    message_padded[((num_blocks * 64)/8) - 5] = (bit_len >> 32) & 0xFF;
    message_padded[((num_blocks * 64)/8) - 6] = (bit_len >> 40) & 0xFF;
    message_padded[((num_blocks * 64)/8) - 7] = (bit_len >> 48) & 0xFF;
    message_padded[((num_blocks * 64)/8) - 8] = (bit_len >> 56) & 0xFF;

    for (i = 0; i < num_blocks; i++) {
        /* Message schedule */
        for (j = 0; j < 16; j++) {
            message[j] =
            ((uint32_t)message_padded[i*64 + j*4 + 0] << 24) |
            ((uint32_t)message_padded[i*64 + j*4 + 1] << 16) |
            ((uint32_t)message_padded[i*64 + j*4 + 2] <<  8) |
            ((uint32_t)message_padded[i*64 + j*4 + 3] <<  0);
        }

        /* Initialize working variables to current hash value */
        a = h[0]; b = h[1]; c = h[2]; d = h[3];
        e = h[4]; f = h[5]; g = h[6]; h_ = h[7];

        /* Compression function */
        for (j = 0; j < 64; j++) {
            s0 = sig0(a); s1 = sig1(e);
            t1 = h_ + Sig1(e) + Ch(e,f,g) + K[j] + message[j%16];
            t2 = Sig0(a) + Maj(a,b,c);
            h_ = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        /* Update hash values */
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h_;
    }

    free(message_padded);

    /* Output hash */
    for (i = 0; i < 8; i++) {
        output[i] = h[i];
    }

    return;
}

int main(void) {
    char input[100];
    uint32_t output[8];
    int i;

    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0';

    sha256(input, output);

    printf("Hash output: ");
    for (i = 0; i < 8; i++) {
        printf("%08x", output[i]);
    }
    printf("\n");

    return 0;
}