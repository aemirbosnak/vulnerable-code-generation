//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16

void xor_blocks(unsigned char *a, unsigned char *b, unsigned char *out) {
    for (int i=0; i<BLOCK_SIZE; i++) {
        out[i] = a[i] ^ b[i];
    }
}

void encrypt_block(unsigned char *key, unsigned char *block) {
    for (int i=0; i<BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

void decrypt_block(unsigned char *key, unsigned char *block) {
    for (int i=0; i<BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

void encrypt(unsigned char *key, unsigned char *input, unsigned char *output, int length) {
    int num_blocks = length / BLOCK_SIZE;
    unsigned char *prev = malloc(BLOCK_SIZE);
    unsigned char *curr = malloc(BLOCK_SIZE);

    xor_blocks(input, key, prev);
    for (int i=1; i<num_blocks; i++) {
        xor_blocks(prev, input+(i*BLOCK_SIZE), curr);
        encrypt_block(key, curr);
        xor_blocks(prev, curr, prev);
        memcpy(output+(i-1)*BLOCK_SIZE, prev, BLOCK_SIZE);
    }

    free(prev);
    free(curr);
}

void decrypt(unsigned char *key, unsigned char *input, unsigned char *output, int length) {
    int num_blocks = length / BLOCK_SIZE;
    unsigned char *prev = malloc(BLOCK_SIZE);
    unsigned char *curr = malloc(BLOCK_SIZE);

    memcpy(prev, input+((num_blocks-2)*BLOCK_SIZE), BLOCK_SIZE);
    decrypt_block(key, prev);
    memcpy(output+(num_blocks-2)*BLOCK_SIZE, prev, BLOCK_SIZE);

    for (int i=num_blocks-2; i>0; i--) {
        xor_blocks(input+(i-1)*BLOCK_SIZE, prev, curr);
        decrypt_block(key, curr);
        xor_blocks(curr, prev, prev);
        memcpy(output+(i-1)*BLOCK_SIZE, prev, BLOCK_SIZE);
    }

    xor_blocks(input, key, prev);
    decrypt_block(key, prev);
    memcpy(output, prev, BLOCK_SIZE);

    free(prev);
    free(curr);
}

int main() {

    unsigned char key[BLOCK_SIZE] = {0x1a, 0x2b, 0x3c, 0x4d, 0x5e, 0x6f, 0x7a, 0x88,
                                     0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char input[] = {0x46, 0x75, 0x6e, 0x20, 0x21, 0x21, 0x21, 0x20};
    unsigned char *output = malloc(sizeof(input));

    encrypt(key, input, output, sizeof(input));
    printf("Encrypted: ");
    for (int i=0; i<sizeof(input); i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    decrypt(key, output, input, sizeof(input));
    printf("Decrypted: %s\n", input);

    free(output);
    return 0;
}