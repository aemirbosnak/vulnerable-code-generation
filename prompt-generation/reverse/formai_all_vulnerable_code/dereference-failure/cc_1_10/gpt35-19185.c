//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants used in the algorithm
#define H0 0x6A09E667
#define H1 0xBB67AE85
#define H2 0x3C6EF372
#define H3 0xA54FF53A
#define H4 0x510E527F
#define H5 0x9B05688C
#define H6 0x1F83D9AB
#define H7 0x5BE0CD19

#define K 0x428A2F98
#define L 0x71374491
#define M 0xB5C0FBCF
#define N 0xE9B5DBA5
#define O 0x3956C25B
#define P 0x59F111F1
#define Q 0x923F82A4
#define R 0xAB1C5ED5

// Function declarations
void sha256(char *, int);
void calculate_hash(unsigned int *, unsigned int *);
void get_words(char *, unsigned int *);
void print_hash(unsigned int *);

int main() {
    // The string to hash
    char *string_to_hash = "This is a secret message.";

    // Hash the string
    sha256(string_to_hash, (int)strlen(string_to_hash));

    return 0;
}

// SHA-256 implementation
void sha256(char *string_to_hash, int length) {
    // Padding the input string
    int current_length = length;
    unsigned char *padded_message = (unsigned char *)calloc(1, length + 64);
    memcpy(padded_message, string_to_hash, length);
    padded_message[length] = 0x80;
    unsigned long long bits_length = length * 8;
    memcpy(padded_message + length + 1, &bits_length, sizeof(bits_length));

    // Converting the padded message into 512-bit chunks
    int number_of_chunks = ((length + 9) / 64) + 1;
    unsigned int *blocks = (unsigned int *)calloc(number_of_chunks * 16, 4);
    get_words(padded_message, blocks);

    // Initializing hash values
    unsigned int hash[8] = {H0, H1, H2, H3, H4, H5, H6, H7};

    // Main loop
    for (int i = 0; i < number_of_chunks; i++) {
        unsigned int *chunk = blocks + (i * 16);
        unsigned int w[64];

        // Compute the message schedule
        for (int j = 0; j < 16; j++) {
            w[j] = chunk[j];
        }
        for (int j = 16; j < 64; j++) {
            unsigned int s0 = (w[j-15] >> 7 | w[j-15] << 25) ^ (w[j-15] >> 18 | w[j-15] << 14) ^ (w[j-15] >> 3);
            unsigned int s1 = (w[j-2] >> 17 | w[j-2] << 15) ^ (w[j-2] >> 19 | w[j-2] << 13) ^ (w[j-2] >> 10);
            w[j] = w[j-16] + s0 + w[j-7] + s1;
        }

        // Update hash values
        calculate_hash(hash, w);
    }

    // Print the resulting hash
    print_hash(hash);

    // Freeing memory
    free(padded_message);
    free(blocks);
}

// Calculates the hash for one chunk
void calculate_hash(unsigned int *hash, unsigned int *w) {
    unsigned int a = hash[0], b = hash[1], c = hash[2], d = hash[3], e = hash[4], f = hash[5], g = hash[6], h = hash[7];

    for (int i = 0; i < 64; i++) {
        unsigned int S1 = (e >> 6 | e << 26) ^ (e >> 11 | e << 21) ^ (e >> 25 | e << 7);
        unsigned int ch = (e & f) ^ (~e & g);
        unsigned int temp1 = h + S1 + ch + w[i] + (unsigned int)R;
        unsigned int S0 = (a >> 2 | a << 30) ^ (a >> 13 | a << 19) ^ (a >> 22 | a << 10);
        unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
        unsigned int temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    hash[0] += a;
    hash[1] += b;
    hash[2] += c;
    hash[3] += d;
    hash[4] += e;
    hash[5] += f;
    hash[6] += g;
    hash[7] += h;
}

// Converts a padded message into 512-bit chunks
void get_words(char *padded_message, unsigned int *blocks) {
    int number_of_words = strlen((const char *)padded_message) / 4;
    for (int i = 0; i < number_of_words; i++) {
        unsigned int word = 0;
        for (int j = 0; j < 4; j++) {
            word += padded_message[i * 4 + j] << (24 - j * 8);
        }
        blocks[i] = word;
    }
}

// Prints the resulting hash
void print_hash(unsigned int *hash) {
    printf("Hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");
}