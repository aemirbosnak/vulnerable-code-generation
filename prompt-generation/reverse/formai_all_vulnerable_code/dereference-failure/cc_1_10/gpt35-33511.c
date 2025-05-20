//FormAI DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 1000
#define MAX_FILES 100

typedef struct File {
    char name[256];
    int size;
    int first_block;
} File;

char* fs;
int free_blocks[NUM_BLOCKS];
File files[MAX_FILES];
int num_files = 0;

void init_fs() {
    fs = malloc(NUM_BLOCKS * BLOCK_SIZE * sizeof(char));
    memset(fs, 0, NUM_BLOCKS * BLOCK_SIZE);

    for (int i = 0; i < NUM_BLOCKS; i++) {
        free_blocks[i] = 1;
    }
}

int find_free_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (free_blocks[i] == 1) {
            free_blocks[i] = 0;
            return i;
        }
    }

    return -1; //no free block found
}

void create_file(char* name, int size) {
    if (num_files >= MAX_FILES) {
        printf("No more files can be created in the file system!\n");
        return;
    }

    int num_blocks = (size / BLOCK_SIZE) + 1;
    int first_block = find_free_block();

    if (first_block == -1) {
        printf("Not enough free space in the file system!\n");
        return;
    }

    File file;
    strcpy(file.name, name);
    file.size = size;
    file.first_block = first_block;

    files[num_files++] = file;

    //write the file data to the file system
    char* file_data = malloc(num_blocks * BLOCK_SIZE * sizeof(char));
    memset(file_data, 0, num_blocks * BLOCK_SIZE);

    memcpy(fs + (first_block * BLOCK_SIZE), file_data, size);

    free(file_data);
}

void read_file(char* name) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            char* file_data = malloc(files[i].size * sizeof(char));
            memcpy(file_data, fs + (files[i].first_block * BLOCK_SIZE), files[i].size);
            printf("%s\n", file_data);
            free(file_data);
            return;
        }
    }

    printf("File not found!\n");
}

int main() {
    init_fs();

    create_file("hello.txt", 12);
    create_file("world.txt", 11);

    read_file("hello.txt");
    read_file("world.txt");
    read_file("foobar.txt");

    return 0;
}