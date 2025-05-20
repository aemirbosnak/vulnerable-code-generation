//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// SHA-256 Constants
#define SHA256_BLOCK_SIZE 32
#define SHA256_K_SIZE 64

// SHA-256 Rotation and Shifting
#define ROTATE_RIGHT(value, amount) ((value >> amount) | (value << (32 - amount)))
#define CH(x, y, z) ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define EP0(x) (ROTATE_RIGHT(x, 2) ^ ROTATE_RIGHT(x, 13) ^ ROTATE_RIGHT(x, 22))
#define EP1(x) (ROTATE_RIGHT(x, 6) ^ ROTATE_RIGHT(x, 11) ^ ROTATE_RIGHT(x, 25))
#define SIG0(x) (ROTATE_RIGHT(x, 7) ^ ROTATE_RIGHT(x, 18) ^ (x >> 3))
#define SIG1(x) (ROTATE_RIGHT(x, 17) ^ ROTATE_RIGHT(x, 19) ^ (x >> 10))

// SHA-256 Initial Hash Values
static const uint32_t sha256_h[] = {
    0x6a09e667U, 0xbb67ae85U, 0x3c6ef372U, 0xa54ff53aU,
    0x510e527fU, 0x9b05688cU, 0x1f83d9abU, 0x5be0cd19U
};

// SHA-256 K Constants
static const uint32_t sha256_k[SHA256_K_SIZE] = {
    0x428a2f98U, 0x71374491U, 0xb5c0fbcfU, 0xe9b5dba5U,
    0x3956c25bU, 0x59f111f1U, 0x923f82a4U, 0xab1c5ed5U,
    0xd807aa98U, 0x12835b01U, 0x243185beU, 0x550c7dc3U,
    0x72be5d74U, 0x80deb1feU, 0x9bdc06a7U, 0xc19bf174U,
    0xe49b69c1U, 0xefbe4786U, 0x0fc19dc6U, 0x240ca1ccU,
    0x2de92c6fU, 0x4a7484aaU, 0x5cb0a9dcU, 0x76f988daU,
    0x983e5152U, 0xa831c66dU, 0xb00327c8U, 0xb5be0ed5U,
    0xc67178f2U
};

// Function to process a single message block
void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    uint32_t a, b, c, d, e, f, g, h, t1, t2;
    uint32_t m[64];

    // Copy message data
    for (size_t i = 0; i < 16; i++) {
        m[i] = ((uint32_t) data[4 * i] << 24) | ((uint32_t) data[4 * i + 1] << 16) |
                ((uint32_t) data[4 * i + 2] << 8) | ((uint32_t) data[4 * i + 3]);
    }
    
    // Extend the first 16 words into the remaining 48 words
    for (size_t i = 16; i < 64; i++) {
        m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
    }

    // Initialize working variables to current hash value
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    f = state[5];
    g = state[6];
    h = state[7];

    // Main loop
    for (size_t i = 0; i < 64; i++) {
        t1 = h + EP1(e) + CH(e, f, g) + sha256_k[i] + m[i];
        t2 = EP0(a) + MAJ(a, b, c);
        h = g;
        g = f;
        f = e;
        e = d + t1;
        d = c;
        c = b;
        b = a;
        a = t1 + t2;
    }

    // Add the compressed chunk to the current hash value
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

// Function to initialize the SHA256 context
void sha256_init(uint32_t state[8]) {
    for (size_t i = 0; i < 8; i++) {
        state[i] = sha256_h[i];
    }
}

// Function to finalize the SHA256 hash and compute the digest
void sha256_final(uint32_t state[8], const uint8_t *data, size_t len, uint8_t hash[SHA256_BLOCK_SIZE]) {
    uint64_t bitlen = len * 8;
    size_t index = len % 64;
    size_t padding_size = (index < 56) ? (56 - index) : (120 - index);
    
    // Append the bit '1' to the input data
    uint8_t *buffer = malloc(len + padding_size + 8);
    memcpy(buffer, data, len);
    buffer[len] = 0x80;

    // Append 0 bits until the length mod 64 is 56
    memset(buffer + len + 1, 0, padding_size - 1);
    
    // Append the original length in bits
    for (size_t i = 0; i < 8; i++) {
        buffer[len + padding_size + i] = (bitlen >> (56 - i * 8)) & 0xff;
    }

    // Process the remaining buffer
    for (size_t i = 0; i < (len + padding_size + 8) / 64; i++) {
        sha256_transform(state, buffer + i * 64);
    }

    // Produce the final hash value (big-endian)
    for (size_t i = 0; i < 8; i++) {
        hash[i * 4] = (state[i] >> 24) & 0xff;
        hash[i * 4 + 1] = (state[i] >> 16) & 0xff;
        hash[i * 4 + 2] = (state[i] >> 8) & 0xff;
        hash[i * 4 + 3] = state[i] & 0xff;
    }

    free(buffer);
}

// Function to compute SHA-256 hash of the given input string
void compute_sha256(const char *input, uint8_t hash[SHA256_BLOCK_SIZE]) {
    uint32_t state[8];
    sha256_init(state);
    sha256_final(state, (const uint8_t *)input, strlen(input), hash);
}

// Function to print the SHA-256 hash in hexadecimal format
void print_hash(const uint8_t hash[SHA256_BLOCK_SIZE]) {
    for (size_t i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Entry point of the program
int main() {
    char input[256];
    uint8_t hash[SHA256_BLOCK_SIZE];

    printf("Enter a string to hash (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // Remove trailing newline

    compute_sha256(input, hash);
    printf("SHA-256 hash: ");
    print_hash(hash);
    
    return 0;
}