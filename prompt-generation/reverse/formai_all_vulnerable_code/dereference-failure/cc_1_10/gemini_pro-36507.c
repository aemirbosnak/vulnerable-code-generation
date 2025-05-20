//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096
#define MAX_BLOCKS 1024
#define MAX_FILES 32

typedef struct {
    char name[256];
    int size;
    int blocks[MAX_BLOCKS];
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
} FileSystem;

FileSystem fs;

void init_fs() {
    fs.num_files = 0;
}

int create_file(const char *name) {
    if (fs.num_files >= MAX_FILES) {
        return -1;
    }

    strcpy(fs.files[fs.num_files].name, name);
    fs.files[fs.num_files].size = 0;
    fs.num_files++;

    return 0;
}

int write_file(const char *name, const char *buf, int size) {
    int i;
    int file_index = -1;

    for (i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        return -1;
    }

    if (size + fs.files[file_index].size > BLOCK_SIZE * MAX_BLOCKS) {
        return -1;
    }

    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    for (i = 0; i < num_blocks; i++) {
        fs.files[file_index].blocks[i] = malloc(BLOCK_SIZE);
        memcpy(fs.files[file_index].blocks[i], buf + i * BLOCK_SIZE, BLOCK_SIZE);
    }

    fs.files[file_index].size += size;

    return 0;
}

int read_file(const char *name, char *buf, int size) {
    int i;
    int file_index = -1;

    for (i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        return -1;
    }

    if (size > fs.files[file_index].size) {
        size = fs.files[file_index].size;
    }

    int num_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;

    for (i = 0; i < num_blocks; i++) {
        memcpy(buf + i * BLOCK_SIZE, fs.files[file_index].blocks[i], BLOCK_SIZE);
    }

    return size;
}

int main() {
    init_fs();

    create_file("file1");
    write_file("file1", "Hello, world!", 13);

    char buf[1024];
    read_file("file1", buf, 1024);

    printf("%s\n", buf);

    return 0;
}