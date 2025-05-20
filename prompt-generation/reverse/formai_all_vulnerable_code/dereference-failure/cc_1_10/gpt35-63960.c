//FormAI DATASET v1.0 Category: File system simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// define macros for block sizes and file limits
#define BLOCK_SIZE 4096
#define MAX_FILES 10

// define struct for file metadata
typedef struct {
    char *filename;
    int size;
    int block_count;
    int *block_ptrs;
} file_t;

// global variables
int next_block = 0;
int file_count = 0;
file_t files[MAX_FILES];

// function to allocate a block of memory
int allocate_block() {
    int block_ptr = next_block;
    next_block += BLOCK_SIZE;
    return block_ptr;
}

// function to create a new file
void create_file(char *filename, int size) {
    // check if there is room for another file
    if (file_count == MAX_FILES) {
        printf("Error: maximum file count reached\n");
        return;
    }

    // check if the file size is too large
    if (size > BLOCK_SIZE * MAX_FILES) {
        printf("Error: file size is too large\n");
        return;
    }

    // allocate blocks for the file
    int block_count = size / BLOCK_SIZE + 1;
    int *block_ptrs = malloc(sizeof(int) * block_count);
    for (int i = 0; i < block_count; i++) {
        block_ptrs[i] = allocate_block();
    }

    // add the file to the file table
    file_t new_file = {filename, size, block_count, block_ptrs};
    files[file_count++] = new_file;

    printf("File created: %s, size: %d bytes\n", filename, size);
}

// function to delete a file
void delete_file(char *filename) {
    int file_index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].filename, filename) == 0) {
            file_index = i;
            break;
        }
    }

    if (file_index == -1) {
        printf("Error: file not found\n");
        return;
    }

    // free the blocks allocated to the file
    for (int i = 0; i < files[file_index].block_count; i++) {
        int block_ptr = files[file_index].block_ptrs[i];
        // clear the data in the block
        memset((void *) block_ptr, 0, BLOCK_SIZE);
        next_block -= BLOCK_SIZE;
    }

    // shift the remaining files down in the file table
    for (int i = file_index + 1; i < file_count; i++) {
        files[i - 1] = files[i];
    }

    // decrement the file count
    file_count--;

    printf("File deleted: %s\n", filename);
}

// function to print the file table
void print_file_table() {
    printf("File table:\n");
    printf("Filename | Size\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s | %d bytes\n", files[i].filename, files[i].size);
    }
}

int main() {
    // create some files for testing
    create_file("file1.txt", 2048);
    create_file("file2.txt", 4096);
    create_file("file3.txt", 8192);

    // print the file table
    print_file_table();

    // delete a file
    delete_file("file2.txt");

    // print the file table again
    print_file_table();

    return 0;
}