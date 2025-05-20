//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROTATE_LEFT(x,n) ((x << n) | (x >> (32-n)))

/* Constants defined for SHA-256 */
const unsigned int K[] = {
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

/* Helper function to print out a message digest. */
void print_digest(unsigned char *digest)
{
    int i;
    for (i = 0; i < 32; i++)
        printf("%02x", digest[i]);
    printf("\n");
}

/* SHA-256 implementation */
void sha256(unsigned char *message, unsigned int message_len, unsigned char *digest)
{
    /* Initialize message schedule and hash values */
    unsigned int W[64];
    unsigned int a, b, c, d, e, f, g, h;
    unsigned int i, j, t1, t2;

    unsigned int H[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    /* Compute the number of blocks needed */
    unsigned int num_blocks = ((message_len + 8 + 64) / 64) + 1;

    /* Allocate memory for padding and length */
    unsigned int *padded_message = (unsigned int*)calloc(num_blocks * 16, 1);

    /* Copy message into the padded message */
    memcpy(padded_message, message, message_len);

    /* Set the bit indicating the end of the message */
    *(padded_message + message_len/4) |= 0x80000000;

    /* Store the length of the message */
    *(padded_message + num_blocks*16 - 2) = message_len * 8;

    /* Loop through each block */
    for (i = 0; i < num_blocks; i++) {
        /* Copy block into message schedule */
        for (j = 0; j < 16; j++) {
            W[j] = *(padded_message + i*16 + j);
        }

        /* Extend message schedule */
        for (j = 16; j < 64; j++) {
            W[j] = W[j-16] + ROTATE_LEFT(W[j-15], 7) + W[j-7] + ROTATE_LEFT(W[j-2], 15);
        }

        /* Initialize working variables */
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        /* Main loop */
        for (j = 0; j < 64; j++) {
            t1 = h + K[j] + W[j] + ROTATE_LEFT(e, 6) + ((e & f) ^ (~e & g));
            t2 = ROTATE_LEFT(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        /* Compute intermediate hash values */
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    /* Copy final hash value into digest */
    for (i = 0; i < 8; i++) {
        digest[i*4+0] = (unsigned char)(H[i] >> 24);
        digest[i*4+1] = (unsigned char)(H[i] >> 16);
        digest[i*4+2] = (unsigned char)(H[i] >> 8);
        digest[i*4+3] = (unsigned char)(H[i]);
    }

    /* Free memory */
    free(padded_message);
}

/* Test the SHA-256 implementation */
int main(int argc, char *argv[])
{
    char *message = "Hello, world!";
    unsigned int message_len = strlen(message);
    unsigned char digest[32];

    /* Compute the message digest */
    sha256((unsigned char*)message, message_len, digest);

    /* Print out the message digest */
    printf("Message Digest: ");
    print_digest(digest);

    return 0;
}