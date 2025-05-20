//FormAI DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LENGTH 10
#define NUM_BLOCKS 10
#define BLOCK_SIZE 200

typedef struct {
    char filename[FILENAME_LENGTH];
    int start_block;
    int num_blocks;
} File;

typedef struct {
    int is_assigned;
    char data[BLOCK_SIZE];
} Block;

File* files[NUM_BLOCKS];
Block* blocks[NUM_BLOCKS];
int num_files = 0;

void init_blocks() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        blocks[i] = (Block*) malloc(sizeof(Block));
        blocks[i]->is_assigned = 0;
    }
}

void create_file(char* filename, int num_blocks) {
    int found_blocks = 0;
    int i = 0;
    while (found_blocks < num_blocks && i < NUM_BLOCKS) {
        if (!blocks[i]->is_assigned) {
            found_blocks++;
        } else {
            found_blocks = 0;
        }
        i++;
    }
    if (found_blocks < num_blocks) {
        printf("Not enough blocks available to create file %s\n", filename);
        return;
    }
    i -= found_blocks;
    for (int j = 0; j < found_blocks; j++) {
        blocks[i+j]->is_assigned = 1;
    }
    files[num_files] = (File*) malloc(sizeof(File));
    strncpy(files[num_files]->filename, filename, FILENAME_LENGTH);
    files[num_files]->start_block = i;
    files[num_files]->num_blocks = num_blocks;
    num_files++;
    printf("File %s created successfully\n", filename);
}

void read_file(char* filename) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Cannot find file %s\n", filename);
        return;
    }
    for (int i = 0; i < files[file_index]->num_blocks; i++) {
        printf("%s", blocks[files[file_index]->start_block+i]->data);
    }
}

void write_file(char* filename, char* data) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Cannot find file %s\n", filename);
        return;
    }
    int blocks_written = 0;
    int data_written = 0;
    for (int i = 0; i < files[file_index]->num_blocks; i++) {
        int bytes_written = sprintf(blocks[files[file_index]->start_block+i]->data, "%s", data+data_written);
        blocks_written++;
        data_written += bytes_written;
        if (data_written >= strlen(data)) {
            break;
        }
    }
    if (blocks_written < files[file_index]->num_blocks) {
        printf("Not enough blocks available to write to file %s\n", filename);
        return;
    }
    printf("Data written successfully to file %s\n", filename);
}

void delete_file(char* filename) {
    int file_index = -1;
    for (int i = 0; i < num_files; i++) {
        if (strcmp(files[i]->filename, filename) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Cannot find file %s\n", filename);
        return;
    }
    for (int i = 0; i < files[file_index]->num_blocks; i++) {
        blocks[files[file_index]->start_block+i]->is_assigned = 0;
    }
    free(files[file_index]);
    for (int i = file_index; i < num_files-1; i++) {
        files[i] = files[i+1];
    }
    num_files--;
    printf("File %s deleted successfully\n", filename);
}

int main() {
    init_blocks();

    create_file("hello.txt", 3);
    write_file("hello.txt", "Hello, world!");
    read_file("hello.txt");
    delete_file("hello.txt");
    
    return 0;
}