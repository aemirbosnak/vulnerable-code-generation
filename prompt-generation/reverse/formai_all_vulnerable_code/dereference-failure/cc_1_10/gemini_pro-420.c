//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define the file system structure
typedef struct {
    char *name;
    uint64_t size;
    uint64_t blocks;
    uint64_t *block_numbers;
} file;

// Define the block structure
typedef struct {
    uint8_t data[512];
} block;

// Define the file system
file files[10];
uint64_t block_count = 100;
block blocks[100];

// Function to create a file
void create_file(char *name, uint64_t size) {
    // Check if the file already exists
    for (int i = 0; i < 10; i++) {
        if (strcmp(files[i].name, name) == 0) {
            printf("Error: File already exists.\n");
            return;
        }
    }

    // Create the file
    file new_file;
    new_file.name = name;
    new_file.size = size;
    new_file.blocks = (size + 511) / 512;
    new_file.block_numbers = malloc(sizeof(uint64_t) * new_file.blocks);

    // Allocate blocks for the file
    for (int i = 0; i < new_file.blocks; i++) {
        new_file.block_numbers[i] = rand() % block_count;
    }

    // Add the file to the file system
    for (int i = 0; i < 10; i++) {
        if (files[i].name == NULL) {
            files[i] = new_file;
            break;
        }
    }

    printf("File %s created.\n", name);
}

// Function to delete a file
void delete_file(char *name) {
    // Check if the file exists
    for (int i = 0; i < 10; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // Free the blocks allocated to the file
            for (int j = 0; j < files[i].blocks; j++) {
                blocks[files[i].block_numbers[j]].data[0] = 0;
            }

            // Remove the file from the file system
            files[i].name = NULL;
            files[i].size = 0;
            files[i].blocks = 0;
            free(files[i].block_numbers);

            printf("File %s deleted.\n", name);
            return;
        }
    }

    printf("Error: File not found.\n");
}

// Function to write to a file
void write_file(char *name, uint64_t offset, uint8_t *data, uint64_t size) {
    // Check if the file exists
    for (int i = 0; i < 10; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // Check if the offset is within the file
            if (offset + size > files[i].size) {
                printf("Error: Offset is outside the file.\n");
                return;
            }

            // Write the data to the file
            for (int j = 0; j < size; j++) {
                blocks[files[i].block_numbers[offset / 512]].data[offset % 512 + j] = data[j];
            }

            printf("Data written to file %s.\n", name);
            return;
        }
    }

    printf("Error: File not found.\n");
}

// Function to read from a file
void read_file(char *name, uint64_t offset, uint8_t *data, uint64_t size) {
    // Check if the file exists
    for (int i = 0; i < 10; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // Check if the offset is within the file
            if (offset + size > files[i].size) {
                printf("Error: Offset is outside the file.\n");
                return;
            }

            // Read the data from the file
            for (int j = 0; j < size; j++) {
                data[j] = blocks[files[i].block_numbers[offset / 512]].data[offset % 512 + j];
            }

            printf("Data read from file %s.\n", name);
            return;
        }
    }

    printf("Error: File not found.\n");
}

// Function to list the files in the file system
void list_files() {
    // Iterate over the files in the file system
    for (int i = 0; i < 10; i++) {
        if (files[i].name != NULL) {
            printf("%s\n", files[i].name);
        }
    }
}

// Main function
int main() {
    // Create some files
    create_file("file1", 1024);
    create_file("file2", 2048);
    create_file("file3", 4096);

    // List the files in the file system
    list_files();

    // Write some data to a file
    uint8_t data[] = "Hello, world!";
    write_file("file1", 0, data, strlen(data));

    // Read some data from a file
    uint8_t buffer[1024];
    read_file("file1", 0, buffer, 1024);

    // Print the data
    printf("%s\n", buffer);

    // Delete a file
    delete_file("file2");

    // List the files in the file system
    list_files();

    return 0;
}