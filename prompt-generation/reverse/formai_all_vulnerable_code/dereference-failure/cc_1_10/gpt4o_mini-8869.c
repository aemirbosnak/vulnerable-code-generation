//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Constants for SHA-256
#define SHA256_BLOCK_SIZE 32 // SHA256 outputs a 32 byte digest
#define ROTATE_RIGHT(value, amount) ((value >> amount) | (value << (32 - amount)))
#define CH(x,y,z) ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIGMA0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ (x >> 3))
#define SIGMA1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ (x >> 10))
#define LITTLE_SIGMA0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define LITTLE_SIGMA1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))

// Initial hash values
static const uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fb57c8c, 0x106a4a81,
    0x19b4c116, 0x1e376c48, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// Function to perform the SHA-256 hash
void sha256(const char *input, uint8_t output[SHA256_BLOCK_SIZE]) {
    uint32_t h[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };
    
    // Preprocessing: Padding
    size_t input_len = strlen(input);
    size_t total_bits = (input_len * 8) + 1; // +1 for the bit '1'
    size_t pad_len = (448 - total_bits) % 512;
    size_t total_len = total_bits + pad_len + 64; // 64 for the length

    uint8_t *padded = calloc((total_len / 8), sizeof(uint8_t));
    memcpy(padded, input, input_len);
    padded[input_len] = 0x80; // Append '1' bit
    uint64_t bit_len = input_len * 8;
    memcpy(padded + (total_len / 8) - 8, &bit_len, 8); // Append length

    // Process each 512-bit chunk
    for (size_t i = 0; i < total_len / 8; i += 64) {
        uint32_t w[64] = {0};
        
        // Prepare the message schedule
        for (size_t j = 0; j < 16; j++) {
            w[j] = (padded[i + j * 4] << 24) |
                   (padded[i + j * 4 + 1] << 16) |
                   (padded[i + j * 4 + 2] << 8) |
                   (padded[i + j * 4 + 3]);
        }
        
        for (size_t j = 16; j < 64; j++) {
            w[j] = SIGMA1(w[j - 2]) + w[j - 7] + SIGMA0(w[j - 15]) + w[j - 16];
        }
        
        // Initialize hash values for this chunk
        uint32_t a = h[0];
        uint32_t b = h[1];
        uint32_t c = h[2];
        uint32_t d = h[3];
        uint32_t e = h[4];
        uint32_t f = h[5];
        uint32_t g = h[6];
        uint32_t h0 = h[7];
        
        // Main loop
        for (size_t j = 0; j < 64; j++) {
            uint32_t temp1 = h0 + LITTLE_SIGMA1(e) + CH(e, f, g) + k[j] + w[j];
            uint32_t temp2 = LITTLE_SIGMA0(a) + MAJ(a, b, c);
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

    // Output the final hash value
    for (size_t i = 0; i < 8; i++) {
        output[i * 4] = (h[i] >> 24) & 0xff;
        output[i * 4 + 1] = (h[i] >> 16) & 0xff;
        output[i * 4 + 2] = (h[i] >> 8) & 0xff;
        output[i * 4 + 3] = h[i] & 0xff;
    }

    free(padded);
}

// Function to print the hash in hexadecimal format
void print_hash(uint8_t hash[SHA256_BLOCK_SIZE]) {
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Main function for user input and hashing
int main() {
    char input[256];
    printf("Enter a string to hash (max 255 chars): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input if exists
    input[strcspn(input, "\n")] = 0;

    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256(input, hash);
    printf("SHA-256 hash: ");
    print_hash(hash);

    return 0;
}