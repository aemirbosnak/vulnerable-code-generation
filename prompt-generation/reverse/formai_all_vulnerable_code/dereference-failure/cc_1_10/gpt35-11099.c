//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16 // 128-bit blocks

void encrypt_block(unsigned char *block, unsigned char *key) {
    unsigned int round, i;
    unsigned int key_schedule[60];

    // Generate key schedule using key
    for (i = 0; i < 8; i++) {
        key_schedule[i] = key[i];
    }
    for (i = 8; i < 60; i++) {
        key_schedule[i] = key_schedule[i-8] ^ key_schedule[i-5] ^ key_schedule[i-3] ^ key_schedule[i-1] ^ 0x9e3779b9 ^ i;
    }

    // Perform 32 rounds of encryption
    for (round = 0; round < 32; round++) {
        // Substitution using S-box
        for (i = 0; i < BLOCK_SIZE; i++) {
            block[i] = block[i] ^ key_schedule[round];
            block[i] = ((block[i] & 0xf0) >> 4) | ((block[i] & 0x0f) << 4);
            block[i] = ((block[i] & 0xcc) >> 2) | ((block[i] & 0x33) << 2);
            block[i] = ((block[i] & 0xaa) >> 1) | ((block[i] & 0x55) << 1);
            block[i] = ((block[i] << 1) & 0xfe) | ((block[i] >> 7) & 0x01);
        }

        // Linear transformation
        unsigned char temp[BLOCK_SIZE];
        for (i = 0; i < BLOCK_SIZE; i++) {
            temp[i] = block[(i + 1) % BLOCK_SIZE] ^ block[(i + 2) % BLOCK_SIZE] ^ block[(i + 3) % BLOCK_SIZE] ^ key_schedule[round + 32];
        }
        memcpy(block, temp, BLOCK_SIZE);
    }
}

void encrypt(unsigned char *input, unsigned int input_length, unsigned char *key, unsigned int key_length, unsigned char *output) {
    unsigned int i, j;
    unsigned char block[BLOCK_SIZE];

    srand(time(NULL)); // Seed random number generator

    // Pad input to multiple of BLOCK_SIZE
    unsigned char *padded_input = (unsigned char *) malloc( ((input_length + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE );
    memcpy(padded_input, input, input_length);
    memset(padded_input + input_length, 0, ((input_length + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE - input_length);

    // Generate random IV
    unsigned char iv[BLOCK_SIZE];
    for (i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = (unsigned char) rand();
        output[i] = iv[i]; // First block of output is IV
    }

    // Encrypt each block using CBC mode
    for (i = 0; i < ((input_length + BLOCK_SIZE - 1) / BLOCK_SIZE); i++) {
        // XOR block with previous block (or IV in first block)
        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] = padded_input[i * BLOCK_SIZE + j] ^ iv[j];
        }

        // Encrypt block using key
        encrypt_block(block, key);

        // Update IV for next block
        memcpy(iv, block, BLOCK_SIZE);

        // Copy encrypted block to output
        memcpy(output + (i + 1) * BLOCK_SIZE, block, BLOCK_SIZE);
    }

    free(padded_input);
}

void decrypt(unsigned char *input, unsigned int input_length, unsigned char *key, unsigned int key_length, unsigned char *output) {
    unsigned int i, j;
    unsigned char block[BLOCK_SIZE];

    // Extract IV from first block of input
    unsigned char iv[BLOCK_SIZE];
    for (i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = input[i];
    }

    // Decrypt each block using CBC mode
    for (i = 0; i < (input_length / BLOCK_SIZE) - 1; i++) {
        // Decrypt block using key
        memcpy(block, input + (i + 1) * BLOCK_SIZE, BLOCK_SIZE);
        encrypt_block(block, key);

        // XOR block with previous block (or IV in first block)
        for (j = 0; j < BLOCK_SIZE; j++) {
            output[i * BLOCK_SIZE + j] = block[j] ^ iv[j];
        }

        // Update IV for next block
        memcpy(iv, input + (i + 1) * BLOCK_SIZE, BLOCK_SIZE);
    }
}

int main() {
    unsigned char input[] = "Hello, world!";
    unsigned int input_length = strlen((const char *) input);
    unsigned char key[] = "supersecret";
    unsigned int key_length = strlen((const char *) key);
    unsigned char output[input_length + BLOCK_SIZE];

    encrypt(input, input_length, key, key_length, output);
    printf("Encrypted output: ");
    for (int i = 0; i < input_length + BLOCK_SIZE; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    unsigned char decrypted_output[input_length];
    decrypt(output, input_length + BLOCK_SIZE, key, key_length, decrypted_output);
    printf("Decrypted output: %s\n", decrypted_output);

    return 0;
}