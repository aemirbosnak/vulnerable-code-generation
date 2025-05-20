//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 1000

typedef struct {
    char* data;
    int size;
} Block;

typedef struct {
    Block* blocks;
    int num_blocks;
} FileSystem;

FileSystem* fs;

void init_fs() {
    fs = malloc(sizeof(FileSystem));
    fs->blocks = malloc(sizeof(Block) * NUM_BLOCKS);
    for (int i = 0; i < NUM_BLOCKS; i++) {
        fs->blocks[i].data = malloc(BLOCK_SIZE);
        fs->blocks[i].size = 0;
    }
    fs->num_blocks = NUM_BLOCKS;
}

void destroy_fs() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free(fs->blocks[i].data);
    }
    free(fs->blocks);
    free(fs);
}

int find_free_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (fs->blocks[i].size == 0) {
            return i;
        }
    }
    return -1;
}

int write_file(char* filename, char* data, int size) {
    int block_num = find_free_block();
    if (block_num == -1) {
        return -1;
    }

    Block* block = &fs->blocks[block_num];
    block->size = size;
    memcpy(block->data, data, size);
    return block_num;
}

int read_file(int block_num, char* data, int size) {
    Block* block = &fs->blocks[block_num];
    if (block->size == 0) {
        return -1;
    }

    memcpy(data, block->data, size);
    return block->size;
}

int main() {
    init_fs();

    char* data = "Hello, world!";
    int size = strlen(data);
    int block_num = write_file("hello.txt", data, size);
    if (block_num == -1) {
        fprintf(stderr, "Error writing file\n");
        return 1;
    }

    char* buffer = malloc(size);
    int bytes_read = read_file(block_num, buffer, size);
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    printf("%s\n", buffer);

    destroy_fs();
    return 0;
}