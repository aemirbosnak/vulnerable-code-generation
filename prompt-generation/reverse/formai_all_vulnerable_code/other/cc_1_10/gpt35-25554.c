//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Function prototypes */
void sha256_hash(unsigned char *input, size_t len, unsigned char *output);
void sha256_transform(uint32_t state[8], const unsigned char block[64]);
void sha256_process_message_block(unsigned char block[64], uint32_t state[8]);
void sha256_pad_message(unsigned char block[64], size_t *length, uint64_t *bit_count);
void sha256_convert_hash_to_string(unsigned char hash[], char *hash_string);

/* Main function */
int main(void) {
    unsigned char input[] = "This is a test input string. The hash function should produce a unique hash value for this string.";
    char hash_string[65]; /* 64 hexadecimals + null terminator */

    /* Perform SHA256 hashing */
    unsigned char hash[32];
    sha256_hash(input, strlen((char*) input), hash);

    /* Convert hash to printable string */
    sha256_convert_hash_to_string(hash, hash_string);

    printf("Input string: %s\n", input);
    printf("Hash value: %s\n", hash_string);

    return 0;
}

/* SHA256 constants */
#define SHA256_BLOCK_SIZE 64
#define SHA256_HASH_SIZE 32
#define SHA256_ROUNDS 64

/* SHA256 state */
static const uint32_t sha256_initial_state[] = { 0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A, 0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19 };

/* SHA256 round constants */
static const uint32_t sha256_round_constants[] = {
    0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
    0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
    0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
    0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
    0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
    0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
    0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
    0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

/* SHA256 hash function */
void sha256_hash(unsigned char *input, size_t len, unsigned char *output) {
    uint32_t state[8];
    unsigned char block[SHA256_BLOCK_SIZE];
    uint64_t bit_count = 0;

    /* Initialize state */
    memcpy(state, sha256_initial_state, sizeof(sha256_initial_state));

    /* Process input message in blocks */
    while (len > 0) {
        /* Process a single message block */
        if (len >= SHA256_BLOCK_SIZE) {
            memcpy(block, input, SHA256_BLOCK_SIZE);
            sha256_process_message_block(block, state);
            input += SHA256_BLOCK_SIZE;
            len -= SHA256_BLOCK_SIZE;
            bit_count += SHA256_BLOCK_SIZE * 8;
        }
        /* Pad and process the final message block */
        else {
            sha256_pad_message(block, &len, &bit_count);
            sha256_process_message_block(block, state);
            break;
        }
    }

    /* Convert state to output hash */
    for (int i = 0; i < 8; i++) {
        output[i*4+0] = (state[i] >> 24) & 0xFF;
        output[i*4+1] = (state[i] >> 16) & 0xFF;
        output[i*4+2] = (state[i] >>  8) & 0xFF;
        output[i*4+3] = (state[i] >>  0) & 0xFF;
    }
}

/* SHA256 state transformation function */
void sha256_transform(uint32_t state[8], const unsigned char block[64]) {
    uint32_t W[SHA256_ROUNDS];

    /* Prepare message schedule */
    for (int t = 0; t < 16; t++) {
        W[t] = block[t * 4 + 0] << 24 |
               block[t * 4 + 1] << 16 |
               block[t * 4 + 2] <<  8 |
               block[t * 4 + 3] <<  0 ;
    }
    for (int t = 16; t < SHA256_ROUNDS; t++) {
        uint32_t S0 = (W[t-15] >>  7) | (W[t-15] << 25);
        uint32_t S1 = (W[t- 2] >> 17) | (W[t- 2] << 15);
        W[t] = W[t-16] + S0 + W[t-7] + S1;
    }

    /* Initialize working variables */
    uint32_t a = state[0];
    uint32_t b = state[1];
    uint32_t c = state[2];
    uint32_t d = state[3];
    uint32_t e = state[4];
    uint32_t f = state[5];
    uint32_t g = state[6];
    uint32_t h = state[7];

    /* Perform rounds */
    for (int t = 0; t < SHA256_ROUNDS; t++) {
        uint32_t S0 = (a >> 2) | (a << 30);
        uint32_t S1 = (a >> 6) | (a << 26);
        uint32_t S2 = (a >> 11) | (a << 21);
        uint32_t S3 = (a >> 25) | (a <<  7);
        uint32_t Ch = (e & f) ^ ((~e) & g);
        uint32_t Maj = (a & b) ^ (a & c) ^ (b & c);
        uint32_t temp1 = h + S3 + Ch + sha256_round_constants[t] + W[t];
        uint32_t temp2 = S0 + Maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = c;
        c = b;
        b = a;
        a = temp1 + temp2;
    }

    /* Update state */
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    state[5] += f;
    state[6] += g;
    state[7] += h;
}

/* SHA256 message block processing function */
void sha256_process_message_block(unsigned char block[64], uint32_t state[8]) {
    /* Convert message block to host byte order */
    for (int i = 0; i < 16; i++) {
        uint32_t word = block[i*4+0] << 24 |
                        block[i*4+1] << 16 |
                        block[i*4+2] <<  8 |
                        block[i*4+3] <<  0 ;
        block[i*4+0] = (word >> 24) & 0xFF;
        block[i*4+1] = (word >> 16) & 0xFF;
        block[i*4+2] = (word >>  8) & 0xFF;
        block[i*4+3] = (word >>  0) & 0xFF;
    }

    /* Perform state transformation */
    sha256_transform(state, block);
}

/* SHA256 message padding function */
void sha256_pad_message(unsigned char block[64], size_t *length, uint64_t *bit_count) {
    /* Add single 1-bit */
    block[*length] = 0x80;
    (*length)++;

    /* Pad with 0-bits */
    if (*length > 56) {
        memset(block + *length, 0, 64 - *length);
        *bit_count += 512;
        sha256_process_message_block(block, sha256_initial_state);
        *length = 0;
    }
    memset(block + *length, 0, 56 - *length);

    /* Add message length in bits */
    block[56] = (*bit_count >> 56) & 0xFF;
    block[57] = (*bit_count >> 48) & 0xFF;
    block[58] = (*bit_count >> 40) & 0xFF;
    block[59] = (*bit_count >> 32) & 0xFF;
    block[60] = (*bit_count >> 24) & 0xFF;
    block[61] = (*bit_count >> 16) & 0xFF;
    block[62] = (*bit_count >>  8) & 0xFF;
    block[63] = (*bit_count >>  0) & 0xFF;
    *bit_count += *length * 8;
    sha256_process_message_block(block, sha256_initial_state);
}

/* SHA256 hash to printable string conversion function */
void sha256_convert_hash_to_string(unsigned char hash[], char *hash_string) {
    static const char hex_digits[] = "0123456789abcdef";
    for (int i = 0; i < SHA256_HASH_SIZE; i++) {
        hash_string[i*2+0] = hex_digits[(hash[i] >> 4) & 0x0F];
        hash_string[i*2+1] = hex_digits[hash[i] & 0x0F];
    }
    hash_string[SHA256_HASH_SIZE*2] = '\0';
}