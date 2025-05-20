//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTLEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

uint8_t* crypto_hash(const uint8_t *data, uint64_t len)
{
    // Initialize variables
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xefcdab89;
    uint32_t h2 = 0x98badcfe;
    uint32_t h3 = 0x10325476;

    // Pre-processing: padding with zeros
    uint32_t padding_amt = ((((len + 8) / 64) + 1) * 64) - 8;
    uint8_t *padded_data = calloc(padding_amt + 64, 1);
    memcpy(padded_data, data, len);
    padded_data[len] = 0x80;
    uint64_t bit_len = len * 8;
    memcpy(padded_data + padding_amt, &bit_len, 8);

    // Process message in 512-bit chunks
    for (uint64_t i = 0; i < padding_amt / 64; ++i) {
        uint32_t* w = (uint32_t*)(padded_data + (i * 64));

        // Initialize hash values for the current chunk
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;

        // Main loop
        for (uint8_t round = 0; round < 64; ++round) {
            uint32_t f, g;

            if (round < 16) {
                f = (b & c) | ((~b) & d);
                g = round;
            } else if (round < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*round + 1) % 16;
            } else if (round < 48) {
                f = b ^ c ^ d;
                g = (3*round + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7*round) % 16;
            }

            uint32_t temp = d;
            d = c;
            c = b;
            b = b + ROTLEFT((a + f + ((uint32_t*)w)[g] + 0x5a827999), 5);
            a = temp;
        }

        // Update hash values for the current chunk
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(padded_data);

    // Concatenate hash values
    uint8_t *hash = calloc(16, 1);
    memcpy(hash, &h0, 4);
    memcpy(hash + 4, &h1, 4);
    memcpy(hash + 8, &h2, 4);
    memcpy(hash + 12, &h3, 4);

    return hash;
}

int main()
{
    const char *data = "hello world!";
    uint8_t *hash = crypto_hash((const uint8_t*)data, strlen(data));
    printf("Hash: ");
    for (int i = 0; i < 16; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    free(hash);

    return 0;
}