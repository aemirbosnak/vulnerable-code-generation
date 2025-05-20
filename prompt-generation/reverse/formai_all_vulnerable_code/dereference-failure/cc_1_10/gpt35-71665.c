//FormAI DATASET v1.0 Category: File system simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 1000
#define BLOCK_SIZE 512

int main(int argc, char const *argv[]) {
    // Initialize file system
    char *fs = malloc(MAX_BLOCKS * BLOCK_SIZE);
    memset(fs, 0, MAX_BLOCKS * BLOCK_SIZE);

    // Create root directory
    int root_block = 0;
    fs[root_block * BLOCK_SIZE] = 1; // mark as directory
    fs[root_block * BLOCK_SIZE + 1] = 0; // parent directory is itself
    fs[root_block * BLOCK_SIZE + 2] = 2; // two entries: . and ..
    fs[root_block * BLOCK_SIZE + 3] = strlen(".") + 1; // length of string + NULL terminator
    strcpy(fs + root_block * BLOCK_SIZE + 4, "."); // current directory name
    fs[root_block * BLOCK_SIZE + 4 + strlen(".") + 1] = 0; // NULL terminator
    fs[root_block * BLOCK_SIZE + 4 + strlen(".") + 2] = strlen("..") + 1; // length of string + NULL terminator
    strcpy(fs + root_block * BLOCK_SIZE + 4 + strlen(".") + 3, ".."); // parent directory name
    fs[root_block * BLOCK_SIZE + 4 + strlen(".") + 3 + strlen("..") + 1] = 0; // NULL terminator

    // Create file
    int file_block = 1;
    fs[file_block * BLOCK_SIZE] = 0; // mark as file
    fs[file_block * BLOCK_SIZE + 1] = root_block; // parent directory is root
    fs[file_block * BLOCK_SIZE + 2] = strlen("file.txt") + 1; // length of string + NULL terminator
    strcpy(fs + file_block * BLOCK_SIZE + 3, "file.txt"); // file name
    fs[file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 1] = 0; // NULL terminator
    fs[file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 2] = 0; // file size (initially 0)

    // Write to file
    char *data = "Hello, world!";
    int data_size = strlen(data);
    memcpy(fs + file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 3, data, data_size);
    fs[file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 3 + data_size] = 0; // NULL terminator
    fs[file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 2] = data_size;

    // Read from file
    int read_size = fs[file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 2];
    char *read_data = malloc(read_size);
    memcpy(read_data, fs + file_block * BLOCK_SIZE + 3 + strlen("file.txt") + 3, read_size);
    printf("Read from file: %s\n", read_data);

    // Free memory
    free(fs);
    free(read_data);

    return 0;
}