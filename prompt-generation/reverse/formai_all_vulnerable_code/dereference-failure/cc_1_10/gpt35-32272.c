//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * This is a custom cryptographic hash function implementation in C.
 * It uses SHA-256 algorithm for hashing the given input string.
 * The SHA-256 is a widely used hash algorithm that outputs 256 bits of data.
 * In this implementation, we use uint32_t to represent the 256 bits hash value.
 * This implementation uses standard bit manipulation functions for hash calculation.
 */

// The SHA-256 algorithm uses modular arithmetic constants
#define ROTR(x,n) (((x)>>(n))|((x)<<(32-(n))))
#define CH(x,y,z) (((x)&(y))^((~(x))&(z)))
#define MAJ(x,y,z) (((x)&(y))^((x)&(z))^((y)&(z)))
#define SIG0(x) (ROTR(x,2)^ROTR(x,13)^ROTR(x,22))
#define SIG1(x) (ROTR(x,6)^ROTR(x,11)^ROTR(x,25))
#define sig0(x) (ROTR(x,7)^ROTR(x,18)^((x)>>3))
#define sig1(x) (ROTR(x,17)^ROTR(x,19)^((x)>>10))

// Hashing function, takes input string and size of string as arguments.
uint32_t *sha256_hash(const char *input, size_t len)
{
    // Message block size, the input string is padded until its length is 448 bits mod 512 bits. 
    const uint32_t blk_size = 512 / 8;
    uint32_t len_bits = len * 8;
    uint32_t num_blks = (((len_bits + 64)/(blk_size)) + 1) * (blk_size/4);
    uint32_t *blk = calloc(num_blks, sizeof(uint32_t));
    
    memcpy(blk, input, len);
    blk[len/4] |= 0x80 << ((3 - (len % 4)) * 8);
    blk[num_blks - 1] = len_bits;

    static uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    uint32_t a, b, c, d, e, f, g, h, t1, t2, i;
    for (i = 0; i < num_blks; i += 16) {
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        // Compression function
        for (uint32_t j = 0; j < 64; j++) {
            if (j < 16) {
                t1 = blk[i+j];
            } else {
                t1 = sig1(blk[i+((j+1)%32)]) + blk[i+((j+14)%32)] + sig0(blk[i+((j+9)%32)]) + blk[i+j];
            }

            t1 += h + SIG1(e) + CH(e, f, g) + (uint32_t)0xffffffff + 1;
            t2 = SIG0(a) + MAJ(a, b, c);

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    free(blk);

    // Output hash value
    static uint32_t hashval[8];
    memcpy(hashval, H, 8 * sizeof(uint32_t));
    return hashval;
}

int main()
{
    char *input_str = "Hello, World!";
    uint32_t *hashval = sha256_hash(input_str, strlen(input_str));

    printf("Input string: \"%s\"\n", input_str);
    printf("Hash value = ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hashval[i]);
    }
    printf("\n");

    return 0;
}