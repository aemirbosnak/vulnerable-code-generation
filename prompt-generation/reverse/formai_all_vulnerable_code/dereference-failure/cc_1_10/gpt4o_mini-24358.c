//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32  // SHA256 outputs a 32 byte digest
#define BLOCK_SIZE 64          // SHA256 operates on 512-bit blocks (64 bytes)
#define ROUNDCONSTANTS 64      // Number of rounds in SHA256

// Helper function to perform right rotation
unsigned int rightRotate(unsigned int value, unsigned int amount) {
    return (value >> amount) | (value << (32 - amount));
}

// The SHA-256 hash function structure
typedef struct {
    unsigned char data[BLOCK_SIZE];
    unsigned int datalen;
    unsigned long long bitlen;
    unsigned int state[8];
} SHA256_CTX;

// SHA-256 initialization constants
unsigned int k[ROUNDCONSTANTS] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
    0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
    0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
    0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa11,
    0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Function to initialize the SHA-256 context
void sha256_init(SHA256_CTX *ctx) {
    ctx->datalen = 0;
    ctx->bitlen = 0;
    ctx->state[0] = 0x6a09e667;
    ctx->state[1] = 0xbb67ae85;
    ctx->state[2] = 0x3c6ef372;
    ctx->state[3] = 0xa54ff53a;
    ctx->state[4] = 0x510e527f;
    ctx->state[5] = 0x9b05688c;
    ctx->state[6] = 0x1f83d9ab;
    ctx->state[7] = 0x5be0cd19;
}

// Function to process a block of data
void sha256_transform(SHA256_CTX *ctx, const unsigned char data[]) {
    unsigned int i, j;
    unsigned int m[64], s0, s1, ch, temp1, temp2, maj;
    unsigned int a, b, c, d, e, f, g, h;

    // 1. Prepare the message schedule
    for (i = 0; i < 16; ++i) {
        m[i] = ((unsigned int)data[i * 4] << 24) | ((unsigned int)data[i * 4 + 1] << 16) |
                ((unsigned int)data[i * 4 + 2] << 8) | (unsigned int)data[i * 4 + 3];
    }
    for (i = 16; i < 64; ++i) {
        s0 = rightRotate(m[i - 15], 7) ^ rightRotate(m[i - 15], 18) ^ (m[i - 15] >> 3);
        s1 = rightRotate(m[i - 2], 17) ^ rightRotate(m[i - 2], 19) ^ (m[i - 2] >> 10);
        m[i] = m[i - 16] + s0 + m[i - 7] + s1;
    }

    // 2. Initialize the working variables
    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    f = ctx->state[5];
    g = ctx->state[6];
    h = ctx->state[7];

    // 3. Compute the hash
    for (i = 0; i < 64; ++i) {
        s1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
        ch = (e & f) ^ (~e & g);
        temp1 = h + s1 + ch + k[i] + m[i];
        s0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
        maj = (a & b) ^ (a & c) ^ (b & c);
        temp2 = s0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    // 4. Add the compressed chunk to the current hash value
    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
    ctx->state[5] += f;
    ctx->state[6] += g;
    ctx->state[7] += h;
}

// Function to update the SHA-256 context with new data
void sha256_update(SHA256_CTX *ctx, const unsigned char data[], size_t len) {
    for (size_t i = 0; i < len; ++i) {
        ctx->data[ctx->datalen] = data[i];
        ctx->datalen++;
        if (ctx->datalen == BLOCK_SIZE) {
            sha256_transform(ctx, ctx->data);
            ctx->bitlen += 8 * BLOCK_SIZE;
            ctx->datalen = 0;
        }
    }
}

// Function to finalize the SHA-256 hash
void sha256_final(SHA256_CTX *ctx, unsigned char hash[]) {
    ctx->bitlen += ctx->datalen * 8;

    // Pad the last block
    ctx->data[ctx->datalen++] = 0x80;
    if (ctx->datalen < 56) {
        memset(ctx->data + ctx->datalen, 0, 56 - ctx->datalen);
    } else {
        memset(ctx->data + ctx->datalen, 0, BLOCK_SIZE - ctx->datalen);
        sha256_transform(ctx, ctx->data);
        memset(ctx->data, 0, 56);
    }

    // Append the size of the original message
    ctx->data[56] = (ctx->bitlen >> 56) & 0xff;
    ctx->data[57] = (ctx->bitlen >> 48) & 0xff;
    ctx->data[58] = (ctx->bitlen >> 40) & 0xff;
    ctx->data[59] = (ctx->bitlen >> 32) & 0xff;
    ctx->data[60] = (ctx->bitlen >> 24) & 0xff;
    ctx->data[61] = (ctx->bitlen >> 16) & 0xff;
    ctx->data[62] = (ctx->bitlen >> 8) & 0xff;
    ctx->data[63] = ctx->bitlen & 0xff;
    sha256_transform(ctx, ctx->data);

    // Copy the final hash value
    for (int i = 0; i < 8; i++) {
        hash[i * 4]     = (ctx->state[i] >> 24) & 0x00ff;
        hash[i * 4 + 1] = (ctx->state[i] >> 16) & 0x00ff;
        hash[i * 4 + 2] = (ctx->state[i] >> 8) & 0x00ff;
        hash[i * 4 + 3] = ctx->state[i] & 0x00ff;
    }
}

// Function to print the SHA-256 hash in hex format
void print_hash(unsigned char hash[]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Main function to drive the SHA-256 hashing
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string_to_hash>\n", argv[0]);
        return 1;
    }

    SHA256_CTX ctx;
    unsigned char hash[SHA256_BLOCK_SIZE];

    // Initialize the context
    sha256_init(&ctx);
    
    // Update with the input string
    sha256_update(&ctx, (unsigned char*)argv[1], strlen(argv[1]));
    
    // Finalize the hash
    sha256_final(&ctx, hash);
    
    // Print the resulting hash in hexadecimal format
    printf("SHA-256 hash of '%s': ", argv[1]);
    print_hash(hash);

    return 0;
}