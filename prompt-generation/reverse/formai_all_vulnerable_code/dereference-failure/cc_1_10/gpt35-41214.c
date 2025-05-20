//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//Constants used in the hash function
#define ROTL32(x,n) ((x) << (n)) | ((x) >> (32 - (n)))

#define CH(x,y,z) ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTL32(x,2) ^ ROTL32(x,13) ^ ROTL32(x,22))
#define SIGMA1(x) (ROTL32(x,6) ^ ROTL32(x,11) ^ ROTL32(x,25))
#define DELTA0(x) (ROTL32(x,7) ^ ROTL32(x,18) ^ (x >> 3))
#define DELTA1(x) (ROTL32(x,17) ^ ROTL32(x,19) ^ (x >> 10))

//Initial hash values
const uint32_t H[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

//Preprocessing steps, padding the message with 1s and zeros
void padding(char *message, uint64_t *len, int *num_blocks, uint32_t **blocks) {
    int i;
    unsigned char *p;
    uint64_t size;

    *len = strlen(message); //Get length of message
    *num_blocks = ((int) (*len + 9) / 64) + 1;
    size = *num_blocks * 64;

    *blocks = calloc(1, size);

    //Copy message to blocks
    p = (unsigned char *) *blocks;
    for (i = 0; i < *len; i++) {
        p[i] = message[i];
    }

    //Add a 1 bit
    p[i++] = 0x80;

    //Add zero bits
    while (i < (size - 8)) {
        p[i++] = 0x00;
    }

    //Add length of message in bits as 64-bit little-endian integer
    *(uint64_t *) &p[size - 8] = *len * 8;
}

//Main hash function
void hash(uint32_t *blocks, uint32_t *hash_values, int num_blocks) {
    int i, j;
    uint32_t t1, t2;
    uint32_t *w, *a, *b, *c, *d, *e, *f, *g, *h;
    uint32_t *k;
    uint32_t temp1, temp2;

    for (i = 0; i < num_blocks; i++) {
        w = &blocks[i * 16];

        a = &hash_values[0];
        b = &hash_values[1];
        c = &hash_values[2];
        d = &hash_values[3];
        e = &hash_values[4];
        f = &hash_values[5];
        g = &hash_values[6];
        h = &hash_values[7];
        k = (uint32_t *) H;

        //Initialize working variables
        for (j = 0; j < 8; j++) {
            hash_values[j] = H[j];
        }

        //Compression loop
        for (j = 0; j < 64; j++) {
            if (j < 16) {
                t1 = *h + SIGMA1(*e) + CH(*e, *f, *g) + k[j] + w[j];
            }
            else {
                t1 = *h + SIGMA1(*e) + MAJ(*e, *f, *g) + k[j] + w[j];
            }
            t2 = SIGMA0(*a) + DELTA1(*e) + CH(*e, *f, *g);
            *h = *g;
            *g = *f;
            *f = *e;
            *e = *d + t1;
            *d = *c;
            *c = *b;
            *b = *a;
            *a = t1 + t2;
        }

        //Add hash values from this block to overall hash
        hash_values[0] += *a;
        hash_values[1] += *b;
        hash_values[2] += *c;
        hash_values[3] += *d;
        hash_values[4] += *e;
        hash_values[5] += *f;
        hash_values[6] += *g;
        hash_values[7] += *h;
    }
}

int main() {
    char message[] = "The quick brown fox jumps over the lazy dog";
    uint64_t len;
    int num_blocks;
    uint32_t *blocks, hash_values[8];

    padding(message, &len, &num_blocks, &blocks);
    hash(blocks, hash_values, num_blocks);

    printf("Hash: %08x%08x%08x%08x%08x%08x%08x%08x\n",
        hash_values[0], hash_values[1], hash_values[2], hash_values[3],
        hash_values[4], hash_values[5], hash_values[6], hash_values[7]);

    free(blocks);
    return 0;
}