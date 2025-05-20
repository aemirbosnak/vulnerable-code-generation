//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to perform a left rotate operation on a 32-bit word
uint32_t left_rotate(uint32_t x, uint32_t c) {
    return (x << c) | (x >> (32 - c));
}

// Function to perform a modified SHA-1 compression operation on a 64-byte chunk of data
void sha1_compress(uint32_t state[5], const uint8_t* data) {
    uint32_t temp, a, b, c, d, e, f, k;
    uint32_t w[80];

    // Copy the 64-byte chunk of data into the first 16 words of the message schedule array
    for (int i = 0; i < 16; i++) {
        w[i] = (data[i * 4] << 24) | (data[i * 4 + 1] << 16) | (data[i * 4 + 2] << 8) | data[i * 4 + 3];
    }

    // Extend the message schedule array to contain 80 words
    for (int i = 16; i < 80; i++) {
        w[i] = left_rotate(w[i-3] ^ w[i-8] ^ w[i-14] ^ w[i-16], 1);
    }

    // Initialize the working variables with the current hash value 
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];

    // Perform 80 rounds of the modified SHA-1 compression operation
    for (int i = 0; i < 80; i++) {
        if (i < 20) {
            f = (b & c) | ((~b) & d);
            k = 0x5A827999;
        }
        else if (i < 40) {
            f = b ^ c ^ d;
            k = 0x6ED9EBA1;
        }
        else if (i < 60) {
            f = (b & c) | (b & d) | (c & d);
            k = 0x8F1BBCDC;
        }
        else {
            f = b ^ c ^ d;
            k = 0xCA62C1D6;
        }

        temp = left_rotate(a, 5) + f + e + k + w[i];
        e = d;
        d = c;
        c = left_rotate(b, 30);
        b = a;
        a = temp;
    }

    // Update the current hash value
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
}

// Function to calculate the SHA-1 hash of a message
void sha1(const uint8_t* message, size_t len, uint8_t hash[20]) {
    // Initialize the 5 working variables with the SHA-1 initial hash value
    uint32_t state[] = {
        0x67452301,
        0xEFCDAB89,
        0x98BADCFE,
        0x10325476,
        0xC3D2E1F0
    };

    // Pad the message to ensure its length is a multiple of 64 bytes
    size_t padded_len = ((len + 8) / 64 + 1) * 64;
    uint8_t* padded_msg = calloc(padded_len, 1);
    memcpy(padded_msg, message, len);
    padded_msg[len] = 0x80;
    *((uint64_t*) (padded_msg + padded_len - 8)) = len * 8;

    // Perform the SHA-1 compression operation on each 64-byte chunk of the padded message
    for (int i = 0; i < padded_len; i += 64) {
        sha1_compress(state, padded_msg + i);
    }

    // Convert the hash value from an array of uint32_t's to an array of uint8_t's
    for (int i = 0; i < 20; i++) {
        hash[i] = (state[i / 4] >> (24 - 8 * (i % 4))) & 0xFF;
    }

    // Free the padded message buffer
    free(padded_msg);
}

int main() {
    // Test vector from FIPS PUB 180-1
    uint8_t message[] = "abc";
    uint8_t expected_hash[] = {0xA9, 0x99, 0x3E, 0x36, 0x47, 0x06, 0x81, 0x6A,
                               0xBA, 0x3E, 0x25, 0x71, 0x78, 0x50, 0xC2, 0x6C,
                               0x9C, 0xD0, 0xD8, 0x9D};
    uint8_t hash[20];

    sha1(message, 3, hash);

    printf("Hash of 'abc': ");
    for (int i = 0; i < 20; i++) {
        printf("%02X", hash[i]);
    }
    printf("\n");

    if (memcmp(hash, expected_hash, 20) == 0) {
        printf("Hash matches expected value.\n");
    }
    else {
        printf("Hash does not match expected value.\n");
    }

    return 0;
}