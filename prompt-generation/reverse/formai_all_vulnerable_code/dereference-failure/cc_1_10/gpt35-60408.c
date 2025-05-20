//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROT_LEFT(x,n)	(((x) << (n)) | ((x) >> (32 - (n))))

// S-Boxes for SHA-256
static const uint32_t K[] = {
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

// SHA-256 initial hash values
static const uint32_t H[] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

// SHA-256 operations
#define CH(x,y,z)	(((x) & (y)) ^ ((~x) & (z)))
#define MAJ(x,y,z)	(((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define BSIG0(x)	(ROT_LEFT((x), 2) ^ ROT_LEFT((x), 13) ^ ROT_LEFT((x), 22))
#define BSIG1(x)	(ROT_LEFT((x), 6) ^ ROT_LEFT((x), 11) ^ ROT_LEFT((x), 25))
#define SSIG0(x)	(ROT_LEFT((x), 7) ^ ROT_LEFT((x), 18) ^ ((x) >> 3))
#define SSIG1(x)	(ROT_LEFT((x), 17) ^ ROT_LEFT((x), 19) ^ ((x) >> 10))

// SHA-256 computation
void sha256(const unsigned char *data, uint32_t len, uint32_t *hash) 
{
    uint32_t w[64];
    uint32_t a, b, c, d, e, f, g, h, i, j, t1, t2;
    
    // Pre-processing
    uint32_t n_blocks = ((len + 8) / 64) + 1;
    uint32_t padded_len = n_blocks * 64;
    uint8_t *padded_data = calloc(1, padded_len);
    memcpy(padded_data, data, len);
    padded_data[len] = 0x80;

    uint32_t bit_len = len * 8;
    memcpy(padded_data + padded_len - 8, &bit_len, sizeof(bit_len));
    
    // Main loop
    for (i = 0; i < n_blocks; i++) {
        // Prepare message schedule
        for (j = 0; j < 16; j++) {
            w[j] = (padded_data[i * 64 + j * 4] << 24)
                | (padded_data[i * 64 + j * 4 + 1] << 16)
                | (padded_data[i * 64 + j * 4 + 2] << 8)
                | padded_data[i * 64 + j * 4 + 3];
        }
        for (j = 16; j < 64; j++) {
            w[j] = SSIG1(w[j-2]) + w[j-7] + SSIG0(w[j-15]) + w[j-16];
        }
        
        // Initialize working variables
        a = hash[0]; b = hash[1]; c = hash[2]; d = hash[3];
        e = hash[4]; f = hash[5]; g = hash[6]; h = hash[7];
        
        // Compression function
        for (j = 0; j < 64; j++) {
            t1 = h + BSIG1(e) + CH(e, f, g) + K[j] + w[j];
            t2 = BSIG0(a) + MAJ(a, b, c);
            h = g; g = f; f = e; e = d + t1;
            d = c; c = b; b = a; a = t1 + t2;
        }
        
        // Update hash values
        hash[0] += a; hash[1] += b; hash[2] += c; hash[3] += d;
        hash[4] += e; hash[5] += f; hash[6] += g; hash[7] += h;
    }
    
    // Free memory
    free(padded_data);
}

int main(int argc, char **argv) 
{
    const char *msg = "Hello, world!";
    uint32_t hash[8] = {H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]};
    uint32_t i;

    // Compute SHA-256 hash
    sha256((unsigned char *)msg, strlen(msg), hash);

    // Print hash
    for (i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");
    
    return 0;
}