//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int block_size;
    int block_count;
    int* used_blocks;
    int free_blocks;
} FileSystem;

// initialize the file system
FileSystem* createFileSystem(int block_size, int block_count) {
    FileSystem* fs = (FileSystem*) malloc(sizeof(FileSystem));
    fs->block_size = block_size;
    fs->block_count = block_count;
    fs->used_blocks = (int*) malloc(sizeof(int) * block_count);
    for (int i = 0; i < block_count; i++) {
        fs->used_blocks[i] = 0;
    }
    fs->free_blocks = block_count;
    return fs;
}

// allocate a block of memory
int allocateBlock(FileSystem* fs) {
    if (fs->free_blocks == 0) {
        return -1;
    }
    int index = rand() % fs->block_count;
    while (fs->used_blocks[index] == 1) {
        index = (index + 1) % fs->block_count;
    }
    fs->used_blocks[index] = 1;
    fs->free_blocks--;
    return index;
}

// free a block of memory
void freeBlock(FileSystem* fs, int index) {
    fs->used_blocks[index] = 0;
    fs->free_blocks++;
}

int main() {
    // initialize file system
    FileSystem* fs = createFileSystem(1024, 10);

    // allocate memory
    int block1 = allocateBlock(fs);
    int block2 = allocateBlock(fs);
    int block3 = allocateBlock(fs);

    // free memory
    freeBlock(fs, block1);
    freeBlock(fs, block3);

    // allocate more memory
    int block4 = allocateBlock(fs);
    int block5 = allocateBlock(fs);

    // print free blocks
    printf("Free blocks: %d\n", fs->free_blocks);

    // deallocate file system
    free(fs->used_blocks);
    free(fs);

    return 0;
}