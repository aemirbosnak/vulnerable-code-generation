//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Function prototypes */
void sha256(const char* message, uint32_t hash[8]);
void transform(uint32_t hash[8], const uint32_t block[16]);

/* SHA-256 constants */
const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

/* SHA-256 functions */
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHR(x, n) ((x) >> (n))

#define CH(x, y, z) (((x) & (y)) ^ ((~x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define S0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define S1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

/* SHA-256 main function */
void sha256(const char* message, uint32_t hash[8])
{
    /* Message padding */
    size_t initial_len = strlen(message);
    uint8_t* padded_message = calloc(initial_len + 64, 1);
    memcpy(padded_message, message, initial_len);
    padded_message[initial_len] = 0x80;
    uint64_t bit_len = initial_len * 8;
    uint32_t* bit_len_ptr = (uint32_t*)(padded_message + initial_len + 56);
    bit_len_ptr[0] = (uint32_t)(bit_len >> 32);
    bit_len_ptr[1] = (uint32_t)(bit_len & 0xFFFFFFFF);
    uint32_t num_blocks = (initial_len + 9 + 63) / 64;

    /* Initial hash values */
    uint32_t H[8] = { 
        0x6a09e667, 
        0xbb67ae85, 
        0x3c6ef372, 
        0xa54ff53a, 
        0x510e527f, 
        0x9b05688c, 
        0x1f83d9ab, 
        0x5be0cd19
    };

    /* Process each block */
    for (uint32_t i = 0; i < num_blocks; ++i) {
        uint32_t* block = (uint32_t*)(padded_message + i * 64);
        transform(H, block);
    }

    /* Return the hash */
    memcpy(hash, H, 8 * sizeof(uint32_t));
}

/* SHA-256 block transformation function */
void transform(uint32_t hash[8], const uint32_t block[16])
{
    /* Initialize working variables */
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = block[i];
    }
    for (int i = 16; i < 64; ++i) {
        w[i] = S1(w[i - 2]) + w[i - 7] + S0(w[i - 15]) + w[i - 16];
    }
    uint32_t a = hash[0];
    uint32_t b = hash[1];
    uint32_t c = hash[2];
    uint32_t d = hash[3];
    uint32_t e = hash[4];
    uint32_t f = hash[5];
    uint32_t g = hash[6];
    uint32_t h = hash[7];

    /* Perform rounds */
    for (int i = 0; i < 64; ++i) {
        uint32_t t1 = h + SIGMA1(e) + CH(e, f, g) + K[i] + w[i];
        uint32_t t2 = SIGMA0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    /* Update hash values */
    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
}

/* Example usage */
int main()
{
    uint32_t hash[8];
    sha256("hello, world", hash);
    printf("SHA-256 hash of \"hello, world\":\n");
    for (int i = 0; i < 8; ++i) {
        printf("%08x ", hash[i]);
    }
    printf("\n");
    return 0;
}