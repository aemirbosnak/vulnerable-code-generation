//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes
#define BLOCK_SIZE 512 // Size of each block in bytes

// Function to read a block from the file
void read_block(FILE *file, int block_num, char *buffer) {
    fseek(file, block_num * BLOCK_SIZE, SEEK_SET);
    fread(buffer, BLOCK_SIZE, 1, file);
}

// Function to write a block to the file
void write_block(FILE *file, int block_num, char *buffer) {
    fseek(file, block_num * BLOCK_SIZE, SEEK_SET);
    fwrite(buffer, BLOCK_SIZE, 1, file);
}

// Function to recover a deleted file
void recover_file(char *filename) {
    FILE *file;
    char buffer[BLOCK_SIZE];
    int file_size = 0;
    int block_num = 0;

    // Open the file for reading and writing
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Read the file size from the first block
    read_block(file, 0, buffer);
    file_size = atoi(buffer);

    // Allocate memory for the recovered file
    char *recovered_file = malloc(file_size + 1);
    if (recovered_file == NULL) {
        printf("Error: Unable to allocate memory.\n");
        exit(1);
    }

    // Read the remaining blocks and write them to the recovered file
    while (file_size > 0) {
        if (file_size > BLOCK_SIZE) {
            read_block(file, block_num, buffer);
            memcpy(recovered_file + (block_num * BLOCK_SIZE), buffer, BLOCK_SIZE);
            file_size -= BLOCK_SIZE;
            block_num++;
        } else {
            read_block(file, block_num, buffer);
            memcpy(recovered_file + (block_num * BLOCK_SIZE), buffer, file_size);
            file_size = 0;
        }
    }

    // Close the file
    fclose(file);

    // Print the recovered file
    printf("Recovered file:\n%s\n", recovered_file);

    // Free the memory allocated for the recovered file
    free(recovered_file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    recover_file(argv[1]);

    return 0;
}