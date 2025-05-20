//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, n) ((x << n) | (x >> (32 - n)))

uint32_t hash(const void *key, size_t len, uint32_t seed) {
    const uint8_t *data = (const uint8_t *)key;
    uint32_t h1 = 0x853c25c9 ^ seed;
    uint32_t h2 = 0x63cd1b79 ^ seed;
    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;
    uint32_t k1, k2;
    
    while (len >= 8) {
        k1 = *((uint32_t *)data);
        k2 = *((uint32_t *)data + 1);
        k1 *= c1;
        k1 = ROTL(k1, 15);
        k1 *= c2;
        h1 ^= k1;
        h1 = ROTL(h1, 13);
        h1 = h1 * 5 + 0xe6546b64;
        k2 *= c2;
        k2 = ROTL(k2, 16);
        k2 *= c1;
        h2 ^= k2;
        h2 = ROTL(h2, 17);
        h2 = h2 * 5 + 0x8f70d153;
        data += 8;
        len -= 8;
    }
    
    k1 = 0;
    k2 = 0;
    
    switch (len) {
        case 7: k2 ^= (uint32_t)data[6] << 16;
        case 6: k2 ^= (uint32_t)data[5] << 8;
        case 5: k2 ^= (uint32_t)data[4];
            k2 *= c2;
            k2 = ROTL(k2, 16);
            k2 *= c1;
            h2 ^= k2;
        case 4: k1 ^= *((uint32_t *)data);
            k1 *= c1;
            k1 = ROTL(k1, 15);
            k1 *= c2;
            h1 ^= k1;
            break;
        case 3: k1 ^= (uint32_t)data[2] << 16;
        case 2: k1 ^= (uint32_t)data[1] << 8;
        case 1: k1 ^= (uint32_t)data[0];
            k1 *= c1;
            k1 = ROTL(k1, 15);
            k1 *= c2;
            h1 ^= k1;
            break;
    }
    
    h1 ^= strlen(key);
    h2 ^= strlen(key);
    h1 += h2;
    h2 += h1;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;
    return h1;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char *str = argv[1];
    uint32_t h = hash(str, strlen(str), 1337);
    printf("Hash of \"%s\": %u\n", str, h);
    return 0;
}