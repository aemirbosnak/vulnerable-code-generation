//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 1024

typedef struct {
    char name[32];
    int size;
    int blocks[NUM_BLOCKS];
} File;

typedef struct {
    File files[100];
    int num_files;
} FileSystem;

FileSystem fs;

void init_fs() {
    fs.num_files = 0;
}

int create_file(char *name, int size) {
    if (fs.num_files >= 100) {
        return -1;
    }

    strcpy(fs.files[fs.num_files].name, name);
    fs.files[fs.num_files].size = size;

    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    for (int i = 0; i < num_blocks; i++) {
        fs.files[fs.num_files].blocks[i] = -1;
    }

    fs.num_files++;

    return 0;
}

int write_file(char *name, char *data, int size) {
    File *file = NULL;

    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            file = &fs.files[i];
            break;
        }
    }

    if (file == NULL) {
        return -1;
    }

    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    for (int i = 0; i < num_blocks; i++) {
        if (file->blocks[i] == -1) {
            file->blocks[i] = malloc(BLOCK_SIZE);
        }

        memcpy(file->blocks[i], data + i * BLOCK_SIZE, BLOCK_SIZE);
    }

    return 0;
}

int read_file(char *name, char *data, int size) {
    File *file = NULL;

    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            file = &fs.files[i];
            break;
        }
    }

    if (file == NULL) {
        return -1;
    }

    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    for (int i = 0; i < num_blocks; i++) {
        if (file->blocks[i] == -1) {
            return -1;
        }

        memcpy(data + i * BLOCK_SIZE, file->blocks[i], BLOCK_SIZE);
    }

    return 0;
}

int main() {
    init_fs();

    create_file("file1.txt", 1024);
    write_file("file1.txt", "Hello, world!", 12);

    char data[1024];

    read_file("file1.txt", data, 1024);

    printf("%s\n", data);

    return 0;
}