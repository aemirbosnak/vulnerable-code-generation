//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t fmix32(uint32_t h) {
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

void Murmur32(const void* key, int len, uint32_t seed, void* out) {
    const uint8_t* data = (const uint8_t*)key;
    const int nblocks = len / 4;
    uint32_t h = seed;
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;
    const uint32_t* blocks = (const uint32_t*)(data + nblocks * 4);
    for (int i = -nblocks; i; i++) {
        uint32_t k = i >= 0 ? blocks[i] : *(const uint32_t*)((const uint8_t*)data + i * 4);
        k *= c1;
        k = ROTATE_LEFT(k, 15);
        k *= c2;
        h ^= k;
        h = ROTATE_LEFT(h, 13);
        h = h * 5 + 0xe6546b64;
    }
    h ^= len;
    h = fmix32(h);
    *(uint32_t*)out = h;
}

void print_hash(void* hash, int len) {
    uint8_t* h = (uint8_t*)hash;
    for (int i = 0; i < len; i++) {
        printf("%02x", h[i]);
    }
    printf("\n");
}

int main() {
    const char* msg = "hello world";
    uint32_t hash = 0;
    Murmur32(msg, strlen(msg), 0, &hash);
    print_hash(&hash, sizeof(hash));
    return 0;
}