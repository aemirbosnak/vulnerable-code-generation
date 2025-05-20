//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Initialising global constants
const int BLOCK_SIZE = 64;
const int HASH_SIZE = 32;

// Helper function(s)
unsigned char* get_padded_message(unsigned char* message, int message_length, int *padded_length);
void compute_hash(unsigned char* message, int message_length, unsigned char** hash, int *hash_length);

// Hash function
void hash(unsigned char* message, int message_length, unsigned char* hash) {

    // Padding message
    int padded_length;
    unsigned char *padded_message = get_padded_message(message, message_length, &padded_length);

    // Computing hash
    unsigned char *computed_hash;
    int computed_hash_length;
    compute_hash(padded_message, padded_length, &computed_hash, &computed_hash_length);

    // Storing computed hash in hash argument
    int i;
    for(i = 0; i < HASH_SIZE; i++) {
        hash[i] = computed_hash[i];
    }

    // Freeing allocated memory
    free(padded_message);
    free(computed_hash);
}

// Helper function to get padded message
unsigned char* get_padded_message(unsigned char* message, int message_length, int *padded_length) {

    // Allocating memory for padded message
    int padded_size = (message_length + 8 + BLOCK_SIZE - 1) / BLOCK_SIZE * BLOCK_SIZE;
    unsigned char *padded_message = (unsigned char*) malloc(padded_size);

    // Copying message to padded message
    int i;
    for(i = 0; i < message_length; i++) {
        padded_message[i] = message[i];
    }

    // Padding message
    padded_message[message_length] = 0x80;
    for(i = message_length + 1; i < padded_size - 8; i++) {
        padded_message[i] = 0x00;
    }

    // Appending length of message in bits (big-endian)
    unsigned long long bit_length = (unsigned long long) message_length * 8;
    for(i = 0; i < 8; i++) {
        padded_message[padded_size - i - 1] = (unsigned char) (bit_length >> (i * 8));
    }

    // Returning padded message and padded length
    *padded_length = padded_size;
    return padded_message;
}

// Helper function to compute hash
void compute_hash(unsigned char* message, int message_length, unsigned char** hash, int *hash_length) {

    // Initializing hash values (first 32 bits of fractional parts of square roots of the first 8 primes 2..19)
    unsigned int h[8] = { 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

    // Initializing constants (first 32 bits of fractional parts of cube roots of the first 64 primes 2..311)
    unsigned int k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Breaking message into blocks
    int num_blocks = message_length / BLOCK_SIZE;
    int i, j, t;
    unsigned char block[BLOCK_SIZE];
    unsigned int w[64];
    for(i = 0; i < num_blocks; i++) {

        // Initializing block
        for(j = 0; j < BLOCK_SIZE; j++) {
            block[j] = message[i * BLOCK_SIZE + j];
        }

        // Extending block
        for(j = 0; j < 16; j++) {
            w[j] = (block[j * 4] << 24) | (block[j * 4 + 1] << 16) | (block[j * 4 + 2] << 8) | (block[j * 4 + 3]);
        }
        for(j = 16; j < 64; j++) {
            w[j] = (w[j - 16] + ((w[j - 15] >> 7) | (w[j - 15] << 25)) + ((w[j - 7] >> 18) | (w[j - 7] << 14)) + w[j - 2]) % 0xFFFFFFFF;
        }

        // Initializing working variables
        unsigned int a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], t1, t2;

        // Main loop
        for(j = 0; j < 64; j++) {
            t1 = (g >> 10) | (g << 22);
            t1 += (e & f) ^ (~e & g);
            t1 += (k[j] + w[j]) % 0xFFFFFFFF;
            t2 = (a >> 2) | (a << 30);
            t2 += (a & b) ^ (a & c) ^ (b & c);
            h[7] = h[6];
            h[6] = h[5];
            h[5] = h[4];
            h[4] = (h[3] + t1) % 0xFFFFFFFF;
            h[3] = h[2];
            h[2] = h[1];
            h[1] = h[0];
            h[0] = (t1 + t2) % 0xFFFFFFFF;
        }
    }

    // Allocating memory for computed hash
    *hash = (unsigned char*) malloc(HASH_SIZE);
    *hash_length = HASH_SIZE;

    // Converting from little-endian byte order to big-endian byte order
    for(i = 0; i < 8; i++) {
        (*hash)[i * 4] = (unsigned char) ((h[i] >> 24) & 0xFF);
        (*hash)[i * 4 + 1] = (unsigned char) ((h[i] >> 16) & 0xFF);
        (*hash)[i * 4 + 2] = (unsigned char) ((h[i] >> 8) & 0xFF);
        (*hash)[i * 4 + 3] = (unsigned char) (h[i] & 0xFF);
    }
}

// Sample usage
int main() {

    // Input message and length
    char *message = "This is a sample message.";
    int message_length = strlen(message);

    // Computing hash
    unsigned char computed_hash[HASH_SIZE];
    hash((unsigned char*) message, message_length, computed_hash);

    // Printing computed hash
    int i;
    printf("Computed Hash (in hex):\n");
    for(i = 0; i < HASH_SIZE; i++) {
        printf("%02x", computed_hash[i]);
    }
    printf("\n");

    return 0;
}