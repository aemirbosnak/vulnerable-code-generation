//FormAI DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILENAME_LENGTH 24
#define MAX_FILESIZE BLOCK_SIZE * 128

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int start_block;
    int file_size;
} File;

typedef struct {
    int block_size;
    int num_blocks;
    int fat_size;
    int free_blocks;
    int *fat;
    File *files;
    void *data;
} FileSystem;

void create_file_system(FileSystem *fs) {
    // initialize file system
    fs->block_size = BLOCK_SIZE;
    fs->num_blocks = 256;
    fs->fat_size = sizeof(int) * 256;
    fs->free_blocks = 256;
    fs->fat = calloc(fs->fat_size, 1);
    fs->files = calloc(sizeof(File), 256);
    fs->data = calloc(BLOCK_SIZE, 256);

    // initialize FAT
    for (int i = 0; i < 256; i++) {
        if (i == 0 || i == 255) {
            // reserved blocks for boot sector and root directory
            fs->fat[i] = -1;
        } else {
            fs->fat[i] = i + 1;
        }
    }
}

int find_next_free_block(FileSystem *fs) {
    for (int i = 0; i < 256; i++) {
        if (fs->fat[i] == 0) {
            return i;
        }
    }
    return -1;
}

void add_file(FileSystem *fs, char *filename, int file_size) {
    // check if file with same name already exists
    for (int i = 0; i < 256; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            printf("File with name %s already exists\n", filename);
            return;
        }
    }

    // check if enough free blocks are available
    if (fs->free_blocks < (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE) {
        printf("Not enough free space\n");
        return;
    }

    // find start block for file
    int start_block = find_next_free_block(fs);
    int cur_block = start_block;
    for (int i = 1; i < (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE; i++) {
        int next_block = find_next_free_block(fs);
        fs->fat[cur_block] = next_block;
        cur_block = next_block;
    }
    fs->fat[cur_block] = -1;

    // add file to files list
    File new_file = {0};
    strcpy(new_file.filename, filename);
    new_file.start_block = start_block;
    new_file.file_size = file_size;

    for (int i = 0; i < 256; i++) {
        if (fs->files[i].filename[0] == '\0') {
            fs->files[i] = new_file;
            break;
        }
    }

    // update free blocks count
    fs->free_blocks -= (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
}

void delete_file(FileSystem *fs, char *filename) {
    for (int i = 0; i < 256; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            // free blocks used by file
            int cur_block = fs->files[i].start_block;
            while (fs->fat[cur_block] != -1) {
                int next_block = fs->fat[cur_block];
                fs->fat[cur_block] = 0;
                cur_block = next_block;
            }
            fs->fat[cur_block] = 0;

            // remove file from files list
            fs->files[i] = (File){0};

            // update free blocks count
            fs->free_blocks += (fs->files[i].file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
            return;
        }
    }
    printf("File with name %s not found\n", filename);
}

void read_from_file(FileSystem *fs, char *filename, int offset, int size, void *buffer) {
    for (int i = 0; i < 256; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            if (offset + size > fs->files[i].file_size) {
                size = fs->files[i].file_size - offset;
            }

            int start_block = fs->files[i].start_block;
            int cur_block = start_block;
            int cur_offset = offset % BLOCK_SIZE;
            int remaining_size = size;
            char *data = (char *)fs->data;

            while (remaining_size > 0) {
                memcpy(buffer, data + cur_block * BLOCK_SIZE + cur_offset, remaining_size);
                remaining_size -= BLOCK_SIZE - cur_offset;
                buffer += BLOCK_SIZE - cur_offset;

                cur_block = fs->fat[cur_block];
                cur_offset = 0;
            }
            return;
        }
    }
    printf("File with name %s not found\n", filename);
}

void write_to_file(FileSystem *fs, char *filename, int offset, int size, void *data) {
    for (int i = 0; i < 256; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            if (offset + size > fs->files[i].file_size) {
                size = fs->files[i].file_size - offset;
            }

            int start_block = fs->files[i].start_block;
            int cur_block = start_block;
            int cur_offset = offset % BLOCK_SIZE;
            int remaining_size = size;
            char *buffer = (char *)data;

            while (remaining_size > 0) {
                memcpy(fs->data + cur_block * BLOCK_SIZE + cur_offset, buffer, remaining_size);
                remaining_size -= BLOCK_SIZE - cur_offset;
                buffer += BLOCK_SIZE - cur_offset;

                cur_block = fs->fat[cur_block];
                cur_offset = 0;
            }
            return;
        }
    }
    printf("File with name %s not found\n", filename);
}

int main() {
    FileSystem fs;

    create_file_system(&fs);

    add_file(&fs, "test1.txt", 1024);
    add_file(&fs, "test2.txt", 2048);

    char buffer[MAX_FILESIZE];
    read_from_file(&fs, "test1.txt", 512, 512, buffer);

    write_to_file(&fs, "test2.txt", 1024, 1024, buffer);

    delete_file(&fs, "test1.txt");

    return 0;
}