//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 32 // hash function block size
#define HASH_SIZE 32 // hash function output size

typedef unsigned char BYTE;
typedef unsigned int WORD;

BYTE *hash(BYTE *data, WORD len);
void addPadding(BYTE *data, WORD len);
void divideBlocks(BYTE *data, WORD len, BYTE **blocks, WORD* numBlocks);
void hashBlocks(BYTE **blocks, WORD numBlocks, BYTE *output);

int main(int argc, char **argv) {
    BYTE text[] = "Example string to be hashed!";
    BYTE *output = hash(text, strlen(text));

    printf("Text: %s\n", text);
    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++)
        printf("%02x", output[i]);
    printf("\n");

    return 0;
}

BYTE *hash(BYTE *data, WORD len) {
    // add padding
    addPadding(data, len);

    // divide data into blocks
    BYTE **blocks = NULL; WORD numBlocks = 0;
    divideBlocks(data, len, &blocks, &numBlocks);

    // hash blocks
    BYTE *output = malloc(HASH_SIZE);
    hashBlocks(blocks, numBlocks, output);

    // free memory
    free(blocks);

    return output;
}

void addPadding(BYTE *data, WORD len) {
    // determine padding size
    WORD padSize = BLOCK_SIZE - (len % BLOCK_SIZE);

    // allocate memory for padding
    BYTE *padding = malloc(padSize);

    // initialize padding
    for (int i = 0; i < padSize; i++)
        padding[i] = (BYTE)padSize;

    // concatenate padding
    data[len] = 0x80;
    memcpy(data + len + 1, padding, padSize - 1);
    free(padding);
}

void divideBlocks(BYTE *data, WORD len, BYTE **blocks, WORD *numBlocks) {
    // determine number of blocks
    *numBlocks = len / BLOCK_SIZE;

    // allocate memory for blocks
    *blocks = malloc(*numBlocks * BLOCK_SIZE);

    // initialize blocks
    for (int i = 0; i < *numBlocks; i++)
        memcpy((*blocks) + i * BLOCK_SIZE, data + i * BLOCK_SIZE, BLOCK_SIZE);
}

void hashBlocks(BYTE **blocks, WORD numBlocks, BYTE *output) {
    // initialize output
    for (int i = 0; i < HASH_SIZE; i++)
        output[i] = 0;

    // initialize state
    BYTE state[BLOCK_SIZE] = {0};

    // hash each block
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++)
            state[j] ^= blocks[i][j];

        // perform compression function
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < BLOCK_SIZE; k++) {
                // example compression function:
                state[k] ^= (state[(k + 1) % BLOCK_SIZE] << 1) ^ (state[(k + 31) % BLOCK_SIZE] >> 1);
            }
        }

        // xor state into output
        for (int j = 0; j < BLOCK_SIZE; j++)
            output[j % HASH_SIZE] ^= state[j];
    }
}