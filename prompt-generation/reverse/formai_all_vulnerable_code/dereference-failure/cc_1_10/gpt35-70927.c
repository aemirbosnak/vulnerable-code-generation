//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))

uint32_t hash(const char* message) {
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;

    const uint8_t* msg = (const uint8_t*)message;
    uint32_t len = strlen(message);
    uint32_t bit_len = len << 3;

    uint32_t pad_count = (bit_len % 512) < 448 ? 448 - (bit_len % 512) : 512 + 448 - (bit_len % 512);
    uint32_t pad_len = (len + pad_count / 8 + 8);
    uint8_t* padded_msg = (uint8_t*)malloc(pad_len);

    memcpy(padded_msg, msg, len);
    padded_msg[len] = 0x80;
    for (uint32_t i = len + 1; i < pad_len - 8; ++i) {
        padded_msg[i] = 0x00;
    }

    padded_msg[pad_len - 8] = bit_len >> 24;
    padded_msg[pad_len - 7] = bit_len >> 16;
    padded_msg[pad_len - 6] = bit_len >> 8;
    padded_msg[pad_len - 5] = bit_len;

    uint32_t* chunks = (uint32_t*)padded_msg;
    uint32_t chunk_len = pad_len / 4;

    for (uint32_t i = 0; i < chunk_len; i += 16) {
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;

        for (uint32_t j = 0; j < 64; ++j) {
            uint32_t f, g;

            if (j < 16) {
                f = (b & c) | ((~b) & d);
                g = j;
            } else if (j < 32) {
                f = (d & b) | ((~d) & c);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7 * j) % 16;
            }

            uint32_t temp_d = d;
            d = c;
            c = b;
            b = b + ROTATE_LEFT(a + f + chunks[i + g] + 0x5A827999, 5);
            a = temp_d;
        }

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
    }

    free(padded_msg);

    return (h3 << 24) | (h2 << 16) | (h1 << 8) | h0;
}

int main() {
    const char* message = "Hello, world!";
    uint32_t h = hash(message);
    printf("%s: %08x\n", message, h);
    return 0;
}