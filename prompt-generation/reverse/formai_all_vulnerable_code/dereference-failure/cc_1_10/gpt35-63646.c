//FormAI DATASET v1.0 Category: File system simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 16
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024
#define SUPERBLOCK_SIZE 1
#define INODE_SIZE 1
#define DIRECTORY_SIZE 1

typedef struct superblock {
    int block_size;
    int num_blocks;
    int free_blocks;
} Superblock;

typedef struct inode {
    int file_size;
    int num_blocks;
    int* block_pointers;
} Inode;

typedef struct directory_entry {
    char filename[MAX_FILENAME_LENGTH];
    int inode_number;
} DirectoryEntry;

void initialize_file_system() {
    // Create superblock
    Superblock superblock;
    superblock.block_size = BLOCK_SIZE;
    superblock.num_blocks = NUM_BLOCKS;
    superblock.free_blocks = NUM_BLOCKS;

    // Create inode table
    Inode* inode_table = (Inode*)malloc(sizeof(Inode) * NUM_BLOCKS);
    for (int i = 0; i < NUM_BLOCKS; i++) {
        inode_table[i].file_size = 0;
        inode_table[i].num_blocks = 0;
        inode_table[i].block_pointers = NULL;
    }

    // Create root directory
    DirectoryEntry root_dir[DIRECTORY_SIZE];
    strcpy(root_dir[0].filename, "/");
    root_dir[0].inode_number = 0;

    // Write to disk
    FILE* disk = fopen("disk.bin", "w+b");
    fwrite(&superblock, sizeof(Superblock), 1, disk);
    fwrite(inode_table, sizeof(Inode), NUM_BLOCKS, disk);
    fwrite(root_dir, sizeof(DirectoryEntry), DIRECTORY_SIZE, disk);
    fseek(disk, BLOCK_SIZE * (SUPERBLOCK_SIZE + INODE_SIZE + DIRECTORY_SIZE), SEEK_SET);
    char empty_block[BLOCK_SIZE] = {0};
    for (int i = 0; i < NUM_BLOCKS; i++) {
        fwrite(empty_block, BLOCK_SIZE, 1, disk);
    }
    fclose(disk);

    // Clean up
    free(inode_table);
}

int main() {
    // Initialize file system
    initialize_file_system();

    // Read from disk
    FILE* disk = fopen("disk.bin", "rb+");
    Superblock superblock;
    fread(&superblock, sizeof(Superblock), 1, disk);
    Inode inode_table[NUM_BLOCKS];
    fread(inode_table, sizeof(Inode), NUM_BLOCKS, disk);
    DirectoryEntry root_dir[DIRECTORY_SIZE];
    fread(root_dir, sizeof(DirectoryEntry), DIRECTORY_SIZE, disk);
    char data[NUM_BLOCKS * BLOCK_SIZE];
    fseek(disk, BLOCK_SIZE * (SUPERBLOCK_SIZE + INODE_SIZE + DIRECTORY_SIZE), SEEK_SET);
    fread(data, BLOCK_SIZE, NUM_BLOCKS, disk);
    fclose(disk);

    // Print superblock information
    printf("Block size: %d\n", superblock.block_size);
    printf("Num blocks: %d\n", superblock.num_blocks);
    printf("Free blocks: %d\n", superblock.free_blocks);

    // Print root directory information
    printf("Root directory:\n");
    for (int i = 0; i < DIRECTORY_SIZE; i++) {
        printf("%s - inode %d\n", root_dir[i].filename, root_dir[i].inode_number);
    }

    // Create new file
    char new_file_name[MAX_FILENAME_LENGTH] = "new_file";
    int new_file_inode = 1;
    inode_table[new_file_inode].file_size = 0;
    inode_table[new_file_inode].num_blocks = 1;
    inode_table[new_file_inode].block_pointers = (int*)malloc(sizeof(int) * inode_table[new_file_inode].num_blocks);
    inode_table[new_file_inode].block_pointers[0] = 1;
    superblock.free_blocks--;
    fseek(disk, BLOCK_SIZE * (SUPERBLOCK_SIZE + INODE_SIZE + DIRECTORY_SIZE + inode_table[new_file_inode].block_pointers[0]), SEEK_SET);
    char new_block[BLOCK_SIZE] = "This is a new file!";
    fwrite(new_block, BLOCK_SIZE, 1, disk);
    fclose(disk);

    // Clean up
    free(inode_table[new_file_inode].block_pointers);

    return 0;
}