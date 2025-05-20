//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTR32(x, y) ((x >> y) | (x << (32 - y)))

uint32_t cyber_hash(const void *key, size_t length, const uint32_t seed) {
    const uint8_t *data = (const uint8_t *)key;
    uint32_t h1 = seed;

    if (length > 3) {
        const uint32_t *key32 = (const uint32_t *)data;
        size_t i, nblocks = length / 4;
        for (i = 0; i < nblocks; i++) {
            uint32_t k1 = key32[i];
            k1 *= 0xcc9e2d51;
            k1 = ROTL32(k1, 15);
            k1 *= 0x1b873593;
            h1 ^= k1;
            h1 = ROTL32(h1, 13);
            h1 = h1 * 5 + 0xe6546b64;
        }
        data += nblocks * 4;
        length -= nblocks * 4;
    }

    if (length > 0) {
        uint32_t k1 = 0;
        uint8_t *tail = (uint8_t *)&k1;
        switch (length & 3) {
            case 3: tail[2] = data[2];
            case 2: tail[1] = data[1];
            case 1: tail[0] = data[0];
        }
        k1 *= 0xcc9e2d51;
        k1 = ROTL32(k1, 15);
        k1 *= 0x1b873593;
        h1 ^= k1;
    }

    h1 ^= length;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    uint32_t seed = 42;
    char *str = strdup(argv[1]);
    size_t len = strlen(str);
    uint32_t hash = cyber_hash(str, len, seed);
    printf("The cyber hash of \"%s\" with seed %u is: %u\n", str, seed, hash);

    free(str);
    return 0;
}