//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL32(x,y) ((x << y) | (x >> (32 - y)))

#define GETU32(p) (((uint32_t)(p)[0] << 24) | ((uint32_t)(p)[1] << 16) | ((uint32_t)(p)[2] << 8) | ((uint32_t)(p)[3]))

#define PUTU32(p,v) { (p)[0] = (v) >> 24; (p)[1] = (v) >> 16; (p)[2] = (v) >> 8; (p)[3] = (v); }

#define BLOCK_SIZE 64
#define HASH_SIZE 32

/* configurable parameters */
#define ROUNDS 16
#define KEY_SIZE 8

typedef struct {
    uint32_t h[8];
    uint32_t t[2];
    uint8_t  buffer[BLOCK_SIZE];
    uint32_t buflen;
} hash_state;

/* key schedule */
static uint32_t K[ROUNDS][4];

/* initialization vectors */
static uint32_t H[] = {
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};

/* round constants */
static const uint32_t RC[ROUNDS] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174
};

/* circular shifts */
static const uint8_t r[] = { 
    0, 36, 3, 41, 18, 1, 44, 10, 45, 2, 62, 6, 43, 15, 61, 28,
    55, 25, 21, 56, 27, 20, 39, 8, 14, 53, 46, 55, 29, 36, 37, 23,
    43, 31, 48, 18, 5, 57, 37, 50, 35, 38, 19, 10, 54, 34, 57, 51
};

/* rotate function */
static uint32_t rotr(uint32_t x, uint8_t n)
{
    return (x >> n) | (x << (32 - n));
}

/* Compression function */
static void sha256_compress(hash_state *S)
{
    int i;
    uint32_t a, b, c, d, e, f, g, h, t1, t2;
    uint32_t W[64];

    /* prepare message schedule */
    for (i = 0; i < 16; i++) {
        W[i] = GETU32(&S->buffer[i * 4]);
    }
    for (i = 16; i < 64; i++) {
        W[i] = W[i-16] + W[i-7] + rotr(W[i-15], 7) + rotr(W[i-15], 18);
    }

    /* initialize working variables */
    a = S->h[0];
    b = S->h[1];
    c = S->h[2];
    d = S->h[3];
    e = S->h[4];
    f = S->h[5];
    g = S->h[6];
    h = S->h[7];

    /* compression loop */
    for (i = 0; i < ROUNDS; i++) {
        t1 = h + rotr(e, 6) + ((e & f) ^ (~e & g)) + K[i][0] + W[i] + RC[i];
        t2 = rotr(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    /* update hash state */
    S->h[0] += a;
    S->h[1] += b;
    S->h[2] += c;
    S->h[3] += d;
    S->h[4] += e;
    S->h[5] += f;
    S->h[6] += g;
    S->h[7] += h;

    /* clear buffer */
    memset(S->buffer, 0, BLOCK_SIZE);
    S->buflen = 0;
}

/* Update hash state with new data */
static void sha256_update(hash_state *S, const uint8_t *data, uint32_t len)
{
    uint32_t i;

    for (i = 0; i < len; i++) {
        S->buffer[S->buflen++] = data[i];
        if (S->buflen == BLOCK_SIZE) {
            sha256_compress(S);
            S->t[0] += BLOCK_SIZE;
            if (S->t[0] == 0) {
                S->t[1]++;
            }
        }
    }
}

/* Finalize hash computation and output hash value */
static void sha256_final(hash_state *S, uint8_t *hash)
{
    uint32_t i;

    /* add padding */
    S->buffer[S->buflen++] = 0x80;
    if (S->buflen > 56) {
        memset(&S->buffer[S->buflen], 0, BLOCK_SIZE - S->buflen);
        sha256_compress(S);
        S->buflen = 0;
    }
    memset(&S->buffer[S->buflen], 0, 56 - S->buflen);
    PUTU32(&S->buffer[56], S->t[1]);
    PUTU32(&S->buffer[60], S->t[0]);
    sha256_compress(S);

    /* serialize hash value */
    for (i = 0; i < HASH_SIZE; i += 4) {
        PUTU32(&hash[i], S->h[i/4]);
    }
}

/* Initialize hash state */
static void sha256_init(hash_state *S)
{
    int i, j;
    uint8_t key[KEY_SIZE];

    /* initialize key schedule */
    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < 4; j++) {
            K[i][j] = GETU32(&key[(i*4+j) % KEY_SIZE]);
        }
    }

    /* initialize hash state */
    memcpy(S->h, H, sizeof(H));
    memset(S->buffer, 0, sizeof(S->buffer));
    S->buflen = 0;
    S->t[0] = 0;
    S->t[1] = 0;
}

/* Hash a message and output hash value */
void sha256(const uint8_t *message, uint32_t len, uint8_t *hash)
{
    hash_state S;

    sha256_init(&S);
    sha256_update(&S, message, len);
    sha256_final(&S, hash);
}

/* Example usage */
int main()
{
    uint8_t message[] = "hello world";
    uint8_t hash[HASH_SIZE];
    int i;

    /* compute hash value */
    sha256(message, strlen((char *)message), hash);

    /* print hash value */
    for (i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}