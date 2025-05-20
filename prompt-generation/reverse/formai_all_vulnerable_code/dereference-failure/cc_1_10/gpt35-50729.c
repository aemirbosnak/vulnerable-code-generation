//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL(x, n) ((x) << (n)) | ((x) >> (32 - (n)))
#define ROTR(x, n) ((x) >> (n)) | ((x) << (32 - (n)))

#define F1(x, y, z) (x & y) ^ (~x & z)
#define F2(x, y, z) (x & y) ^ (x & z) ^ (y & z)
#define F3(x, y, z) x ^ y ^ z

typedef struct {
    uint32_t h0, h1, h2, h3;
} hash_state;

/* Initialize the hash state */
void init(hash_state *state) {
    state->h0 = 0x67452301;
    state->h1 = 0xefcdab89;
    state->h2 = 0x98badcfe;
    state->h3 = 0x10325476;
}

/* Process one 64-byte block of data */
void process_block(const void *data, hash_state *state) {
    const uint32_t k[] = {
        0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6
    };

    uint32_t w[80];
    memcpy(w, data, 64);

    uint32_t a = state->h0;
    uint32_t b = state->h1;
    uint32_t c = state->h2;
    uint32_t d = state->h3;

    for (int i = 16; i < 80; i++) {
        w[i] = ROTL(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);
    }

    for (int i = 0; i < 20; i++) {
        uint32_t f = F1(b, c, d);
        uint32_t k_i = k[0];

        uint32_t temp = ROTL(a, 5) + f + b + k_i + w[i];
        d = c;
        c = b;
        b = ROTL(a, 30);
        a = temp;
    }

    for (int i = 20; i < 40; i++) {
        uint32_t f = F2(b, c, d);
        uint32_t k_i = k[1];

        uint32_t temp = ROTL(a, 5) + f + b + k_i + w[i];
        d = c;
        c = b;
        b = ROTL(a, 30);
        a = temp;
    }

    for (int i = 40; i < 60; i++) {
        uint32_t f = F3(b, c, d);
        uint32_t k_i = k[2];

        uint32_t temp = ROTL(a, 5) + f + b + k_i + w[i];
        d = c;
        c = b;
        b = ROTL(a, 30);
        a = temp;
    }

    for (int i = 60; i < 80; i++) {
        uint32_t f = F2(b, c, d);
        uint32_t k_i = k[3];

        uint32_t temp = ROTL(a, 5) + f + b + k_i + w[i];
        d = c;
        c = b;
        b = ROTL(a, 30);
        a = temp;
    }

    state->h0 += a;
    state->h1 += b;
    state->h2 += c;
    state->h3 += d;
}

/* Finalize and output the hash */
void finalize(const void *data, size_t length, hash_state *state, void *output) {
    // Pad the message
    size_t pad_size = 64 - (length % 64);
    if (pad_size < 8) {
        pad_size += 64;
    }
    uint8_t *padded = malloc(length + pad_size);
    memcpy(padded, data, length);
    padded[length] = 0x80;
    memset(padded + length + 1, 0, pad_size - 8);
    uint64_t bit_length = ((uint64_t) length) << 3;
    padded[length + pad_size - 8] = (bit_length >> 56) & 0xff;
    padded[length + pad_size - 7] = (bit_length >> 48) & 0xff;
    padded[length + pad_size - 6] = (bit_length >> 40) & 0xff;
    padded[length + pad_size - 5] = (bit_length >> 32) & 0xff;
    padded[length + pad_size - 4] = (bit_length >> 24) & 0xff;
    padded[length + pad_size - 3] = (bit_length >> 16) & 0xff;
    padded[length + pad_size - 2] = (bit_length >> 8) & 0xff;
    padded[length + pad_size - 1] = (bit_length >> 0) & 0xff;

    // Process the padded message
    size_t num_blocks = (length + pad_size) / 64;
    for (size_t i = 0; i < num_blocks; i++) {
        process_block(padded + (i * 64), state);
    }

    // Output the hash
    uint32_t *output32 = output;
    output32[0] = state->h0;
    output32[1] = state->h1;
    output32[2] = state->h2;
    output32[3] = state->h3;

    free(padded);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    const char *input = argv[1];
    size_t length = strlen(input);

    uint8_t output[16];
    memset(output, 0, sizeof(output));

    hash_state state;
    init(&state);
    finalize(input, length, &state, output);

    printf("Input: %s\n", input);
    printf("Output: ");
    for (int i = 0; i < sizeof(output); i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}