//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: artistic
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Constants for SHA-256
const uint32_t SHA256_K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2c9c057a, 0x4a7484aa, 0x76e33e69, 0x983e5152,
    0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3,
    0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85,
    0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354,
    0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1,
    0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819,
    0xd6990624, 0xf40e3585, 0x106aa070, 0x19b4c79c,
    0x1bda6a57, 0x3c6ef372, 0x5be0cd19, 0x766a0abb
};

// Function to create a hash of an input string
void sha256(const char *input, uint32_t output[8]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    uint32_t w[64] = {0};
    uint32_t a, b, c, d, e, f, g, h0, temp1, temp2;

    // Padding the input (not fully implemented in this artistic piece)
    size_t len = strlen(input);
    size_t new_len = (len + 1 + 8) % 64;
    size_t total_len = len + new_len + 8;
    
    // Process in chunks
    for (size_t i = 0; i < total_len; i += 64) {
        memset(w, 0, sizeof(w));
        
        // Copy input chunk
        for (size_t j = 0; j < 64 && (i + j) < total_len; j++) {
            w[j] = (j < len) ? input[i + j] : 0;
        }

        // Expand the message
        for (size_t j = 16; j < 64; j++) {
            w[j] = w[j-16] + (w[j-15] >> 3) + (w[j-7]) + (w[j-2] >> 10);
        }

        // Initialize working variables
        a = h[0];
        b = h[1];
        c = h[2];
        d = h[3];
        e = h[4];
        f = h[5];
        g = h[6];
        h0 = h[7];

        // Main loop
        for (size_t j = 0; j < 64; j++) {
            temp1 = h0 + (e >> 6) + ((e & f) ^ (~e & g)) + SHA256_K[j] + w[j];
            temp2 = (a >> 2) + ((a & b) ^ (a & c) ^ (b & c));

            h0 = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // Add the compressed chunk to the current hash value
        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h0;
    }

    // Store the output
    for (int i = 0; i < 8; i++) {
        output[i] = h[i];
    }
}

// Function to print the hash
void print_hash(uint32_t hash[8]) {
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");
}

int main() {
    const char *message = "The beauty of the code lies in its elegance!";
    uint32_t hash[8];

    printf("Original Message: %s\n", message);
    sha256(message, hash);
    printf("SHA-256 Hash: ");
    print_hash(hash);

    return 0;
}