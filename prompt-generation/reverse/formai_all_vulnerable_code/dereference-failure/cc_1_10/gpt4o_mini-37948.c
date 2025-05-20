//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants for the SHA-256 algorithm
#define SHA256_BLOCK_SIZE 32
#define ROTRIGHT(a,b) ((a >> b) | (a << (32 - b)))
#define CH(x,y,z) ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTRIGHT(x, 7) ^ ROTRIGHT(x, 18) ^ (x >> 3))
#define SIGMA1(x) (ROTRIGHT(x, 17) ^ ROTRIGHT(x, 19) ^ (x >> 10))
#define sigma0(x) (ROTRIGHT(x, 2) ^ ROTRIGHT(x, 13) ^ ROTRIGHT(x, 22))
#define sigma1(x) (ROTRIGHT(x, 6) ^ ROTRIGHT(x, 11) ^ ROTRIGHT(x, 25))

// SHA-256 function
void sha256(const char *message, uint8_t hash[SHA256_BLOCK_SIZE]) {
    // Initialize hash values
    uint32_t k[] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc67178f2
    };
    
    uint32_t h[] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Preprocessing the input message
    size_t message_len = strlen(message);
    size_t new_len = message_len + (message_len % 512 < 448 ? (448 - message_len % 512) : (960 - message_len % 512)) + 64;
    uint8_t *buffer = calloc(new_len / 8, 1);
    memcpy(buffer, message, message_len);
    buffer[message_len] = 0x80; // Append the '1' bit

    // Append the length of the original message
    uint64_t bitlen = message_len * 8;
    memcpy(buffer + new_len / 8 - 8, &bitlen, 8);

    // Process the message in successive 512-bit chunks
    for (size_t i = 0; i < new_len; i += 512 / 8) {
        uint32_t w[64] = {0};
        for (int j = 0; j < 16; j++) {
            memcpy(&w[j], buffer + i + j * 4, 4);
            w[j] = __builtin_bswap32(w[j]); // Convert to big-endian
        }
        for (int j = 16; j < 64; j++) {
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
        }

        uint32_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint32_t e = h[4], f = h[5], g = h[6], h_val = h[7];

        for (int j = 0; j < 64; j++) {
            uint32_t t1 = h_val + SIGMA1(e) + CH(e, f, g) + k[j] + w[j];
            uint32_t t2 = SIGMA0(a) + MAJ(a, b, c);
            h_val = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h[0] += a;
        h[1] += b;
        h[2] += c;
        h[3] += d;
        h[4] += e;
        h[5] += f;
        h[6] += g;
        h[7] += h_val;
    }

    // Convert hash values to bytes
    for (int i = 0; i < 8; i++) {
        h[i] = __builtin_bswap32(h[i]); // Convert to big-endian
        memcpy(hash + i * 4, &h[i], 4);
    }

    free(buffer);
}

// Helper function to print the hash value
void print_hash(uint8_t hash[SHA256_BLOCK_SIZE]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

// Main function to take user input and display the hash
int main() {
    char input[1024];
    uint8_t hash[SHA256_BLOCK_SIZE];

    printf("Enter a string to hash (max 1024 chars): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    sha256(input, hash);
    
    printf("SHA-256 Hash: ");
    print_hash(hash);

    return 0;
}