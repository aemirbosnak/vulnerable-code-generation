//FormAI DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define BLOCK_COUNT 64
#define FILENAME_SIZE 16

typedef struct {
    char name[FILENAME_SIZE];
    int start_block;
    int size;
} File;

char disk[BLOCK_SIZE * BLOCK_COUNT];
int free_blocks[BLOCK_COUNT];
File files[BLOCK_COUNT];

void init() {
    memset(disk, 0, BLOCK_SIZE * BLOCK_COUNT);
    memset(free_blocks, 1, BLOCK_COUNT);
    memset(files, 0, BLOCK_COUNT * sizeof(File));
}

int find_free_block() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (free_blocks[i]) {
            free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

void write_block(int block_number, char* data) {
    memcpy(disk + block_number * BLOCK_SIZE, data, BLOCK_SIZE);
}

void read_block(int block_number, char* data) {
    memcpy(data, disk + block_number * BLOCK_SIZE, BLOCK_SIZE);
}

void create_file(char* name, int size) {
    int start_block = find_free_block();
    if (start_block == -1) {
        fprintf(stderr, "Disk space is full\n");
        return;
    }
    File new_file;
    strncpy(new_file.name, name, FILENAME_SIZE);
    new_file.start_block = start_block;
    new_file.size = size;
    char block[BLOCK_SIZE];
    memset(block, 0, BLOCK_SIZE);
    memcpy(block, name, strlen(name));
    *((int*) (block + FILENAME_SIZE)) = size;
    write_block(start_block, block);
    for (int i = 1; i < size; i++) {
        int block_number = find_free_block();
        if (block_number == -1) {
            fprintf(stderr, "Disk space is full\n");
            return;
        }
        write_block(start_block + i, "");
    }
    files[start_block] = new_file;
}

void delete_file(char* name) {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (strlen(files[i].name) > 0 && strcmp(files[i].name, name) == 0) {
            files[i] = (File) {0};
            free_blocks[i] = 1;
            int size = files[i].size;
            for (int j = 0; j < size; j++) {
                free_blocks[i + j] = 1;
            }
            printf("File deleted successfully\n");
            return;
        }
    }
    fprintf(stderr, "File not found\n");
}

void print_files() {
    for (int i = 0; i < BLOCK_COUNT; i++) {
        if (strlen(files[i].name) > 0) {
            printf("%s, %d blocks, starting at block %d\n", files[i].name, files[i].size, files[i].start_block);
        }
    }
}

int main() {
    init();
    create_file("file1", 3);
    create_file("file2", 5);
    print_files();
    delete_file("file2");
    print_files();
    return 0;
}