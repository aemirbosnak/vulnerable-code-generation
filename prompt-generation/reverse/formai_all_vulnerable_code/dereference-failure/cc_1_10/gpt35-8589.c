//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 100
#define BLOCK_SIZE 512

typedef struct {
    int id;
    int size;
    int blocks;
    int *block_ids;
} File;

int disk_size = 1000;
int bitmap[1000];
char disk[1000][BLOCK_SIZE];
File files[MAX_FILES];
int num_files = 0;

int allocate_block() {
    for (int i = 0; i < disk_size; i++) {
        if (bitmap[i] == 0) {
            bitmap[i] = 1;
            return i;
        }
    }
    return -1;
}

void deallocate_block(int id) {
    bitmap[id] = 0;
}

File create_file(int size) {
    File file;
    file.id = num_files;
    file.size = size;
    file.blocks = 0;
    file.block_ids = (int*) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        int block_id = allocate_block();
        if (block_id == -1) {
            printf("Error: disk is full\n");
            exit(1);
        }
        file.blocks++;
        file.block_ids[i] = block_id;
    }
    num_files++;
    files[num_files - 1] = file;
    return file;
}

void read_file(File file) {
    printf("[File %d] Size: %d bytes\n", file.id, file.size);
    for (int i = 0; i < file.blocks; i++) {
        printf("[Block %d] %s\n", file.block_ids[i], disk[file.block_ids[i]]);
    }
}

void write_file(File file, char *data) {
    if (file.size < strlen(data)) {
        printf("Error: file size is too small\n");
        return;
    }
    for (int i = 0; i < file.blocks; i++) {
        strncpy(disk[file.block_ids[i]], &data[i*BLOCK_SIZE], BLOCK_SIZE);
    }
    printf("Successfully wrote to file %d\n", file.id);
}

void delete_file(File file) {
    for (int i = 0; i < file.blocks; i++) {
        deallocate_block(file.block_ids[i]);
    }
    printf("Successfully deleted file %d\n", file.id);
}

int main() {
    // create files
    File file1 = create_file(5);
    File file2 = create_file(7);
    File file3 = create_file(11);

    // write to files
    write_file(file1, "hello");
    write_file(file2, "world!");
    write_file(file3, "this is a test");

    // read files
    read_file(file1);
    read_file(file2);
    read_file(file3);

    // delete file
    delete_file(file1);
    delete_file(file2);
    delete_file(file3);
    
    return 0;
}