//GPT-4o-mini DATASET v1.0 Category: Cryptographic hash function ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define a simple hash structure
typedef struct {
    uint32_t h[5];
} HashState;

// Initialize the hash state with some values
void init_hash(HashState *state) {
    state->h[0] = 0x67452301;
    state->h[1] = 0xEFCDAB89;
    state->h[2] = 0x98BADCFE;
    state->h[3] = 0x10325476;
    state->h[4] = 0xC3D2E1F0;
}

// Rotate left function
uint32_t rotate_left(uint32_t value, uint32_t count) {
    return (value << count) | (value >> (32 - count));
}

// Compression function for the hash operation
void compress(HashState *state, const uint8_t *data, size_t length) {
    uint32_t a = state->h[0];
    uint32_t b = state->h[1];
    uint32_t c = state->h[2];
    uint32_t d = state->h[3];
    uint32_t e = state->h[4];

    for (size_t i = 0; i < length; ++i) {
        uint32_t temp = rotate_left(a + (b & c | ~b & d) + data[i] + 0x5A827999, 5) + e;
        a = e;
        e = d;
        d = c;
        c = b;
        b += temp;
    }

    state->h[0] += a;
    state->h[1] += b;
    state->h[2] += c;
    state->h[3] += d;
    state->h[4] += e;
}

// Simple hashing function to create a hash of the given input
void hash(const uint8_t *input, size_t length, HashState *state) {
    init_hash(state);
    size_t block_size = 16;  // Process 16 bytes at a time

    for (size_t i = 0; i < length; i += block_size) {
        size_t to_process = (length - i < block_size) ? (length - i) : block_size;
        compress(state, input + i, to_process);
    }
}

// Function to convert hash state to a string representation
void hash_to_string(const HashState *state, char *output) {
    for (int i = 0; i < 5; ++i) {
        sprintf(output + i * 8, "%08x", state->h[i]);
    }
}

// Main function to demonstrate the hash function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string to hash>\n", argv[0]);
        return 1;
    }

    HashState state;
    const char *input = argv[1];
    size_t length = strlen(input);
    
    // Allocate space for the output hash string
    char output[41];  // 40 characters for hash + 1 for null terminator
    output[40] = '\0';

    // Hash the input and convert the result to string
    hash((const uint8_t *)input, length, &state);
    hash_to_string(&state, output);

    // Print the resulting hash
    printf("Hash of '%s': %s\n", input, output);
    
    return 0;
}