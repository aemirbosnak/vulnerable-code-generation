//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASHSIZE 16             // hash size in bytes

uint8_t* hash(uint8_t* data, size_t datalen) {

    uint32_t state[4] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    uint32_t* data32 = (uint32_t*)data;

    for (size_t i = 0; i < datalen / 4; i += 16) {
        uint32_t a = state[0];
        uint32_t b = state[1];
        uint32_t c = state[2];
        uint32_t d = state[3];

        for (size_t j = 0; j < 64; j++) {

            uint32_t f, g;

            if (j < 16) {
                f = (b & c) | (~b & d);
                g = j;
            }
            else if (j < 32) {
                f = (d & b) | (~d & c);
                g = (5 * j + 1) % 16;
            }
            else if (j < 48) {
                f = b ^ c ^ d;
                g = (3 * j + 5) % 16;
            }
            else {
                f = c ^ (b | ~d);
                g = (7 * j) % 16;
            }

            uint32_t temp = d;
            d = c;
            c = b;
            b += ((a + f + data32[g + i] + 0x5A827999) << (j % 32));
            a = temp;
        }

        state[0] += a;
        state[1] += b;
        state[2] += c;
        state[3] += d;
    }

    uint8_t* digest = malloc(HASHSIZE);

    for (int i = 0; i < 4; i++) {
        digest[i * 4] = (state[i] >> 24) & 0xFF;
        digest[i * 4 + 1] = (state[i] >> 16) & 0xFF;
        digest[i * 4 + 2] = (state[i] >> 8) & 0xFF;
        digest[i * 4 + 3] = state[i] & 0xFF;
    }

    return digest;
}

int main(int argc, char** argv) {

    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    uint8_t* data = (uint8_t*)argv[1];
    size_t datalen = strlen((char*)data);

    uint8_t* digest = hash(data, datalen);

    printf("Hash: ");

    for (int i = 0; i < HASHSIZE; i++) {
        printf("%02x", digest[i]);
    }

    printf("\n");

    free(digest);

    return 0;
}