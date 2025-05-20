//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16 // 16 bytes block size
#define KEY_SIZE 64   // 64 bytes key size
#define ROUNDS 16     // 16 rounds

typedef unsigned char byte; // byte type

void generate_key(byte *key) {
    srand(time(NULL)); // seed random with current time
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // generate random byte
    }
}

void xor(byte *a, byte *b, byte *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] ^ b[i]; // XOR a and b and store the result in c
    }
}

void encrypt_block(byte *block, byte *key) {
    byte round_key[KEY_SIZE]; // round key
    byte temp_block[BLOCK_SIZE]; // temporary block for storing intermediate results

    memcpy(temp_block, block, BLOCK_SIZE); // copy input block to temporary block
    for (int round = 0; round < ROUNDS; round++) {
        memcpy(round_key, key + round * 4, 4); // generate round key

        for (int i = 0; i < BLOCK_SIZE; i++) {
            temp_block[i] = temp_block[i] ^ round_key[i % 4]; // XOR each byte of the block with a byte from the round key
        }

        byte sbox[] = {0x9, 0x4, 0xA, 0xB, 0xD, 0x1, 0x8, 0x5, 0x6, 0x2, 0x0, 0x3, 0xC, 0xE, 0xF, 0x7}; // sbox

        for (int i = 0; i < BLOCK_SIZE; i++) {
            temp_block[i] = sbox[temp_block[i]]; // substitute each byte with a byte from the sbox
        }

        byte permutation[] = {1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16}; // permutation

        byte permuted_block[BLOCK_SIZE]; // permuted block
        for (int i = 0; i < BLOCK_SIZE; i++) {
            permuted_block[i] = temp_block[permutation[i] - 1]; // permute each byte of the block
        }

        memcpy(temp_block, permuted_block, BLOCK_SIZE); // copy permuted block to temporary block
    }
    memcpy(block, temp_block, BLOCK_SIZE); // copy encrypted block to output
}

void encrypt(byte *input, byte *output, byte *key, int length) {
    for (int i = 0; i < length / BLOCK_SIZE; i++) {
        byte block[BLOCK_SIZE];
        memcpy(block, input + i * BLOCK_SIZE, BLOCK_SIZE); // copy input block to block
        encrypt_block(block, key); // encrypt block
        memcpy(output + i * BLOCK_SIZE, block, BLOCK_SIZE); // copy encrypted block to output
    }
}

int main() {
    byte key[KEY_SIZE];
    generate_key(key); // generate random key

    byte input[] = "This is a test message"; // input message
    int length = strlen(input) + 1; // length of input message including null terminator

    int blocks = length / BLOCK_SIZE + (length % BLOCK_SIZE != 0); // number of blocks needed

    byte *encrypted = malloc(blocks * BLOCK_SIZE); // encrypted message

    encrypt(input, encrypted, key, length); // encrypt input message

    printf("Original message: %s\n", input);
    printf("Encrypted message: ");
    for (int i = 0; i < blocks * BLOCK_SIZE; i++) {
        printf("%02x", encrypted[i]); // print encrypted message as hexadecimal
    }
    printf("\n");

    free(encrypted); // free encrypted message memory

    return 0;
}