//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// rotate left function
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// paranoia level
#define PARANOIA_LEVEL 5

// Hashing function
uint32_t hash(const void *key, size_t len, uint32_t seed)
{
    // Constants derived from the golden ratio
    const uint32_t golden_ratio = 0x9e3779b9;
    const uint32_t inverse_golden_ratio = 0x61c88647;
    
    // This is our state
    uint32_t a[PARANOIA_LEVEL+1];
    memset(a, 0, sizeof(a));
    
    // Initialize the state with the seed
    a[0] = seed;
    
    // Mix in the length
    a[1] = len;
    
    // Mix in the input data
    const uint32_t *key32 = (const uint32_t *)key;
    size_t i = 0;
    while (len >= 4)
    {
        a[2] += key32[i];
        a[3] ^= key32[i];
        a[4] += ROTL(key32[i], (a[3] & 0x1F));
        a[1] ^= ROTL(key32[i], (a[2] & 0x1F));
        ++i;
        len -= 4;
    }
    
    // Mix in the remaining data byte by byte
    const uint8_t *key8 = (const uint8_t*)key32 + i*4;
    uint32_t w = 0;
    switch (len)
    {
        case 3: w += key8[2] << 16;
        case 2: w += key8[1] << 8;
        case 1: w += key8[0];
    }
    a[2] += w;
    a[3] ^= w;
    a[4] += ROTL(w, (a[3] & 0x1F));
    a[1] ^= ROTL(w, (a[2] & 0x1F));
    
    // Mix in some more paranoia
    a[5] = golden_ratio * a[1];
    for (size_t i = 0; i < PARANOIA_LEVEL; ++i)
    {
        a[i] ^= a[i+1];
        a[i+1] += inverse_golden_ratio * a[i];
    }
    
    // Return the hash
    return a[PARANOIA_LEVEL];
}

// Test program
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        return 1;
    }
    
    const char *input = argv[1];
    size_t len = strlen(input);
    uint32_t hashval = hash(input, len, 0);
    printf("%08X\n", hashval);
    
    return 0;
}