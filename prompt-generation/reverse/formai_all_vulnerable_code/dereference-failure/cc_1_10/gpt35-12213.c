//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 64
#define MESSAGE_DIGEST_SIZE 32

typedef unsigned char byte;

// ROTATE SET OF BITS
#define ROTL(x, n) (((x)<<(n))|((x)>>(32-(n))))

// CONSTANTS
const unsigned int K[64] = {
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

// F1 FUNCTION
unsigned int F1(unsigned int x, unsigned int y, unsigned int z) {
    return ((x & y) | ((~x) & z));
}

// F2 FUNCTION 
unsigned int F2(unsigned int x, unsigned int y, unsigned int z) {
    return ((x & y) | (x & z) | (y & z));
}

// F3 FUNCTION
unsigned int F3(unsigned int x) {
    return (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22));
}

// F4 FUNCTION
unsigned int F4(unsigned int x) {
    return (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25));
}

// F5 FUNCTION
unsigned int F5(unsigned int x) {
    return (ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3));
}

// F6 FUNCTION
unsigned int F6(unsigned int x) {
    return (ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10));
}

// HASH FUNCTION
byte *hash(const byte *data, size_t len) {
    // INITIALIZE VARIABLES
    unsigned int H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
    unsigned int W[64];
    unsigned int a, b, c, d, e, f, g, h, i, j, t, T1, T2;
    size_t new_len;
    byte *msg, *padded, *result;

    // PREPROCESS MESSAGE
    new_len = ((len + 8) / BLOCK_SIZE + 1) * BLOCK_SIZE;
    msg = (byte *)calloc(new_len + 64, 1);
    padded = (byte *)msg;
    memcpy(padded, data, len);
    padded[len] = 0x80;
    *(unsigned long long *)(padded + new_len) = len * 8;

    // PROCESS MESSAGE IN BLOCKS
    for (i = 0; i < new_len; i += BLOCK_SIZE) {
        // INITIALIZE W
        for (j = 0; j < 16; j++) {
            W[j] = ((unsigned int)padded[i + j * 4 + 0] << 24) |
                   ((unsigned int)padded[i + j * 4 + 1] << 16) |
                   ((unsigned int)padded[i + j * 4 + 2] << 8) |
                   ((unsigned int)padded[i + j * 4 + 3] << 0); 
        }

        for (; j < 64; j++) {
            W[j] = F6(W[j - 16]) + W[j - 7] + F5(W[j - 15]) + W[j - 16];
        }

        // INITIALIZE VARIABLES
        a = H[0]; b = H[1]; c = H[2]; d = H[3];
        e = H[4]; f = H[5]; g = H[6]; h = H[7];

        // PERFORM ROUNDS
        for (j = 0; j < 64; j++) {
            T1 = h + F4(e) + F1(e, f, g) + K[j] + W[j];
            T2 = F3(a) + F2(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // UPDATE HASH VALUES
        H[0] += a; H[1] += b; H[2] += c; H[3] += d;
        H[4] += e; H[5] += f; H[6] += g; H[7] += h;
    }

    // ALLOCATE MEMORY FOR RESULT
    result = (byte *)malloc(MESSAGE_DIGEST_SIZE);

    // FORMAT RESULT AS HEXADECIMAL STRING
    for (i = 0; i < MESSAGE_DIGEST_SIZE / 4; i++) {
        sprintf((char *)result + i * 8, "%08x", H[i]);
    }

    // FREE MEMORY
    free(msg);

    // RETURN RESULT
    return result;
}

// MAIN FUNCTION
int main() {
    // GENERATE RANDOM INPUT AND COMPUTE HASH    
    srand(time(NULL));
    byte data[64];
    byte *hash_val;
    int i;

    for (i = 0; i < 64; i++) {
        data[i] = rand() % 256;
    }

    hash_val = hash(data, 64);

    // PRINT INPUT AND HASH VALUES
    printf("Input: ");
    for (i = 0; i < 64; i++) {
        printf("%02x", data[i]);
    }

    printf("\nHash: ");
    for (i = 0; i < MESSAGE_DIGEST_SIZE; i++) {
        printf("%02x", hash_val[i]);
    }

    printf("\n");

    // FREE MEMORY
    free(hash_val);

    // SUCCESS
    return 0;
}