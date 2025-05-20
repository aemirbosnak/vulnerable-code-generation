//FormAI DATASET v1.0 Category: File system simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 100
#define MAX_FILES 50
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    int id;
    char data[BLOCK_SIZE];
} Block;

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int start_block;
    int num_blocks;
} File;

int free_blocks[MAX_BLOCKS];
Block disk[MAX_BLOCKS];
File files[MAX_FILES];
int num_blocks_used = 0;
int num_files = 0;

void init() {
    // initialize the free block array
    for (int i = 0; i < MAX_BLOCKS; i++) {
        free_blocks[i] = 1;
    }
}

int next_free_block() {
    // find the next free block
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (free_blocks[i]) {
            free_blocks[i] = 0;
            num_blocks_used++;
            return i;
        }
    }
    return -1;
}

void create_file(char *name, char *data) {
    // allocate blocks for the file
    int num_blocks_needed = strlen(data) / BLOCK_SIZE + 1;
    int *blocks = (int *) malloc(num_blocks_needed * sizeof(int));
    for (int i = 0; i < num_blocks_needed; i++) {
        blocks[i] = next_free_block();
    }

    // create the file
    File file;
    strcpy(file.name, name);
    file.start_block = blocks[0];
    file.num_blocks = num_blocks_needed;
    files[num_files++] = file;

    // write the data to the blocks
    for (int i = 0; i < num_blocks_needed; i++) {
        int block_id = blocks[i];
        int start = i * BLOCK_SIZE;
        int end = start + BLOCK_SIZE;
        if (end > strlen(data)) {
            end = strlen(data);
        }
        memcpy(disk[block_id].data, data + start, end - start);
    }
}

void read_file(char *name, char *buffer) {
    // find the file
    File *file = NULL;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            file = &files[i];
            break;
        }
    }

    // if file is found, read the data into buffer
    if (file) {
        int num_blocks = file->num_blocks;
        int block_id = file->start_block;
        int offset = 0;
        for (int i = 0; i < num_blocks; i++) {
            memcpy(buffer + offset, disk[block_id].data, BLOCK_SIZE);
            offset += BLOCK_SIZE;
            block_id = block_id + 1;
        }
    }
}

int main() {
    init();
    create_file("myFile.txt", "Hello World!");
    char buffer[BLOCK_SIZE * MAX_BLOCKS];
    read_file("myFile.txt", buffer);
    printf("%s", buffer);
    return 0;
}