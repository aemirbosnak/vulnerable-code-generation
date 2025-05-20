//FormAI DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a file
typedef struct {
    char fileName[50];
    int fileSize;
    int fileBlocks[20];
} File;

// Structure to represent a block of the file system
typedef struct {
    int blockNumber;
    int isOccupied;
    File contents;
} Block;

// Function to initialize the file system as empty
void initialize(Block* blocks, int numOfBlocks) {
    for(int i=0; i<numOfBlocks; i++) {
        blocks[i].blockNumber = i;
        blocks[i].isOccupied = 0;
    }
    printf("The file system has been initialized with %d blocks\n", numOfBlocks);
}

// Function to allocate a block to a file
void allocate(Block* blocks, int numOfBlocks, File file) {
    for(int i=0; i<numOfBlocks; i++) {
        if(blocks[i].isOccupied == 0) {
            blocks[i].contents = file;
            blocks[i].isOccupied = 1;
            printf("Block %d has been allocated to %s\n", i, file.fileName);
            break;
        }
    }
}

// Function to deallocate a block from a file
void deallocate(Block* blocks, int numOfBlocks, File file) {
    for(int i=0; i<numOfBlocks; i++) {
        if(blocks[i].isOccupied == 1 && strcmp(blocks[i].contents.fileName, file.fileName) == 0) {
            blocks[i].isOccupied = 0;
            printf("Block %d has been deallocated from %s\n", i, file.fileName);
        }
    }
}

int main() {
    int numOfBlocks = 10;
    Block* blocks = (Block*) malloc(numOfBlocks * sizeof(Block));
    initialize(blocks, numOfBlocks);
    
    File file1 = {"file1.txt", 1024, {0, 1}};
    allocate(blocks, numOfBlocks, file1);

    File file2 = {"file2.jpg", 2048, {2, 3, 4}};
    allocate(blocks, numOfBlocks, file2);

    deallocate(blocks, numOfBlocks, file1);

    free(blocks);
    return 0;
}