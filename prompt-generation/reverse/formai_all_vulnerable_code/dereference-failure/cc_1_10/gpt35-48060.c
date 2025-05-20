//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 256
#define MAX_BLOCKS 10

/* A block of data */
typedef struct {
    char data[BLOCK_SIZE];
    int size;
} Block;

/* An array of blocks */
Block *blocks[MAX_BLOCKS];

/* The number of blocks currently in use */
int numBlocks = 0;

/* Returns 1 if the given block pointer is valid */
int validateBlock(Block *block) {
    int i;
    for (i = 0; i < numBlocks; i++) {
        if (block == blocks[i]) {
            return 1;
        }
    }
    return 0;
}

/* Allocates a block of data */
Block *allocateBlock() {
    if (numBlocks >= MAX_BLOCKS) {
        printf("Error: maximum number of blocks reached\n");
        exit(1);
    }

    Block *block = malloc(sizeof(Block));
    if (block == NULL) {
        printf("Error: failed to allocate memory\n");
        exit(1);
    }

    block->size = 0;
    blocks[numBlocks++] = block;

    return block;
}

/* Deallocates a block of data */
void deallocateBlock(Block *block) {
    if (!validateBlock(block)) {
        printf("Error: invalid block pointer\n");
        exit(1);
    }

    int i;
    for (i = 0; i < numBlocks; i++) {
        if (block == blocks[i]) {
            free(block);
            blocks[i] = blocks[numBlocks-1];
            numBlocks--;
            return;
        }
    }
}

/* Reallocates a block of data */
Block *reallocateBlock(Block *block, int newSize) {
    if (!validateBlock(block)) {
        printf("Error: invalid block pointer\n");
        exit(1);
    }

    if (newSize > BLOCK_SIZE) {
        printf("Error: cannot allocate more than %d bytes per block\n", BLOCK_SIZE);
        exit(1);
    }

    Block *newBlock = allocateBlock();
    newBlock->size = newSize;

    int i;
    for (i = 0; i < newSize; i++) {
        newBlock->data[i] = block->data[i];
    }

    deallocateBlock(block);

    return newBlock;
}

int main() {
    // allocate a block of data
    Block *block1 = allocateBlock();
    block1->size = 10;
    for (int i = 0; i < block1->size; i++) {
        block1->data[i] = 'a' + i;
    }

    // reallocate the block of data with a smaller size
    Block *block2 = reallocateBlock(block1, 5);
    for (int i = 0; i < block2->size; i++) {
        printf("%c ", block2->data[i]);
    }
    printf("\n");

    // deallocate the block of data
    deallocateBlock(block2);

    return 0;
}