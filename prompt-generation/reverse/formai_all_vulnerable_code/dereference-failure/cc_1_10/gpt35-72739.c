//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/* Helper macro to get the minimum number of two numbers */
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/* Constants used for the hash function */
#define BLOCK_SIZE 64
#define INITIAL_HASH_VALUE 0x98563B21

/* Rotate left and right helper macros */
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))

/* Message block structure */
typedef struct {
    uint8_t data[BLOCK_SIZE];
    uint8_t padding;
    uint64_t length;
} MessageBlock;

/*
 * Hash function that uses the SHA-256 algorithm.
 * It takes an input message and returns a 32-bit integer hash value.
 */
uint32_t sha256_hash(const uint8_t *message, size_t message_length) {
    uint32_t h[8] = { INITIAL_HASH_VALUE, 0x6A09E667, 0xBB67AE85, 0x3C6EF372,
                      0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB };
    uint32_t k[64] = { 0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
                       0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
                       0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
                       0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
                       0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
                       0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
                       0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
                       0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
                       0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
                       0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
                       0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
                       0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
                       0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
                       0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
                       0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
                       0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2 };

    size_t message_block_count = (message_length + 9) / BLOCK_SIZE + 1;
    MessageBlock *message_blocks = calloc(message_block_count, sizeof(MessageBlock));

    /* Copy the input message into the message blocks */
    for (size_t i = 0; i < message_length; i++) {
        message_blocks[i / BLOCK_SIZE].data[i % BLOCK_SIZE] = message[i];
    }

    /* Append the padding bits. */
    size_t last_block_index = message_length / BLOCK_SIZE;
    message_blocks[last_block_index].data[message_length % BLOCK_SIZE] = 0x80;
    for (size_t i = message_length % BLOCK_SIZE + 1; i < BLOCK_SIZE - 8; i++) {
        message_blocks[last_block_index].data[i] = 0x00;
    }

    for (size_t i = 0; i < message_block_count; i++) {
        /* Add the length of the input message to the last message block */
        if (i == message_block_count - 1) {
            message_blocks[i].length = message_length * 8;
        }

        /* Convert the message block from 8-bit to 32-bit words */
        uint32_t *wa = (uint32_t *)message_blocks[i].data;
        uint32_t w[64];
        memcpy(w, wa, BLOCK_SIZE);

        /* Extend the 16 32-bit words into 64 32-bit words */
        for (uint32_t j = 16; j < 64; j++) {
            uint32_t s0 = ROTR(w[j - 15], 7) ^ ROTR(w[j - 15], 18) ^ (w[j - 15] >> 3);
            uint32_t s1 = ROTR(w[j - 2], 17) ^ ROTR(w[j - 2], 19) ^ (w[j - 2] >> 10);
            w[j] = w[j - 16] + s0 + w[j - 7] + s1;
        }

        /* Initialize the working variables */
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t _h = h[7];

        /* Perform the hash computation for this message block */
        for (uint32_t j = 0; j < 64; j++) {
            uint32_t S1 = ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = _h + S1 + ch + k[j] + w[j];
            uint32_t S0 = ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            _h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        /* Update the hash value */
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += _h;
    }

    /* Create the final hash value by concatenating the 8 32-bit hash values */
    uint32_t hash = 0;
    for (size_t i = 0; i < 8; i++) {
        hash ^= h[i];
        hash ^= ROTR(hash, 13);
        hash += ROTL(hash, 7);
    }

    /* Clean up */
    free(message_blocks);

    return hash;
}

int main() {
    const char *message = "Hello, world!";
    size_t message_length = strlen(message);

    uint32_t hash = sha256_hash((const uint8_t *)message, message_length);
    printf("Hash value: 0x%x\n", hash);

    return 0;
}