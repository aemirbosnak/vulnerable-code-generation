//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define file system block size
#define BLOCK_SIZE 512

// Define file system information structure
typedef struct fs_info {
    int total_blocks;
    int free_blocks;
} fs_info;

// Define file structure
typedef struct file {
    char name[32];
    int size;
    int block_start;
} file;

// Define file system block structure
typedef struct block {
    char data[BLOCK_SIZE];
    int next_block;
} block;

// Define file system structure
typedef struct file_system {
    fs_info info;
    file* files;
    block* blocks;
} file_system;

// Define function to initialize file system
file_system* init_file_system(int total_blocks) {
    // Allocate memory for file system struct
    file_system* fs = (file_system*)malloc(sizeof(file_system));
    fs->info.total_blocks = total_blocks;
    fs->info.free_blocks = total_blocks;

    // Allocate memory for file array
    fs->files = (file*)malloc(sizeof(file) * total_blocks);

    // Allocate memory for block array
    fs->blocks = (block*)malloc(sizeof(block) * total_blocks);

    // Initialize all blocks to be free, and connect each block to the next
    for (int i = 0; i < total_blocks; i++) {
        memset(fs->blocks[i].data, 0, BLOCK_SIZE);
        fs->blocks[i].next_block = i + 1;
    }

    // Set the last block's next block to -1, indicating the end of the file system
    fs->blocks[total_blocks - 1].next_block = -1;

    return fs;
}

// Define function to add a file to the file system
void add_file(file_system* fs, char* name, int size) {
    // Check if there is enough space in the file system
    if (fs->info.free_blocks == 0) {
        printf("Error: Not enough space in file system to add file %s\n", name);
        return;
    }

    // Find the first free block
    int block_index = 0;
    while (fs->blocks[block_index].next_block != block_index + 1) {
        block_index = fs->blocks[block_index].next_block;
    }

    // Set the block to be used and update the file system info
    fs->blocks[block_index].next_block = -1;
    fs->info.free_blocks--;
    fs->files[fs->info.total_blocks - fs->info.free_blocks - 1].block_start = block_index;

    // Copy the file name and size to the file struct
    strncpy(fs->files[fs->info.total_blocks - fs->info.free_blocks - 1].name, name, 32);
    fs->files[fs->info.total_blocks - fs->info.free_blocks - 1].size = size;

    printf("File %s added successfully!\n", name);
}

// Define function to delete a file from the file system
void delete_file(file_system* fs, char* name) {
    // Find the file with the given name
    int file_index = -1;
    for (int i = 0; i < fs->info.total_blocks - fs->info.free_blocks; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    // If the file was found, free its blocks and update the file system info
    if (file_index != -1) {
        int block_index = fs->files[file_index].block_start;
        while (block_index != -1) {
            int next_block = fs->blocks[block_index].next_block;
            memset(fs->blocks[block_index].data, 0, BLOCK_SIZE);
            fs->blocks[block_index].next_block = block_index + 1;
            fs->info.free_blocks++;
            block_index = next_block;
        }

        // Shift all following files in the file array to fill the gap
        for (int i = file_index + 1; i < fs->info.total_blocks - fs->info.free_blocks; i++) {
            fs->files[i - 1] = fs->files[i];
        }

        printf("File %s deleted successfully!\n", name);
    } else {
        printf("Error: File %s not found in file system\n", name);
    }
}

int main() {
    // Declare and initialize the file system
    file_system* fs = init_file_system(10);

    // Add a few files
    add_file(fs, "file1.txt", 1024);
    add_file(fs, "file2.mp3", 2048);
    add_file(fs, "file3.jpg", 4096);

    // Delete a file
    delete_file(fs, "file2.mp3");

    // Add another file
    add_file(fs, "file4.txt", 8192);

    // Free the memory used by the file system
    free(fs->files);
    free(fs->blocks);
    free(fs);

    return 0;
}