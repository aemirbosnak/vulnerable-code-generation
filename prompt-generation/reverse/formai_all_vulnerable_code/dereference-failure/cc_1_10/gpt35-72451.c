//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define some constants for the hash function
#define ROTL32(x, y) ((x << y) | (x >> (32 - y)))
#define ROTL64(x, y) ((x << y) | (x >> (64 - y)))
#define BIG_CONSTANT(x) (x##LLU)

// Initialize the hash values (using the first 64 bits of the fractional parts of the square roots of the first 8 primes)
uint64_t h0 = 0x6a09e667f3bcc908ULL;
uint64_t h1 = 0xbb67ae8584caa73bULL;
uint64_t h2 = 0x3c6ef372fe94f82bULL;
uint64_t h3 = 0xa54ff53a5f1d36f1ULL;
uint64_t h4 = 0x510e527fade682d1ULL;
uint64_t h5 = 0x9b05688c2b3e6c1fULL;
uint64_t h6 = 0x1f83d9abfb41bd6bULL;
uint64_t h7 = 0x5be0cd19137e2179ULL;

// The main hash function
void hash(const void *data, size_t length, uint64_t *out)
{
    const uint8_t *p = (const uint8_t *)data;
    const uint8_t *end = p + length;
    uint64_t h[8];
    uint64_t *q;
    uint64_t k1, k2, c1, c2;
    
    // Initialize the hash values
    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    
    // Define some constants
    c1 = BIG_CONSTANT(0x87c37b91114253d5);
    c2 = BIG_CONSTANT(0x4cf5ad432745937f);
    
    // Main loop
    while (p + 8 <= end) {
        k1 = *((const uint64_t *)p);
        k2 = *((const uint64_t *)(p + 8));
        p += 16;
        
        k1 *= c1;
        k1 = ROTL64(k1, 31);
        k1 *= c2;
        h[0] ^= k1;
        h[0] = ROTL64(h[0], 27);
        h[0] += h[4];
        h[0] = h[0] * 5 + 0x52dce729;
        
        k2 *= c2;
        k2 = ROTL64(k2, 33);
        k2 *= c1;
        h[4] ^= k2;
        h[4] = ROTL64(h[4], 31);
        h[4] += h[0];
        h[4] = h[4] * 5 + 0x38495ab5;
    }
    
    // Handle the remaining bytes
    k1 = 0;
    k2 = 0;
    q = (uint64_t *)p;
    switch (end - p) {
        case 7: k2 ^= (uint64_t)p[6] << 48;
        case 6: k2 ^= (uint64_t)p[5] << 40;
        case 5: k2 ^= (uint64_t)p[4] << 32;
        case 4: k2 ^= (uint64_t)p[3] << 24;
        case 3: k2 ^= (uint64_t)p[2] << 16;
        case 2: k2 ^= (uint64_t)p[1] << 8;
        case 1: k2 ^= (uint64_t)p[0];
                k2 *= c2;
                k2 = ROTL64(k2, 33);
                k2 *= c1;
                h[4] ^= k2;
        case 0: k1 ^= (uint64_t)*q;
                k1 *= c1;
                k1 = ROTL64(k1, 31);
                k1 *= c2;
                h[0] ^= k1;
    }
    
    // Finalize the hash
    h[0] ^= length;
    h[4] ^= length;
    h[0] += h[4];
    h[4] += h[0];
    h[0] = ((h[0] >> 1) | (h[0] << 63));
    h[4] = ((h[4] >> 1) | (h[4] << 63));
    h[1] ^= h[0];
    h[1] = ROTL64(h[1], 32);
    h[2] ^= h[4];
    h[2] = ROTL64(h[2], 32);
    h[3] ^= h[0];
    h[4] ^= h[1];
    h[5] ^= h[2];
    h[6] ^= h[3];
    h[7] ^= h[4];
    out[0] = h[0];
    out[1] = h[1];
    out[2] = h[2];
    out[3] = h[3];
    out[4] = h[4];
    out[5] = h[5];
    out[6] = h[6];
    out[7] = h[7];
}

// Test the hash function
int main(void)
{
    char *message = "Hello, world!";
    uint64_t digest[8];
    hash(message, strlen(message), digest);
    printf("SHA-256 hash of \"%s\":\n", message);
    printf("%016llx %016llx %016llx %016llx %016llx %016llx %016llx %016llx\n",
           digest[0], digest[1], digest[2], digest[3], digest[4], digest[5], digest[6], digest[7]);
    return 0;
}