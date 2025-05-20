//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTLEFT(a,b) ((a << b) | (a >> (32 - b)))

static const uint32_t k[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void sha256(const char *message, uint32_t hash[8]) {

    uint32_t *w, s0, s1, maj, t1, t2, ch, h[8];
    uint64_t bits = strlen(message) * 8;

    // Initialize hash values
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;

    // Pre-processing
    uint32_t new_len = ((((bits + 1) + 64) / 512) + 1) * 512;
    uint8_t *msg = (uint8_t *)calloc(new_len/8, sizeof(uint8_t));
    memcpy(msg, message, strlen(message));
    msg[strlen(message)] = 0x80;
    for (int i = 0; i < 8; i++) {
        msg[(new_len/8 - 8) + i] = (uint8_t)(bits >> (56 - i * 8));
    }

    // Process the message in successive 512-bit chunks
    for (int chunk = 0; chunk < (new_len/512); chunk++) {

        // Prepare the message schedule
        w = (uint32_t *)(msg + chunk * 64);
        for (int i = 0; i < 16; i++) {
            w[i] = htonl(w[i]);
        }
        for (int i = 16; i < 64; i++) {
            uint32_t s0 = ROTLEFT(w[i-15], 7) ^ ROTLEFT(w[i-15], 18) ^ (w[i-15] >> 3);
            uint32_t s1 = ROTLEFT(w[i-2], 17) ^ ROTLEFT(w[i-2], 19) ^ (w[i-2] >> 10);
            w[i] = w[i-16] + s0 + w[i-7] + s1;
        }

        // Initialize working variables to current hash value
        for (int i = 0; i < 8; i++) {
            hash[i] = h[i];
        }

        // Compression function main loop
        for (int i = 0; i < 64; i++) {
            s1 = ROTLEFT(hash[4], 6) ^ ROTLEFT(hash[4], 11) ^ ROTLEFT(hash[4], 25);
            ch = (hash[4] & hash[5]) ^ (~hash[4] & hash[6]);
            t1 = hash[7] + s1 + ch + k[i] + w[i];
            s0 = ROTLEFT(hash[0], 2) ^ ROTLEFT(hash[0], 13) ^ ROTLEFT(hash[0], 22);
            maj = (hash[0] & hash[1]) ^ (hash[0] & hash[2]) ^ (hash[1] & hash[2]);
            t2 = s0 + maj;

            hash[7] = hash[6];
            hash[6] = hash[5];
            hash[5] = hash[4];
            hash[4] = hash[3] + t1;
            hash[3] = hash[2];
            hash[2] = hash[1];
            hash[1] = hash[0];
            hash[0] = t1 + t2;
        }

        // Add the compressed chunk to the current hash value
        for (int i = 0; i < 8; i++) {
            h[i] += hash[i];
        }
    }

    // Produce the final hash value (big-endian)
    for (int i = 0; i < 8; i++) {
        hash[i] = h[i];
    }
}

int main() {
    
    // Sample message to hash
    char message[] = "Hello, world!";

    // Compute and print the hash
    uint32_t hash[8];
    sha256(message, hash);

    printf("SHA-256 hash of \"%s\" is: ", message);
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}