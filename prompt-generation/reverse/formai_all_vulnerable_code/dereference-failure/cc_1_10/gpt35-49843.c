//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 512

unsigned int rotate_left(unsigned int x, int n) {
    return (x << n) | (x >> (32 - n));
}

unsigned int sha1_padding(char *message, unsigned char **padded_message, unsigned int *message_len) {
    unsigned int len = strlen(message);

    // Calculate message length including the padding bits and length
    unsigned int length_in_bits = len * 8 + 8 + 64;
    unsigned int length_in_blocks = length_in_bits / BLOCK_SIZE + (length_in_bits % BLOCK_SIZE > 0 ? 1 : 0);
    *message_len = length_in_blocks * BLOCK_SIZE / 8;

    // Allocate memory for the padded message
    *padded_message = (unsigned char *) calloc(*message_len, sizeof(unsigned char));
    memcpy(*padded_message, message, len);

    // Add padding bits
    (*padded_message)[len] = 0x80;

    // Add message length in bits to the end
    for (int i = 0; i < 8; i++) {
        (*padded_message)[*message_len - i - 1] = (unsigned char) ((length_in_bits >> i * 8) & 0xFF);
    }

    return length_in_bits;
}

void sha1_main_loop(unsigned int *h, unsigned char *message, unsigned int length_in_blocks) {
    unsigned int a, b, c, d, e, f, k, temp;

    // Constants
    const unsigned int K[] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6};

    // Initialize hash values
    a = h[0];
    b = h[1];
    c = h[2];
    d = h[3];
    e = h[4];

    // Process each block in the message
    for (int i = 0; i < length_in_blocks; i++) {
        unsigned int w[80];

        // Divide block into 16 32-bit big-endian words
        for (int j = 0; j < 16; j++) {
            w[j] = (message + i * BLOCK_SIZE)[j * 4] << 24;
            w[j] |= (message + i * BLOCK_SIZE)[j * 4 + 1] << 16;
            w[j] |= (message + i * BLOCK_SIZE)[j * 4 + 2] << 8;
            w[j] |= (message + i * BLOCK_SIZE)[j * 4 + 3];
        }

        // Extend the first 16 words into the remaining 64 words
        for (int j = 16; j < 80; j++) {
            w[j] = rotate_left(w[j - 3] ^ w[j - 8] ^ w[j - 14] ^ w[j - 16], 1);
        }

        // Main loop
        for (int j = 0; j < 80; j++) {
            if (j < 20) {
                f = (b & c) | (~b & d);
                k = K[0];
            } else if (j < 40) {
                f = b ^ c ^ d;
                k = K[1];
            } else if (j < 60) {
                f = (b & c) | (b & d) | (c & d);
                k = K[2];
            } else {
                f = b ^ c ^ d;
                k = K[3];
            }

            temp = rotate_left(a, 5) + f + e + k + w[j];
            e = d;
            d = c;
            c = rotate_left(b, 30);
            b = a;
            a = temp;
        }

        // Add this block's hash to result so far
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
    }
}

void sha1(char *message, unsigned char *hash) {
    unsigned char *padded_message;
    unsigned int message_len;

    // Padding
    unsigned int length_in_bits = sha1_padding(message, &padded_message, &message_len);

    // Hash computation
    unsigned int h[] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
    sha1_main_loop(h, padded_message, message_len / BLOCK_SIZE);

    // Output hash
    for (int i = 0; i < 5; i++) {
        hash[i * 4] = (unsigned char) ((h[i] >> 24) & 0xFF);
        hash[i * 4 + 1] = (unsigned char) ((h[i] >> 16) & 0xFF);
        hash[i * 4 + 2] = (unsigned char) ((h[i] >> 8) & 0xFF);
        hash[i * 4 + 3] = (unsigned char) (h[i] & 0xFF);
    }

    // Free memory
    free(padded_message);
}

int main() {
    char message[] = "Hello, world!";
    unsigned char hash[20];

    // Compute hash
    sha1(message, hash);

    // Output hash
    printf("Message: %s\n", message);
    printf("Hash: ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}