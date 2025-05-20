//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the block size and number of blocks
#define BLOCK_SIZE 512
#define NUM_BLOCKS 1000

// Create a struct for the file
typedef struct File {
    char* filename;
    int size;
    int* blocks;
} File;

// Create an array to hold the files
File* files[NUM_BLOCKS];

// Create an array to hold the free blocks
int free_blocks[NUM_BLOCKS];

// Create a function to initialize the file system
void init_file_system() {
    // Allocate memory for all the files
    for (int i = 0; i < NUM_BLOCKS; i++) {
        files[i] = (File*) malloc(sizeof(File));
        files[i]->filename = NULL;
        files[i]->size = 0;
        files[i]->blocks = NULL;
    }

    // Set all the blocks as free
    for (int i = 0; i < NUM_BLOCKS; i++) {
        free_blocks[i] = 1;
    }
}

// Create a function to find free blocks
int find_free_block() {
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (free_blocks[i] == 1) {
            free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

// Create a function to create a new file
void create_file(char* filename, int size) {
    // Find free blocks
    int num_blocks = size / BLOCK_SIZE + 1;
    int blocks[num_blocks];
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = find_free_block();
        if (blocks[i] == -1) {
            printf("Error: not enough free blocks for file %s\n", filename);
            return;
        }
    }

    // Create the file
    File* file = (File*) malloc(sizeof(File));
    file->filename = strdup(filename);
    file->size = size;
    file->blocks = (int*) malloc(num_blocks * sizeof(int));
    memcpy(file->blocks, blocks, num_blocks * sizeof(int));

    // Add the file to the files array
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (files[i]->filename == NULL) {
            files[i] = file;
            return;
        }
    }

    printf("Error: maximum number of files reached\n");
}

// Create a function to delete a file
void delete_file(char* filename) {
    // Find the file
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (files[i]->filename != NULL && strcmp(files[i]->filename, filename) == 0) {
            // Free the blocks
            int num_blocks = files[i]->size / BLOCK_SIZE + 1;
            for (int j = 0; j < num_blocks; j++) {
                free_blocks[files[i]->blocks[j]] = 1;
            }

            // Free the file
            free(files[i]->filename);
            free(files[i]->blocks);
            free(files[i]);
            files[i]->filename = NULL;
            return;
        }
    }

    printf("Error: file %s not found\n", filename);
}

// Create a function to list all the files
void list_files() {
    printf("File system contents:\n");
    for (int i = 0; i < NUM_BLOCKS; i++) {
        if (files[i]->filename != NULL) {
            printf("%s\t%d bytes\n", files[i]->filename, files[i]->size);
        }
    }
}

// Create a main function to test the file system
int main() {
    init_file_system();
    create_file("file1", 1024);
    create_file("file2", 2048);
    list_files();
    delete_file("file1");
    list_files();
    create_file("file3", 3072);
    list_files();
    create_file("file4", 4096);
    return 0;
}