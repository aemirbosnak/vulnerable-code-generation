//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Define the initial hash values
const uint32_t h0 = 0x67452301;
const uint32_t h1 = 0xEFCDAB89;
const uint32_t h2 = 0x98BADCFE;
const uint32_t h3 = 0x10325476;
const uint32_t h4 = 0xC3D2E1F0;

// Define the message schedule
const uint32_t k[] = {
    0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6,
    0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6
};

// Define the message expansion function
uint32_t W(const uint32_t *w, int t) {
    return t < 16 ? w[t] : ROTL(w[t-3] ^ w[t-8] ^ w[t-14] ^ w[t-16], 1);
}

// Define the compression function
void compress(uint32_t *h, const uint32_t *w) {
    uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];

    for (int t = 0; t < 80; t++) {
        uint32_t f, g;
        if (t < 20) {
            f = d ^ (b & (c ^ d));
            g = t;
        } else if (t < 40) {
            f = b ^ c ^ d;
            g = (5*t + 1) % 16;
        } else if (t < 60) {
            f = (b & c) | (d & (b | c));
            g = (3*t + 5) % 16;
        } else {
            f = b ^ c ^ d;
            g = (7*t) % 16;
        }

        uint32_t temp = ROTL(a, 5) + f + e + k[t] + W(w, g);
        e = d;
        d = c;
        c = ROTL(b, 30);
        b = a;
        a = temp;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
}

// Define the padding function
void pad(uint8_t *msg, uint64_t len) {
    // Append a 1 bit
    msg[len] = 0x80;

    // Append 0 bits until the length is 56 bytes modulo 64
    while ((len + 1) % 64 != 56) {
        msg[len + 1] = 0x00;
        len++;
    }

    // Append the length of the message in bits
    uint64_t bits = len * 8;
    msg[len + 1] = (bits >> 56) & 0xFF;
    msg[len + 2] = (bits >> 48) & 0xFF;
    msg[len + 3] = (bits >> 40) & 0xFF;
    msg[len + 4] = (bits >> 32) & 0xFF;
    msg[len + 5] = (bits >> 24) & 0xFF;
    msg[len + 6] = (bits >> 16) & 0xFF;
    msg[len + 7] = (bits >> 8) & 0xFF;
    msg[len + 8] = bits & 0xFF;
}

// Define the hash function
void hash(uint32_t *h, const uint8_t *msg, uint64_t len) {
    // Pad the message
    uint8_t padded[len + 64];
    memcpy(padded, msg, len);
    pad(padded, len);

    // Process the message in 512-bit blocks
    for (int i = 0; i < len + 64; i += 64) {
        uint32_t w[16];
        for (int j = 0; j < 16; j++) {
            w[j] = (padded[i + 4*j] << 24) | (padded[i + 4*j + 1] << 16) | (padded[i + 4*j + 2] << 8) | padded[i + 4*j + 3];
        }

        // Compress the message block
        compress(h, w);
    }
}

int main(int argc, char **argv) {
    // Check the arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    // Get the message
    const uint8_t *msg = (uint8_t *)argv[1];
    uint64_t len = strlen((char *)msg);

    // Create the hash context
    uint32_t h[5] = {h0, h1, h2, h3, h4};

    // Hash the message
    hash(h, msg, len);

    // Print the hash
    for (int i = 0; i < 5; i++) {
        printf("%08x", h[i]);
    }
    printf("\n");

    return 0;
}