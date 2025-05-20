//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x) << (n)) | ((x) >> (32 - (n)))

uint32_t f1(uint32_t x, uint32_t y, uint32_t z) {
    return x ^ y ^ z;
}

uint32_t f2(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) | (~x & z);
}

uint32_t f3(uint32_t x, uint32_t y, uint32_t z) {
    return (x | ~y) ^ z;
}

uint32_t f4(uint32_t x, uint32_t y, uint32_t z) {
    return (x & z) | (y & ~z);
}

typedef uint32_t (*hash_func)(uint32_t, uint32_t, uint32_t);

hash_func funcs[] = {f1, f2, f3, f4};

void hash(const uint8_t *data, size_t len, uint32_t *hash_value) {
    uint32_t a = 0x67452301;
    uint32_t b = 0xefcdab89;
    uint32_t c = 0x98badcfe;
    uint32_t d = 0x10325476;

    uint32_t *words = malloc(len + 64);

    size_t i;
    for (i = 0; i < len + 64; i += 4) {
        if (i < len) {
            words[i >> 2] = (uint32_t)data[i] |
                            ((uint32_t)data[i + 1] << 8) |
                            ((uint32_t)data[i + 2] << 16) |
                            ((uint32_t)data[i + 3] << 24);
        } else if (i == len) {
            words[i >> 2] = 0x80;
        } else {
            words[i >> 2] = 0;
        }
    }

    size_t num_blocks = (len + 8 + 64) >> 6;
    words[num_blocks << 4 >> 2] = (uint32_t)len << 3;
    words[num_blocks << 4 >> 2 + 1] = (uint32_t)len >> 29;

    size_t j;
    for (i = 0; i < num_blocks; i++) {
        uint32_t *block = words + i * 16;
        uint32_t aa = a;
        uint32_t bb = b;
        uint32_t cc = c;
        uint32_t dd = d;
        for (j = 0; j < 64; j++) {
            uint32_t f = funcs[j >> 4](b, c, d);
            uint32_t g = (j % 16);
            uint32_t temp = d;
            d = c;
            c = b;
            b = b + ROTL(a + f + words[g] + 0x5a827999, j % 32);
            a = temp;
        }
        a += aa;
        b += bb;
        c += cc;
        d += dd;
    }

    hash_value[0] = a;
    hash_value[1] = b;
    hash_value[2] = c;
    hash_value[3] = d;
}

void print_hash(const uint32_t *hash_value) {
    printf("%08x%08x%08x%08x\n", hash_value[0], hash_value[1], hash_value[2],hash_value[3]);
}

int main() {
    const char *msg = "Hello, world!";
    size_t len = strlen(msg);
    uint32_t hash_value[4];
    hash((const uint8_t *)msg, len, hash_value);
    print_hash(hash_value);
    return 0;
}