//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// rotate left operation 
#define ROTL(x, b) (uint32_t)( ((x) << (b)) | ((x) >> (32 - (b))) )

// F1 operation 
#define F1(x, y, z) (uint32_t)( (x) ^ (y) ^ (z) )

// F2 operation 
#define F2(x, y, z) (uint32_t)( ((x) & (y)) | ((~(x)) & (z)) )

// F3 operation 
#define F3(x, y, z) (uint32_t)( ((x) | (~(y))) ^ (z) )

// F4 operation 
#define F4(x, y, z) (uint32_t)( ((x) & (z)) | ((y) & (~(z))) )

// message schedule array 
static const uint32_t K[] = {
    0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

// circular shift macro 
#define S(x, n) ROTL((x), (n))

// SHA-1 Hash function 
void sha1(char* message, uint32_t* digest) {
    // initialization variables
    uint32_t H[5] = {
        0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0
    };
    uint32_t W[80];
    uint32_t a, b, c, d, e, temp;
    int i, j;

    int message_length = strlen(message);
    int bit_length = message_length * 8; // number of bits in message 
    int padding_length = (bit_length % 512 <= 447) ? 448 - (bit_length % 512) : 960 - (bit_length % 512);
    
    // copy message to new buffer with padding '1' bit
    char* padded_message = (char*) malloc(message_length + padding_length / 8 + 8);
    memcpy(padded_message, message, message_length);
    padded_message[message_length] = 0x80;

    // append original bit length
    for (i = 0; i < 8; i++) {
        padded_message[message_length + padding_length / 8 + i] = (bit_length >> ((7 - i) * 8)) & 0xFF;
    }
    int num_blocks = (message_length + padding_length / 8 + 8) / 64;

    for (i = 0; i < num_blocks; i++) {
        // copy block to buffer
        uint32_t* block = (uint32_t*) (padded_message + i * 64);
        for (j = 0; j < 16; j++) {
            W[j] = block[j];
        }
        // extend buffer
        for (j = 16; j < 80; j++) {
            W[j] = S(W[j-3] ^ W[j-8] ^ W[j-14] ^ W[j-16], 1);
        }
        // copy initialization variables for each block
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];

        for (j = 0; j < 80; j++) {
            // four rounds for each block 
            if (j < 20) {
                temp = S(a, 5) + F1(b, c, d) + e + W[j] + K[0];
            } else if (j < 40) {
                temp = S(a, 5) + F2(b, c, d) + e + W[j] + K[1];
            } else if (j < 60) {
                temp = S(a, 5) + F3(b, c, d) + e + W[j] + K[2];
            } else {
                temp = S(a, 5) + F4(b, c, d) + e + W[j] + K[3];
            }

            // update variables
            e = d;
            d = c;
            c = S(b, 30);
            b = a;
            a = temp;
        }

        // update initialization variables for next block
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
    }

    // store digest
    for (i = 0; i < 5; i++) {
        digest[i] = H[i];
    }

    free(padded_message);
} 

// driver function to test SHA-1 hash function 
int main() {
    char message[] = "Hello World!";
    uint32_t digest[5] = {0};

    sha1(message, digest);

    printf("Digest: %08X-%08X-%08X-%08X-%08X\n", digest[0], digest[1], digest[2], digest[3], digest[4]);

    return 0;
}