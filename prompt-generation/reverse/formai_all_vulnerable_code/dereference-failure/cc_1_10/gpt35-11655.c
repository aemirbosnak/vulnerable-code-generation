//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: single-threaded
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 64

// Rotate left function
#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// SHA256 initial hash values
uint32_t H[] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

// SHA256 round constants
uint32_t K[] = {
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2
};

// SHA256 compression function
void sha_256(const uint8_t *message, size_t message_len, uint32_t hash[8]) {
    uint32_t w[64], a, b, c, d, e, f, g, h, t1, t2;
    uint8_t *padded_message = NULL;

    // Pre-processing - padding the message
    size_t padded_len = message_len + 1 + 8;
    size_t padded_blocks = padded_len / BLOCK_SIZE + ((padded_len % BLOCK_SIZE) ? 1 : 0);
    padded_message = calloc(padded_blocks, BLOCK_SIZE);

    memcpy(padded_message, message, message_len);
    padded_message[message_len] = 0x80;
    uint64_t bit_len = message_len * 8;
    memcpy(padded_message + padded_len - 8, &bit_len, 8);

    for (size_t i = 0; i < padded_blocks; i++) {
        for (size_t j = 0; j < BLOCK_SIZE / 4; j++) {
            int offset = i * BLOCK_SIZE / 4 + j;
            w[j] = (offset < padded_len / 4) ? ((uint32_t)padded_message[offset * 4] << 24) |
                                                   ((uint32_t)padded_message[offset * 4 + 1] << 16) |
                                                   ((uint32_t)padded_message[offset * 4 + 2] << 8) |
                                                   ((uint32_t)padded_message[offset * 4 + 3])
                                             : 0;
        }

        // Compression
        a = hash[0];
        b = hash[1];
        c = hash[2];
        d = hash[3];
        e = hash[4];
        f = hash[5];
        g = hash[6];
        h = hash[7];

        for (size_t j = 0; j < 64; j++) {
            t1 = h + K[j] + w[j] + ((e & f) ^ (~e & g)) + LEFT_ROTATE(a, 5) + b;
            t2 = ((a & b) ^ (a & c) ^ (b & c)) + LEFT_ROTATE(d, 2);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        // Update hash values
        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
        hash[4] += e;
        hash[5] += f;
        hash[6] += g;
        hash[7] += h;
    }

    free(padded_message);
}

int main() {
    const char *message = "The quick brown fox jumps over the lazy dog";
    uint32_t hash[8];

    memset(hash, 0, sizeof(hash));

    sha_256((const uint8_t *)message, strlen(message), hash);

    printf("Hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}