//FormAI DATASET v1.0 Category: File system simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // size of each block in the file system
#define NUM_BLOCKS 1000 // number of total blocks in the file system

// define the basic structure of a file
typedef struct file {
    char* name; // name of the file
    int size; // size of the file in bytes
    int* data_blocks; // array of data block indices containing file data
} File;

// define basic structure of the file system
typedef struct file_system {
    File* files[NUM_BLOCKS]; // array of files in the file system
    int free_blocks[NUM_BLOCKS]; // array of free block indices in the file system
    int num_files; // number of files in the file system
    int num_free_blocks; // number of free blocks in the file system
} FileSystem;

// initialize a new file system
FileSystem* init_file_system() {
    FileSystem* file_system = (FileSystem*) malloc(sizeof(FileSystem));

    // initialize all blocks as free
    for (int i = 0; i < NUM_BLOCKS; i++) {
        file_system->free_blocks[i] = i;
    }
    file_system->num_free_blocks = NUM_BLOCKS;

    // initialize the array of files as empty
    for (int i = 0; i < NUM_BLOCKS; i++) {
        file_system->files[i] = NULL;
    }
    file_system->num_files = 0;

    return file_system;
}

// allocate a new block for data in the file system
int allocate_block(FileSystem* file_system) {
    if (file_system->num_free_blocks == 0) {
        printf("FILE SYSTEM ERROR: Cannot allocate new block. File system is full.\n");
        return -1;
    }

    int block_idx = file_system->free_blocks[file_system->num_free_blocks - 1];
    file_system->num_free_blocks--;
    return block_idx;
}

// deallocate a block of data in the file system
int deallocate_block(FileSystem* file_system, int block_idx) {
    file_system->free_blocks[file_system->num_free_blocks] = block_idx;
    file_system->num_free_blocks++;
    return 0;
}

// create a new file in the file system
int create_file(FileSystem* file_system, char* name) {
    if (file_system->num_files == NUM_BLOCKS) {
        printf("FILE SYSTEM ERROR: Cannot create file. File system is full.\n");
        return -1;
    }

    // allocate new file and initialize values
    File* new_file = (File*) malloc(sizeof(File));
    new_file->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new_file->name, name);
    new_file->size = 0;
    new_file->data_blocks = NULL;

    // add the file to the file system array
    file_system->files[file_system->num_files] = new_file;
    file_system->num_files++;

    return 0;
}

// write data to an existing file in the file system
int write_file(FileSystem* file_system, char* name, char* data, int num_bytes) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->files[i]->name, name) == 0) {
            File* file = file_system->files[i];

            // determine number of blocks needed for data
            int num_blocks_needed = (num_bytes / BLOCK_SIZE) + 1;
            int current_block_idx = 0;

            // allocate new blocks for file data if needed
            if (num_blocks_needed > file->size) {
                int* new_data_blocks = (int*) malloc(sizeof(int) * num_blocks_needed);
                memcpy(new_data_blocks, file->data_blocks, sizeof(int) * file->size);
                file->data_blocks = new_data_blocks;

                for (int j = file->size; j < num_blocks_needed; j++) {
                    int new_block_idx = allocate_block(file_system);
                    file->data_blocks[j] = new_block_idx;
                }
                
                file->size = num_blocks_needed;
            }

            // write data to file data blocks
            char* current_data = data;
            int bytes_left_to_write = num_bytes;
            while (bytes_left_to_write > 0) {
                int block_idx = file->data_blocks[current_block_idx];
                int bytes_to_write = bytes_left_to_write > BLOCK_SIZE ? BLOCK_SIZE : bytes_left_to_write;
                memcpy(block_idx, current_data, bytes_to_write);

                current_data += bytes_to_write;
                bytes_left_to_write -= bytes_to_write;
                current_block_idx++;
            }

            return 0;
        }
    }

    printf("FILE SYSTEM ERROR: File not found.\n");
    return -1;
}

// read data from an existing file in the file system
char* read_file(FileSystem* file_system, char* name) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->files[i]->name, name) == 0) {
            File* file = file_system->files[i];

            // determine total size of file data
            int total_size = file->size * BLOCK_SIZE;
            if (file->size > 1) {
                total_size -= (BLOCK_SIZE - (file->data_blocks[file->size - 1] % BLOCK_SIZE));
            }

            // allocate buffer for file data
            char* buffer = (char*) malloc(sizeof(char) * total_size);

            // read file data from blocks
            int current_block_idx = 0;
            char* current_buffer = buffer;
            while (current_block_idx < file->size) {
                int block_idx = file->data_blocks[current_block_idx];
                int bytes_to_read = current_block_idx == file->size - 1 ? 
                    file->size * BLOCK_SIZE - (file->size - 1) * BLOCK_SIZE : BLOCK_SIZE;
                
                memcpy(current_buffer, block_idx, bytes_to_read);

                current_buffer += bytes_to_read;
                current_block_idx++;
            }

            return buffer;
        }
    }

    printf("FILE SYSTEM ERROR: File not found.\n");
    return NULL;
}

// delete an existing file from the file system
int delete_file(FileSystem* file_system, char* name) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->files[i]->name, name) == 0) {
            File* file = file_system->files[i];

            // deallocate all file data blocks
            for (int j = 0; j < file->size; j++) {
                deallocate_block(file_system, file->data_blocks[j]);
            }
            free(file->data_blocks);

            // remove file from file system array and deallocate memory
            file_system->files[i] = file_system->files[file_system->num_files - 1];
            file_system->files[file_system->num_files - 1] = NULL;
            file_system->num_files--;

            free(file->name);
            free(file);

            return 0;
        }
    }

    printf("FILE SYSTEM ERROR: File not found.\n");
    return -1;
}

// main function for testing file system functionality
int main() {
    FileSystem* fs = init_file_system();

    create_file(fs, "test.txt");
    write_file(fs, "test.txt", "Hello, world!", 13);

    char* buffer = read_file(fs, "test.txt");
    printf("%s\n", buffer);
    free(buffer);

    delete_file(fs, "test.txt");

    return 0;
}