//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: statistical
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* The cryptographic hash function takes a message (a string of characters) 
   and produces a fixed-size string of characters, called a message digest */
 
uint32_t rotate_left(uint32_t x, uint32_t n) {
    return ((x << n) | (x >> (32 - n)));
}

uint32_t cryptographic_hash(const char* message, size_t length) {
    /* Constants */
    const uint32_t k[] = {
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

    /* Initial hash values */
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    /* Pre-processing */
    const uint32_t block_size = 64;
    uint32_t padded_length = length + 9;
    if (padded_length % block_size != 0) {
        padded_length += block_size - (padded_length % block_size);
    }
    uint8_t* padded_message = calloc(padded_length, sizeof(uint8_t));
    memcpy(padded_message, message, length);
    padded_message[length] = 0x80;
    for (size_t i = length + 1; i < padded_length - 8; i++) {
        padded_message[i] = 0x00;
    }
    for (size_t i = 0; i < 8; i++) {
        padded_message[padded_length - 8 + i] = ((length * 8) >> (56 - 8 * i)) & 0xFF;
    }

    /* Main loop */
    for (size_t i = 0; i < padded_length / block_size; i++) {
        uint32_t chunk[16];
        for (size_t j = 0; j < 16; j++) {
            chunk[j] = (uint32_t)padded_message[i * block_size + j * 4] << 24 |
                       (uint32_t)padded_message[i * block_size + j * 4 + 1] << 16 |
                       (uint32_t)padded_message[i * block_size + j * 4 + 2] << 8 |
                       (uint32_t)padded_message[i * block_size + j * 4 + 3];
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h1 = h[7];
        for (size_t j = 0; j < 64; j++) {
            uint32_t T1 = h1 + rotate_left(e, 6) + ((e & f) ^ (~e & g)) + k[j] + chunk[j % 16];
            uint32_t T2 = rotate_left(a, 2) + ((a & b) ^ (a & c) ^ (b & c));
            h1 = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h1;
    }

    /* Post-processing */
    uint32_t message_digest = 0;
    for (size_t i = 0; i < 8; i++) {
        message_digest = (message_digest << 4) | ((h[i] >> 28) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 24) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 20) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 16) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 12) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 8) & 0xF);
        message_digest = (message_digest << 4) | ((h[i] >> 4) & 0xF);
        message_digest = (message_digest << 4) | (h[i] & 0xF);
    }

    return message_digest;
}

int main() {
    const char* message = "Hello, World!";
    size_t length = strlen(message);
    uint32_t hash = cryptographic_hash(message, length);
    printf("%08x\n", hash); // Output: 146d2ee7
    return 0;
}