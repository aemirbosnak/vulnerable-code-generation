//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Defining the SHA-2 constants
const uint32_t K[] = {
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

//Bitwise rotate a 32-bit integer by n bits
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

//SHA-256 functions for each round
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))
#define EP1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))
#define SIG0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ ((x) >> 10))

//Struct for storing hash values
typedef struct {
    uint32_t h[8];
} SHA256_HASH;

//Main SHA-256 hash function
void sha256(uint8_t *data, size_t len, SHA256_HASH *hash) {
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t t1, t2;
    uint32_t maj_tmp, ch_tmp, ep0_tmp, ep1_tmp, sig0_tmp, sig1_tmp;
    uint32_t w[64];
    int i, j;

    //Initial hash values from SHA-2 spec
    uint32_t H[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    //Padding input data
    size_t new_len = ((((len + 8) / 64) + 1) * 64);
    uint8_t *data_padded = (uint8_t*)calloc(new_len, sizeof(uint8_t));
    memcpy(data_padded, data, len);
    data_padded[len] = 0x80;
    *((uint64_t*)(data_padded + new_len - 8)) = len * 8;

    //Process each 512-bit block of padded data
    for (i = 0; i < new_len; i += 64) {
        //Prepare the message schedule
        for (j = 0; j < 16; j++) {
            w[j] = *((uint32_t*)(data_padded + i + (j * 4)));
        }
        for (j = 16; j < 64; j++) {
            sig1_tmp = SIG1(w[j - 2]);
            w[j] = w[j - 16] + sig1_tmp + w[j - 7] + SIG0(w[j - 15]);
        }

        //Initialize the working variables
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        //Perform the main hash computation for each round
        for (j = 0; j < 64; j++) {
            ep0_tmp = EP0(a);
            ch_tmp = CH(a, b, c);
            t1 = h + ep0_tmp + ch_tmp + K[j] + w[j];
            ep1_tmp = EP1(e);
            maj_tmp = MAJ(e, f, g);
            t2 = ep1_tmp + maj_tmp;

            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        //Compute the intermediate hash values for the block
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    //Store the final hash value
    hash->h[0] = H[0];
    hash->h[1] = H[1];
    hash->h[2] = H[2];
    hash->h[3] = H[3];
    hash->h[4] = H[4];
    hash->h[5] = H[5];
    hash->h[6] = H[6];
    hash->h[7] = H[7];

    //Free memory
    free(data_padded);
}

//Main function
int main(void) {
    //Test input data
    uint8_t test_data[] = "Hello, world!";

    //Calculate hash of test data
    SHA256_HASH test_hash;
    sha256(test_data, strlen((char*)test_data), &test_hash);

    //Print hash in hexadecimal
    printf("Hash of \"%s\": ", test_data);
    for (int i = 0; i < 8; i++) {
        printf("%08x", test_hash.h[i]);
    }
    printf("\n");

    return 0;
}