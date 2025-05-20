//FormAI DATASET v1.0 Category: File system simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    int blockNumber;
    char data[BLOCK_SIZE];
} Block;

typedef struct {
    int numBlocks;
    int freeBlocks;
    int *freeBlockList;
} FileSystem;

FileSystem createFileSystem(int numBlocks) {
    FileSystem fs;
    fs.numBlocks = numBlocks;
    fs.freeBlocks = numBlocks;
    fs.freeBlockList = (int*) malloc(numBlocks * sizeof(int));
    for (int i = 0; i < numBlocks; i++) {
        fs.freeBlockList[i] = i;
    }
    return fs;
}

int allocateBlock(FileSystem *fs) {
    if (fs->freeBlocks == 0) {
        return -1; // No free blocks available
    }
    int blockNumber = fs->freeBlockList[fs->freeBlocks - 1];
    fs->freeBlocks--;
    return blockNumber;
}

void freeBlock(FileSystem *fs, int blockNumber) {
    fs->freeBlockList[fs->freeBlocks] = blockNumber;
    fs->freeBlocks++;
}

void writeToBlock(Block *block, char *data) {
    strncpy(block->data, data, BLOCK_SIZE);
}

void readBlock(Block *block, char *data) {
    strncpy(data, block->data, BLOCK_SIZE);
}

int main() {
    FileSystem fs = createFileSystem(10);
    printf("File system initialized with %d blocks\n", fs.numBlocks);
    Block blocks[fs.numBlocks];
    for (int i = 0; i < fs.numBlocks; i++) {
        int blockNumber = allocateBlock(&fs);
        if (blockNumber == -1) {
            printf("Error: No free blocks available!\n");
            break;
        }
        blocks[i].blockNumber = blockNumber;
        writeToBlock(&blocks[i], "Some data");
    }
    printf("Free blocks: %d\n", fs.freeBlocks);
    printf("Writing data to block 3...\n");
    writeToBlock(&blocks[3], "Hello world!");
    char data[BLOCK_SIZE];
    printf("Reading data from block 3...\n");
    readBlock(&blocks[3], data);
    printf("Data read: %s\n", data);
    printf("Freeing block 5...\n");
    freeBlock(&fs, blocks[5].blockNumber);
    printf("Free blocks: %d\n", fs.freeBlocks);
    return 0;
}