//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x,n) ((x << n) | (x >> (32-n))) // Bit Rotation 
#define ROTR(x,n) ((x >> n) | (x << (32-n))) // Bit Rotation 
#define SHR(x,n)  (x >> n) // Bit Shifting 
#define CH(x,y,z) ((x & y) ^ (~x & z)) // Conditional Function 
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z)) // Majority Function 
#define SIGMA(x) (ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22)) // Sigma Function 
#define SIGMA_INV(x) (ROTR(x,7) ^ ROTR(x,18) ^ SHR(x,3)) // Inverse Sigma

void sha256(uint8_t *data, uint32_t len, uint8_t *hash)
{
    // Message Schedule
    uint32_t w[64]; 

    // Hash Values
    uint32_t a, b, c, d, e, f, g, h; 

    // Hash Constants 
    uint32_t k[64] = 
    {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Initial Hash Values
    a = 0x6a09e667; 
    b = 0xbb67ae85; 
    c = 0x3c6ef372; 
    d = 0xa54ff53a; 
    e = 0x510e527f; 
    f = 0x9b05688c; 
    g = 0x1f83d9ab; 
    h = 0x5be0cd19; 

    uint32_t i, j; 

    // Message Padding
    uint32_t new_len = ((((len + 8)/64) + 1)*64) - 8; 
    uint8_t *msg_padded = (uint8_t*) calloc(new_len + 64, 1); 
    memcpy(msg_padded, data, len); 
    msg_padded[len] = 0x80; 
    *((uint64_t*) (msg_padded + new_len)) = len*8; 

    // Hash Calculation
    for(i = 0; i < new_len; i += 64)
    {
        for(j = 0; j < 16; ++j) 
        {
            w[j] = ((uint32_t)msg_padded[i+4*j+0] << 24) |
                   ((uint32_t)msg_padded[i+4*j+1] << 16) |
                   ((uint32_t)msg_padded[i+4*j+2] <<  8) |
                   ((uint32_t)msg_padded[i+4*j+3] <<  0);
        }

        for(j = 16; j < 64; ++j) 
        {
            uint32_t s0 = SIGMA(w[j-15]);
            uint32_t s1 = SIGMA_INV(w[j-2]);
            w[j] = w[j-16] + s0 + w[j-7] + s1;
        }

        uint32_t temp1, temp2; 

        for(j = 0; j < 64; ++j)
        {
            temp1 = h + CH(e, f, g) + SIGMA_INV(e) + w[j] + k[j];
            temp2 = MAJ(a, b, c) + SIGMA(a);
            h = g; 
            g = f; 
            f = e; 
            e = d + temp1; 
            d = c; 
            c = b; 
            b = a; 
            a = temp1 + temp2; 
        }

        a += 0x6a09e667; 
        b += 0xbb67ae85; 
        c += 0x3c6ef372; 
        d += 0xa54ff53a; 
        e += 0x510e527f; 
        f += 0x9b05688c; 
        g += 0x1f83d9ab; 
        h += 0x5be0cd19;
    }

    free(msg_padded); 

    // Hash Output
    *((uint32_t*)hash) = a; 
    *((uint32_t*)hash + 1) = b; 
    *((uint32_t*)hash + 2) = c; 
    *((uint32_t*)hash + 3) = d; 
    *((uint32_t*)hash + 4) = e; 
    *((uint32_t*)hash + 5) = f; 
    *((uint32_t*)hash + 6) = g; 
    *((uint32_t*)hash + 7) = h;
}

int main() 
{
    uint8_t data[] = "Example Hash Program";
    uint8_t hash[32];

    sha256(data, sizeof(data), hash);

    int i;
    printf("Hash Output:\n");
    for (i = 0; i < 32; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}