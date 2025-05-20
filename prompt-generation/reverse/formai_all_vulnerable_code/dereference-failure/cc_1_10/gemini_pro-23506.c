//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the file system structure
typedef struct file_system {
    char *name;
    int size;
    int num_blocks;
    int *blocks;
} file_system;

// Create a new file system
file_system *create_file_system(char *name) {
    file_system *fs = malloc(sizeof(file_system));
    fs->name = strdup(name);
    fs->size = 0;
    fs->num_blocks = 0;
    fs->blocks = NULL;
    return fs;
}

// Destroy a file system
void destroy_file_system(file_system *fs) {
    free(fs->name);
    free(fs->blocks);
    free(fs);
}

// Add a block to a file system
int add_block(file_system *fs, int size) {
    fs->blocks = realloc(fs->blocks, (fs->num_blocks + 1) * sizeof(int));
    fs->blocks[fs->num_blocks] = size;
    fs->num_blocks++;
    fs->size += size;
    return fs->num_blocks - 1;
}

// Remove a block from a file system
void remove_block(file_system *fs, int block_index) {
    if (block_index < 0 || block_index >= fs->num_blocks) {
        return;
    }

    fs->size -= fs->blocks[block_index];
    for (int i = block_index; i < fs->num_blocks - 1; i++) {
        fs->blocks[i] = fs->blocks[i + 1];
    }
    fs->num_blocks--;
    fs->blocks = realloc(fs->blocks, fs->num_blocks * sizeof(int));
}

// Print the file system
void print_file_system(file_system *fs) {
    printf("File system: %s\n", fs->name);
    printf("Size: %d\n", fs->size);
    printf("Number of blocks: %d\n", fs->num_blocks);
    printf("Blocks: ");
    for (int i = 0; i < fs->num_blocks; i++) {
        printf("%d ", fs->blocks[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new file system
    file_system *fs = create_file_system("My file system");

    // Add some blocks to the file system
    add_block(fs, 100);
    add_block(fs, 200);
    add_block(fs, 300);

    // Print the file system
    print_file_system(fs);

    // Remove a block from the file system
    remove_block(fs, 1);

    // Print the file system again
    print_file_system(fs);

    // Destroy the file system
    destroy_file_system(fs);

    return 0;
}