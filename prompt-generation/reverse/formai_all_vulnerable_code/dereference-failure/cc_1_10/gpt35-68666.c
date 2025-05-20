//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Function declarations */
void sha256(const uint8_t *message, size_t len, uint8_t hash[32]);
void pad_message(const uint8_t *message, size_t message_len, uint8_t **padded_message, size_t *padded_len);

/* Constants for SHA-256 */
#define KLEN 64
static const uint32_t K[KLEN] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
};
#define HLEN 8
static const uint32_t H[HLEN] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19,
};

/* Rotate right (circular right shift) */
#define ROTR(x, n) ((x) >> (n) | (x) << (32 - (n)))

/* Helper functions for SHA-256 */
#define sigma0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define sigma1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define gamma0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define gamma1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

/* Core SHA-256 function */
void sha256(const uint8_t *message, size_t len, uint8_t hash[32]) {
    /* Padded message */
    uint8_t *padded_message;
    size_t padded_len;
    pad_message(message, len, &padded_message, &padded_len);

    /* Initial hash value */
    uint32_t H_cur[HLEN];
    memcpy(H_cur, H, sizeof(H));

    /* Process each block */
    for (size_t i = 0; i < padded_len; i += 64) {
        /* Message schedule */
        uint32_t W[64];
        for (int t = 0; t < 16; t++) {
            W[t] = ((uint32_t)padded_message[i + t * 4] << 24) |
                   ((uint32_t)padded_message[i + t * 4 + 1] << 16) |
                   ((uint32_t)padded_message[i + t * 4 + 2] << 8) |
                   (uint32_t)padded_message[i + t * 4 + 3];
        }
        for (int t = 16; t < 64; t++) {
            W[t] = gamma1(W[t - 2]) + W[t - 7] + gamma0(W[t - 15]) + W[t - 16];
        }

        /* Computation of hash values */
        uint32_t a = H_cur[0];
        uint32_t b = H_cur[1];
        uint32_t c = H_cur[2];
        uint32_t d = H_cur[3];
        uint32_t e = H_cur[4];
        uint32_t f = H_cur[5];
        uint32_t g = H_cur[6];
        uint32_t h = H_cur[7];
        for (int t = 0; t < 64; t++) {
            uint32_t T1 = h + sigma1(e) + ((e & f) ^ (~e & g)) + K[t] + W[t];
            uint32_t T2 = sigma0(a) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }
        H_cur[0] += a;
        H_cur[1] += b;
        H_cur[2] += c;
        H_cur[3] += d;
        H_cur[4] += e;
        H_cur[5] += f;
        H_cur[6] += g;
        H_cur[7] += h;
    }

    /* Output hash */
    for (int i = 0; i < 8; i++) {
        hash[i*4] = (H_cur[i] >> 24) & 0xff;
        hash[i*4+1] = (H_cur[i] >> 16) & 0xff;
        hash[i*4+2] = (H_cur[i] >> 8) & 0xff;
        hash[i*4+3] = H_cur[i] & 0xff;
    }

    /* Free memory */
    free(padded_message);
}

/* Pad message according to SHA-256 */
void pad_message(const uint8_t *message, size_t message_len, uint8_t **padded_message, size_t *padded_len) {
    /* Compute length of padded message */
    size_t bits_len = message_len * 8;
    size_t padding_len = 64 - ((bits_len + 8) % 64);
    *padded_len = message_len + padding_len + 8;

    /* Allocate memory for padded message */
    *padded_message = malloc(*padded_len);
    if (*padded_message == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    /* Copy message to padded message */
    memcpy(*padded_message, message, message_len);

    /* Pad message */
    (*padded_message)[message_len] = 0x80;
    for (size_t i = message_len + 1; i < message_len + padding_len; i++) {
        (*padded_message)[i] = 0x00;
    }

    /* Append length */
    for (size_t i = message_len + padding_len; i < *padded_len; i++) {
        (*padded_message)[i] = (bits_len >> (56 - (i - (message_len + padding_len))) & 0xff);
    }
}

/* Example usage */
int main(void) {
    uint8_t message[] = "Hello, world!";
    uint8_t hash[32];
    sha256(message, sizeof(message) - 1, hash);
    for (int i = 0; i < 32; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}