//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INODE_SIZE 1024
#define BLOCK_SIZE 4096

typedef struct {
    char name[256];
    int size;
    int blocks[10];
} inode_t;

typedef struct {
    char data[BLOCK_SIZE];
} block_t;

typedef struct {
    inode_t *inodes;
    block_t *blocks;
} filesystem_t;

int main() {
    // Create a new filesystem
    filesystem_t fs;

    // Allocate memory for the inodes
    fs.inodes = malloc(INODE_SIZE);

    // Allocate memory for the blocks
    fs.blocks = malloc(BLOCK_SIZE);

    // Create a new inode for the root directory
    inode_t *root_inode = &fs.inodes[0];

    // Set the name of the root directory
    strcpy(root_inode->name, "/");

    // Set the size of the root directory to 0
    root_inode->size = 0;

    // Create a new block for the root directory
    block_t *root_block = &fs.blocks[0];

    // Set the data in the root block to 0
    memset(root_block->data, 0, BLOCK_SIZE);

    // Add the root block to the root inode
    root_inode->blocks[0] = 0;

    // Create a new file in the root directory
    inode_t *file_inode = &fs.inodes[1];

    // Set the name of the file
    strcpy(file_inode->name, "test.txt");

    // Set the size of the file to 0
    file_inode->size = 0;

    // Create a new block for the file
    block_t *file_block = &fs.blocks[1];

    // Set the data in the block to 0
    memset(file_block->data, 0, BLOCK_SIZE);

    // Add the file block to the file inode
    file_inode->blocks[0] = 1;

    // Write some data to the file
    strcpy(file_block->data, "Hello, world!");

    // Print the contents of the file
    printf("%s\n", file_block->data);

    // Free the memory allocated for the filesystem
    free(fs.inodes);
    free(fs.blocks);

    return 0;
}