//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char magic[2];
    int version;
    int num_files;
    int file_size;
    char reserved[10];
} super_block_t;

typedef struct {
    int inode_num;
    int size;
    int num_blocks;
    int block_size;
    int direct_blocks[12];
} inode_t;

typedef struct {
    inode_t inode;
    char data[BLOCK_SIZE - sizeof(inode_t)];
} block_t;

int main(int argc, char *argv[]) {
    FILE *disk;
    super_block_t super_block;
    inode_t inode;
    block_t block;

    disk = fopen("disk.img", "rb+");
    if (disk == NULL) {
        printf("Error opening disk image.\n");
        return 1;
    }

    // Read super block
    fseek(disk, 0, SEEK_SET);
    fread(&super_block, sizeof(super_block_t), 1, disk);

    // Check if super block is valid
    if (strcmp(super_block.magic, "EXT3")!= 0) {
        printf("Invalid super block.\n");
        return 1;
    }

    // Read inode
    fseek(disk, super_block.file_size * (super_block.num_files - 1), SEEK_SET);
    fread(&inode, sizeof(inode_t), 1, disk);

    // Check if inode is valid
    if (inode.inode_num == 0) {
        printf("Invalid inode.\n");
        return 1;
    }

    // Read block
    fseek(disk, inode.block_size * inode.num_blocks, SEEK_SET);
    fread(&block, sizeof(block_t), 1, disk);

    // Print block contents
    printf("Block contents:\n");
    for (int i = 0; i < BLOCK_SIZE - sizeof(inode_t); i++) {
        printf("%c", block.data[i]);
    }
    printf("\n");

    fclose(disk);

    return 0;
}